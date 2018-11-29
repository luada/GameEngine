#include "ObjectFactory.h"
#include "Object.h"

namespace MM
{

    void ObjectFactory::destroyInstance(Object* object)
    {
        delete object;
    }

}
