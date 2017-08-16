#ifndef __BOS_MUTEX_H__
#define __BOS_MUTEX_H__

//TO_BE_EXPORTED
#include "bOS.h"
#include "bOSSmartLocker.h"

namespace bOS
{
    namespace Core
    {
        class BOS_API Mutex
        {
            public:

                typedef SmartLocker<Mutex> Lock;

                Mutex( std::string Name = "" );

                virtual ~Mutex();

                void lock();

                void unlock();

                bool tryLock();

                MUTEX getHandle();

				std::string getName();

                void setName( std::string Name );

            protected:
#ifdef _BOS_ON_WIN32_
                MUTEX m_hMtx;
#else
                pthread_mutexattr_t  attr;
                pthread_mutex_t      mutex;
#endif
				std::string   sName;

        };
    }
};

#endif



