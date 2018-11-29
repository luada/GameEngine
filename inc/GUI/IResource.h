#ifndef __I_RESOURCE_H__
#define __I_RESOURCE_H__

#include "Prerequest.h"
#include "XmlDocument.h"
#include "Guid.h"
#include "Version.h"
#include "ISerializable.h"
#include "ResourceHolder.h"

namespace GUI
{

	class IResource;
	typedef IResource * IResourcePtr;

	class ResourceManager;

	class GUI_EXPORT IResource : public ISerializable
	{
		friend class ResourceManager;
		friend class ResourceHolder<IResource>;

		RTTI_DERIVED(IResource)

	public:
		const std::string& GetResourceName() { return mResourceName; }
		const Guid& GetResourceID() { return mResourceID; }

	protected:
		IResource() { }
	private:
		// constructors and operator =, without implementation, just for private
		IResource(IResource const &);
		IResource& operator = (IResource const &);

	protected:
		virtual void Deserialization(xml::ElementPtr node, Version version)
		{
			mResourceID = Guid::Parse(node->findAttribute("id"));
			mResourceName = node->findAttribute("name");
		}

		virtual ~IResource() { }

	private:
		std::string mResourceName;
		Guid mResourceID;
	};

} // namespace GUI

#endif // __I_RESOURCE_H__

