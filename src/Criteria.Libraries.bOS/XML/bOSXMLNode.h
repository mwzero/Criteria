#ifndef __BOS_XMLNODE_H__
#define __BOS_XMLNODE_H__

//TO_BE_EXPORTED

#include "bOS.h"

#include "bOSXMLAttribute.h"

#include "bOSCollection.h"

namespace bOS
{
    namespace XML
    {
		class BOS_API XMLNode : public bOS::Collections::CollectionEntry
        {
            public:

                XMLNode();
                XMLNode(const char* acName, const char* acValue);
				XMLNode(const char* acName, const std::string& sValue);
				XMLNode(const char* acName, unsigned int uiValue);
				XMLNode(const char* acName, int uiValue);
				XMLNode(const char* acName, long lValue);

                virtual ~XMLNode();

				//bOS::Collections::CollectionEntry
				bool equalTo(bOS::Collections::CollectionEntry*);

                std::string getXMLText( bool bIndent = false, unsigned int uilevel = 0 );
				std::string getInnerXML();

                XMLNode* getParentNode();
                void setParent( XMLNode* node );

                const char* getName();
                void setName( const char* acName );

                const char* getValue();
				unsigned int getUIntValue();
				int getIntValue();
				long getLongValue();

                void setValue( const char* acValue );

				//Attribute
                void addAttribute( XMLAttribute* attribute);
                bool removeAttribute( XMLAttribute* attribute);
                XMLAttribute* getAttribute(const char* acName );
				bOS::Collections::Collection& getAttributes();

				//Node
				bOS::Collections::Collection& getNodes();
                void addNode( XMLNode* node );
                bool removeNode( XMLNode* node );
				XMLNode* getNode(const char* acName);

            protected:

            private:

				static std::string getValueTranscoded(const char* acValue);
				bOS::Collections::Collection vAttributes;
                bOS::Collections::Collection vNodes;

                XMLNode* nodeParent;

                std::string sName;
                std::string sValue;
        };
    }
};

#endif

