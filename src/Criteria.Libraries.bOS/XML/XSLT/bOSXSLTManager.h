#ifndef _XSLT_LIBRARY_H_
#define _XSLT_LIBRARY_H_

//TO_BE_EXPORTED

#include "bOS.h"

namespace bOS
{
	namespace XML
	{
		namespace XSLT
		{
			class BOS_API XSLTManager
			{
			public:
				static std::string byString(const char* acXml, const char* acXsl);
				static void byFile( const char* acXmlFileIn, const char* acXslFile, const char* acXmlFileOut);
			};
		}
	}
}

#endif //_XSLT_LIBRARY_H_


