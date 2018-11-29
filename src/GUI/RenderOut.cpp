#include "Precompiled.h"
#include "RenderOut.h"
#include "Utility.h"

#include "Gui.h"
#include "FontManager.h"
#include "LayerManager.h"
#include "SkinManager.h"
#include "StaticText.h"

namespace GUI
{
	namespace implement
	{

		struct Info
		{
			Info() : num(0), count(1)  { }
			Info(size_t num, const std::string& line) : num(num), count(1), line(line) { }

			size_t num;
			size_t count;
			std::string line;
		};

		void Render_out(const std::string& value)
		{
			typedef std::deque<Info> DequeInfo;

			static size_t num = 0;
			static DequeInfo lines;

			const int offset = 10;
			const size_t count_lines = 20;
			static const std::string font = "DejaVuSans.14";
			static const std::string layer = "Statistic";
			static const std::string skin = "StaticText";

			static StaticText* widget = nullptr;
			static StaticText* widget_shadow = nullptr;

			if (widget == nullptr)
			{
				Gui * gui = Gui::GetInstancePtr();
				if (gui == nullptr) return;

				const IntSize& size = gui->GetViewSize();

				if (!LayerManager::GetInstance().IsExist(layer)) return;
				if (!SkinManager::GetInstance().IsExist(skin)) return;


				widget_shadow = gui->CreateWidget<StaticText>(skin, IntCoord(offset + 1, offset + 1, size.width - offset - offset, size.height - offset - offset), Align::Stretch, layer);
				widget_shadow->SetNeedMouseFocus(false);
				widget_shadow->SetTextAlign(Align::Default);
				widget_shadow->SetTextColour(Colour::Black);

				widget = gui->CreateWidget<StaticText>(skin, IntCoord(offset, offset, size.width - offset - offset, size.height - offset - offset), Align::Stretch, layer);
				widget->SetNeedMouseFocus(false);
				widget->SetTextAlign(Align::Default);
				widget->SetTextColour(Colour::White);

				if (FontManager::GetInstance().GetByName(font) != nullptr)
				{
					widget_shadow->SetFontName(font);
					widget->SetFontName(font);
				}
			}

			if (lines.empty())
			{
				lines.push_back(Info(num++, value));

			}
			else
			{
				if (lines.back().line == value) lines.back().count ++;
				else
				{
					lines.push_back(Info(num++, value));
					if (lines.size() > count_lines) lines.pop_front();
				}

			}

			std::string str_out;
			str_out.reserve(2048);

			for (DequeInfo::iterator iter=lines.begin(); iter != lines.end(); ++iter)
			{
				str_out += utility::ToString("[ ", (unsigned int)iter->num, (iter->count > 1) ? (" , " + utility::ToString((unsigned int)iter->count)) : "", " ]  ", iter->line, "\n");
			}

			widget_shadow->SetCaption(str_out);
			widget->SetCaption(str_out);
		}
	}

} // namespace GUI

