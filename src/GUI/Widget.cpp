#include "Precompiled.h"
#include "Gui.h"
#include "Widget.h"
#include "InputManager.h"
#include "SkinManager.h"
#include "SubWidgetManager.h"
#include "WidgetManager.h"
#include "ResourceSkin.h"
#include "WidgetDefines.h"
#include "LayerItem.h"
#include "LayerManager.h"
#include "RenderItem.h"
#include "ISubWidget.h"
#include "ISubWidgetText.h"
#include "StaticText.h"
#include "FactoryManager.h"
#include "LanguageManager.h"
#include "CoordConverter.h"
#include "RenderManager.h"


namespace GUI
{

	const float WIDGET_TOOLTIP_TIMEOUT = 0.5f;

	Widget::Widget(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name) :
		mMaskPickInfo(nullptr),
		mText(nullptr),
		mMainSkin(nullptr),
		mEnabled(true),
		mInheritsEnabled(true),
		mSubSkinsVisible(true),
		mInheritsVisible(true),
		mAlpha(ALPHA_MIN),
		mRealAlpha(ALPHA_MIN),
		mInheritsAlpha(true),
		mTexture(nullptr),
		mParent(nullptr),
		mIWidgetCreator(nullptr),
		mNeedKeyFocus(false),
		mNeedMouseFocus(true),
		mInheritsPick(false),
		mWidgetClient(nullptr),
		mNeedToolTip(false),
		mEnableToolTip(true),
		mToolTipVisible(false),
		mToolTipCurrentTime(0),
		mToolTipOldIndex(ITEM_NONE),
		mWidgetStyle(WidgetStyle::Child),
		mDisableUpdateRelative(false)
	{
		_initialise(style, coord, align, info, parent, croppedParent, creator, name);
	}

	Widget::Widget() :
		mMaskPickInfo(nullptr),
		mText(nullptr),
		mMainSkin(nullptr),
		mEnabled(true),
		mInheritsEnabled(true),
		mSubSkinsVisible(true),
		mInheritsVisible(true),
		mAlpha(ALPHA_MIN),
		mRealAlpha(ALPHA_MIN),
		mInheritsAlpha(true),
		mTexture(nullptr),
		mParent(nullptr),
		mIWidgetCreator(nullptr),
		mNeedKeyFocus(false),
		mNeedMouseFocus(true),
		mInheritsPick(false),
		mWidgetClient(nullptr),
		mNeedToolTip(false),
		mEnableToolTip(true),
		mToolTipVisible(false),
		mToolTipCurrentTime(0),
		mToolTipOldIndex(ITEM_NONE),
		mWidgetStyle(WidgetStyle::Child),
		mDisableUpdateRelative(false)
	{
	}

	void Widget::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		mCoord = IntCoord(coord.Point(), info->GetSize());
		mStateInfo = info->GetStateInfo();
		mMaskPickInfo = info->GetMask();

		mTextureName = info->GetTextureName();
		mTexture = RenderManager::GetInstance().GetTexture(mTextureName);

		mAlign = align;
		mCroppedParent = croppedParent;

		mName = name;
		mParent = parent;
		mIWidgetCreator = creator;

		mWidgetStyle = style;

		mWidgetEventSender = this;

#if DEBUG_MODE == 1
		if (mWidgetStyle == WidgetStyle::Child)
		{
			ASSERT(mCroppedParent, "must be cropped");
			ASSERT(mParent, "must be curParent");
		}
		else if (mWidgetStyle == WidgetStyle::Overlapped)
		{
			ASSERT((mParent == nullptr) == (mCroppedParent == nullptr), "error cropped");
		}
		else if (mWidgetStyle == WidgetStyle::Popup)
		{
			ASSERT(!mCroppedParent, "cropped must be nullptr");
			ASSERT(mParent, "must be curParent");
		}
#endif

		mAbsolutePosition = coord.Point();

		if (nullptr != mCroppedParent)
		{
			mAbsolutePosition += mCroppedParent->GetAbsolutePosition();
		}

		const IntSize& parent_size = mCroppedParent ? mCroppedParent->GetSize() : Gui::GetInstance().GetViewSize();

		if (parent_size.width)
		{
			mRelativeCoord.left = (float)coord.left / (float)parent_size.width;
			mRelativeCoord.width = (float)coord.width / (float)parent_size.width;
		}
		else
		{
			mRelativeCoord.left = 0;
			mRelativeCoord.width = 0;
		}

		if (parent_size.height)
		{
			mRelativeCoord.top = (float)coord.top / (float)parent_size.height;
			mRelativeCoord.height = (float)coord.height / (float)parent_size.height;
		}
		else
		{
			mRelativeCoord.top = 0;
			mRelativeCoord.height = 0;
		}

		InitialiseWidgetSkin(info, coord.Size());

