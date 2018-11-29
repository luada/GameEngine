#ifndef __SUB_WIDGET_BINDING_H__
#define __SUB_WIDGET_BINDING_H__

#include "Prerequest.h"
#include "ISubWidget.h"

namespace GUI
{

	class GUI_EXPORT SubWidgetBinding
	{
		friend class ResourceSkin;

	public:
		SubWidgetBinding()
		{
			Clear();
		}

		SubWidgetBinding(const IntCoord& coord, Align aligin, const std::string& type)
		{
			Create(coord, aligin, type);
		}

		void Create(const IntCoord& coord, Align aligin, const std::string& type)
		{
			Clear();
			mOffset = coord;
			mAlign = aligin;
			mType = type;
		}

		void Clear()
		{
			mType = "";
			mAlign = Align::Default;
			mStates.clear();
		}

		void Add(const std::string& name, IStateInfo* data, const std::string& skin)
		{
			MapStateInfo::const_iterator iter = mStates.find(name);
			if (iter != mStates.end())
			{
				delete data;
				LOG(warning, "state with curName '" << name << "' already exist in curSkin '" << skin << "'");
				return;
			}
			mStates[name] = data;
		}

	private:
		IntCoord mOffset;
		Align mAlign;
		std::string mType;
		MapStateInfo mStates;
	};

} // namespace GUI


#endif // __SUB_WIDGET_BINDING_H__

