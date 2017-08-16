
#ifndef __BOS_PROCESS_H__
#define __BOS_PROCESS_H__

//TO_BE_EXPORTED
#include "bOS.h"

namespace bOS
{
    namespace System
    {
        typedef std::vector<std::string> ProcessArguments;

        /**
         * A Process represents an EXE. More docs here...
         */
        class BOS_API Process
        {
            public:

                Process();

				Process(unsigned int pid);

                virtual ~Process();

                virtual unsigned int getProcessID();

                virtual unsigned int getThreadID();

                virtual void createProcess( const std::string& processName, ProcessArguments args );

                virtual std::string getProcessName();

                virtual int getExitCode();

                virtual bool isRunning();

                virtual int waitFor();

                virtual void destroyProcess();

				static void* getCurrentProcessId();

            protected:

                PROCESS         m_hProcess;

                unsigned int    m_ProcessID;
                unsigned int    m_ThreadID;

                std::string          m_processFileName;
        };
    }
};

#endif


