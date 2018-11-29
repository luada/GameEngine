#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "Prerequisites.h"

// ----------------------------------------------------------------------------
// forward declares
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// classes
// ----------------------------------------------------------------------------

namespace MM {

	class System;
	class LogicModel;

    class Actor
    {
    protected:
        typedef LogicModel Impl;

        Impl* mImpl;

    public:
    //    Actor(Ogre::SceneManager* creator, const String& name, bool editable);
		Actor( System *system, const String& name, const String& modelName, Ogre::SceneNode* node );
        virtual ~Actor();

        Impl* getImpl(void) const
        {
            return mImpl;
        }

        Ogre::SceneNode* getSceneNode(void) const;

        Ogre::AxisAlignedBox getBoundingBox(void) const;

        void setUserObject(Ogre::UserDefinedObject* userObject);
        Ogre::UserDefinedObject* getUserObject(void) const;
    };

}

#endif 
