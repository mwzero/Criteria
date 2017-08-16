#include "CommonDefines.h"

#include "bOSRuntimeException.h"
using namespace bOS::Exception;

#include "bOSSystem.h"
using namespace bOS::CoreSystem;

#define MAX_VAR 8192

unsigned long System::getCurrentTimeMillis()
{
    #ifdef _BOS_ON_WIN32_
        return ((unsigned long)::GetTickCount());
	#else // _BOS_ON_SOLARIS_ _BOS_ON_HP_
        timeb aTime;
        ftime(&aTime);
        return (unsigned long)(aTime.time*1000 + aTime.millitm);
    #endif
}

std::string System::getEnvironmentVariable(std::string Name)
{
    #ifdef _BOS_ON_WIN32_
        std::string oldValue = "";
        Char newVar[MAX_VAR];
        DWORD dwSuccess;
        // lpszOldValue gets current value of "varname", or NULL if "varname"
        // environment variable does not exist.
        dwSuccess = GetEnvironmentVariable( Name.c_str(), newVar, MAX_VAR );
        if ( dwSuccess > 0 )
            oldValue = newVar;
        return oldValue;
	#else // _BOS_ON_SOLARIS_ _BOS_ON_HP_
        std::string var = "";
        Char* _var = getenv(Name.c_str());
        if ( _var != NULL )
            var = _var;
        return var;
    #endif
}

void System::setEnvironmentVariable(std::string Name, std::string Value, EnvironmentStrategy es)
{
    #ifdef _BOS_ON_WIN32_
        HKEY _userEnv;
        Char newVar[MAX_VAR];
        //Open the HKEY_CURRENT_USER\Environment key
        LONG lRet = RegOpenKeyEx(HKEY_CURRENT_USER, "Environment\\", 0, KEY_ALL_ACCESS, &_userEnv);
        if ( lRet != ERROR_SUCCESS )
        {
            LPVOID lpMsgBuffer;
            FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                        NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                        (LPTSTR) &lpMsgBuffer, 0, NULL );
            throw RuntimeException( ENV_DEFAULT_ERROR + std::string((LPTSTR)lpMsgBuffer) );
        }
        unsigned long lType = 0;
        unsigned long lSize = MAX_VAR;
        if ( (es != esCreate) && (es != esOverwrite) )
        {
            //Query if the variable name exist
            lRet = RegQueryValueEx(_userEnv, Name.c_str(), NULL, &lType, (Byte*)newVar, &lSize);
            if ( lRet != ERROR_SUCCESS )
            {
                LPVOID lpMsgBuffer;
                FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                            NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                            (LPTSTR) &lpMsgBuffer, 0, NULL );
                throw RuntimeException( ENV_DEFAULT_ERROR + std::string((LPTSTR)lpMsgBuffer) );
            }
        }
        switch (es)
        {
        case esCreate:
        case esOverwrite:
            {
                strcpy(newVar, Value.c_str());
                lSize = Value.length();
            }
            break;
        case esAppendBegin:
            {
                std::string tmp = newVar;
                Value += ";" + tmp;
                strcpy( newVar, Value.c_str() );
                lSize = Value.length();
            }
            break;
        case esAppendAtEnd:
            {
                strcat( newVar, ";" );
                strcat( newVar, Value.c_str() );
                lSize = strlen( newVar ) + 1;
            }
            break;
        }
        //Set the new variable
        lRet = RegSetValueEx(_userEnv, Name.c_str(), NULL, REG_SZ, (Byte*)newVar, lSize);
        if ( lRet != ERROR_SUCCESS )
        {
            LPVOID lpMsgBuffer;
            FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                        NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                        (LPTSTR) &lpMsgBuffer, 0, NULL );
            throw RuntimeException( ENV_DEFAULT_ERROR + std::string((LPTSTR)lpMsgBuffer) );
        }
        lRet = RegCloseKey(_userEnv);
        if ( lRet != ERROR_SUCCESS )
        {
            LPVOID lpMsgBuffer;
            FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                        NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                        (LPTSTR) &lpMsgBuffer, 0, NULL );
            throw RuntimeException( ENV_DEFAULT_ERROR + std::string((LPTSTR)lpMsgBuffer) );
        }
	#else // _BOS_ON_SOLARIS_ _BOS_ON_HP_
        /*
        #ifdef HAVE_SETENV
            setenv(name, value, (int)overwrite);
        #else
            char strbuf[256];
            _snprintf(strbuf, sizeof(strbuf), "%s=%s", Name, Value);
            if(!Overwrite)
                if(getenv(strbuf))
                    return;
            putenv(strbuf);
        #endif
        */
    #endif
}

std::string System::getErrorString( const long lErrorCode)
{
    std::string result = "";

    #ifdef _BOS_ON_WIN32_
        LPVOID lpMessageBuffer = 0;
        FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                       NULL, lErrorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                       (LPTSTR) &lpMessageBuffer, 0, NULL );
        result = (char*)lpMessageBuffer;
        LocalFree( (HLOCAL)lpMessageBuffer );
        // Strip trailing .crlf if present
        if ( result.size() > 2 && (result[result.size()-3] == '.') )
	        result.erase( result.size() - 3 );
	#else
        result = std::string( strerror(lErrorCode) );
    #endif

    return result;
}

std::string System::expandEnvironmentStrings( const std::string& sString )
{
	std::string sResult = "";

    #ifdef _BOS_ON_WIN32_
        char acBuffer[2048];
        if ( ExpandEnvironmentStrings( sString.c_str(), acBuffer, sizeof(acBuffer) ) )
            sResult = acBuffer;
        else
            sResult = sString;
	#else
		sResult = sString;

	#endif

	return sResult;
}
