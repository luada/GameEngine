#include "precompiled.h"
#include "EditorWindow.h"

namespace demo
{

	EditorWindow::EditorWindow() : BaseLayout("EditorWindow.layout")
	{
	}

	void EditorWindow::ClearView()
	{
		GUI::WidgetManager::GetInstance().DestroyWidgets(mMainWidget->GetEnumerator());
	}


} // namespace demo
