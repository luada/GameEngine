#ifndef __DEMO_KEEPER_H__
#define __DEMO_KEEPER_H__

#include "BaseManager.h"
#include "EditorWindow.h"
#include "MainPanel.h"
#include "InformationWindow.h"
#include "ColourWindow.h"

namespace demo
{

	class DemoKeeper : public base::BaseManager
	{
	public:
		DemoKeeper();

		virtual void CreateScene();
		virtual void DestroyScene();

	private:
		void NotifyEventAction(MainPanel::TypeEvents action, size_t index);
		void DestroyWindows();
		void CreateWindows();
		virtual void SetupResources();

	private:
		EditorWindow * mEditorWindow;
		MainPanel * mMainPanel;
		InformationWindow * mInformationWindow;
		ColourWindow * mColourWindow;
	};

} // namespace demo

#endif // __DEMO_KEEPER_H__
