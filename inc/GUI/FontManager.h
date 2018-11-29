#ifndef __FONT_MANAGER_H__
#define __FONT_MANAGER_H__

#include "Prerequest.h"
#include "Enumerator.h"
#include "IFont.h"
#include "Instance.h"
#include "XmlDocument.h"
#include "ResourceManager.h"

namespace GUI
{

	class GUI_EXPORT FontManager
	{
		INSTANCE_HEADER(FontManager)

	public:
		void Initialise();
		void Shutdown();

		/** Load additional GUI *_font.xml file */
		bool Load(const std::string& file);
		void _load(xml::ElementPtr node, const std::string& file, Version version);

		const std::string& GetDefaultFont() const { return mDefaultName; }
		void SetDefaultFont(const std::string& value);

		/** Get font resource */
		IFont* GetByName(const std::string& name) const;

	private:
		std::string mDefaultName;
	};

} // namespace GUI

#endif // __FONT_MANAGER_H__
