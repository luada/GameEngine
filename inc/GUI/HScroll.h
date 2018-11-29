#ifndef __HSCROLL_H__
#define __HSCROLL_H__

#include "Prerequest.h"
#include "VScroll.h"

namespace GUI
{

	class GUI_EXPORT HScroll :
		public VScroll
	{
		RTTI_DERIVED(HScroll)
		DEFINE_GET_THIS(HScroll, BASS(VScroll, END))

	public:
		HScroll();

		//! @copydoc VScroll::GetLineSize()
		//@ExportToLua
		virtual int GetLineSize();

		//! @copydoc VScroll::SetTrackSize(int value)
		//@ExportToLua
		virtual void SetTrackSize(int value);
		//! @copydoc VScroll::GetTrackSize()
		//@ExportToLua
		virtual int GetTrackSize();

	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~HScroll();

		void BaseChangeWidgetSkin(ResourceSkin* info);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

		void TrackMove(int left, int top);
		void UpdateTrack();

	};

} // namespace GUI

#endif // __HSCROLL_H__
