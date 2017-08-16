#include "CommonDefines.h"

#include "WAPI.h"
#include "WAPIError.h"

//DB
#include "DataBaseHelper.h"
#include "DBException.h"
using namespace DataManager::DataBase;

#include "Engine.h"
#include "EngineException.h"
using namespace WorkflowEngine::Criteria; 

#include "bOS/bOSXMLHelper.h"

#include "bOS/bOS.h"
#include "bOS/bOSSystem.h"
using namespace bOS::CoreSystem;

#include "bOS/Tracer.h"

extern "C" ENGINE_API const char* Version()
{
	return CRITERIA_VERSION.c_str();
}


extern "C" ENGINE_API void InitSession(Response* response)
{
	CM_SETTING_TO("WAPI", 7);
	CM_CODEBLOCK(WAPI::InitSession)
	
	StringBuffer sPath;
	try
	{
		CM_TRACE_INFO("Retrieving Criteria configuration files");
		String sWfHome = System::getEnvironmentVariable("CRITERIA_HOME");
		if ( sWfHome.length() == 0) 
		{
			CM_TRACE_FATAL("WF_HOME Environment Variable is not defined.")
			response->iCode = WAPI_DATABASE_INSTANCE_ERROR;
			response->sMsg = "Impossible to retrieve WF_HOME";
			return;
		}
		
		sPath.append(sWfHome);
		sPath.append(SLASH);
		sPath.append("database");
		sPath.append(SLASH);
		sPath.append("Criteria.xml");
	}
	catch ( ... )
	{
		CM_TRACE_ERROR("Error instancing DB-Engine[Unknow Error]")
		response->iCode = WAPI_INSTANCE_ERROR;
		response->sMsg = "Unknow Error";
	}
	
	InitSessionWithParams (sPath.getData(),response);
}

extern "C" ENGINE_API void InitSessionWithParams(const char* acConfigFile,Response* response)
{
	CM_SETTING_TO("Criteria", 7);
	CM_CODEBLOCK(WAPI::InitSession)
	
	CM_TRACE_INFO("Initializing XML Engine")
	bOS::XML::XMLHelper::initialize();

	try
	{
		DataBaseHelper::instance()->open(acConfigFile);

		CM_TRACE_INFO("Instancing Engine")
		Core::Engine::instance();
	}
	catch (DBException& dbErr ) 
	{
		CM_TRACE_ERROR("Error instancing DB[" << dbErr.getMessage() << "]")
		response->iCode = WAPI_DATABASE_INSTANCE_ERROR;
		response->sMsg = StringUtils::toChar (dbErr.getMessage());
	}
	catch ( EngineException& wfErr) 
	{
		CM_TRACE_ERROR("Error instancing Engine[" << wfErr.getMessage() << "]")
		response->iCode = WAPI_ENGINE_INSTANCE_ERROR;
		response->sMsg = StringUtils::toChar (wfErr.getMessage());
	}
	catch ( ... )
	{
		CM_TRACE_ERROR("Error instancing DB-Engine[Unknow Error]")
		response->iCode = WAPI_INSTANCE_ERROR;
		response->sMsg = "Unknow Error";
	}

	CM_TRACE_INFO("Initializing OK")
}

extern "C" ENGINE_API void EndSession(Response* response)
{
	CM_CODEBLOCK(EndSession)

	try
	{
		CM_TRACE_INFO("De-Instancing DataBase");
		DataBaseHelper::deinstance();

		CM_TRACE_INFO("De-Instancing Engine");
		Core::Engine::deinstance();
	}
	catch (DBException& dbErr ) 
	{
		CM_TRACE_ERROR("Error deinstancing DB[" << dbErr.getMessage() << "]")
		response->iCode = WAPI_DATABASE_INSTANCE_ERROR;
		response->sMsg = StringUtils::toChar (dbErr.getMessage());
	}
	catch ( EngineException& wfErr) 
	{
		CM_TRACE_ERROR("Error deinstancing Engine[" << wfErr.getMessage() << "]")
		response->iCode = WAPI_ENGINE_INSTANCE_ERROR;
		response->sMsg = StringUtils::toChar (wfErr.getMessage());
	}
	catch ( ... )
	{
		CM_TRACE_ERROR("Error deinstancing DB-Engine[Unknow Error]")
		response->iCode = WAPI_INSTANCE_ERROR;
		response->sMsg = "Unknow Error";
	}
	
	bOS::XML::XMLHelper::terminate();
}


extern "C" ENGINE_API char* GetScenarioExecutionDirectory(Response* response)
{
	CM_CODEBLOCK(GetScenarioExecutionDirectory)

	string sDirectory = bOS::CoreSystem::System::getEnvironmentVariable ("WF_HOME");

	if ( sDirectory == "" )
	{
		CM_TRACE_ERROR("Error retrieving Variable")
		response->iCode = WAPI_DATABASE_INSTANCE_ERROR;
		response->sMsg = StringUtils::toChar ("Error retrieving Variable");
		return "";
	}
	else
	{
		response->iCode = 0;
	}

	return StringUtils::toChar (sDirectory);
}

extern "C" ENGINE_API char* GetCheckListFolder(Response* response)
{
	String sFolder = DataBaseHelper::instance()->getCheckListFolder();

	return StringUtils::toChar(sFolder);
}