#include "CommonDefines.h"

#include "bOSMutex.h"
using namespace bOS::Core;

#include "bOSSynchronizationException.h"
using namespace bOS::Exception;


Mutex::Mutex( std::string Name )
{

#ifdef _BOS_ON_WIN32_
	setName(Name);

    m_hMtx = CreateMutex( NULL, FALSE, Name.c_str() );

    if ( m_hMtx == NULL )
	{
        throw SynchronizationException();
	}
#else
    pthread_mutexattr_init (&attr);
    if (pthread_mutex_init(&mutex, &attr))
    {
        //return RC_OBJECT_NOT_CREATED;
        throw SynchronizationException(RC_OBJECT_NOT_CREATED);
    }

#endif
}

Mutex::~Mutex()
{
#ifdef _BOS_ON_WIN32_
    if ( m_hMtx != NULL )
	{
        CloseHandle( m_hMtx );
	}
#else
if (pthread_mutex_destroy(&mutex) == EBUSY)
            //return RC_NOT_OWNER;
            throw SynchronizationException( RC_NOT_OWNER );
#endif
}

void Mutex::lock()
{
#ifdef _BOS_ON_WIN32_
    DWORD nResult = WaitForSingleObject( m_hMtx, INFINITE );
    if (nResult == WAIT_FAILED)
	{
        throw SynchronizationException();
	}
#else
if ( pthread_mutex_lock(&mutex))
        //return RC_LOCK_ERROR;
        throw SynchronizationException( RC_LOCK_ERROR );
#endif
}

void Mutex::unlock()
{
#ifdef _BOS_ON_WIN32_
    BOOL bResult = ReleaseMutex( m_hMtx );
    if ( !bResult )
	{
        throw SynchronizationException();
	}
#else
if ( pthread_mutex_unlock(&mutex))
        //return RC_UNLOCK_ERROR;
        throw SynchronizationException( RC_UNLOCK_ERROR );
#endif
}

bool Mutex::tryLock()
{
#ifdef _BOS_ON_WIN32_
    DWORD nResult = WaitForSingleObject( m_hMtx, 0 );
    switch ( nResult )
    {
    case WAIT_OBJECT_0:
	    return true;
    case WAIT_TIMEOUT:
	    return false;
    default:
	    throw SynchronizationException();
    }
#else
    if ( pthread_mutex_lock(&mutex))
        //return RC_LOCK_ERROR;
        throw SynchronizationException( RC_LOCK_ERROR );
#endif
}

std::string Mutex::getName()
{
    return sName;
}

void Mutex::setName( std::string Name )
{
    sName = Name;
}


