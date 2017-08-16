#ifndef __BOS_XML_STRINGTRANSCODED_H__
#define __BOS_XML_STRINGTRANSCODED_H__

//TO_BE_EXPORTED

#include "bOS.h"

#include <xercesc/util/XMLChar.hpp>
using namespace xercesc_3_1;

namespace bOS
{
    namespace XML
    {
        class XMLStringTranscoded
        {
            public:

                XMLStringTranscoded(const XMLCh* toTranscode);
                ~XMLStringTranscoded();

				char* getMessage();

            private:

                char* acString;
        };
    }
};

#endif //__BOS_XML_STRINGTRANSCODED_H__

