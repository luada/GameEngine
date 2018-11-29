#ifndef __GUI_H__
#define __GUI_H__

#include "Prerequest.h"
#include "Types.h"
#include "Instance.h"
#include "XmlDocument.h"
#include "IWidgetCreator.h"
#include "IUnlinkWidget.h"
#include "Widget.h"

namespace GUI
{

	typedef delegates::CMultiDelegate1<float> FrameEventDelegate;

	class GUI_EXPORT Gui : public IWidgetCreator, public IUnlinkWidget
	{
		friend class WidgetManager;
		INSTANCE_HEADER(Gui)

	public:
		/** Initialise GUI and all GUI Managers
			@param
				_core name of core config file for GUI (contain main config files with skins, layers, fonts, etc.)
			@param
				_logFileName Log file name
		*/
		void Initialise(const std::string& core = "core.xml", const std::string& logFileName = LOG_FILENAME);

		/** Shutdown GUI and all GUI Managers*/
		void Shutdown();

		//@ExportToLua
		static Gui& Instance()
		{
			return GetInstance();
		}

		// methods for creating widgets
		/** Create widget
			@param _type widget type
			@param _skin widget skin
			@param coord int coordinates of Widget (left, top, width, height)
			@param _align widget Align (possible values can be found in enum Align)
			@param _layer layer where widget will be Created (all layers usually defined in core.layer file).
				If your widget will overlap with any other you shoud select _layer with "overlapped" property enabled.
			@param _name if Needed (you can use it for finding widget by name later)
		*/
		//@ExportToLua
		Widget* CreateWidgetT(const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name = "")
		{
			return BaseCreateWidget(WidgetStyle::Overlapped, type, skin, coord, align, layer, name);
		}

		/** See Gui::CreateWidgetT */
		//@ExportToLua
		Widget* CreateWidgetT(const std::string& type, const std::string& skin, int left, int top, int width, int height, Align align, const std::string& layer, const std::string& name = "")
		{
			return CreateWidgetT(type, skin, IntCoord(left, top, width, height), align, layer, name);
		}

		/** Create widget using coordinates relative to parent. see Gui::CreateWidgetT */
		//@ExportToLua
		Widget* CreateWidgetRealT(const std::string& type, const std::string& skin, const FloatCoord& coord, Align align, const std::string& layer, const std::string& name = "")
		{
			return CreateWidgetT(type, skin, IntCoord((int)(coord.left*mViewSize.width), (int)(coord.top*mViewSize.height), (int)(coord.width*mViewSize.width), (int)(coord.height*mViewSize.height)), align, layer, name);
		}

		/** Create widget using coordinates relative to parent. see Gui::CreateWidgetT */
		//@ExportToLua
		Widget* CreateWidgetRealT(const std::string& type, const std::string& skin, float left, float top, float width, float height, Align align, const std::string& layer, const std::string& name = "")
		{
			return CreateWidgetT(type, skin, IntCoord((int)(left*mViewSize.width), (int)(top*mViewSize.height), (int)(width*mViewSize.width), (int)(height*mViewSize.height)), align, layer, name);
		}

		// templates for creating widgets by type
		/** Same as Gui::CreateWidgetT but return T* instead of Widget* */
		template <typename T>
		T* CreateWidget(const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name = "")
		{
			return static_cast<T*>(CreateWidgetT(T::GetClassTypeName(), skin, coord, align, layer, name));
		}
		/** Same as Gui::CreateWidgetT but return T* instead of Widget* */
		template <typename T>
		T* CreateWidget(const std::string& skin, int left, int top, int width, int height, Align align, const std::string& layer, const std::string& name = "")
		{
			return static_cast<T*>(CreateWidgetT(T::GetClassTypeName(), skin, IntCoord(left, top, width, height), align, layer, name));
		}
		/** Same as Gui::createWidgetRealT but return T* instead of Widget* */
		template <typename T>
		T* CreateWidgetReal(const std::string& skin, const FloatCoord& coord, Align align, const std::string& layer, const std::string& name = "")
		{
			return static_cast<T*>(createWidgetRealT(T::GetClassTypeName(), skin, coord, align, layer, name));
		}
		/** Same as Gui::createWidgetRealT but return T* instead of Widget* */
		template <typename T>
		T* CreateWidgetReal(const std::string& skin, float left, float top, float width, float height, Align align, const std::string& layer, const std::string& name = "")
		{
			return static_cast<T*>(createWidgetRealT(T::GetClassTypeName(), skin, left, top, width, height, align, layer, name));
		}

		/** Get view size of GUI area */
		//@ExportToLua
		const IntSize& GetViewSize() const { return mViewSize; }

		//@ExportToLua
		int GetViewWidth() { return mViewSize.width; }

		//@ExportToLua
		int GetViewHeight() { return mViewSize.height; }

