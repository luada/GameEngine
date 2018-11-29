#include "precompiled.h"
#include "Parse.h"

namespace Parse
{

	bool CheckParseFileName(GUI::Edit* edit)
	{
		static const GUI::UString colour = GUI::LanguageManager::GetInstance().GetTag("ColourError");
		const GUI::UString & text = edit->GetOnlyText();
		size_t index = edit->GetTextCursor();

		bool success = false;

		if (text.find_first_of("*?") == std::string::npos)
		{
			success = GUI::DataManager::GetInstance().IsDataExist(text);
		}
		else
		{
			success = false;
		}

		if (success)
			edit->SetCaption(text);
		else
			edit->SetCaption(colour + text);

		edit->SetTextCursor(index);

		return success;
	}

} // namespace Parse
