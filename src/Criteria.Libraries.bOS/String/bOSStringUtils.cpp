#include "CommonDefines.h"

#include "bOSStringUtils.h"
#include "bOSStringBuffer.h"
using namespace bOS::CoreString;

#define TO_STRING_TXT_SIZE	50
#define MAX_TRACE_STRING        5000

int StringUtils::compareNoCase( const std::string& lhs, const std::string& rhs )
{
	std::string::const_iterator ilhs = lhs.begin();
	std::string::const_iterator irhs = rhs.begin();

	while ( ilhs != lhs.end() && irhs != rhs.end() )
	{
		if ( toupper(*ilhs) != toupper(*irhs) )
			return (toupper(*ilhs) < toupper(*irhs)) ? -1 : 1;
		irhs++;
		ilhs++;
	}
	return (rhs.size() ==lhs.size()) ? 0 : (lhs.size() < rhs.size()) ? -1 : 1;
}

std::string StringUtils::format( std::string formatText, ... )
{
    std::string result = "";

    // Initialize variable arguments.
    va_list argList;
    va_start( argList, formatText );
    char* buf = new char[MAX_TRACE_STRING];
    memset( buf, 0, MAX_TRACE_STRING );

	vsnprintf( buf, MAX_TRACE_STRING, formatText.c_str(), argList );

    va_end( argList );
    // Reset variable arguments.

    result = buf;
    delete [] buf;
    return result;
}


std::string StringUtils::toLowerCase( const std::string text )
{
    std::string result = "";
	unsigned int iSize=strlen(text.c_str());

    for (unsigned int i = 0; i < iSize; i++)
        result += tolower( text[i] );

    return result;
}

std::string StringUtils::toUpperCase( const std::string text )
{
    std::string result = "";
	unsigned int iSize = strlen(text.c_str());

    for (unsigned int i = 0; i < iSize; i++)
        result += toupper( text[i] );

    return result;
}

std::string StringUtils::toString( const int& value )
{
    char tmp[TO_STRING_TXT_SIZE];
    memset( tmp, 0, TO_STRING_TXT_SIZE );
    sprintf( tmp, "%d", value );
    return std::string( tmp );
}

std::string StringUtils::toString( const long& value )
{
    char tmp[TO_STRING_TXT_SIZE];
    memset( tmp, 0, TO_STRING_TXT_SIZE );
    sprintf( tmp, "%ld", value );
    return std::string( tmp );
}

std::string StringUtils::toString( const float& value )
{
    char tmp[TO_STRING_TXT_SIZE];
    memset( tmp, 0, TO_STRING_TXT_SIZE );
    sprintf( tmp, "%.5f", value );
    return std::string( tmp );
}

std::string StringUtils::toString( const double& value )
{
    char tmp[TO_STRING_TXT_SIZE];
    memset( tmp, 0, TO_STRING_TXT_SIZE );
    sprintf( tmp, "%.5f", value );
    return std::string( tmp );
}

std::string StringUtils::toString( const unsigned long & value )
{
    char tmp[TO_STRING_TXT_SIZE];
    memset( tmp, 0, TO_STRING_TXT_SIZE );
    sprintf( tmp, "%ld", value );
    return std::string( tmp );
}

std::string StringUtils::toString( const unsigned int & value )
{
    char tmp[TO_STRING_TXT_SIZE];
    memset( tmp, 0, TO_STRING_TXT_SIZE );
    sprintf( tmp, "%d", value );
    return std::string( tmp );
}

std::string StringUtils::toString( const char& value )
{
    char tmp[TO_STRING_TXT_SIZE];
    memset( tmp, 0, TO_STRING_TXT_SIZE );
    sprintf( tmp, "%c", value );
    return std::string( tmp );
}

std::string StringUtils::toString( const bool& value )
{
    return ( value == true ) ? "true" : "false";
}

double StringUtils::toDouble( const std::string& value )
{
    return atof( value.c_str() );
}

long StringUtils::toLong( const std::string& value )
{
    return atol( value.c_str() );
}

int StringUtils::toInteger( const std::string& value )
{
    return atoi( value.c_str() );
}

unsigned int StringUtils::toUInteger( const std::string& value )
{
    return atoi( value.c_str() );
}

std::string StringUtils::getErrorString( const long& errorCode )
{
    std::string result = "";

    #ifdef _BOS_ON_WIN32_
        LPVOID lpMessageBuffer = 0;
        FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                       NULL, errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                       (LPTSTR) &lpMessageBuffer, 0, NULL );
        result = (char*)lpMessageBuffer;
        LocalFree( (HLOCAL)lpMessageBuffer );
        // Strip trailing .crlf if present
        if ( result.size() > 2 && (result[result.size()-3] == '.') )
	        result.erase( result.size() - 3 );
	#else // _BOS_ON_SOLARIS_ _BOS_ON_HP_
        result = std::string( strerror(errorCode) );
    #endif

    return result;
}

std::string StringUtils::duplicate( const char* source )
{
    //rem by mfarina on 2017/03/08 after -std=c++11 argument
    //char* newString;
    //newString = strdup( source );
    std::string s = source;
    //free( newString );
    return s;
}

void StringUtils::trim( std::string& source )
{
    if ( source.find_first_not_of("\t\n ") != std::string::npos )
        source = source.substr( source.find_first_not_of("\t\n ") );

    if ( source.find_last_not_of("\t\n ") != std::string::npos )
        source = source.substr( 0, source.find_last_not_of("\t\n ") + 1 );
}

char* StringUtils::toChar(const std::string& s)
{
	unsigned int uiSize = s.size();
	char* c = new char[uiSize + 1];
	strcpy(c, s.c_str());
	return c;
}

char* StringUtils::toChar(char* s)
{
	unsigned int uiSize = strlen(s);
	char* c = new char[uiSize + 1];
	strcpy(c, s);
	return c;
}

void StringUtils::quoteAndTwice( std::string& source )
{
	char CHAR_APICE = 39;
    std::string STRING_APICE = "'";

	StringBuffer s;
    s.append( STRING_APICE.c_str() );
	for (unsigned int i = 0; i < source.length(); i++)
	{
		s.append( source.substr(i,1).c_str() );
        if ( source.at(i) == CHAR_APICE )
			s.append( STRING_APICE.c_str() );
	}
	s.append( STRING_APICE.c_str() );

    source = s.getData();
}

std::string StringUtils::returnQuoteAndTwice( const std::string& source)
{
    std::string s=source;

    StringUtils::quoteAndTwice(s);

    return s;
}

std::string StringUtils::fillWith(const std::string& sSrc, std::string sFiller, bool bFillLeft)
{
	std::string sRet;

	if ( bFillLeft )
	{
		sRet = sFiller.substr( 1, (sFiller.length() - sSrc.length()) );
		sRet += sSrc;
	}
	else
	{
		sRet = sSrc;
		sRet += sFiller.substr( 1, (sFiller.length() - sSrc.length()) );
	}

	return sRet;
}
