#ifndef __BOS_STRINGUTILS_H__
#define __BOS_STRINGUTILS_H__

//TO_BE_EXPORTED
#include "bOS.h"

namespace bOS
{
    namespace CoreString
    {
        class BOS_API StringUtils
        {
            public:

                static int compareNoCase( const std::string& lhs, const std::string& rhs );

                static std::string format( std::string formatText, ... );

                static std::string toLowerCase( const std::string text );

                static std::string toUpperCase( const std::string text );

                static std::string toString( const int& value );

                static std::string toString( const long& value );

                static std::string toString( const float& value );

                static std::string toString( const double& value );

                static std::string toString( const unsigned long& value );

                static std::string toString( const unsigned int& value );

                static std::string toString( const char& value );

                static std::string toString( const bool& value );

                static double toDouble( const std::string& value );

                static long toLong( const std::string& value );

                static int toInteger( const std::string& value );

				static unsigned int toUInteger( const std::string& sValue);

                static std::string getErrorString( const long& errorCode );

                static std::string duplicate( const char* source );

                static void trim( std::string& source );

				static std::string fillWith(const std::string& sSrc, std::string sFiller, bool bFillLeft);

				static char* toChar(const std::string& s);
				static char* toChar(char* s);

				static void quoteAndTwice( std::string& source );
				static std::string returnQuoteAndTwice( const std::string& source);
        };
    }
};

#endif



