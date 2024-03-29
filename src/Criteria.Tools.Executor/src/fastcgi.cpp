#include <iostream>

#include "fcgio.h"
#include "fcgi_config.h"

#include <regex>
#include "json.h"

#include "bOS/bOSStringBuffer.h"
using namespace bOS::CoreString;

#include "bOS/Tracer.h"

#include "bOS/bOSTimer.h"

#include "Criteria/WAPI.h"
#include "Criteria/WAPIActivity.h"
#include "Criteria/WAPIWorkItem.h"
#include "Criteria/WAPIProcess.h"
#include "Criteria/WAPIWorkflow.h"

#include "Criteria/Activity.h"

using namespace std;

std::map<std::string, std::string> parse_query_string(const std::string& query)
{
    std::map<std::string, std::string> data;
    std::regex pattern("([\\w+%]+)=([^&]*)");
    auto words_begin = std::sregex_iterator(query.begin(), query.end(), pattern);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; i++)
    {
        std::string key = (*i)[1].str();
        std::string value = (*i)[2].str();
        data[key] = value;
    }

    return data;

}
int fastcgi(void) {

	Response* response = new Response();
	response->iCode= 0;

	CM_SETTING_TO("criteria.web", 7);
	InitSession(response);
	if ( response->iCode != 0 )
	{
		cout << "Criteria session Initialization [KO].Error[" << response->sMsg << "]. Exit." << endl;
		exit(2);
	}
	cout << "Criteria session Initialization [OK]" << endl;

    // Backup the stdio streambufs
    streambuf * cin_streambuf  = cin.rdbuf();
    streambuf * cout_streambuf = cout.rdbuf();
    streambuf * cerr_streambuf = cerr.rdbuf();

    FCGX_Request request;

    FCGX_Init();
	FCGX_OpenSocket(":8000", 10);
    FCGX_InitRequest(&request, 0, 0);

    while (FCGX_Accept_r(&request) == 0) {

        fcgi_streambuf cin_fcgi_streambuf(request.in);
        fcgi_streambuf cout_fcgi_streambuf(request.out);
        fcgi_streambuf cerr_fcgi_streambuf(request.err);

        cin.rdbuf(&cin_fcgi_streambuf);
        cout.rdbuf(&cout_fcgi_streambuf);
        cerr.rdbuf(&cerr_fcgi_streambuf);

        //retrieve all settings
		const char * acQueryString = FCGX_GetParam("QUERY_STRING", request.envp);
		const char * acRequestMethod = FCGX_GetParam("REQUEST_METHOD", request.envp);
		const char * acContentType = FCGX_GetParam("CONTENT_TYPE", request.envp);
		char * acContentLength = FCGX_GetParam("CONTENT_LENGTH", request.envp);
		const char * acScriptFileName = FCGX_GetParam("SCRIPT_FILENAME", request.envp);
		const char * acScriptName = FCGX_GetParam("SCRIPT_NAME", request.envp);
		const char * acRequestUri = FCGX_GetParam("REQUEST_URI", request.envp);
		const char * acDocumentUri = FCGX_GetParam("DOCUMENT_URI", request.envp);
		const char * acDocumentRoot = FCGX_GetParam("DOCUMENT_ROOT", request.envp);
		const char * acServerProtocol = FCGX_GetParam("SERVER_PROTOCOL", request.envp);
		const char * acRemoteAddr = FCGX_GetParam("REMOTE_ADDR", request.envp);
		const char * acRemotePort = FCGX_GetParam("REMOTE_PORT", request.envp);
		const char * acServerName = FCGX_GetParam("SERVER_NAME", request.envp);
		std::map<std::string, std::string> queryString = parse_query_string (acQueryString);

		char * content_buffer = 0;
		unsigned long STDIN_MAX = 10000;
		unsigned long content_length = STDIN_MAX;
	    if (acContentLength) {

			content_length = strtol(acContentLength,
                                &acContentLength,
                                10);

			if (*acContentLength) {
				cout << "Can't Parse 'CONTENT_LENGTH='"
					 << FCGX_GetParam("CONTENT_LENGTH", request.envp)
					 << "'. Consuming stdin up to " << STDIN_MAX << endl;
			}

			if (content_length > STDIN_MAX) {
				content_length = STDIN_MAX;
			}

			content_buffer = new char[content_length + 1];
			cin.read(content_buffer, content_length);
			content_length = cin.gcount();

			content_buffer[content_length] = 0;

			//cout << "<tr><td>CONTENT</td><td>" << content_buffer << "</td></tr>\n";

		} else {
			// Do not read from stdin if CONTENT_LENGTH is missing
			content_length = 0;
		}

		{
			CM_CODEBLOCK("RequestLog")
			CM_TRACE_DEBUG("QUERY_STRING[" << acQueryString << "]");
			CM_TRACE_DEBUG("CONTENT_TYPE[" << acContentType << "]");
			CM_TRACE_DEBUG("CONTENT_LENGTH[" << acContentLength << "]");
			CM_TRACE_DEBUG("SCRIPT_FILENAME[" << acScriptFileName << "]");
			CM_TRACE_DEBUG("SCRIPT_NAME [" << acScriptName << "]");
			CM_TRACE_DEBUG("DOCUMENT_URI[" << acDocumentUri << "]");
			CM_TRACE_DEBUG("DOCUMENT_ROOT[" << acDocumentRoot << "]");

			CM_TRACE_DEBUG(
				"REQUEST_METHOD[" << acRequestMethod << "]" <<
				"SERVER_NAME[" << acServerName << "]" <<
				"REMOTE_PORT[" << acRemotePort << "]" <<
				"REMOTE_ADDR[" << acRemoteAddr << "]" <<
				"REQUEST_URI[" << acRequestUri << "]");

			if ( acQueryString ) {

				typedef std::map<std::string, std::string>::iterator it_type;
				for(it_type iterator = queryString.begin(); iterator != queryString.end(); iterator++) {
					// iterator->first = key
					// iterator->second = value
					CM_TRACE_DEBUG(
						"QUERY_KEY[" << iterator->first << "]" <<
						"QUERY_VAL[" <<iterator->second << "]");
				}
			}

			if ( content_length > 0 )
				CM_TRACE_DEBUG("CONTENT[" << content_buffer << "]");
		}

		//processes template list
		if ( strcmp(acDocumentUri, "/criteria/processes/templates") == 0 )
		{

			cout << "Content-type: application/xml\r\n" << "\r\n";
			string workflowList = getWorkflowList(response);
			cout << workflowList << "\r\n";

		}
		// create and start process process template
		else if ( strcmp(acDocumentUri, "/criteria/processes/templates/create") == 0 )  {

			cout << "Content-type: application/xml\r\n" << "\r\n";

			std::string processName = queryString["process"];
			char* lProcessId = new char[50];
			createWorkflowProcess(processName.c_str(), lProcessId, response);
			if ( response->iCode == 0 )
			{
				startProcessInSynchWay(lProcessId, response);
				if ( response->iCode == 0 )
				{
					Json::Value root;
					root["processId"] = lProcessId;
					root["code"] = 0;

					Json::StyledWriter styledWriter;
					std::cout << styledWriter.write(root) << "\r\n";
				}
				else
				{
					cout << "Execute process instance [KO]. Process Instance Id[" << lProcessId << "] not started" << endl;
				}
			}
			else
			{
				cout << "Create process instance [KO]. Err[" << response->sMsg << "]" << endl;
			}

		}
		//get processes instances list
		else if ( strcmp(acDocumentUri, "/criteria/processes/instances") == 0 ) {

			cout << "Content-type: application/xml\r\n"
				<< "\r\n";

			string processes = getProcesses(response);

			cout << processes << "\r\n";

		}
		//get process
		else if ( strcmp(acDocumentUri, "/criteria/processes/instances/process") == 0 )  {

			cout << "Content-type: application/xml\r\n" << "\r\n";

			std::string processID = queryString["id"];
			char* lProcessId = new char[50];
			std::string result = getProcessInstance((char*)processID.c_str(), response);
			if ( response->iCode == 0 )
			{
				cout << result << "\r\n";
			}
			else
			{
				cout << "Error Retrieving process process instance [KO]. Err[" << response->sMsg << "]" << endl;
			}

		}
		//get process attributes
		else if ( strcmp(acDocumentUri, "/criteria/processes/instances/process/attributes") == 0 )  {

			cout << "Content-type: application/xml\r\n" << "\r\n";

			std::string processID = queryString["id"];

			if ( strcmp(acRequestMethod,"GET") == 0 ) {
				std::string result = getProcessInstanceAttributes((char*)processID.c_str(),response);
				if ( response->iCode == 0 )
				{
					cout << result << "\r\n";
				}
				else
				{
					cout << "Error Retrieving process process instance [KO]. Err[" << response->sMsg << "]" << endl;
				}
			} else if ( strcmp(acRequestMethod, "POST" )== 0) {

				std::string result = setProcessInstanceAttributes((char*)processID.c_str(), content_buffer, response);
				if ( response->iCode == 0 )
				{
					cout << result << "\r\n";
				}
				else
				{
					cout << "Error Retrieving process process instance [KO]. Err[" << response->sMsg << "]" << endl;
				}
			}

		}
		//execute task
		else if ( strcmp(acDocumentUri, "/criteria/tasks/execute") == 0 )  {

			cout << "Content-type: application/xml\r\n" << "\r\n";

			std::string processID = queryString["id"];
			std::string activityName = queryString["activity"];

			DataManager::Panorama::WorkflowProcesses::Activity activity;
			activity.setName (activityName.c_str());
			activity.setProcessId (processID.c_str());
			String sUser="scenario";
			String sActivity = activity.getXMLString(0);


			acquireActivity((char*)sActivity.c_str(), (char*)sUser.c_str(), response);
			doWorkItem((char*)sActivity.c_str(), (char*)sUser.c_str(), response);
			completeWorkItem((char*)sActivity.c_str(), (char*)sUser.c_str(),"", response);

			char* lProcessId = new char[50];
			std::string result = getProcessInstance((char*)processID.c_str(), response);
			if ( response->iCode == 0 )
			{
				cout << result << "\r\n";
			}
			else
			{
				cout << "Error Retrieving process process instance [KO]. Err[" << response->sMsg << "]" << endl;
			}

		}
		//get task attribute
		else if ( strcmp(acDocumentUri, "/criteria/tasks/attributes") == 0 )  {

			cout << "Content-type: application/xml\r\n" << "\r\n";



			std::string processID = queryString["id"];
			std::string activityName = queryString["activity"];

			DataManager::Panorama::WorkflowProcesses::Activity activity;
			activity.setName (activityName.c_str());
			activity.setProcessId (processID.c_str());
			String sUser="scenario";
			String sActivity = activity.getXMLString(0);

			if ( strcmp(acRequestMethod,"GET") == 0 ) {

				std::string strAttributes =  getActivityAttributes((char*)sActivity.c_str(), (char*)sUser.c_str(), response);
				if ( response->iCode == 0 )
				{
					cout << strAttributes << "\r\n";
				}
				else
				{
					cout << "Error Retrieving process process instance [KO]. Err[" << response->sMsg << "]" << endl;
				}
			} else {

				std::string strAttributes =  setActivityAttributes((char*)sActivity.c_str(), content_buffer, (char*)sUser.c_str(), response);
				if ( response->iCode == 0 )
				{
					cout << strAttributes << "\r\n";
				}
				else
				{
					cout << "Error Retrieving process process instance [KO]. Err[" << response->sMsg << "]" << endl;
				}
			}
		}
		else {

			cout << "Content-type: application/json\r\n" << "\r\n";
			Json::Value root;

			root["QUERY_STRING"] = acQueryString;
			root["REQUEST_METHOD"] = acRequestMethod;
			root["CONTENT_TYPE"] = acContentType;
			root["CONTENT_LENGTH"] = acContentLength;
			root["SCRIPT_FILENAME"] = acScriptFileName;
			root["SCRIPT_NAME"] = acScriptName;
			root["REQUEST_URI"] = acRequestUri;
			root["DOCUMENT_URI"] = acDocumentUri;
			root["DOCUMENT_ROOT"] = acDocumentRoot;
			root["SERVER_PROTOCOL"] = acServerProtocol;
			root["REMOTE_ADDR"] = acRemoteAddr;
			root["REMOTE_PORT"] = acRemotePort;
			root["SERVER_NAME"] = acServerName;

			if ( content_length > 0 )
				root["CONTENT"] = content_buffer;

			if ( acQueryString ) {
				Json::Value array;
				typedef std::map<std::string, std::string>::iterator it_type;
				for(it_type iterator = queryString.begin(); iterator != queryString.end(); iterator++) {
					Json::Value keyvalue;
					keyvalue[iterator->first] = iterator->second;

					array.append(keyvalue);
				}

				root["QUERY_STRING"] = array;
			}

			Json::StyledWriter styledWriter;
			std::cout << styledWriter.write(root) << "\r\n";
		}
		/*
		cout << "<table>\n";
		cout << "<tr><td>QUERY_STRING</td><td>" << acQueryString << "</td></tr>\n";
		cout << "<tr><td>REQUEST_METHOD</td><td>" << acRequestMethod << "</td></tr>\n";
		cout << "<tr><td>CONTENT_TYPE</td><td>" << acContentType << "</td></tr>\n";
		cout << "<tr><td>CONTENT_LENGTH</td><td>" << acContentLength << "</td></tr>\n";
		cout << "<tr><td>SCRIPT_FILENAME</td><td>" << acScriptFileName << "</td></tr>\n";
		cout << "<tr><td>SCRIPT_NAME</td><td>" << acScriptName << "</td></tr>\n";
		cout << "<tr><td>REQUEST_URI</td><td>" << acRequestUri << "</td></tr>\n";
		cout << "<tr><td>DOCUMENT_URI</td><td>" << acDocumentUri << "</td></tr>\n";
		cout << "<tr><td>DOCUMENT_ROOT</td><td>" << acDocumentRoot << "</td></tr>\n";
		cout << "<tr><td>SERVER_PROTOCOL</td><td>" << acServerProtocol << "</td></tr>\n";
		cout << "<tr><td>REMOTE_ADDR</td><td>" << acRemoteAddr << "</td></tr>\n";
		cout << "<tr><td>REMOTE_PORT</td><td>" << acRemotePort << "</td></tr>\n";
		cout << "<tr><td>SERVER_NAME</td><td>" << acServerName << "</td></tr>\n";
		*/



		//cout << "</table>\n";

		/*

		Json::Value root;   // will contains the root value after parsing.
		Json::Reader reader;
		bool parsingSuccessful = reader.parse( config_doc, root );
		if ( !parsingSuccessful )
		{
			// report to the user the failure and their locations in the document.
			std::cout  << "Failed to parse configuration\n"
					   << reader.getFormattedErrorMessages();
			cout << "Error";

			continue;
		}
		*/

		/*
		std::string encoding = root.get("encoding", "UTF-8" ).asString();
		const Json::Value plugins = root["plug-ins"];
		for ( unsigned int index = 0; index < plugins.size(); ++index )  // Iterates over the sequence elements.
			cout <<  plugins[index].asString() ;
		*/
		/*
		Json::StyledWriter writer;
		std::string outputConfig = writer.write( root );

		std::cin >> root["subtree"];

		cout << root;
		*/
        // Note: the fcgi_streambuf destructor will auto flush
		//cout << "  </body>\n" << "</html>\n";
    }

    // restore stdio streambufs
    cin.rdbuf(cin_streambuf);
    cout.rdbuf(cout_streambuf);
    cerr.rdbuf(cerr_streambuf);

	cout << "EndSession......." << endl;
	response->iCode = 0;
	EndSession(response);
	if ( response->iCode == 0 )
	{
		cout << "Session Terminated [OK]" << endl;
	}
	else
	{
		cout << "Terminating [KO].Err[" << response->sMsg << "]" << endl;
	}


    return 0;
}