		if (mWidgetStyle == WidgetStyle::Child)
		{
			if (mParent) mParent->AddChildItem(this);
		}
		else if (mWidgetStyle == WidgetStyle::Overlapped)
		{
			if (mParent) mParent->AddChildNode(this);
		}
	}

	Widget::~Widget()
	{
		Gui::GetInstance().eventFrameStart -= NewDelegate(this, &Widget::FrameEntered);

		if (mToolTipVisible) eventToolTip(this, ToolTipInfo(ToolTipInfo::Hide));

		ShutdownWidgetSkin(true);

		_destroyAllChildWidget();

		if (mWidgetStyle == WidgetStyle::Child)
		{
			if (mParent) mParent->RemoveChildItem(this);
		}
		else if (mWidgetStyle == WidgetStyle::Overlapped)
		{
			if (mParent) mParent->RemoveChildNode(this);
		}
	}

	void Widget::ChangeWidgetSkin(const std::string& skinname)
	{
		ResourceSkin* skin_info = SkinManager::GetInstance().GetByName(skinname);
		BaseChangeWidgetSkin(skin_info);
	}

	void Widget::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		IntSize size = mCoord.Size();

		SaveLayerItem();

		ShutdownWidgetSkin();
		InitialiseWidgetSkin(info, size);

		RestoreLayerItem();
	}

	void Widget::InitialiseWidgetSkin(ResourceSkin* info, const IntSize& size)
	{
		FactoryManager& factory = FactoryManager::GetInstance();

		mTextureName = info->GetTextureName();
		mTexture = RenderManager::GetInstance().GetTexture(mTextureName);

		SetRenderItemTexture(mTexture);
		mStateInfo = info->GetStateInfo();
		Widget::SetSize(info->GetSize());

		for (VectorSubWidgetInfo::const_iterator iter=info->GetBasisInfo().begin(); iter!=info->GetBasisInfo().end(); ++iter)
		{
			IObject* object = factory.CreateObject("BasisSkin", (*iter).type);
			if (object == nullptr) continue;

			ISubWidget* sub = object->CastType<ISubWidget>();
			sub->_setCroppedParent(this);
			sub->SetCoord((*iter).coord);
			sub->SetAlign((*iter).align);

			mSubSkinChild.push_back(sub);
			AddRenderItem(sub);

			if (mMainSkin == nullptr) mMainSkin = sub->CastType<ISubWidgetRect>(false);
			if (mText == nullptr) mText = sub->CastType<ISubWidgetText>(false);
		}

		if (!IsRootWidget())
		{
			if ((!mParent->IsVisible()) || (!mParent->_isInheritsVisible()))
			{
				bool value = false;
				mInheritsVisible = value;
				for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
					(*skin)->SetVisible(value);
				for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget)
					(*widget)->_setInheritsVisible(value);
				for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget)
					(*widget)->_setInheritsVisible(value);
			}
			if ((!mParent->IsEnabled()) || (!mParent->_isInheritsEnable()))
			{
				bool value = false;
				mInheritsEnabled = false;
				for (VectorWidgetPtr::iterator iter = mWidgetChild.begin(); iter != mWidgetChild.end(); ++iter)
					(*iter)->_setInheritsEnable(value);
				for (VectorWidgetPtr::iterator iter = mWidgetChildSkin.begin(); iter != mWidgetChildSkin.end(); ++iter)
					(*iter)->_setInheritsEnable(value);
			}
		}

		Widget::SetState("normal");//FIXME 

		const MapString& properties = info->GetProperties();
		if (!properties.empty())
		{
			MapString::const_iterator iter = properties.end();
			if ((iter = properties.find("NeedKey")) != properties.end()) SetNeedKeyFocus(utility::ParseBool(iter->second));
			if ((iter = properties.find("NeedMouse")) != properties.end()) SetNeedMouseFocus(utility::ParseBool(iter->second));
			if ((iter = properties.find("Pointer")) != properties.end()) mPointer = iter->second;
			if ((iter = properties.find("Visible")) != properties.end()) { SetVisible(utility::ParseBool(iter->second)); }

			// OBSOLETE
			if ((iter = properties.find("AlignText")) != properties.end()) _setTextAlign(Align::Parse(iter->second));
			if ((iter = properties.find("Colour")) != properties.end()) _setTextColour(Colour::Parse(iter->second));
			if ((iter = properties.find("Show")) != properties.end()) { SetVisible(utility::ParseBool(iter->second)); }
			if ((iter = properties.find("TextAlign")) != properties.end()) _setTextAlign(Align::Parse(iter->second));
			if ((iter = properties.find("TextColour")) != properties.end()) _setTextColour(Colour::Parse(iter->second));
			if ((iter = properties.find("FontName")) != properties.end()) _setFontName(iter->second);
			if ((iter = properties.find("FontHeight")) != properties.end()) _setFontHeight(utility::ParseInt(iter->second));
		}

		Widget::SetAlpha(ALPHA_MAX);//FIXME 

		const VectorChildSkinInfo& child = info->GetChild();
		for (VectorChildSkinInfo::const_iterator iter=child.begin(); iter!=child.end(); ++iter)
		{
			//FIXME 
			Widget* widget = Widget::BaseCreateWidget(iter->style, iter->type, iter->skin, iter->coord, iter->align, iter->layer, "");
			widget->_setInternalData(iter->name);
			for (MapString::const_iterator prop=iter->params.begin(); prop!=iter->params.end(); ++prop)
			{
				widget->SetUserString(prop->first, prop->second);
			}
			mWidgetChildSkin.push_back(widget);
			mWidgetChild.pop_back();
		}

		Widget::SetSize(size);//FIXME
	}

	void Widget::ShutdownWidgetSkin(bool deep)
	{
		mMainSkin = nullptr;
		mText = nullptr;

		RemoveAllRenderItems();

		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
		{
			delete (*skin);
		}
		mSubSkinChild.clear();

		mStateInfo.clear();

		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			mWidgetChild.push_back(*iter);
			_destroyChildWidget(*iter);
		}
		mWidgetChildSkin.clear();
	}

	Widget* Widget::BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name)
	{
		Widget* widget = WidgetManager::GetInstance().CreateWidget(style, type, skin, coord, align, this,
			style == WidgetStyle::Popup ? nullptr : this, this, name);

		mWidgetChild.push_back(widget);

		if (!layer.empty() && widget->IsRootWidget()) LayerManager::GetInstance().AttachToLayerNode(layer, widget);

		return widget;
	}

	Widget* Widget::CreateWidgetRealT(const std::string& type, const std::string& skin, const FloatCoord& coord, Align align, const std::string& name)
	{
		return CreateWidgetT(type, skin, CoordConverter::ConvertFromRelative(coord, GetSize()), align, name);
	}

	void Widget::_updateView()
	{

		bool margin = mCroppedParent ? _checkMargin() : false;

		if (margin)
		{
			if (_checkOutside())
			{
				mIsMargin = margin;

				_setSubSkinVisible(false);

				//for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin) (*skin)->_updateView();

				for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateView();
				for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateView();

				return;
			}

		}
		else if (!mIsMargin)
		{
			//mIsMargin = margin;

			//_setSubSkinVisible(true);
			for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin) (*skin)->_updateView();

			return;
		}

		mIsMargin = margin;

		_setSubSkinVisible(true);

		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateView();
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateView();
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin) (*skin)->_updateView();

	}

	void Widget::SetCaption(const UString& caption)
	{
		if (nullptr != mText) mText->SetCaption(caption);
	}

	const UString& Widget::GetCaption()
	{
		if (nullptr == mText)
		{
			static UString empty;
			return empty;
		}
		return mText->GetCaption();
	}

	bool Widget::SetState(const std::string& state)
	{
		MapWidgetStateInfo::const_iterator iter = mStateInfo.find(state);
		if (iter == mStateInfo.end()) return false;
		size_t index=0;
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin, ++index)
		{
			IStateInfo* data = (*iter).second[index];
			if (data != nullptr)
			{
				(*skin)->SetStateData(data);
			}
		}
		return true;
	}

	void Widget::_destroyChildWidget(Widget* widget)
	{
		ASSERT(nullptr != widget, "invalid curWidget pointer");

		VectorWidgetPtr::iterator iter = std::find(mWidgetChild.begin(), mWidgetChild.end(), widget);
		if (iter != mWidgetChild.end())
		{

			GUI::Widget* curWidget = *iter;

			*iter = mWidgetChild.back();
			mWidgetChild.pop_back();

			WidgetManager::GetInstance().UnlinkFromUnlinkers(widget);

			_deleteWidget(curWidget);
		}
		else
		{
			EXCEPT("Widget '" << widget->GetName() << "' not found");
		}
	}

	void Widget::_destroyAllChildWidget()
	{
		WidgetManager& manager = WidgetManager::GetInstance();
		while (!mWidgetChild.empty())
		{

			Widget* widget = mWidgetChild.back();
			mWidgetChild.pop_back();

			//if (widget->IsRootWidget()) widget->DetachWidget();

			manager.UnlinkFromUnlinkers(widget);

			delete widget;
		}
	}

	IntCoord Widget::GetClientCoord()
	{
		ASSERT(mWidgetClient != this, "mWidgetClient can not be this widget");
		if (mWidgetClient != nullptr) return mWidgetClient->GetCoord();
		return IntCoord(0, 0, mCoord.width, mCoord.height);
	}

	void Widget::SetAlpha(float alpha)
	{
		if (mAlpha == alpha) return;
		mAlpha = alpha;
		if (nullptr != mParent) mRealAlpha = mAlpha * (mInheritsAlpha ? mParent->_getRealAlpha() : ALPHA_MAX);
		else mRealAlpha = mAlpha;

		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAlpha();
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAlpha();
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin) (*skin)->SetAlpha(mRealAlpha);
	}

	void Widget::_updateAlpha()
	{
		DEBUG_ASSERT(nullptr != mParent, "Widget must have parent");
		mRealAlpha = mAlpha * (mInheritsAlpha ? mParent->_getRealAlpha() : ALPHA_MAX);

		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAlpha();
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAlpha();
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin) (*skin)->SetAlpha(mRealAlpha);
	}

	void Widget::SetInheritsAlpha(bool inherits)
	{
		mInheritsAlpha = inherits;
		float alpha = mAlpha;
		mAlpha = 101;
		SetAlpha(alpha);
	}

	ILayerItem * Widget::GetLayerItemByPoint(int left, int top)
	{
		if (!mSubSkinsVisible
			|| !mEnabled
			|| !mVisible
			|| (!mNeedMouseFocus && !mInheritsPick)
			|| !_checkPoint(left, top)
			|| ((!mMaskPickInfo->empty()) && (!mMaskPickInfo->Pick(IntPoint(left - mCoord.left, top - mCoord.top), mCoord))))
				return nullptr;
		for (VectorWidgetPtr::reverse_iterator widget= mWidgetChild.rbegin(); widget != mWidgetChild.rend(); ++widget)
		{
			if ((*widget)->mWidgetStyle == WidgetStyle::Popup) continue;

			ILayerItem * item = (*widget)->GetLayerItemByPoint(left - mCoord.left, top - mCoord.top);
			if (item != nullptr) return item;
		}
		for (VectorWidgetPtr::reverse_iterator widget= mWidgetChildSkin.rbegin(); widget != mWidgetChildSkin.rend(); ++widget)
		{
			ILayerItem * item = (*widget)->GetLayerItemByPoint(left - mCoord.left, top - mCoord.top);
			if (item != nullptr) return item;
		}
		return mInheritsPick ? nullptr : this;
	}

	void Widget::_updateAbsolutePoint()
	{
		if (!mCroppedParent) return;

		mAbsolutePosition = mCroppedParent->GetAbsolutePosition() + mCoord.Point();

		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin) (*skin)->_correctView();
	}

	void Widget::_setUVSet(const FloatRect& rect)
	{
		if (nullptr != mMainSkin) mMainSkin->_setUVSet(rect);
	}

	void Widget::_setTextureName(const std::string& texture)
	{
		//if (texture == mTextureName) return;

		mTextureName = texture;
		mTexture = RenderManager::GetInstance().GetTexture(mTextureName);

		SetRenderItemTexture(mTexture);
	}

	const std::string& Widget::_getTextureName()
	{
		return mTextureName;
	}

	void Widget::_setSubSkinVisible(bool visible)
	{
		if (mSubSkinsVisible == visible) return;
		mSubSkinsVisible = visible;

		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
		{
			(*skin)->_updateView();
		}
	}

	void Widget::_forcePeek(Widget* widget)
	{
		ASSERT(mWidgetClient != this, "mWidgetClient can not be this curWidget");
		if (mWidgetClient != nullptr) mWidgetClient->_forcePeek(widget);

		size_t size = mWidgetChild.size();
		if ( (size < 2) || (mWidgetChild[size-1] == widget) ) return;
		for (size_t pos=0; pos<size; pos++)
		{
			if (mWidgetChild[pos] == widget)
			{
				mWidgetChild[pos] = mWidgetChild[size-1];
				mWidgetChild[size-1] = widget;
				return;
			}
		}
	}

	const std::string& Widget::GetLayerName()
	{
		ILayer* layer = GetLayer();
		if (nullptr == layer)
		{
			static std::string empty;
			return empty;
		}
		return layer->GetName();
	}

	void Widget::_getContainer(Widget*& list, size_t& index)
	{
		list = nullptr;
		index = ITEM_NONE;
		_requestGetContainer(this, list, index);
	}

	Widget* Widget::FindWidget(const std::string& name)
	{
		if (name == mName) return this;
		ASSERT(mWidgetClient != this, "mWidgetClient can not be this widget");
		if (mWidgetClient != nullptr) return mWidgetClient->FindWidget(name);
		for (VectorWidgetPtr::iterator it = mWidgetChild.begin(), endIt = mWidgetChild.end(); it != endIt; ++it)
		{
			Widget* find = (*it)->FindWidget(name);
			if (nullptr != find) return find;
		}
		return nullptr;
	}

	void Widget::SetNeedToolTip(bool need)
	{
		if (mNeedToolTip == need) return;
		mNeedToolTip = need;

		if (mNeedToolTip)
		{
			Gui::GetInstance().eventFrameStart += NewDelegate(this, &Widget::FrameEntered);
			mToolTipCurrentTime = 0;
		}
		else
		{
			Gui::GetInstance().eventFrameStart -= NewDelegate(this, &Widget::FrameEntered);
		}
	}

	void Widget::FrameEntered(float frame)
	{
		if ( ! mEnableToolTip ) return;

		IntPoint point = InputManager::GetInstance().GetMousePositionByLayer();

		if (mToolTipOldPoint != point)
		{

			mToolTipCurrentTime = 0;

			bool inside = GetAbsoluteRect().Inside(point);
			if (inside)
			{
				inside = false;
				Widget* widget = InputManager::GetInstance().GetMouseFocusWidget();
				while (widget != 0)
				{
					if (widget/*->GetName()*/ == this/*mName*/)
					{
						inside = true;
						break;
					}
					if (widget->GetNeedToolTip())
						widget = 0;//widget->GetParent();
					else
						widget = widget->GetParent();
				}

				if (inside)
				{
					size_t index = _getContainerIndex(point);
					if (mToolTipOldIndex != index)
					{
						if (mToolTipVisible)
						{
							mToolTipCurrentTime = 0;
							mToolTipVisible = false;
							eventToolTip(this, ToolTipInfo(ToolTipInfo::Hide));
						}
						mToolTipOldIndex = index;
					}

				}
				else
				{
					if (mToolTipVisible)
					{
						mToolTipCurrentTime = 0;
						mToolTipVisible = false;
						eventToolTip(this, ToolTipInfo(ToolTipInfo::Hide));
					}
				}

			}
			else
			{
				if (mToolTipVisible)
				{
					mToolTipCurrentTime = 0;
					mToolTipVisible = false;
					eventToolTip(this, ToolTipInfo(ToolTipInfo::Hide));
				}
			}

			mToolTipOldPoint = point;
		}
		else
		{
			bool inside = GetAbsoluteRect().Inside(point);
			if (inside)
			{
				inside = false;
				Widget* widget = InputManager::GetInstance().GetMouseFocusWidget();
				while (widget != 0)
				{
					if (widget/*->GetName()*/ == this/*mName*/)
					{
						inside = true;
						break;
					}
					if (widget->GetNeedToolTip())
						widget = 0;//widget->GetParent();
					else
						widget = widget->GetParent();
				}

				if (inside)
				{
					if ( ! mToolTipVisible)
					{
						mToolTipCurrentTime += frame;
						if (mToolTipCurrentTime > WIDGET_TOOLTIP_TIMEOUT)
						{
							mToolTipVisible = true;
							eventToolTip(this, ToolTipInfo(ToolTipInfo::Show, mToolTipOldIndex, point));
						}
					}
				}
			}
		}
	}

	void Widget::SetEnableToolTip(bool enable)
	{
		if (enable == mEnableToolTip) return;
		mEnableToolTip = enable;

		if ( ! mEnableToolTip)
		{
			if (mToolTipVisible)
			{
				mToolTipCurrentTime = 0;
				mToolTipVisible = false;
				eventToolTip(this, ToolTipInfo(ToolTipInfo::Hide));
			}
		}
		else
		{
			mToolTipCurrentTime = 0;
		}
	}

	void Widget::_resetContainer(bool updateOnly)
	{
		if ( mEnableToolTip)
		{
			if (mToolTipVisible)
			{
				mToolTipVisible = false;
				eventToolTip(this, ToolTipInfo(ToolTipInfo::Hide));
			}
			mToolTipCurrentTime = 0;
			mToolTipOldIndex = ITEM_NONE;
		}
	}

	void Widget::SetMaskPick(const std::string& filename)
	{
		if (mOwnMaskPickInfo.Load(filename))
		{
			mMaskPickInfo = &mOwnMaskPickInfo;
		}
		else
		{
			LOG(Error, "mask not load '" << filename << "'");
		}
	}

	void Widget::SetRealPosition(const FloatPoint& point)
	{
		SetPosition(CoordConverter::ConvertFromRelative(point, mCroppedParent == nullptr ? Gui::GetInstance().GetViewSize() : mCroppedParent->GetSize()));
	}

	void Widget::SetRealSize(const FloatSize& size)
	{
		SetSize(CoordConverter::ConvertFromRelative(size, mCroppedParent == nullptr ? Gui::GetInstance().GetViewSize() : mCroppedParent->GetSize()));
	}

	void Widget::SetRealCoord(const FloatCoord& coord)
	{
		SetCoord(CoordConverter::ConvertFromRelative(coord, mCroppedParent == nullptr ? Gui::GetInstance().GetViewSize() : mCroppedParent->GetSize()));
	}

	void Widget::_linkChildWidget(Widget* widget)
	{
		VectorWidgetPtr::iterator iter = std::find(mWidgetChild.begin(), mWidgetChild.end(), widget);
		ASSERT(iter == mWidgetChild.end(), "widget already exist");
		mWidgetChild.push_back(widget);
	}

	void Widget::_unlinkChildWidget(Widget* widget)
	{
		VectorWidgetPtr::iterator iter = std::remove(mWidgetChild.begin(), mWidgetChild.end(), widget);
		ASSERT(iter != mWidgetChild.end(), "widget not found");
		mWidgetChild.erase(iter);
	}

	void Widget::_setTextAlign(Align align)
	{
		StaticText* text = this->CastType<StaticText>(false);
		if (text) text->SetTextAlign(align);

		if (mText != nullptr) mText->SetTextAlign(align);
	}

	Align Widget::_getTextAlign()
	{
		StaticText* text = this->CastType<StaticText>(false);
		if (text) return text->GetTextAlign();

		if (mText != nullptr) return mText->GetTextAlign();
		return Align::Default;
	}

	void Widget::_setTextColour(const Colour& colour)
	{
		StaticText* text = this->CastType<StaticText>(false);
		if (text) return text->SetTextColour(colour);

		if (nullptr != mText) mText->SetTextColour(colour);
	}

	const Colour& Widget::_getTextColour()
	{
		StaticText* text = this->CastType<StaticText>(false);
		if (text) return text->GetTextColour();

		return (nullptr == mText) ? Colour::Zero : mText->GetTextColour();
	}

	void Widget::_setFontName(const std::string& font)
	{
		StaticText* text = this->CastType<StaticText>(false);
		if (text) text->SetFontName(font);

		if (nullptr != mText) mText->SetFontName(font);
	}

	const std::string& Widget::_getFontName()
	{
		StaticText* text = this->CastType<StaticText>(false);
		if (text) return text->GetFontName();

		if (nullptr == mText)
		{
			static std::string empty;
			return empty;
		}
		return mText->GetFontName();
	}

	void Widget::_setFontHeight(int height)
	{
		StaticText* text = this->CastType<StaticText>(false);
		if (text) text->SetFontHeight(height);

		if (nullptr != mText) mText->SetFontHeight(height);
	}

	int Widget::_getFontHeight()
	{
		StaticText* text = this->CastType<StaticText>(false);
		if (text) return text->GetFontHeight();

		return (nullptr == mText) ? 0 : mText->GetFontHeight();
	}

	IntSize Widget::_getTextSize()
	{
		StaticText* text = this->CastType<StaticText>(false);
		if (text) return text->GetTextSize();

		return (nullptr == mText) ? IntSize() : mText->GetTextSize();
	}

	IntCoord Widget::_getTextRegion()
	{
		StaticText* text = this->CastType<StaticText>(false);
		if (text) return text->GetTextRegion();

		return (nullptr == mText) ? IntCoord() : mText->GetCoord();
	}

	void Widget::_setAlign(const IntCoord& oldcoord, bool update)
	{
		_setAlign(oldcoord.Size(), update);
	}

	void Widget::_setAlign(const IntSize& oldsize, bool update)
	{
		const IntSize& size = mCroppedParent ? mCroppedParent->GetSize() : Gui::GetInstance().GetViewSize();

		bool need_move = false;
		bool need_size = false;
		IntCoord coord = mCoord;

		if (mAlign.IsHRelative())
		{
			coord.left = int((float)size.width * mRelativeCoord.left);
			coord.width = int((float)size.width * mRelativeCoord.width);
		}
		else if (mAlign.IsHStretch())
		{
			coord.width = mCoord.width + (size.width - oldsize.width);
			need_size = true;
		}
		else if (mAlign.IsRight())
		{
			coord.left = mCoord.left + (size.width - oldsize.width);
			need_move = true;
		}
		else if (mAlign.IsHCenter())
		{
			coord.left = (size.width - mCoord.width) / 2;
			need_move = true;
		}

		if (mAlign.IsVRelative())
		{
			coord.top = int((float)size.height * mRelativeCoord.top);
			coord.height = int((float)size.height * mRelativeCoord.height);
		}
		else if (mAlign.IsVStretch())
		{
			coord.height = mCoord.height + (size.height - oldsize.height);
			need_size = true;
		}
		else if (mAlign.IsBottom())
		{
			coord.top = mCoord.top + (size.height - oldsize.height);
			need_move = true;
		}
		else if (mAlign.IsVCenter())
		{
			coord.top = (size.height - mCoord.height) / 2;
			need_move = true;
		}

		if (mAlign.IsHRelative() || mAlign.IsVRelative())
		{
			mDisableUpdateRelative = true;
			SetCoord(coord);
			mDisableUpdateRelative = false;
		}
		else if (need_move)
		{
			if (need_size) SetCoord(coord);
			else SetPosition(coord.Point());
		}
		else if (need_size)
		{
			SetSize(coord.Size());
		}
		else
		{
			_updateView(); 
		}

	}

	void Widget::SetPosition(const IntPoint& point)
	{
		if (mAlign.IsHRelative() || mAlign.IsVRelative())
		{

			const IntSize& parent_size = mCroppedParent ? mCroppedParent->GetSize() : Gui::GetInstance().GetViewSize();

			if (parent_size.width)
			{
				mRelativeCoord.left = (float)point.left / (float)parent_size.width;
			}
			else
			{
				mRelativeCoord.left = 0;
			}

			if (parent_size.height)
			{
				mRelativeCoord.top = (float)point.top / (float)parent_size.height;
			}
			else
			{
				mRelativeCoord.top = 0;
			}

		}

		mAbsolutePosition += point - mCoord.Point();

		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();

		mCoord = point;

		_updateView();
	}

	void Widget::SetSize(const IntSize& size)
	{
		if (mAlign.IsHRelative() || mAlign.IsVRelative())
		{

			const IntSize& parent_size = mCroppedParent ? mCroppedParent->GetSize() : Gui::GetInstance().GetViewSize();

			if (parent_size.width)
			{
				mRelativeCoord.width = (float)size.width / (float)parent_size.width;
			}
			else
			{
				mRelativeCoord.width = 0;
			}

			if (parent_size.height)
			{
				mRelativeCoord.height = (float)size.height / (float)parent_size.height;
			}
			else
			{
				mRelativeCoord.height = 0;
			}

		}

		IntSize old = mCoord.Size();
		mCoord = size;

		bool visible = true;

		bool margin = mCroppedParent ? _checkMargin() : false;

		if (margin)
		{
			if (_checkOutside())
			{
				visible = false;
			}
		}

		_setSubSkinVisible(visible);

		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_setAlign(old, mIsMargin || margin);
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_setAlign(old, mIsMargin || margin);
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin) (*skin)->_setAlign(old, mIsMargin || margin);

		mIsMargin = margin;

	}

	void Widget::SetCoord(const IntCoord& coord)
	{
		if (!mDisableUpdateRelative && (mAlign.IsHRelative() || mAlign.IsVRelative()))
		{

			const IntSize& parent_size = mCroppedParent ? mCroppedParent->GetSize() : Gui::GetInstance().GetViewSize();

			if (parent_size.width)
			{
				mRelativeCoord.left = (float)coord.left / (float)parent_size.width;
				mRelativeCoord.width = (float)coord.width / (float)parent_size.width;
			}
			else
			{
				mRelativeCoord.left = 0;
				mRelativeCoord.width = 0;
			}

			if (parent_size.height)
			{
				mRelativeCoord.top = (float)coord.top / (float)parent_size.height;
				mRelativeCoord.height = (float)coord.height / (float)parent_size.height;
			}
			else
			{
				mRelativeCoord.top = 0;
				mRelativeCoord.height = 0;
			}

		}

		mAbsolutePosition += coord.Point() - mCoord.Point();

		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();

		IntCoord old = mCoord;
		mCoord = coord;

		bool visible = true;

		bool margin = mCroppedParent ? _checkMargin() : false;

		if (margin)
		{
			if (_checkOutside())
			{
				visible = false;
			}
		}

		_setSubSkinVisible(visible);

		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_setAlign(old, mIsMargin || margin);
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_setAlign(old, mIsMargin || margin);
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin) (*skin)->_setAlign(old, mIsMargin || margin);

		mIsMargin = margin;

	}

	void Widget::SetAlign(Align align)
	{
		ICroppedRectangle::SetAlign(align);

		if (mAlign.IsHRelative() || mAlign.IsVRelative())
		{
			const IntSize& parent_size = mCroppedParent ? mCroppedParent->GetSize() : Gui::GetInstance().GetViewSize();

			if (parent_size.width)
			{
				mRelativeCoord.left = (float)mCoord.left / (float)parent_size.width;
				mRelativeCoord.width = (float)mCoord.width / (float)parent_size.width;
			}
			else
			{
				mRelativeCoord.left = 0;
				mRelativeCoord.width = 0;
			}

			if (parent_size.height)
			{
				mRelativeCoord.top = (float)mCoord.top / (float)parent_size.height;
				mRelativeCoord.height = (float)mCoord.height / (float)parent_size.height;
			}
			else
			{
				mRelativeCoord.top = 0;
				mRelativeCoord.height = 0;
			}

		}

	}

	void Widget::DetachFromWidget(const std::string& layer)
	{
		std::string oldlayer = GetLayerName();

		Widget* parent = GetParent();
		if (parent)
		{
			if ( ! IsRootWidget() )
			{
				DetachFromLayerItemNode(true);

				if (mWidgetStyle == WidgetStyle::Child)
				{
					mParent->RemoveChildItem(this);
				}
				else if (mWidgetStyle == WidgetStyle::Overlapped)
				{
					mParent->RemoveChildNode(this);
				}

				mWidgetStyle = WidgetStyle::Overlapped;

				mCroppedParent = nullptr;

				mAbsolutePosition = mCoord.Point();

				for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
				for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();

				mMargin.Clear();

				_updateView();
			}

			while (parent->GetParent()) { parent = parent->GetParent(); }

			mIWidgetCreator = parent->mIWidgetCreator;
			mIWidgetCreator->_linkChildWidget(this);
			mParent->_unlinkChildWidget(this);
			mParent = nullptr;
		}

		if (!layer.empty())
		{
			LayerManager::GetInstance().AttachToLayerNode(layer, this);
		}
		else if (!oldlayer.empty())
		{
			LayerManager::GetInstance().AttachToLayerNode(oldlayer, this);
		}

		float alpha = mAlpha;
		mAlpha = -1;
		SetAlpha(alpha);

	}

	void Widget::AttachToWidget(Widget* parent, WidgetStyle style, const std::string& layer)
	{
		ASSERT(parent, "parent must be valid");
		ASSERT(parent != this, "cyclic Attach (attaching to self)");

		// attach to client if widget have it
		if (parent->GetClientWidget()) parent = parent->GetClientWidget();

		Widget* curParent = parent;
		while (curParent->GetParent())
		{
			ASSERT(curParent != this, "cyclic attach");
			curParent = curParent->GetParent();
		}

		DetachFromWidget();

		mWidgetStyle = style;

		if (style == WidgetStyle::Popup)
		{
			mIWidgetCreator->_unlinkChildWidget(this);
			mIWidgetCreator = parent;
			mParent = parent;
			mParent->_linkChildWidget(this);

			mCroppedParent = nullptr;

			if (!layer.empty())
			{
				LayerManager::GetInstance().AttachToLayerNode(layer, this);
			}
		}
		else if (style == WidgetStyle::Child)
		{
			LayerManager::GetInstance().DetachFromLayer(this);

			mIWidgetCreator->_unlinkChildWidget(this);
			mIWidgetCreator = parent;
			mParent = parent;
			mParent->_linkChildWidget(this);

			mCroppedParent = parent;
			mAbsolutePosition = parent->GetAbsolutePosition() + mCoord.Point();

			for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
			for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();

			mParent->AddChildItem(this);

			_updateView();
		}
		else if (style == WidgetStyle::Overlapped)
		{
			LayerManager::GetInstance().DetachFromLayer(this);

			mIWidgetCreator->_unlinkChildWidget(this);
			mIWidgetCreator = parent;
			mParent = parent;
			mParent->_linkChildWidget(this);

			mCroppedParent = parent;
			mAbsolutePosition = parent->GetAbsolutePosition() + mCoord.Point();

			for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
			for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();

			mParent->AddChildNode(this);

			_updateView();
		}

		float alpha = mAlpha;
		mAlpha = -1;
		SetAlpha(alpha);

	}

	void Widget::SetWidgetStyle(WidgetStyle style, const std::string& layer)
	{
		if (style == mWidgetStyle) return;
		if (nullptr == GetParent()) return;

		Widget* parent = mParent;

		DetachFromWidget();
		AttachToWidget(parent, style, layer);
		/*Widget* root = this;
		while (!root->IsRootWidget())
		{
			root = root->GetParent();
		}

		std::string layername;
		ILayer* curLayer = root->GetLayer();
		if (curLayer)
		{
			layername = curLayer->GetName();
			LayerManager::GetInstance().DetachFromLayer(root);

			if (root == this)
			{
				layername.clear();

				if (getParent())
				{
					root = GetParent();
					while (!root->IsRootWidget())
					{
						root = root->GetParent();
					}

					curLayer = root->GetLayer();
					if (curLayer)
					{
						layername = curLayer->GetName();
						LayerManager::GetInstance().DetachFromLayer(root);
					}

				}
			}
		}

		mWidgetStyle = style;
		if (style == WidgetStyle::Child)
		{

			Widget* parent = GetParent();
			if (parent)
			{
				mAbsolutePosition = parent->GetAbsolutePosition() + mCoord.Point();
				mCroppedParent = parent;
				for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
				for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();
			}

		}
		else if (style == WidgetStyle::Popup)
		{

			mCroppedParent = nullptr;
			mAbsolutePosition = mCoord.Point();
			mMargin.clear();

			for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
			for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();

		}
		else if (style == WidgetStyle::Overlapped)
		{

			Widget* parent = GetParent();
			if (parent)
			{
				mAbsolutePosition = parent->GetAbsolutePosition() + mCoord.Point();
				mCroppedParent = parent;
				for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
				for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();
			}

		}

		if (!layername.empty())
		{
			LayerManager::GetInstance().AttachToLayerNode(layername, root);
		}*/

	}

	void Widget::SetCaptionWithNewLine(const std::string& value)
	{
		// change '\n' on char 10
		size_t pos = value.find("\\n");
		if (pos == std::string::npos)
		{
			SetCaption(LanguageManager::GetInstance().ReplaceTags(value));
		}
		else
		{
			std::string curValue(value);
			while (pos != std::string::npos)
			{
				curValue[pos++] = '\n';
				curValue.erase(pos, 1);
				pos = curValue.find("\\n");
			}
			SetCaption(LanguageManager::GetInstance().ReplaceTags(curValue));
		}
	}

	Widget* Widget::CreateWidgetT(const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& name)
	{
		return BaseCreateWidget(WidgetStyle::Child, type, skin, coord, align, "", name);
	}

	Widget* Widget::CreateWidgetT(const std::string& type, const std::string& skin, int left, int top, int width, int height, Align align, const std::string& name)
	{
		return CreateWidgetT(type, skin, IntCoord(left, top, width, height), align, name);
	}

	Widget* Widget::CreateWidgetRealT(const std::string& type, const std::string& skin, float left, float top, float width, float height, Align align, const std::string& name)
	{
		return CreateWidgetRealT(type, skin, FloatCoord(left, top, width, height), align, name);
	}

	Widget* Widget::CreateWidgetT(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name)
	{
		return BaseCreateWidget(style, type, skin, coord, align, layer, name);
	}

	EnumeratorWidgetPtr Widget::GetEnumerator()
	{
		ASSERT(mWidgetClient != this, "mWidgetClient can not be this widget");
		if (mWidgetClient != nullptr) return mWidgetClient->GetEnumerator();
		return Enumerator<VectorWidgetPtr>(mWidgetChild.begin(), mWidgetChild.end());
	}

	size_t Widget::GetChildCount()
	{
		ASSERT(mWidgetClient != this, "mWidgetClient can not be this widget");
		if (mWidgetClient != nullptr) return mWidgetClient->GetChildCount();
		return mWidgetChild.size();
	}

	Widget* Widget::GetChildAt(size_t index)
	{
		ASSERT(mWidgetClient != this, "mWidgetClient can not be this widget");
		if (mWidgetClient != nullptr) return mWidgetClient->GetChildAt(index);
		ASSERT_RANGE(index, mWidgetChild.size(), "Widget::getChildAt");
		return mWidgetChild[index];
	}

	const std::string& Widget::GetPointer()
	{
		if (!mEnabled)
		{
			static std::string empty;
			return empty;
		}
		return mPointer;
	}

	void Widget::SetProperty(const std::string& key, const std::string& value)
	{
		/// @wproperty{Widget, Widget_Caption, string} Sets caption
		if (key == "Widget_Caption") SetCaptionWithNewLine(value);
		/// @wproperty{Widget, Widget_Position, IntPoint} Sets position
		else if (key == "Widget_Position") SetPosition(utility::ParseValue<IntPoint>(value));
		else if (key == "Widget_Size") SetSize(utility::ParseValue<IntSize>(value));
		else if (key == "Widget_Coord") SetCoord(utility::ParseValue<IntCoord>(value));
		else if (key == "Widget_Visible") SetVisible(utility::ParseValue<bool>(value));
		else if (key == "Widget_Alpha") SetAlpha(utility::ParseValue<float>(value));
		else if (key == "Widget_Colour") SetColour(utility::ParseValue<Colour>(value));
		else if (key == "Widget_InheritsAlpha") SetInheritsAlpha(utility::ParseValue<bool>(value));
		else if (key == "Widget_InheritsPick") SetInheritsPick(utility::ParseValue<bool>(value));
		else if (key == "Widget_MaskPick") SetMaskPick(value);
		else if (key == "Widget_State") SetState(value);
		else if (key == "Widget_NeedKey") SetNeedKeyFocus(utility::ParseValue<bool>(value));
		else if (key == "Widget_NeedMouse") SetNeedMouseFocus(utility::ParseValue<bool>(value));
		else if (key == "Widget_Enabled") SetEnabled(utility::ParseValue<bool>(value));
		else if (key == "Widget_NeedToolTip") SetNeedToolTip(utility::ParseValue<bool>(value));
		else if (key == "Widget_Pointer") SetPointer(value);
		else if (key == "Script_Class")	  CreateScriptObj(value);
		else
		{
			LOG(warning, "Property " << key << " not found");
			return;
		}

		eventChangeProperty(this, key, value);
	}

	void Widget::BaseUpdateEnable()
	{
		if (mEnabled)
		{
			SetState("normal");
		}
		else
		{
			SetState("disabled");
		}
	}

	void Widget::SetVisible(bool value)
	{
		if (mVisible == value) return;
		mVisible = value;

		if (mInheritsVisible)
		{
			for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
				(*skin)->SetVisible(value);
			for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget)
				(*widget)->_setInheritsVisible(value);
			for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget)
				(*widget)->_setInheritsVisible(value);
		}

	}

	void Widget::_setInheritsVisible(bool value)
	{
		if (mInheritsVisible == value) return;
		mInheritsVisible = value;

		if (mVisible)
		{
			for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
				(*skin)->SetVisible(value);
			for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget)
				(*widget)->_setInheritsVisible(value);
			for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget)
				(*widget)->_setInheritsVisible(value);
		}
	}

	void Widget::SetEnabled(bool value)
	{
		if (mEnabled == value) return;
		mEnabled = value;

		if (mInheritsEnabled)
		{
			for (VectorWidgetPtr::iterator iter = mWidgetChild.begin(); iter != mWidgetChild.end(); ++iter)
				(*iter)->_setInheritsEnable(value);
			for (VectorWidgetPtr::iterator iter = mWidgetChildSkin.begin(); iter != mWidgetChildSkin.end(); ++iter)
				(*iter)->_setInheritsEnable(value);

			BaseUpdateEnable();
		}

		if (!mEnabled)
		{
			InputManager::GetInstance().UnlinkWidget(this);
		}
	}

	void Widget::_setInheritsEnable(bool value)
	{
		if (mInheritsEnabled == value) return;
		mInheritsEnabled = value;

		if (mEnabled)
		{
			for (VectorWidgetPtr::iterator iter = mWidgetChild.begin(); iter != mWidgetChild.end(); ++iter)
				(*iter)->_setInheritsEnable(value);
			for (VectorWidgetPtr::iterator iter = mWidgetChildSkin.begin(); iter != mWidgetChildSkin.end(); ++iter)
				(*iter)->_setInheritsEnable(value);

			BaseUpdateEnable();
		}

		if (!mEnabled)
		{
			InputManager::GetInstance().UnlinkWidget(this);
		}
	}

	void Widget::SetColour(const Colour& value)
	{
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
		{
			ISubWidgetRect* rect = (*skin)->CastType<ISubWidgetRect>(false);
			if (rect)
				rect->_setColour(value);
		}
	}

} // namespace GUI


