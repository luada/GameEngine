#include "Precompiled.h"
#include "Progress.h"
#include "ResourceSkin.h"
#include "Widget.h"
#include "Gui.h"
#include "SkinManager.h"

namespace GUI
{

	const size_t PROGRESS_AUTO_WIDTH = 200;
	const size_t PROGRESS_AUTO_RANGE = 1000;
	const float PROGRESS_AUTO_COEF = 400;

	Progress::Progress() :
		mTrackWidth(1),
		mTrackStep(0),
		mTrackMin(0),
		mRange(0),
		mStartPosition(0),
		mEndPosition(0),
		mAutoPosition(0.0f),
		mAutoTrack(false),
		mFillTrack(false),
		mStartPoint(Align::Left),
		mClient(nullptr)
	{
	}

	void Progress::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	Progress::~Progress()
	{
		ShutdownWidgetSkin();
	}

	void Progress::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void Progress::InitialiseWidgetSkin(ResourceSkin* info)
	{
		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			if (*(*iter)->_getInternalData<std::string>() == "Client")
			{
				DEBUG_ASSERT( ! mClient, "widget already assigned");
				mClient = (*iter);
			}
		}
		if (nullptr == mClient) mClient = this;

		const MapString& properties = info->GetProperties();
		MapString::const_iterator iterS = properties.find("TrackSkin");
		if (iterS != properties.end()) mTrackSkin = iterS->second;
		iterS = properties.find("TrackWidth");
		if (iterS != properties.end()) mTrackWidth = utility::ParseInt(iterS->second);
		iterS = properties.find("TrackMin");
		if (iterS != properties.end()) mTrackMin = utility::ParseInt(iterS->second);
		if (1 > mTrackWidth) mTrackWidth = 1;
		iterS = properties.find("TrackStep");
		if (iterS != properties.end()) mTrackStep = utility::ParseInt(iterS->second);
		else mTrackStep = mTrackWidth;
		iterS = properties.find("TrackFill");
		if (iterS != properties.end()) mFillTrack = utility::ParseBool(iterS->second);
		iterS = properties.find("StartPoint");
		if (iterS != properties.end()) SetProgressStartPoint(Align::Parse(iterS->second));

	}

	void Progress::ShutdownWidgetSkin()
	{
		mClient = nullptr;
	}

	void Progress::SetProgressRange(size_t range)
	{
		if (mAutoTrack) return;
		mRange = range;
		if (mEndPosition > mRange) mEndPosition = mRange;
		if (mStartPosition > mRange) mStartPosition = mRange;
		UpdateTrack();
	}

	void Progress::SetProgressPosition(size_t pos)
	{
		if (mAutoTrack) return;
		mEndPosition = pos;
		if (mEndPosition > mRange) mEndPosition = mRange;
		UpdateTrack();
	}

	void Progress::SetProgressAutoTrack(bool value)
	{
		if (mAutoTrack == value) return;
		mAutoTrack = value;

		if (mAutoTrack)
		{
			Gui::GetInstance().eventFrameStart += NewDelegate(this, &Progress::FrameEntered);
			mRange = PROGRESS_AUTO_RANGE;
			mEndPosition = mStartPosition = 0;
			mAutoPosition = 0.0f;
		}
		else
		{
			Gui::GetInstance().eventFrameStart -= NewDelegate(this, &Progress::FrameEntered);
			mRange = mEndPosition = mStartPosition = 0;
		}
		UpdateTrack();
	}

	void Progress::FrameEntered(float time)
	{
		if (!mAutoTrack) return;
		mAutoPosition += (PROGRESS_AUTO_COEF * time);
		size_t pos = (size_t)mAutoPosition;

		if (pos > (mRange + PROGRESS_AUTO_WIDTH)) mAutoPosition = 0.0f;

		if (pos > mRange) mEndPosition = mRange;
		else mEndPosition = size_t(mAutoPosition);

		if (pos < PROGRESS_AUTO_WIDTH) mStartPosition = 0;
		else mStartPosition = pos - PROGRESS_AUTO_WIDTH;

		UpdateTrack();
	}

	void Progress::SetPosition(const IntPoint& point)
	{
		Base::SetPosition(point);
	}

	void Progress::SetSize(const IntSize& size)
	{
		UpdateTrack();

		Base::SetSize(size);
	}

	void Progress::SetCoord(const IntCoord& coord)
	{
		UpdateTrack();

		Base::SetCoord(coord);
	}

	void Progress::UpdateTrack()
	{
		if ((0 == mRange) || (0 == mEndPosition))
		{
			for (VectorWidgetPtr::iterator iter=mVectorTrack.begin(); iter!=mVectorTrack.end(); ++iter)
			{
				(*iter)->SetVisible(false);
			}
			return;
		}

		if (mFillTrack)
		{
			if (mVectorTrack.empty())
			{
				Widget* widget = mClient->CreateWidget<Widget>(mTrackSkin, IntCoord(), Align::Left | Align::VStretch);
				mVectorTrack.push_back(widget);
			}
			else
			{
				VectorWidgetPtr::iterator iter=mVectorTrack.begin();
				(*iter)->SetVisible(true);
				(*iter)->SetAlpha(ALPHA_MAX);

				++iter;
				for (; iter!=mVectorTrack.end(); ++iter)
				{
					(*iter)->SetVisible(false);
				}
			}

			Widget* wid = mVectorTrack.front();

			if ((0 == mStartPosition) && (mRange == mEndPosition))
			{
				SetTrackPosition(wid, 0, 0, GetClientWidth(), GetClientHeight());
			}
			else
			{
				int pos = (int)mStartPosition * (GetClientWidth() - mTrackMin) / (int)mRange;
				SetTrackPosition(wid, pos, 0, ((int)mEndPosition * (GetClientWidth() - mTrackMin) / (int)mRange) - pos + mTrackMin, GetClientHeight());
			}

			return;
		}

		int width = GetClientWidth() - mTrackWidth + mTrackStep;
		int count = width / mTrackStep;
		int ost = (width % mTrackStep);
		if (ost > 0)
		{
			width += mTrackStep - ost;
			count ++;
		}

		while ((int)mVectorTrack.size() < count)
		{
			Widget* widget = mClient->CreateWidget<Widget>(mTrackSkin, IntCoord(/*(int)mVectorTrack.size() * mTrackStep, 0, mTrackWidth, GetClientHeight()*/), Align::Left | Align::VStretch);
			widget->SetVisible(false);
			mVectorTrack.push_back(widget);
		}

		if ((0 == mStartPosition) && (mRange == mEndPosition))
		{
			int pos = 0;
			for (VectorWidgetPtr::iterator iter=mVectorTrack.begin(); iter!=mVectorTrack.end(); ++iter)
			{
				(*iter)->SetAlpha(ALPHA_MAX);
				(*iter)->SetVisible(true);
				SetTrackPosition(*iter, pos * mTrackStep, 0, mTrackWidth, GetClientHeight());
				pos++;
			}
		}
		else
		{
			int hide_pix = (width * (int)mStartPosition / (int)mRange);
			int hide_count = hide_pix / mTrackStep;
			int show_pix = (width * (int)mEndPosition / (int)mRange);
			int show_count = show_pix / mTrackStep;

			int pos = 0;
			for (VectorWidgetPtr::iterator iter=mVectorTrack.begin(); iter!=mVectorTrack.end(); ++iter)
			{
				if (0 > show_count)
				{
					(*iter)->SetVisible(false);
				}
				else if (0 == show_count)
				{
					(*iter)->SetAlpha((float)(show_pix % mTrackStep) / (float)mTrackStep);
					(*iter)->SetVisible(true);
					SetTrackPosition(*iter, pos * mTrackStep, 0, mTrackWidth, GetClientHeight());
				}
				else
				{
					if (0 < hide_count)
					{
						(*iter)->SetVisible(false);
					}
					else if (0 == hide_count)
					{
						(*iter)->SetAlpha(1.0f - ((float)(hide_pix % mTrackStep) / (float)mTrackStep));
						(*iter)->SetVisible(true);
						SetTrackPosition(*iter, pos * mTrackStep, 0, mTrackWidth, GetClientHeight());
					}
					else
					{
						(*iter)->SetAlpha(ALPHA_MAX);
						(*iter)->SetVisible(true);
						SetTrackPosition(*iter, pos * mTrackStep, 0, mTrackWidth, GetClientHeight());
					}
				}
				hide_count --;
				show_count --;
				pos ++;
			}
		}
	}

	void Progress::SetTrackPosition(Widget* widget, int left, int top, int width, int height)
	{
		if (mStartPoint.IsLeft()) widget->SetCoord(left, top, width, height);
		else if (mStartPoint.IsRight()) widget->SetCoord(mClient->GetWidth() - left - width, top, width, height);
		else if (mStartPoint.IsTop()) widget->SetCoord(top, left, height, width);
		else if (mStartPoint.IsBottom()) widget->SetCoord(top, mClient->GetHeight() - left - width, height, width);
	}

	void Progress::SetProgressStartPoint(Align align)
	{
		if ((align == Align::Left) || (align == Align::Right) || (align == Align::Top) || (align == Align::Bottom))
		{
			mStartPoint = align;
		}
		else
		{
			mStartPoint = Align::Left;
			LOG(warning, "Progress bar support only Left, Right, Top or Bottom curAlign values");
		}
		UpdateTrack();
	}

	void Progress::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "Progress_Range") SetProgressRange(utility::ParseValue<size_t>(value));
		else if (key == "Progress_Position") SetProgressPosition(utility::ParseValue<size_t>(value));
		else if (key == "Progress_AutoTrack") SetProgressAutoTrack(utility::ParseValue<bool>(value));
		else if (key == "Progress_StartPoint") SetProgressStartPoint(utility::ParseValue<Align>(value));
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

} // namespace GUI

