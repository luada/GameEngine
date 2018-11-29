#include "Precompiled.h"
#include "Message.h"
#include "ResourceSkin.h"
#include "WidgetManager.h"
#include "LayerManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "Gui.h"
#include "ControllerManager.h"
#include "StaticImage.h"
#include "LanguageManager.h"

namespace GUI
{

	const float MESSAGE_ALPHA_MAX = 0.5f;
	const float MESSAGE_ALPHA_MIN = 0.0f;
	const float MESSAGE_SPEED_COEF = 3.0f;

	Message::Message() :
		mWidgetText(nullptr),
		mInfoOk(MessageBoxStyle::None),
		mInfoCancel(MessageBoxStyle::None),
		mSmoothShow(false),
		mWidgetFade(nullptr),
		mIcon(nullptr),
		mLeftOffset1(0),
		mLeftOffset2(0)
	{
	}

	void Message::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	Message::~Message()
	{
		ShutdownWidgetSkin();
	}

	void Message::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void Message::InitialiseWidgetSkin(ResourceSkin* info)
	{
		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			if (*(*iter)->_getInternalData<std::string>() == "Text")
			{
				DEBUG_ASSERT( ! mWidgetText, "widget already assigned");
				mWidgetText = (*iter);
				mOffsetText.Set(mCoord.width - mWidgetText->GetWidth(), mCoord.height - mWidgetText->GetHeight());
				mLeftOffset2 = mLeftOffset1 = mWidgetText->GetLeft();
			}
			else if (*(*iter)->_getInternalData<std::string>() == "Icon")
			{
				DEBUG_ASSERT( ! mIcon, "widget already assigned");
				mIcon = (*iter)->CastType<StaticImage>();
			}
		}
		//ASSERT(nullptr != mWidgetText, "Child Text not found in Skin (MessageBox must have widget for text)");

		if (mIcon != nullptr)
		{
			mLeftOffset2 = mIcon->GetRight() + 3;
		}

