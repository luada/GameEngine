#ifndef __SKIN_MANAGER_H__
#define __SKIN_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"
#include "Enumerator.h"
#include "ResourceSkin.h"
#include "XmlDocument.h"
#include "ResourceManager.h"

namespace GUI
{

	class GUI_EXPORT SkinManager
	{
		INSTANCE_HEADER(SkinManager)

	public:
		void Initialise();
		void Shutdown();

		/** Load additional GUI *_skin.xml file */
		bool Load(const std::string& file);
		void _load(xml::ElementPtr node, const std::string& file, Version version);

		ResourceSkin* GetByName(const std::string& name) const;

		bool IsExist(const std::string& name) const;

		const std::string GetDefaultSkin() const { return mDefaultName; }
		void SetDefaultSkin(const std::string& value);


	private:
		void CreateDefault(const std::string& value);

	private:
		std::string mDefaultName;

	};

} // namespace GUI

#endif // __SKIN_MANAGER_H__
