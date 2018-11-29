#ifndef __LANGUAGE_MANAGER_H__
#define __LANGUAGE_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"
#include "XmlDocument.h"
#include "Delegate.h"

namespace GUI
{

	class GUI_EXPORT LanguageManager
	{
		INSTANCE_HEADER(LanguageManager)

	public:
		void Initialise();
		void Shutdown();

		//@ExportToLua
		static LanguageManager& Instance()
		{
			return GetInstance();
		}

		/** Load additional GUI *_language.xml file */
		//@ExportToLua
		bool Load(const std::string& file);

		void _load(xml::ElementPtr node, const std::string& file, Version version);

		/** Set current language for replacing #{} tags */
		//@ExportToLua
		void SetCurrentLanguage(const std::string& name);

		/** Get current language */
		//@ExportToLua
		const std::string& GetCurrentLanguage();

		/** Replace all tags #{tagname} in _line with appropriate string dependent
		on current language or keep #{tagname} if 'tagname' not found found */
		//@ExportToLua
		UString ReplaceTags(const UString& line);

		/** Get tag value */
		//@ExportToLua
		UString GetTag(const UString& tag);

		/** Add user tag */
		//@ExportToLua
		void AddUserTag(const UString& tag, const UString& replace);

		/** delete all user tags */
		//@ExportToLua
		void ClearUserTags();

		//@ExportToLua
		bool LoadUserTags(const std::string& file);

		/** Event : Change current language.\n
			signature : void Method(const std::string& language);
			@param _language Current language.
		*/
		delegates::CMultiDelegate1<const std::string &> eventChangeLanguage;

	private:
		//bool LoadResourceLanguage(const std::string& name);
		bool LoadLanguage(const std::string& file, bool user = false);
		void _loadLanguage(IDataStream* stream, bool user);
		void _loadLanguageXML(IDataStream* stream, bool user);
		//void _loadSource(xml::ElementPtr node, const std::string& file, Version version);

	private:
		typedef std::map<UString, UString> MapLanguageString;

		MapLanguageString mMapLanguage;
		MapLanguageString mUserMapLanguage;

		std::string mCurrentLanguageName;

		typedef std::vector<std::string> VectorString;
		typedef std::map<std::string, VectorString> MapListString;
		MapListString mMapFile;

	};

	inline const GUI::UString Localise(const GUI::UString & str)
	{
		return GUI::LanguageManager::GetInstance().GetTag(str);
	}

} // namespace GUI

#endif // __LANGUAGE_MANAGER_H__
