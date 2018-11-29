#ifndef __POINTER_MANAGER_H__
#define __POINTER_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"
#include "IUnlinkWidget.h"
#include "IWidgetCreator.h"
#include "StaticImage.h"
#include "IPointer.h"

namespace GUI
{

	class GUI_EXPORT PointerManager :
		public IUnlinkWidget,
		public IWidgetCreator
	{
		INSTANCE_HEADER(PointerManager)

	public:
		void Initialise();
		void Shutdown();

	public:
		/** Load additional GUI *_pointer.xml file */
		bool Load(const std::string& file);

		void _load(xml::ElementPtr node, const std::string& file, Version version);

		/** Show or hide mouse pointer */
		void SetVisible(bool visible);
		/** Is mouse pointer visible */
		bool IsVisible() const { return mVisible; }

		/** Set pointer that will be shown
			@param _name of pointer
		*/
		void SetPointer(const std::string& name);
		/** Reset to default pointer */
		void ResetToDefaultPointer();

		/** Get default pointer */
		const std::string& GetDefaultPointer() { return mDefaultName; }
		/** Set default pointer */
		void SetDeafultPointer(const std::string& value);

		const std::string& GetLayerName() { return mLayerName; }
		void SetLayerName(const std::string& value);

		/** Get pointer resource */
		IPointer* GetByName(const std::string& name) const;

	/*event:*/
		/** Event : Mouse pointer has been changed.\n
			signature : void Method(const std::string& pointerName)\n
			@param _pointerName Name of current mouse pointer
		*/
		delegates::CMultiDelegate1<const std::string &>
			eventChangeMousePointer;

	private:
		void _unlinkWidget(Widget* widget);

		virtual Widget* BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name);

		virtual void _destroyChildWidget(Widget* widget);

		virtual void _destroyAllChildWidget();

		void Update();

		void NotifyFrameStart(float time);
		void NotifyChangeMouseFocus(Widget* widget);
		void SetPointer(const std::string& name, Widget* owner);

	private:
		VectorWidgetPtr mWidgetChild;

		std::string mDefaultName;
		IntPoint mPoint;
		bool mVisible;
		std::string mLayerName;
		std::string mSkinName;

		Widget* mWidgetOwner;
		StaticImage* mMousePointer;
		IPointer* mPointer;
		std::string mCurrentMousePointer;
	};

} // namespace GUI

#endif // __POINTER_MANAGER_H__

