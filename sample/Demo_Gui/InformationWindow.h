#ifndef __INFORMATION_WINDOW_H__
#define __INFORMATION_WINDOW_H__

#include <GUI.h>
#include "BaseLayout.h"

namespace demo
{

	class InformationWindow : public wraps::BaseLayout
	{
	public:
		InformationWindow(GUI::Widget* parent);
		virtual ~InformationWindow();

	private:
		void NotifyFrameStart(float time);
		int GetRand(int min, int max);

	private:
		GUI::Edit* mInfo;
		GUI::Widget* mFocus;
	};

} // namespace demo

#endif // __INFORMATION_WINDOW_H__
