#ifndef __TAB_ITEM_H__
#define __TAB_ITEM_H__

#include "Prerequest.h"
#include "Widget.h"
#include "Tab.h"

namespace GUI
{

	class GUI_EXPORT TabItem :
		public Widget
	{
		RTTI_DERIVED(TabItem)
		DEFINE_GET_THIS(TabItem, BASS(Widget, END))

	public:
		TabItem();

		/** Set item caption */
		//@ExportToLua
		virtual void SetCaption(const UString& value);
		/** Get item caption */
		//@ExportToLua
		virtual const UString& GetCaption();

		//! Set button width
		//@ExportToLua
		void SetButtonWidth(int value = -1/*DEFAULT*/);
		//! Get button width
		//@ExportToLua
		int GetButtonWidth();

		//! Replace an item name
		//@ExportToLua
		void SetItemName(const UString& value);
		//! Get item name
		//@ExportToLua
		const UString& GetItemName();

		//! Replace an item name
		void SetItemData(Any value);
		//@ExportToLua
		void SetItemData(Widget* value) { SetItemData(Any(value)); }

		//! Get item data
		template <typename ValueType>
		ValueType * GetItemData(bool _throw = true)
		{
			return mOwner->getItemData<ValueType>(this, _throw);
		}

		//! Select sheet
		//@ExportToLua
		void SetItemSelected();

		//! Remove item
		//@ExportToLua
		void RemoveItem();

		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);

	/*internal*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~TabItem();

		void SetSelected(bool value);

	private:
		Tab* mOwner;

	};

} // namespace GUI

#endif // __TAB_ITEM_H__