		// mirror of InputManager methods
		/** Inject MouseMove event
			@return true if event has been processed by GUI
		*/
		bool InjectMouseMove(int absx, int absy, int absz);
		/** Inject MousePress event
			@return true if event has been processed by GUI
		*/
		bool InjectMousePress(int absx, int absy, MouseButton id);
		/** Inject MouseRelease event
			@return true if event has been processed by GUI
		*/
		bool InjectMouseRelease(int absx, int absy, MouseButton id);

		/** Inject KeyPress event
			@return true if event has been processed by GUI
		*/
		bool InjectKeyPress(KeyCode key, Char text = 0);
		/** Inject KeyReleas event
			@return true if event has been processed by GUI
		*/
		bool InjectKeyRelease(KeyCode key);

		/** Destroy any created widget */
		//@ExportToLua
		void DestroyWidget(Widget* widget);

		/** Destroy vector of widgets */
		void DestroyWidgets(VectorWidgetPtr& widgets);

		/** Destroy Enumerator of widgets */
		void DestroyWidgets(EnumeratorWidgetPtr& widgets);

		/** Find widget by name
			If widget is not found the exception will be thrown, or if the second parameter is false the nullptr pointer will be returned
		*/
		//@ExportToLua
		Widget* findWidgetT(const std::string& name, bool _throw = true);

		/** Find widget by name and prefix
			If widget is not found the exception will be thrown, or if the second parameter is false the nullptr pointer will be returned
		*/
		Widget* findWidgetT(const std::string& name, const std::string& prefix, bool _throw = true)
		{
			return findWidgetT(prefix + name, _throw);
		}

		// mirror WidgetManager
		/** Find widget by name and cast it to T type.
			If widget not found or T and found widget have different types cause exception, or if the second parameter is false the nullptr pointer will be returned
		*/
		template <typename T>
		T* FindWidget(const std::string& name, bool _throw = true)
		{
			Widget* widget = findWidgetT(name, _throw);
			if (nullptr == widget) return nullptr;
			return widget->CastType<T>(_throw);
		}

		/** Find widget by name and prefix and cast it to T type
			If widget not found or T and found widget have different types cause exception, or if the second parameter is false the nullptr pointer will be returned
		*/
		template <typename T>
		T* FindWidget(const std::string& name, const std::string& prefix, bool _throw = true)
		{
			return findWidget<T>(prefix + name, _throw);
		}


		/** Show or hide mouse pointer */
		//@ExportToLua
		void SetVisiblePointer(bool visible);

		/** Is mouse pointer visible */
		//@ExportToLua
		bool IsVisiblePointer();


		// mirror ResourceManager
		/** Load config with any Info (file can have different data such other config files that will be loaded, skins, layers, pointers, etc) */
		//@ExportToLua
		bool Load(const std::string& file);

		//@ExportToLua
		void ResizeWindow(const IntSize& size);

		/** Destroy child widget or throw exception if this child widget not found */
		//@ExportToLua
		void DestroyChildWidget(Widget* widget) { _destroyChildWidget(widget); }

		/** Destroy all child widgets */
		//@ExportToLua
		void DestroyAllChildWidget() { _destroyAllChildWidget(); }

		/** Get name of Gui ResourceGroup*/
		//static const std::string& GetResourceGroup();

		/** Get root widgets Enumerator */
		EnumeratorWidgetPtr GetEnumerator() { return EnumeratorWidgetPtr(mWidgetChild); }

	/*internal:*/

		/** Inject frame entered Event (called be renderer, do not call it manually).
			This function is called every frame by renderer.
		*/
		void _injectFrameEntered(float time);

	/*event:*/
		/** Multidelegate for GUI per frame call.\n
			signature : void Method(float time)\n
			@param _time Time elapsed since last frame
		*/
		FrameEventDelegate eventFrameStart;

	private:
		virtual Widget* BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name);

		void _destroyChildWidget(Widget* widget);

		void _destroyAllChildWidget();

		virtual void _unlinkWidget(Widget* widget);

		virtual void _linkChildWidget(Widget* widget);

		virtual void _unlinkChildWidget(Widget* widget);


	private:
		VectorWidgetPtr mWidgetChild;

		IntSize mViewSize;

		InputManager * mInputManager;
		SubWidgetManager * mSubWidgetManager;
		LayerManager* mLayerManager;
		SkinManager* mSkinManager;
		WidgetManager* mWidgetManager;
		FontManager* mFontManager;
		ControllerManager* mControllerManager;
		PointerManager* mPointerManager;
		ClipboardManager* mClipboardManager;
		LayoutManager* mLayoutManager;
		DynLibManager* mDynLibManager;
		PluginManager* mPluginManager;
		LanguageManager* mLanguageManager;
		ResourceManager* mResourceManager;
		FactoryManager* mFactoryManager;

	};

} // namespace GUI

#endif // __GUI_H__

