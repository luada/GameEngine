#ifndef __POSTFILTERFACTORY_H__
#define __POSTFILTERFACTORY_H__

#include "PostFilterPrerequisites.h"

#include <OgreFactoryObj.h>

namespace MM {

// forward declaration
class PostFilter;

class PostFilterFactory : public Ogre::FactoryObj<PostFilter>
{
public:
    virtual void _init(void) = 0;
};

}

#endif // 
