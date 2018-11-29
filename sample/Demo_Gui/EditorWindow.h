#ifndef __EDITOR_WINDOW_H__
#define __EDITOR_WINDOW_H__

#include <GUI.h>
#include "BaseLayout.h"

namespace demo
{

	class EditorWindow : public wraps::BaseLayout
	{
	public:
		EditorWindow();

		void ClearView();
		GUI::Widget* GetView() { return mMainWidget; }

	};

} // namespace demo

#endif // __EDITOR_WINDOW_H__
