#ifndef ___Transform_H__
#define ___Transform_H__

#include <OgreVector3.h>
#include <OgreQuaternion.h>

namespace MM
{

    struct Transform
    {
        Ogre::Vector3 position;
        Ogre::Quaternion orientation;
        Ogre::Vector3 scale;

        Transform(void);
        Transform(const Ogre::Vector3& position,
                  const Ogre::Quaternion& orientation,
                  const Ogre::Vector3& scale);
    };

}

#endif // 
