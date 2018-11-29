/********************************************************************
filename:   EffectBasic.cpp

purpose:    the basic of effect and effect element.
*********************************************************************/

#include "EffectBasic.h"
#include "EffectManager.h"
#include "System.h"

#include <OgreSceneNode.h>
#include <OgreSceneManager.h>

namespace MM	{

	///////////////////////////////////////////////////////////////////////
	EffectBasic::EffectBasic( System *system ) :
	mBasicNode(NULL),
	mSystem(system),
    mVisible(true)
	{
	}
    //---------------------------------------------------------------------
	EffectBasic::~EffectBasic()
	{
		deleteSceneNode();
	}    
	
    //---------------------------------------------------------------------
	void EffectBasic::deleteSceneNode(void)
	{
		if (mBasicNode)
        {
            mBasicNode->destroy();
            mBasicNode = NULL;
        }		
	}

	void EffectBasic::dumpSceneNode(Ogre::SceneNode *node, bool create) const
	{
		static std::ofstream of("scenenode.txt");

		assert (node);

		assert (node->getParent());

		if (create)
		{
			of << "create" << node->getName() << "  " << node->getParent()->getName() << std::endl;
		}
		else
		{
			of << "destroy" << node->getName() << "  " << node->getParent()->getName() << std::endl;
		}
	}	

    void EffectBasic::setVisible(bool visible)
    {
       // mBasicNode->setVisible(visible);
        if (visible != mVisible)
        {
            mVisible = visible;

            if (mBasicNode)
                mBasicNode->setVisible(mVisible);
        }
    }

}