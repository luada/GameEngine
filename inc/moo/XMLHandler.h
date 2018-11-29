#ifndef __XMLHANDLER_H__
#define __XMLHANDLER_H__

#include "Prerequisites.h"

namespace MM
{
    class XMLAttributes;

    class XMLHandler
    {
    public:
        /*!
        \brief
            XMLHandler base class constructor.
         */
        XMLHandler(void) {}

        /*!
        \brief
            XMLHandler base class destructor.
         */
        virtual ~XMLHandler() {}

        /*!
        \brief
            Method called to receive notification of character data inside an element.

        \param chars
            String object holding the character data.

        \return
            Nothing.
         */
        virtual void characters(const String& chars);

        /*!
        \brief
            Method called to notify the handler at the start of each XML element encountered.

        \param element
            String object holding the name of the element that is starting.

        \param attributes
            An XMLAttributes object holding the collection of attributes specified for the element.

        \return
            Nothing.
         */
        virtual void startElement(const String& element, const XMLAttributes& attributes);
        
        /*!
        \brief
            Method called to notify the handler at the end of each XML element encountered.

        \param element
            String object holding the name of the element that is ending.

        \return
            Nothing.
         */
        virtual void endElement(const String& element);
    };

}

#endif  // 
