#ifndef __BOS_SEMAPHORE_H__
#define __BOS_SEMAPHORE_H__

//TO_BE_EXPORTED
#include "bOS.h"

namespace bOS
{
    namespace Core
    {
        class BOS_API Semaphore
        {
            public:

                Semaphore( std::string Name = "", int initialCount = 0, int maxCount = -1 );
                virtual ~Semaphore();
                virtual void wait();
                bool tryWait();
                virtual void post();

            protected:
#ifdef _BOS_ON_WIN32_
                SEMAPHORE  m_hSemaphore;
#else
                sem_t  m_hSemaphore;
                sem_t *sem_ptr;
#endif

            private:

                bool                _isNamed;
                std::string		        _Name;
#ifdef _BOS_ON_WIN32_
                unsigned long       _OwnerThread;
#else
                pthread_t _OwnerThread;
#endif

                //Not implemented
                Semaphore( const Semaphore& cs );
                Semaphore& operator= ( const Semaphore& cs );
        };
    }
};

#endif



