#include "CommonDefines.h"

#include "WorkflowListener.h"
using namespace WorkflowEngine::Criteria::Event::Listener;

#include "BaseEvent.h"
using namespace WorkflowEngine::Criteria::Event;

//Events
#include "StartedWorkflowEvent.h"
#include "RestartedWorkflowEvent.h"
#include "ManualWorkflowEvent.h"
#include "ErrorWorkflowEvent.h"
#include "EndWorkflowEvent.h"
using namespace WorkflowEngine::Criteria::Event::WorkflowEvent;

#include "bOS/bOS.h"
#include "bOS/bOSStringUtils.h"
using namespace bOS::CoreString;






const String WorkflowListener::ENGINE_NOTIFY	= "AMMNOTIFICATION";
const String WorkflowListener::PROCESSINSTANCE	= "PROCESS_INSTANCE";
const String WorkflowListener::STATUS			= "STATUS";

WorkflowListener::WorkflowListener() : EventListener("WorkflowListener")
{
}

WorkflowListener::~WorkflowListener()
{
}

void WorkflowListener::eventAction( BaseEvent& event )
{
    CM_CODEBLOCK(eventAction)

    const char* processID = 0;
    String sEvent = "";

	BaseEvent* evt = &event;

    if ( evt->getName() == "RestartedWorkflowEvent" )
	{
        CM_TRACE_CODEPATH( "Event Received:[RestartedWorkflowEvent]")
        //processID = ((RestartedWorkflowEvent*)evt)->getProcessID();
        sEvent = "RESTARTED";
	}
    else if ( evt->getName() == "ManualWorkflowEvent" )
	{
        CM_TRACE_CODEPATH( "Event Received:[ManualWorkflowEvent]")
        //processID = ((ManualWorkflowEvent*)evt)->getProcessID();
        sEvent = "STOPPED";
	}
    else if ( evt->getName() == "ErrorWorkflowEvent" )
	{
        CM_TRACE_CODEPATH( "Event Received:[ErrorWorkflowEvent]")
        //processID = ((ErrorWorkflowEvent*)evt)->getProcessID();
        sEvent = "ERROR";
	}
    else if ( evt->getName() == "EndWorkflowEvent" )
	{
        CM_TRACE_CODEPATH( "Event Received:[EndWorkflowEvent]")
        //processID = ((EndWorkflowEvent*)evt)->getProcessID();
        sEvent = "COMPLETED";
	}
    else if ( evt->getName() == "StartedWorkflowEvent" )
    {
        CM_TRACE_CODEPATH( "Event Received:[StartedWorkflowEvent]. No Action.")
        //processID = ((StartWorkflowEvent*)evt)->getProcessID();
        sEvent = "STARTED";

        return;
    }
    else
    {
        CM_TRACE_CODEPATH( "Event Received:[Unknow]")
        return;
    }

    CM_TRACE_CODEPATH( "Sending Message. ProcessID[" << processID << "] Status[" << sEvent << "]")
}


