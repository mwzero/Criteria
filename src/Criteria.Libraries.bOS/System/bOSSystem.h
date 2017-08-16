
#ifndef __BOS_SYSTEM_H__
#define __BOS_SYSTEM_H__

//TO_BE_EXPORTED
#include "bOS.h"

namespace bOS
{
    namespace CoreSystem
    {
        enum EnvironmentStrategy
        {
            esCreate = 1,
            esOverwrite,
            esAppendBegin,
            esAppendAtEnd
        };

        class BOS_API System
        {
            public:

                static unsigned long getCurrentTimeMillis();

				static std::string expandEnvironmentStrings( const std::string& sString );
                static std::string getEnvironmentVariable( std::string Name );
                static void setEnvironmentVariable( std::string Name, std::string Value, EnvironmentStrategy es = esCreate );
                static std::string getHostName();
                static std::string createUUID();

				static std::string getErrorString( const long lErrorCode);
        };
    }
};

#endif


