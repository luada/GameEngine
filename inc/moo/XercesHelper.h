#ifndef __XERCESHELPER_H__
#define __XERCESHELPER_H__

#include "Prerequisites.h"

// Xerces-C includes
#include <OgreNoMemoryMacros.h>
#include <xercesc/util/XercesDefs.hpp>
#include <OgreMemoryMacros.h>


namespace MM
{
    class XercesHelper
    {
    public:
        static std::basic_string<char> transcode(const XMLCh *toTranscode);
        static std::basic_string<XMLCh> transcode(const char *toTranscode);
        static std::basic_string<char> transcode(const std::basic_string<XMLCh>& toTranscode);
        static std::basic_string<XMLCh> transcode(const std::basic_string<char>& toTranscode);

        XercesHelper(void);
        ~XercesHelper();

    protected:
        bool mInitialised;
    };

} 

#endif  
