#ifndef __WIDGET_H__
#define __WIDGET_H__

#include "Prerequest.h"
#include "Any.h"
#include "ICroppedRectangle.h"
#include "ISubWidgetRect.h"
#include "ISubWidgetText.h"
#include "LayerItem.h"
#include "WidgetUserData.h"
#include "IWidgetCreator.h"
#include "ResourceSkin.h"
#include "IObject.h"
#include "UIScriptObject.h"


namespace GUI
{

	class GUI_EXPORT Widget :
		public UIScriptObject,
		public IObject,
		public ICroppedRectangle,
		public LayerItem,
		public UserData,
		public IWidgetCreator,
		public delegates::IDelegateUnlink
	{
		friend class IWidgetCreator;

		RTTI_BASE(Widget)
		DEFINE_GET_THIS(Widget, END)

	public:
		Widget();

		/** Create child widget
			@param _type widget type
			@param _skin widget skin
			@param coord int coordinates of Widget (left, top, width, height)
			@param _align widget Align (possible values can be found in enum Align)
			@param _name if Needed (you can use it for finding widget by name later)
		*/
		Widget* CreateWidgetT(const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& name = "");

		/** See Widget::CreateWidgetT(const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& name = "") */
		//@ExportToLua
		Widget* CreateWidgetT(const std::string& type, const std::string& skin, int left, int top, int width, int height, Align align, const std::string& name = "");

		/** Create widget using coordinates relative to parent. see Widget::CreateWidgetT(const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& name = "") */
		Widget* CreateWidgetRealT(const std::string& type, const std::string& skin, const FloatCoord& coord, Align align, const std::string& name = "");

		/** Create widget using coordinates relative to parent. see Widget::CreateWidgetT(const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& name = "") */
		//@ExportToLua
		Widget* CreateWidgetRealT(const std::string& type, const std::string& skin, float left, float top, float width, float height, Align align, const std::string& name = "");

		// templates for creating widgets by type
		/** Same as Widget::CreateWidgetT but return T pointer instead of Widget* */
		template <typename T>
		T* CreateWidget(const std::string& skin, const IntCoord& coord, Align align, const std::string& name = "")
		{
			return static_cast<T*>(CreateWidgetT(T::GetClassTypeName(), skin, coord, align, name));
		}

		/** Same as Widget::CreateWidgetT but return T pointer instead of Widget* */
		template <typename T>
		T* CreateWidget(const std::string& skin, int left, int top, int width, int height, Align align, const std::string& name = "")
		{
			return static_cast<T*>(CreateWidgetT(T::GetClassTypeName(), skin, IntCoord(left, top, width, height), align, name));
		}

		/** Same as Widget::createWidgetRealT but return T* instead of Widget* */
		template <typename T>
		T* CreateWidgetReal(const std::string& skin, const FloatCoord& coord, Align align, const std::string& name = "")
		{
			return static_cast<T*>(createWidgetRealT(T::GetClassTypeName(), skin, coord, align, name));
		}

		/** Same as Widget::createWidgetRealT but return T* instead of Widget* */
		template <typename T>
		T* CreateWidgetReal(const std::string& skin, float left, float top, float width, float height, Align align, const std::string& name = "")
		{
			return static_cast<T*>(createWidgetRealT(T::GetClassTypeName(), skin, left, top, width, height, align, name));
		}

		/** Create child widget
			@param _style Child, Popup or Overlapped widget style
			@param _type widget type
			@param _skin widget skin
			@param coord int coordinates of Widget (left, top, width, height)
			@param _align widget Align (possible values can be found in enum Align)
			@param _name if Needed (you can use it for finding widget by name later)
		*/
		Widget* CreateWidgetT(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer = "", const std::string& name = "");

		/** Same as Widget::CreateWidgetT but return T* instead of Widget* */
		template <typename T>
		T* CreateWidget(WidgetStyle style, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer = "", const std::string& name = "")
		{
			return static_cast<T*>(CreateWidgetT(style, T::GetClassTypeName(), skin, coord, align, layer, name));
		}

		//! Get name of widget
		//@ExportToLua
		const std::string& GetName() const { return mName; }


		/** Set widget Position (position of left top corner) */
		virtual void SetPosition(const IntPoint& value);
		/** Set widget size */
		virtual void SetSize(const IntSize& value);
		/** Set widget position and size */
		virtual void SetCoord(const IntCoord& value);

		/** See Widget::SetPosition(const IntPoint& pos) */
		//@ExportToLua
		void SetPosition(int left, int top) { SetPosition(IntPoint(left, top)); }

		/** See Widget::SetSize(const IntSize& size) */
		//@ExportToLua
		void SetSize(int width, int height) { SetSize(IntSize(width, height)); }

		/** See Widget::SetCoord(const IntCoord& coord) */
		//@ExportToLua
		void SetCoord(int left, int top, int width, int height) { SetCoord(IntCoord(left, top, width, height)); }

		/** Set widget Position (position of left top corner)*/
		void SetRealPosition(const FloatPoint& value);
		/** Set widget size */
		void SetRealSize(const FloatSize& value);
		/** Set widget position and size*/
		void SetRealCoord(const FloatCoord& value);

		/** See Widget::SetRealPosition(const FloatPoint& point) */
		//@ExportToLua
		void SetRealPosition(float left, float top) { SetRealPosition(FloatPoint(left, top)); }

		/** See Widget::SetRealSize(const FloatSize& size) */
		//@ExportToLua
		void SetRealSize(float width, float height) { SetRealSize(FloatSize(width, height)); }

		/** See Widget::SetRealPosition(const FloatCoord& coord) */
		//@ExportToLua
		void SetRealCoord(float left, float top, float width, float height) { SetRealCoord(FloatCoord(left, top, width, height)); }

		/** Hide or show widget */
		//@ExportToLua
		virtual void SetVisible(bool value);

		/** Set align */
		//@ExportToLua
		virtual void SetAlign(Align value);

		/** Set widget caption */
		//@ExportToLua
		virtual void SetCaption(const UString& value);

		/** Get widget caption */
		//@ExportToLua
		virtual const UString& GetCaption();

		/** Set widget opacity */
		//@ExportToLua
		void SetAlpha(float value);

		/** Get widget opacity */
		//@ExportToLua
		float GetAlpha() { return mAlpha; }

		/** Enable or disable inherits alpha mode */
		//@ExportToLua
		void SetInheritsAlpha(bool value);

		/** Get inherits alpha mode flag */
		//@ExportToLua
		bool IsInheritsAlpha() { return mInheritsAlpha; }

		/** Set widget's state */
		//@ExportToLua
		bool SetState(const std::string& value);

		//@ExportToLua
		void SetColour(const Colour& value);

		/** Is this widget is root Widget (root == without parents) */
		//@ExportToLua
		bool IsRootWidget() { return nullptr == mCroppedParent; }

		/** Get parent widget or nullptr if no parent */
		//@ExportToLua
		Widget* GetParent() { return mParent; }

		/** Get child widgets Enumerator */
		EnumeratorWidgetPtr GetEnumerator();

		/** Get child count */
		//@ExportToLua
		size_t GetChildCount();

		/** Get child by Index (index from 0 to child_count - 1) */
		//@ExportToLua
		Widget* GetChildAt(size_t index);

		/** Find widget by Name (search recursively through all childs starting from this widget) */
		//@ExportToLua
		Widget* FindWidget(const std::string& name);

		/** Set need key focus flag */
		//@ExportToLua
		void SetNeedKeyFocus(bool value) { mNeedKeyFocus = value; }

		/** Is need key focus
			If disable this widget won't be reacting on keyboard at all.\n
			Enabled (true) by default.
		*/
		//@ExportToLua
		bool IsNeedKeyFocus() { return mNeedKeyFocus; }

		/** Set need mouse focus flag */
		//@ExportToLua
		void SetNeedMouseFocus(bool value) { mNeedMouseFocus = value; }

		/** Is need mouse focus
			If disable this widget won't be reacting on mouse at all.\n
			Enabled (true) by default.
		*/
		//@ExportToLua
		bool IsNeedMouseFocus() { return mNeedMouseFocus; }

		/** Set inherits mode flag
			This mode makes all child widgets pickable even if widget don't
			need mouse Focus (was set SetNeedKeyFocus(false)).\n
			Disabled (false) by default.
		*/
		//@ExportToLua
		void SetInheritsPick(bool value) { mInheritsPick = value; }

		/** Get inherits mode flag */
		//@ExportToLua
		bool IsInheritsPick() { return mInheritsPick; }

		/** Set picking mask for widget */
		//@ExportToLua
		void SetMaskPick(const std::string& filename);

		/** Enable or disable widget */
		//@ExportToLua
		virtual void SetEnabled(bool value);

		/** Enable or disable widget without changing widget's state */
		//@ExportToLua
		void SetEnabledSilent(bool value) { mEnabled = value; }

		/** Is widget enabled */
		//@ExportToLua
		bool IsEnabled() { return mEnabled; }

		/** Set mouse pointer for this widget */
		//@ExportToLua
		void SetPointer(const std::string& value) { mPointer = value; }

		/** Get mouse pointer name for this widget */
		//@ExportToLua
		const std::string& GetPointer();

		/** Get widget's layer, return "" if widget is not root Widget (root == without parents) */
		//@ExportToLua
		const std::string& GetLayerName();

		/** Get rect where child widgets placed */
		IntCoord GetClientCoord();

		/** Get clien area widget or nullptr if widget don't have client */
		//@ExportToLua
		Widget* GetClientWidget() { return mWidgetClient; }

		/** Get text sub widget or nullptr if no text sub widget */
		ISubWidgetText * GetSubWidgetText() { return mText; }
		/** Get sub widget of first texture or nullptr if no sub widget with texture */
		ISubWidgetRect * GetSubWidgetMain() { return mMainSkin; }

		/** Set need tool tip mode flag. Enable this if you need tool tip events for widget */
		//@ExportToLua
		void SetNeedToolTip(bool value);

		/** Get need tool tip mode flag */
		//@ExportToLua
		bool GetNeedToolTip() { return mNeedToolTip; }

		/** Enable or disable tooltip event */
		//@ExportToLua
		void SetEnableToolTip(bool value);

		/** Get tool tip enabled flag */
		//@ExportToLua
		bool GetEnableToolTip() { return mEnableToolTip; }

		/** Detach widget from widgets hierarchy
			@param _layer Attach to specified Layer (if any)
		*/
		//@ExportToLua
		void DetachFromWidget(const std::string& layer = "");

		/** Attach widget to parent
			@param _style Child widget type
			@param _layer Attach to specified Layer (if any)
			@note you might also need to call void Widget::SetWidgetStyle(WidgetStyle style);
				to set widget Style (widget attached with GUI::WidgetStyle::Popup by default)
		*/
		//@ExportToLua
		void AttachToWidget(Widget* parent, WidgetStyle style = WidgetStyle::Child, const std::string& layer = "");

		/** Change widget skin */
		//@ExportToLua
		void ChangeWidgetSkin(const std::string& skinname);

		/** Set widget style.
			@param _layer Attach to specified Layer (if any)
			@note When choosing WidgetStyle::Popup style you also need attach widget to layer
			see LayerManager::attachToLayerNode
		*/
		//@ExportToLua
		void SetWidgetStyle(WidgetStyle style, const std::string& layer = "");
		
		/** Get widget style */
		//@ExportToLua
		WidgetStyle GetWidgetStyle() { return mWidgetStyle; }

		/** Set any widget property
			@param _key Property Name (for example Widget_Alpha or Edit_MultiLine)
			@param _value Value converted to string
		*/
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);


