#ifndef __XMLPARSER_H__
#define __XMLPARSER_H__

#include "Prerequisites.h"

namespace MM
{
    class XMLHandler;

    class XMLParser
    {
    public:
        XMLParser(void);

        virtual ~XMLParser();

        virtual void parseXMLFile(XMLHandler& handler, const String& filename, const String& resourceGroup, const String& schemaName, const String& schemaResourceGroup) = 0;
    };

} 

#endif  // end of guard 
