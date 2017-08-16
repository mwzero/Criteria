#ifndef _XSLT_EXCEPTION_H_
#define _XSLT_EXCEPTION_H_

//TO_BE_EXPORTED
#include "bOS.h"
#include "bOSException.h"

namespace bOS
{
	namespace Exception
	{
        class BOS_API XSLTException : public BaseException
        {
            public:
                XSLTException(const std::string & message ): BaseException( message ) {}

                XSLTException() : BaseException() {}

                XSLTException( const std::string & message, const int lineNumber )
                    : BaseException(message, lineNumber) {}

                virtual ~XSLTException() {}
        };
    }
}

#endif //_XSLT_EXCEPTION_H_