	/*internal:*/
		virtual void _getContainer(Widget*& container, size_t& index);

		void _forcePeek(Widget* widget);

		void _setUVSet(const FloatRect& rect);

		virtual void _setTextureName(const std::string& texture);
		virtual const std::string& _getTextureName();

		IWidgetCreator * _getIWidgetCreator() { return mIWidgetCreator; }

		IntCoord _getTextRegion();
		IntSize _getTextSize();
		void _setFontName(const std::string& font);
		const std::string& _getFontName();
		void _setFontHeight(int height);
		int _getFontHeight();
		void _setTextAlign(Align align);
		Align _getTextAlign();
		void _setTextColour(const Colour& colour);
		const Colour& _getTextColour();

		//@ExportToLua
		void SetCaptionWithNewLine(const std::string& value);
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

//-----------------------------------------------------------------------------------------------------------------------
		//@ExportToLua
		IntCoord GetTextCoord() { return _getTextRegion(); }
		//@ExportToLua
		IntSize GetTextSize() { return _getTextSize(); }

		//@ExportToLua
		void SetFontName(const std::string& font) { _setFontName(font); }
		//@ExportToLua
		const std::string& GetFontName() { return _getFontName(); }

		//@ExportToLua
		void SetFontHeight(int height) { _setFontHeight(height); }
		//@ExportToLua
		int GetFontHeight() { return _getFontHeight(); }

