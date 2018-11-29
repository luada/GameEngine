#ifndef __RESOURCECOLLECTION_H__
#define __RESOURCECOLLECTION_H__

#include "Prerequisites.h"

// ----------------------------------------------------------------------------
// classes
// ----------------------------------------------------------------------------

namespace MM {

    class ResourceCollection
    {
    public:
        ResourceCollection(void) {}
        virtual ~ResourceCollection() {}

        virtual void add(const String& resourceType, const String& resourceName) = 0;
    };

}

#endif 
