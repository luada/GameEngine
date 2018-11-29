#include "Precompiled.h"
#include "MenuBar.h"

namespace GUI
{

	MenuBar::MenuBar()
	{
		mHideByAccept = false;
		mMenuDropMode = true;
		mIsMenuDrop = false;
	}

	void MenuBar::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);
		InitialiseWidgetSkin(info);
	}

	MenuBar::~MenuBar()
	{
		ShutdownWidgetSkin();
	}

	void MenuBar::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void MenuBar::InitialiseWidgetSkin(ResourceSkin* info)
	{
	}

	void MenuBar::ShutdownWidgetSkin()
	{
	}

} // namespace GUI