		//@ExportToLua
		void SetTextAlign(Align align) { _setTextAlign(align); }
		//@ExportToLua
		Align GetTextAlign() { return _getTextAlign(); }

		//@ExportToLua
		void SetTextColour(const Colour& colour) { _setTextColour(colour); }
		//@ExportToLua
		const Colour& GetTextColour() { return _getTextColour(); }

//-----------------------------------------------------------------------------------------------------------------------

	protected:
		Widget(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);
		virtual ~Widget();

		virtual void BaseChangeWidgetSkin(ResourceSkin* info);

		void _updateView(); 

		void _setAlign(const IntSize& oldsize, bool update);
		void _setAlign(const IntCoord& oldcoord, bool update);

		virtual Widget* BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name);

		virtual void _destroyChildWidget(Widget* widget);

		virtual void _destroyAllChildWidget();

		virtual size_t _getContainerIndex(const IntPoint& point) { return ITEM_NONE; }

		virtual void _resetContainer(bool update);

		virtual void BaseUpdateEnable();

		virtual ILayerItem * GetLayerItemByPoint(int left, int top);
		virtual const IntCoord& GetLayerItemCoord() { return mCoord; }

	private:
		void FrameEntered(float frame);

		void InitialiseWidgetSkin(ResourceSkin* info, const IntSize& size);
		void ShutdownWidgetSkin(bool deep = false);

		void _updateAlpha();
		void _updateAbsolutePoint();

		void _setInheritsVisible(bool value);
		bool _isInheritsVisible() { return mInheritsVisible; }

		void _setInheritsEnable(bool value);
		bool _isInheritsEnable() { return mInheritsEnabled; }

		void _setSubSkinVisible(bool visible);

		float _getRealAlpha() { return mRealAlpha; }

		virtual void _linkChildWidget(Widget* widget);
		virtual void _unlinkChildWidget(Widget* widget);

	protected:
		MapWidgetStateInfo mStateInfo;
		MaskPickInfo const * mMaskPickInfo;
		MaskPickInfo mOwnMaskPickInfo;

		VectorWidgetPtr mWidgetChild;
		VectorWidgetPtr mWidgetChildSkin;
		VectorSubWidget mSubSkinChild;

		ISubWidgetText * mText;
		ISubWidgetRect * mMainSkin;

		bool mEnabled;
		bool mInheritsEnabled;
		bool mSubSkinsVisible;
		bool mInheritsVisible;
		float mAlpha;
		float mRealAlpha;
		bool mInheritsAlpha;
		std::string mName;
		std::string mPointer;
		std::string mTextureName;
		ITexture* mTexture;

		Widget* mParent;

		IWidgetCreator * mIWidgetCreator;

		bool mNeedKeyFocus;
		bool mNeedMouseFocus;
		bool mInheritsPick;

		Widget* mWidgetClient;

		bool mNeedToolTip;
		bool mEnableToolTip;
		bool mToolTipVisible;
		float mToolTipCurrentTime;
		IntPoint mToolTipOldPoint;
		size_t mToolTipOldIndex;
		IntPoint m_oldMousePoint;

		WidgetStyle mWidgetStyle;

		FloatCoord mRelativeCoord;
		bool mDisableUpdateRelative;

	};

} // namespace GUI

#endif // __WIDGET_H__


