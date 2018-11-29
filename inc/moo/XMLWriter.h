#ifndef __XMLWRITER_H__
#define __XMLWRITER_H__

#include "Prerequisites.h"

namespace MM
{
    class XMLNode;

    class XMLWriter
    {
    public:
        XMLWriter(void);

        virtual ~XMLWriter();

        virtual void writeXMLFile(const XMLNode* root, const String& filename) = 0;
    };

}

#endif  // end of guard 
