#ifndef __PARSE_H__
#define __PARSE_H__

#include <GUI.h>

namespace Parse
{
	template <typename T>
	bool CheckParseInterval(GUI::Edit* edit, size_t count, T min, T max)
	{
		static const GUI::UString colour = GUI::LanguageManager::GetInstance().GetTag("ColourError");
		const GUI::UString & text = edit->GetOnlyText();
		size_t index = edit->GetTextCursor();
		bool success = true;

		T p;
		std::istringstream str(text);
		while (success && count > 0)
		{
			str >> p;
			if (p > max || p < min) success = false;
			-- count;
		}
		if (success)
		{
			if (str.fail())
			{
				success = false;
			}
			else
			{
				std::string tmp;
				str >> tmp;
				if (!str.fail() || tmp.find_first_not_of(" \t\r") != std::string::npos)
				{
					success = false;
				}
				else
				{
					success = true;
				}
			}
		}

		if (success) edit->SetCaption(text);
		else edit->SetCaption(colour + text);
		edit->SetTextCursor(index);
		return success;
	}

	template <typename T>
	bool CheckParse(GUI::Edit* edit, size_t count)
	{
		static const GUI::UString colour = GUI::LanguageManager::GetInstance().GetTag("ColourError");
		const GUI::UString & text = edit->GetOnlyText();
		size_t index = edit->GetTextCursor();
		bool success = false;

		T p;
		std::istringstream str(text);
		while (count > 0)
		{
			str >> p;
			-- count;
		}
		if (str.fail())
		{
			success = false;
		}
		else
		{
			std::string tmp;
			str >> tmp;
			if (!str.fail() || tmp.find_first_not_of(" \t\r") != std::string::npos)
			{
				success = false;
			}
			else
			{
				success = true;
			}
		}
		if (success) edit->SetCaption(text);
		else edit->SetCaption(colour + text);
		edit->SetTextCursor(index);
		return success;
	}

	bool CheckParseFileName(GUI::Edit* edit);

}// namespace Parse

#endif // __PARSE_H__
