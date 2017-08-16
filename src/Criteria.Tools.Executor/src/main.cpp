#include "bOS/bOSStringBuffer.h"
using namespace bOS::CoreString;

#include "bOS/Tracer.h"

#include "bOS/bOSTimer.h"

#include "Criteria/WAPI.h"
#include "Criteria/WAPIActivity.h"
#include "Criteria/WAPIWorkItem.h"
#include "Criteria/WAPIProcess.h"

#include "Criteria/Activity.h"

static void usage()
{
	cout << "\nUsage:\n"
			"	CriteriaToolsExecutor <WorkflowName> [NrExecution]\n\n"
			"This program invokes criteria workflow engine and execute <WorkflowName>\n"
			"Options:\n"
			"	NrExecution		the number of process execution. Default is 1\n"
	<< endl;
}

int run(int argc, char* argv[]);
int fastcgi();

int main(int argc, char* argv[])
{
    CM_SETTING_TO("criteria", 7);

    if ( argc == 1 )
	{
		usage();
		exit(1);
	}

	String command;
    command = argv[1];

    if ( command == "database") {

        cout << "This command drop and create the database.\n" << endl;

        //TODO: Recover this part
        /*
        DataBase::instance();

        DataBase::instance()->drop();

        DataBase::instance()->create();

        DataBase::deinstance();
        */

    } else if (command == "run") {

        run(argc,argv);
    }

}


int run(int argc, char* argv[])
{
	String sWorkflowName;
	if ( argc >= 3 )
	{
		sWorkflowName = argv[2];
	}

	unsigned int uiSize =1;
	if ( argc == 4 )
	{
		uiSize = atoi(argv[3]);
	}

	cout << "The program will perform the following steps:\n\n"
				"1: Criteria session initialization (only one time)\n"
				"	----- for each process (begin) -----\n"
				"2: Create process instance from template\n"
				"3: Execute process instance just created\n"
				"	----- for each process (end) -----\n"
				"4: Querying for activity pending\n"
				"5: close criteria session\n\n";

	cout << "Press a Key for beginning................................................" << endl;
	getchar();

	Response* response = new Response();
	response->iCode= 0;

	cout << "Criteria session Initialization.....(look at Executor trace file)" << endl;
	InitSession(response);
	if ( response->iCode != 0 )
	{
		cout << "Criteria session Initialization [KO].Error[" << response->sMsg << "]. Exit." << endl;
		exit(2);
	}
	cout << "Criteria session Initialization [OK]" << endl;

	bOS::Utils::Timer tExecutionTimer;
	tExecutionTimer.start();

	char* lProcessId = new char[50];
	//char* acRet = NULL;

	StringBuffer outputSimplified;
	cout << "Create process instance from template" << endl;
	for ( unsigned int i=0; i<uiSize; i++)
	{
		bOS::Utils::Timer tTot;
		bOS::Utils::Timer tCreate;
		bOS::Utils::Timer tStart;

		tTot.start();

		tCreate.start();
		createWorkflowProcess((char*)sWorkflowName.c_str(), lProcessId, response);
		tCreate.stop();

		if ( response->iCode == 0 )
		{
			//cout << "Create process instance [OK]. Process Instance Id[" << lProcessId << "]" << endl;
			tStart.start();
			startProcessInSynchWay(lProcessId, response);
			tStart.stop();
			tTot.stop();

			if ( response->iCode == 0 )
			{
				//cout << "Execute process instance [OK]. Process Instance Id[" << lProcessId << "] just started" << endl;
				cout << "[" << i << "] Process [" << lProcessId << "] [" << tCreate.getTicks() << "] [" << tStart.getTicks() << "] [" << tTot.getTicks() << "]" << endl;
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

	cout << "Querying for activity pending" << endl;

	unsigned long lWorkflowRunning=0;
	do
	{
		lWorkflowRunning= getNumberRunningWorkflow(response);
		if ( response->iCode == 0 )
		{
			cout << "WorkflowRunning[" << lWorkflowRunning << "]" << endl;
		}
		else
		{
			cout << "Error retreiving RunningWorkflow.Err[" << response->sMsg << "]" << endl;
		}
	}
	while ( lWorkflowRunning > 0);

	tExecutionTimer.stop();

	cout << "Execution Time(ms): " << tExecutionTimer.getTicks() << endl;
	cout << "Press a Key for terminating................................................" << endl;
	getchar();


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
//

	return 0;
}

