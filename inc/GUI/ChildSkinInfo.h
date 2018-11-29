#ifndef __CHILD_SKIN_INFO_H__
#define __CHILD_SKIN_INFO_H__

#include "Prerequest.h"
#include "WidgetStyle.h"

namespace GUI
{

	struct GUI_EXPORT ChildSkinInfo
	{
		ChildSkinInfo() : style(WidgetStyle::Child), align(Align::Default) { }

		ChildSkinInfo(const std::string& type, const WidgetStyle& style, const std::string& skin, const IntCoord& coord, const Align& align, const std::string& layer, const std::string& name) :
			type(type),
			skin(skin),
			name(name),
			layer(layer),
			style(style),
			coord(coord),
			align(align)
		{
			// set Child style by default
			if (this->style == WidgetStyle::MAX) 
			{
				this->style = WidgetStyle::Child;
			}
		}

		void AddParam(const std::string& key, const std::string& value)
		{
			params[key] = value;
		}

		std::string findValue(const std::string& key) const
		{
			MapString::const_iterator iter = params.find(key);
			if (iter != params.end()) return iter->second;
			return "";
		}

		std::string type, skin, name, layer;
		WidgetStyle style;
		IntCoord coord;
		Align align;
		MapString params;
	};

	typedef std::vector<ChildSkinInfo> VectorChildSkinInfo;

} // namespace GUI


#endif // __CHILD_SKIN_INFO_H__
