#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"
#include "Enumerator.h"
#include "Guid.h"
#include "XmlDocument.h"
#include "IResource.h"
#include "ResourceHolder.h"
#include "Delegate.h"

namespace GUI
{

	class GUI_EXPORT ResourceManager :
		public ResourceHolder<IResource>
	{
		INSTANCE_HEADER(ResourceManager)

	public:
		void Initialise();
		void Shutdown();

	public:

		/** Load additional GUI *_resource.xml file */
		bool Load(const std::string& file);

		bool _loadImplement(const std::string& file, bool match, const std::string& type, const std::string& instance);
		void _load(xml::ElementPtr node, const std::string& file, Version version);
		void _loadList(xml::ElementPtr node, const std::string& file, Version version);

		/** Get resource by GUID */
		IResourcePtr GetByID(const Guid& id, bool _throw = true);

		std::string GetFileNameByID(const Guid& id);

		void AddResource(IResourcePtr item);

		void RemoveResource(IResourcePtr item);

		typedef delegates::CDelegate3<xml::ElementPtr, const std::string &, Version> LoadXmlDelegate;

		LoadXmlDelegate& RegisterLoadXmlDelegate(const std::string& key);

		void UnregisterLoadXmlDelegate(const std::string& key);


	private:
		typedef std::map<Guid, IResourcePtr> MapResourceID;
		MapResourceID mResourcesID;

		typedef std::map<std::string, LoadXmlDelegate> MapLoadXmlDelegate;
		MapLoadXmlDelegate mMapLoadXmlDelegate;

		std::string mResourceGroup;
		typedef std::vector<Guid> VectorGuid;
		typedef std::map<std::string, VectorGuid> MapVectorString;

		MapVectorString mListFileGuid;
	};

} // namespace GUI

#endif // __RESOURCE_MANAGER_H__

