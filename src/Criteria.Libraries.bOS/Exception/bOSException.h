#ifndef __BOS_BASE_EXCEPTION_H__
#define __BOS_BASE_EXCEPTION_H__

#include "bOS.h"

//TO_BE_EXPORTED

namespace bOS
{
	namespace Exception
	{
		class BOS_API BaseException
		{
			public:

				BaseException();

				BaseException( const std::string & message );

				BaseException( const std::string & message, const int lineNumber );

				virtual ~BaseException();

	            std::string getMessage();

		    protected:

			   std::string sMessage;

			private:
		};
    }
};

#endif

