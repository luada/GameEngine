#include "Actor.h"

#include "Resources.h"
#include "System.h"

#include "LogicModel.h"
#include "LogicModelManager.h"

#include <OgreEntity.h>
#include <OgreSceneNode.h>

namespace MM {

    //-----------------------------------------------------------------------
	Actor::Actor( System *system, const String& name, const String& modelName, Ogre::SceneNode* node )
		: mImpl(NULL)
	{
		assert (system);

		String resourceName, groupName;
		splitResourceName(name, resourceName, groupName);

		mImpl = LogicModelManager::getSingleton().createLogicModel(name, modelName);
		assert(mImpl);

		mImpl->setParentSceneNode(node);		

	}
    //-----------------------------------------------------------------------
    Actor::~Actor()
    {       
		LogicModelManager::getSingleton().destroyLogicModel(mImpl);
    }
    //-----------------------------------------------------------------------
    Ogre::SceneNode* Actor::getSceneNode(void) const
    {
        assert(mImpl);
        assert(mImpl->getSceneNode());
        return mImpl->getSceneNode();
    }
    //-----------------------------------------------------------------------
    Ogre::AxisAlignedBox Actor::getBoundingBox(void) const
    {
        assert(mImpl);
        return mImpl->getBoundingBox();
    }
    //-----------------------------------------------------------------------
    void Actor::setUserObject(Ogre::UserDefinedObject* userObject)
    {
        assert(mImpl);
        mImpl->setUserObject(userObject);
    }
    //-----------------------------------------------------------------------
    Ogre::UserDefinedObject* Actor::getUserObject(void) const
    {
        assert(mImpl);
        return mImpl->getUserObject();
    }
}
