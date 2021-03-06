#include "bOSXMLStringTranscoded.h"
using namespace bOS::XML;

#include <xercesc/util/XMLString.hpp>
using namespace xercesc_3_1;

XMLStringTranscoded::XMLStringTranscoded(const XMLCh* toTranscode)
{
	assert(toTranscode != NULL);
	acString = XMLString::transcode(toTranscode);
}

XMLStringTranscoded::~XMLStringTranscoded()
{
	XMLString::release(&acString);
}

char* XMLStringTranscoded::getMessage()
{
	return acString;
}
