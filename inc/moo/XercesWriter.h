#ifndef __XERCESWRITER_H__
#define __XERCESWRITER_H__

#include "XMLWriter.h"
#include "XercesHelper.h"


namespace MM
{
    /*!
    \brief
        Implementation of XMLWriter using Xerces-C++
     */
    class XercesWriter : public XMLWriter, public XercesHelper
    {
    public:
        XercesWriter(void);
        ~XercesWriter();

        // Implementation of public abstract interface
        virtual void writeXMLFile(const XMLNode* root, const String& filename);
    };

}

#endif  
