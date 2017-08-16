#include "CommonDefines.h"

#include "bOS.h"
#include "bOSException.h"
using namespace bOS::Exception;

BaseException::BaseException()
{
    sMessage = "";
}

BaseException::BaseException( const std::string & message )
{
    sMessage = message;
}

BaseException::BaseException( const std::string & message, const int lineNumber )
{
    sMessage = message;
    char txt[256];
    sprintf( txt, "\nError at line number %d", lineNumber );
    sMessage += txt;
}

BaseException::~BaseException()
{
}

std::string BaseException::getMessage()
{
    return sMessage;
}

