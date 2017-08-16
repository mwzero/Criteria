#ifndef _EVENTS_MANAGER_H_
#define _EVENTS_MANAGER_H_


//TO_BE_EXPORTED

#include "CriteriaCommonDefines.h"

#include "bOS/bOS.h"

namespace DataManager
{
	namespace Panorama
	{
		namespace WorkflowEvents
		{
			class OccurredEvent;
			class Event;
			class WaitingActivity;
		}

		namespace WorkflowProcesses
		{
			class Activity;
		}
	}
}
using namespace DataManager::Panorama;

namespace WorkflowEngine
{
	class ENGINE_API WorkflowAction
	{
	public:
		WorkflowAction(String sWorkflowName);
		WorkflowAction(const char* processId, String sActivityName);
		~WorkflowAction();

		const char* getProcessId();
		String& getActivityName();
		String& getWorkflowName();

	private:
		String sWorkflowName;
		String processId;
		String sActivityName;

	};
	typedef vector<WorkflowAction> WorkflowActionList;

	class ENGINE_API EventsManager
	{
	public:
		static EventsManager* instance();
		static void deinstance();

		WorkflowEvents::OccurredEvent* addEventbyActivity(WorkflowEvents::Event* event, WorkflowProcesses::Activity* task);
		WorkflowEvents::WaitingActivity* addWaitingActivity(WorkflowProcesses::Activity* task,WorkflowEvents::Event* event);

		WorkflowEvents::OccurredEvent* getAnEvent2Manage(WorkflowActionList&);
		void setEvent2Managed(WorkflowEvents::OccurredEvent* occurredEvent);

	private:
		static EventsManager* _instance;

		EventsManager();
		~EventsManager();

	};
}

#endif //_EVENTS_MANAGER_H_
