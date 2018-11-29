#ifndef __XERCESPARSER_H__
#define __XERCESPARSER_H__

#include "XMLParser.h"
#include "XercesHelper.h"


namespace MM
{
    /*!
    \brief
        Implementation of XMLParser using Xerces-C++
     */
    class XercesParser : public XMLParser, public XercesHelper
    {
    public:
        XercesParser(void);
        ~XercesParser();

        // Implementation of public abstract interface
        void parseXMLFile(XMLHandler& handler, const String& xmlName, const String& xmlResourceGroup, const String& schemaName, const String& schemaResourceGroup);
    };

} 

#endif  
