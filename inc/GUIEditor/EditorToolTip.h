#ifndef __EDITOR_TOOL_TIP_H__
#define __EDITOR_TOOL_TIP_H__

#include "BaseLayout.h"

class EditorToolTip : public wraps::BaseLayout
{
public:
	EditorToolTip();

	void Show(const GUI::UString & text, const GUI::IntPoint & point);
	void Show(GUI::Widget* sender, const GUI::IntPoint & point);
	void Hide();

private:
	void SetPosition(const GUI::IntPoint & point);
	GUI::Edit* mText;

	int minWidth;
	int minHeight;
	GUI::Widget* lastWidget;
};

#endif // __EDITOR_TOOL_TIP_H__
