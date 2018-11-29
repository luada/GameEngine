#ifndef __OBJECTFACTORY_H__
#define __OBJECTFACTORY_H__

#include "Factory.h"

namespace MM
{
    class Object;

    class ObjectFactory : public Factory<Object>
    {
    public:
        void destroyInstance(Object* object);
    };

}

#endif 