		const MapString& properties = info->GetProperties();
		if (!properties.empty())
		{
			MapString::const_iterator iter = properties.find("ButtonSkin");
			if (iter != properties.end()) mButtonSkin = iter->second;
			iter = properties.find("ButtonType");
			if (iter != properties.end()) mButtonType = iter->second;
			iter = properties.find("ButtonSize");
			if (iter != properties.end()) mButtonSize = IntSize::Parse(iter->second);
			iter = properties.find("ButtonOffset");
			if (iter != properties.end()) mButtonOffset = IntSize::Parse(iter->second);
			iter = properties.find("DefaultLayer");
			if (iter != properties.end()) mDefaultLayer = iter->second;
			iter = properties.find("FadeSkin");
			if (iter != properties.end()) mFadeSkin = iter->second;
			iter = properties.find("FadeLayer");
			if (iter != properties.end()) mFadeLayer = iter->second;
		}

	}

	void Message::ShutdownWidgetSkin()
	{
		mWidgetText = nullptr;
		mIcon = nullptr;
	}

	void Message::SetMessageText(const UString& message)
	{
		if (mWidgetText != nullptr)
			mWidgetText->SetCaption(message);
		UpdateSize();
	}

	MessageBoxStyle Message::AddButtonName(const UString& name)
	{
		//FIXME
		if (mVectorButton.size() >= MessageBoxStyle::_CountUserButtons)
		{
			LOG(warning, "Too many buttons in message box, ignored");
			return MessageBoxStyle::None;
		}
		MessageBoxStyle info = MessageBoxStyle(MessageBoxStyle::Enum(FLAG(mVectorButton.size() + MessageBoxStyle::_IndexUserButton1)));

		if (mVectorButton.empty()) mInfoOk = info;
		mInfoCancel = info;

		Widget* button = CreateWidgetT(mButtonType, mButtonSkin, IntCoord(), Align::Left | Align::Bottom);
		button->eventMouseButtonClick = NewDelegate(this, &Message::NotifyButtonClick);
		button->SetCaption(name);
		button->_setInternalData(info);
		mVectorButton.push_back(button);

		UpdateSize();
		return info;
	}

	void Message::SetMessageIcon(MessageBoxStyle icon)
	{
		if (nullptr == mIcon) return;
		if (mIcon->GetItemResource() != nullptr)
		{
			mIcon->SetItemName( GetIconName(icon.GetIconIndex()) );
		}
		else
		{
			mIcon->SetImageIndex(icon.GetIconIndex());
		}

		UpdateSize();
	}

	void Message::SetMessageButton(MessageBoxStyle info)
	{
		ClearButton();

		std::vector<MessageBoxStyle> buttons = info.GetButtons();

		for (size_t index=0; index<buttons.size(); ++index)
		{
			MessageBoxStyle curInfo = buttons[index];

			AddButtonName(GetButtonName(curInfo));

			mVectorButton.back()->_setInternalData(curInfo);

			if (mVectorButton.size() == 1) mInfoOk = curInfo;
			mInfoCancel = curInfo;
		}

		UpdateSize();
	}

	void Message::SetMessageStyle(MessageBoxStyle style)
	{
		SetMessageButton(style);
		SetMessageIcon(style);
	}

	void Message::NotifyButtonClick(GUI::Widget* sender)
	{
		_destroyMessage(*sender->_getInternalData<MessageBoxStyle>());
	}

	void Message::ClearButton()
	{
		for (VectorWidgetPtr::iterator iter=mVectorButton.begin(); iter!=mVectorButton.end(); ++iter)
		{
			WidgetManager::GetInstance().DestroyWidget(*iter);
		}
		mVectorButton.clear();
	}

	void Message::OnKeyButtonPressed(KeyCode key, Char _char)
	{
		Base::OnKeyButtonPressed(key, _char);
		if ((key == KeyCode::Return) || (key == KeyCode::NumpadEnter)) _destroyMessage(mInfoOk);
		else if (key == KeyCode::Escape) _destroyMessage(mInfoCancel);
	}

	void Message::_destroyMessage(MessageBoxStyle result)
	{
		eventMessageBoxResult(this, result);
		if (nullptr != mWidgetFade)
		{
			if (mSmoothShow)
			{
				ControllerFadeAlpha* controller = CreateControllerFadeAlpha(MESSAGE_ALPHA_MIN, MESSAGE_SPEED_COEF, false);
				controller->eventPostAction = NewDelegate(Action::ActionWidgetDestroy);
				ControllerManager::GetInstance().AddItem(mWidgetFade, controller);
			}
			else
			{
				WidgetManager::GetInstance().DestroyWidget(mWidgetFade);
			}
		}
		if (mSmoothShow) DestroySmooth();
		else WidgetManager::GetInstance().DestroyWidget(this);
	}

	void Message::SetSmoothShow(bool smooth)
	{
		mSmoothShow = smooth;
		if (mSmoothShow)
		{
			SetAlpha(ALPHA_MIN);
			SetVisible(true);
			SetVisibleSmooth(true);
		}
	}

	void Message::SetWindowFade(bool fade)
	{
		return; 

		if (fade)
		{
			if (nullptr == mWidgetFade)
			{
				Gui& gui = Gui::GetInstance();
				mWidgetFade = gui.CreateWidgetT(Widget::GetClassTypeName(), mFadeSkin, IntCoord(0, 0, gui.GetViewSize().width, gui.GetViewSize().height), Align::Stretch, mFadeLayer);
				if (mSmoothShow)
				{
					mWidgetFade->SetVisible(false);

					ControllerFadeAlpha* controller = CreateControllerFadeAlpha(MESSAGE_ALPHA_MAX, MESSAGE_SPEED_COEF, false);
					ControllerManager::GetInstance().AddItem(mWidgetFade, controller);
				}
				else
				{
					mWidgetFade->SetAlpha(MESSAGE_ALPHA_MAX);
				}
			}
		}
		else
		{
			if (nullptr != mWidgetFade)
			{
				WidgetManager::GetInstance().DestroyWidget(mWidgetFade);
				mWidgetFade = nullptr;
			}
		}
	}

	const char * Message::GetIconName(size_t index)
	{
		static const size_t CountIcons = 4;
		static const char * IconNames[CountIcons + 1] = { "Info", "Quest", "Error", "warning", "" };
		if (index >= CountIcons) return IconNames[CountIcons];
		return IconNames[index];
	}

	GUI::Message* Message::CreateMessageBox(const std::string& skin,
		const UString& caption,
		const UString& message,
		MessageBoxStyle style,
		const std::string& layer,
		bool modal,
		const std::string& button1,
		const std::string& button2,
		const std::string& button3,
		const std::string& button4)
	{
		Message* mess = Gui::GetInstance().CreateWidget<Message>(skin, IntCoord(), Align::Default, layer);

		mess->SetCaption(caption);
		mess->SetMessageText(message);

		mess->SetSmoothShow(true);
		if (modal) mess->SetWindowFade(true);

		mess->SetMessageStyle(style);

		if (!button1.empty())
		{
			mess->AddButtonName(button1);
			if (!button2.empty())
			{
				mess->AddButtonName(button2);
				if (!button3.empty())
				{
					mess->AddButtonName(button3);
				}
			}
		}

		if (layer.empty()) LayerManager::GetInstance().AttachToLayerNode(mess->GetDefaultLayer(), mess);
		if (modal) InputManager::GetInstance().AddWidgetModal(mess);

		return mess;
	}

	void Message::UpdateSize()
	{
		ISubWidgetText* text = nullptr;
		if (mWidgetText != nullptr)
			text = mWidgetText->GetSubWidgetText();
		IntSize size = text == nullptr ? IntSize() : text->GetTextSize();
		if ((nullptr != mIcon) && (mIcon->GetImageIndex() != ITEM_NONE))
		{
			if (size.height < mIcon->GetHeight()) size.height = mIcon->GetHeight();
			size.width += mIcon->GetSize().width;
		}
		size += mOffsetText;
		size.width += 3;

		int width = ((int)mVectorButton.size() * mButtonSize.width) + (((int)mVectorButton.size()+1) * mButtonOffset.width);
		if (size.width < width) size.width = width;

		int offset = (size.width - width)/2;
		offset += mButtonOffset.width;

		const IntSize& view = Gui::GetInstance().GetViewSize();
		SetCoord((view.width-size.width)/2, (view.height-size.height)/2, size.width, size.height);

		if (nullptr != mIcon)
		{
			if (mWidgetText != nullptr)
			{
				if (mIcon->GetImageIndex() != ITEM_NONE) mWidgetText->SetCoord(mLeftOffset2, mWidgetText->GetTop(), mWidgetText->GetWidth(), mWidgetText->GetHeight());
				else mWidgetText->SetCoord(mLeftOffset1, mWidgetText->GetTop(), mWidgetText->GetWidth(), mWidgetText->GetHeight());
			}
		}

		for (VectorWidgetPtr::iterator iter=mVectorButton.begin(); iter!=mVectorButton.end(); ++iter)
		{
			(*iter)->SetCoord(offset, mCoord.height - mButtonOffset.height, mButtonSize.width, mButtonSize.height);
			offset += mButtonOffset.width + mButtonSize.width;
		}
	}

	ControllerFadeAlpha* Message::CreateControllerFadeAlpha(float alpha, float coef, bool enable)
	{
		ControllerItem* item = ControllerManager::GetInstance().CreateItem(ControllerFadeAlpha::GetClassTypeName());
		ControllerFadeAlpha* controller = item->CastType<ControllerFadeAlpha>();

		controller->SetAlpha(alpha);
		controller->SetCoef(coef);
		controller->SetEnabled(enable);

		return controller;
	}

	void Message::SetMessageModal(bool value)
	{
		if (value) InputManager::GetInstance().AddWidgetModal(this);
		else InputManager::GetInstance().RemoveWidgetModal(this);
	}

	UString Message::GetButtonName(MessageBoxStyle style)
	{
		size_t index = style.GetButtonIndex();
		const char* tag = GetButtonTag(index);
		UString result = LanguageManager::GetInstance().ReplaceTags(utility::ToString("#{", tag, "}"));
		if (result == tag) return GetButtonName(index);
		return result;
	}

	const char * Message::GetButtonName(size_t index)
	{
		static const size_t Count = 9;
		static const char * Names[Count + 1] = { "Ok", "Yes", "No", "Abort", "Retry", "Ignore", "Cancel", "Try", "Continue", "" };
		if (index >= Count) return Names[Count];
		return Names[index];
	}

	const char * Message::GetButtonTag(size_t index)
	{
		static const size_t Count = 9;
		static const char * Names[Count + 1] = { "MessageBox_Ok", "MessageBox_Yes", "MessageBox_No", "MessageBox_Abort", "MessageBox_Retry", "MessageBox_Ignore", "MessageBox_Cancel", "MessageBox_Try", "MessageBox_Continue", "" };
		if (index >= Count) return Names[Count];
		return Names[index];
	}

	void Message::endMessage(MessageBoxStyle result)
	{
		_destroyMessage(result);
	}

	void Message::endMessage()
	{
		_destroyMessage(mInfoCancel);
	}

	void Message::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "Message_Caption") SetCaption(value);
		else if (key == "Message_Message") SetMessageText(value);
		else if (key == "Message_Modal") SetMessageModal(utility::ParseValue<bool>(value));
		else if (key == "Message_Button") SetMessageButton(utility::ParseValue<MessageBoxStyle>(value));
		else if (key == "Message_AddButton") AddButtonName(value);
		else if (key == "Message_SmoothShow") SetSmoothShow(utility::ParseValue<bool>(value));
		else if (key == "Message_Fade") SetWindowFade(utility::ParseValue<bool>(value));
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

} // namespace GUI


