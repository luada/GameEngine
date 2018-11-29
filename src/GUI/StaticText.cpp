#include "Precompiled.h"
#include "StaticText.h"

namespace GUI
{

	StaticText::StaticText()
	{
	}

	void StaticText::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	StaticText::~StaticText()
	{
		ShutdownWidgetSkin();
	}

	void StaticText::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void StaticText::InitialiseWidgetSkin(ResourceSkin* info)
	{
		const MapString& properties = info->GetProperties();
		if (!properties.empty())
		{
			MapString::const_iterator iter = properties.end();
			if ((iter = properties.find("FontName")) != properties.end()) SetFontName(iter->second);
			if ((iter = properties.find("FontHeight")) != properties.end()) SetFontHeight(utility::ParseInt(iter->second));
			if ((iter = properties.find("TextAlign")) != properties.end()) SetTextAlign(Align::Parse(iter->second));
			if ((iter = properties.find("TextColour")) != properties.end()) SetTextColour(Colour::Parse(iter->second));
		}
	}

	void StaticText::ShutdownWidgetSkin()
	{
	}

	IntCoord StaticText::GetTextRegion()
	{
		return (nullptr == mText) ? IntCoord() : mText->GetCoord();
	}

	IntSize StaticText::GetTextSize()
	{
		return (nullptr == mText) ? IntSize() : mText->GetTextSize();
	}

	void StaticText::SetTextAlign(Align align)
	{
		if (mText != nullptr) mText->SetTextAlign(align);
	}

	Align StaticText::GetTextAlign()
	{
		if (mText != nullptr) return mText->GetTextAlign();
		return Align::Default;
	}

	void StaticText::SetTextColour(const Colour& colour)
	{
		if (nullptr != mText) mText->SetTextColour(colour);
	}

	const Colour& StaticText::GetTextColour()
	{
		return (nullptr == mText) ? Colour::Zero : mText->GetTextColour();
	}

	void StaticText::SetFontName(const std::string& font)
	{
		if (nullptr != mText) mText->SetFontName(font);
	}

	const std::string& StaticText::GetFontName()
	{
		if (nullptr == mText)
		{
			static std::string empty;
			return empty;
		}
		return mText->GetFontName();
	}

	void StaticText::SetFontHeight(int height)
	{
		if (nullptr != mText) mText->SetFontHeight(height);
	}

	int StaticText::GetFontHeight()
	{
		return (nullptr == mText) ? 0 : mText->GetFontHeight();
	}

	void StaticText::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "Text_TextColour") SetTextColour(utility::ParseValue<Colour>(value));
		else if (key == "Text_TextAlign") SetTextAlign(utility::ParseValue<Align>(value));
		else if (key == "Text_FontName") SetFontName(value);
		else if (key == "Text_FontHeight") SetFontHeight(utility::ParseValue<int>(value));
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

} // namespace GUI

