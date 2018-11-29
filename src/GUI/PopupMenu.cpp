#include "Precompiled.h"
#include "PopupMenu.h"

namespace GUI
{

	PopupMenu::PopupMenu()
	{
		mHideByLostKey = true;
	}

	void PopupMenu::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	PopupMenu::~PopupMenu()
	{
		ShutdownWidgetSkin();
	}

	void PopupMenu::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void PopupMenu::InitialiseWidgetSkin(ResourceSkin* info)
	{
	}

	void PopupMenu::ShutdownWidgetSkin()
	{
	}

} // namespace GUI
