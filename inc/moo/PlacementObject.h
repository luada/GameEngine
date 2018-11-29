#ifndef ___PLACEMENTOBJECT_H__
#define ___PLACEMENTOBJECT_H__

#include "Object.h"
#include "Transform.h"

namespace MM
{
    class System;

    class PlacementObject : public Object
    {
    public:
        PlacementObject(void);
        virtual ~PlacementObject();

        void createRenderInstance(System* system);
        void destroyRenderInstance(void);

        Variant getProperty(const String& name) const;
        String getPropertyAsString(const String& name) const;

        void processMessage(const String& msg, const Variant& params);

        //////////////////////////////////////////////////////////////////////////

        Ogre::SceneNode* getSceneNode(void) const
        {
            return mSceneNode;
        }

        Real getCreateLevel(void) const
        {
            return mCreateLevel;
        }

        void setCreateLevel(Real level);

    protected:
        void addBaseProperty(void);

        void _updateCreateLevel(void);

        Ogre::SceneNode* mSceneNode;

        Real mCreateLevel;

        System* mSystem;

    public:     // Intend for direct access by property commands only, DO NOT access outside
        Transform mTransform;
    };

}

#endif 
