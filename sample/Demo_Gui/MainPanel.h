#ifndef __MAIN_PANEL_H__
#define __MAIN_PANEL_H__

#include <GUI.h>
#include "BaseLayout.h"

namespace demo
{

	class MainPanel : public wraps::BaseLayout
	{
	public:

		typedef enum
		{
			EventNew,
			EventLoad,
			EventQuit,
			EventCreate
		} TypeEvents;

	public:
		MainPanel();

		void AddObject(const GUI::UString & name);

	private:
		void NotifyMouseButtonClick(GUI::Widget* sender);
		void NotifyComboAccept(GUI::ComboBox* sender, size_t index);

	public:
		GUI::delegates::CDelegate2<TypeEvents, size_t> eventAction;

		GUI::Button* mButtonNew;
		GUI::Button* mButtonLoad;
		GUI::Button* mButtonQuit;

		GUI::ComboBox* mComboCreate;
	};

} // namespace demo

#endif // __MAIN_PANEL_H__
