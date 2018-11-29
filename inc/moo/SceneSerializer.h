#ifndef __SCENESERIALIZER_H__
#define __SCENESERIALIZER_H__

#include "Prerequisites.h"

namespace MM
{
    class Scene;
    class XMLParser;
    class XMLWriter;

    class SceneSerializer
    {
    public:
        SceneSerializer(void);
        virtual ~SceneSerializer();

        virtual void load(Scene* scene, XMLParser* parser, const String& filename, const String& groupName);
        virtual void save(Scene* scene, XMLWriter* writer, const String& filename);
    };
}

#endif // 
