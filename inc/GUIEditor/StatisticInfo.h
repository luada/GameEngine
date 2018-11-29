#ifndef __STATISTIC_INFO_H__
#define __STATISTIC_INFO_H__

#include <GUI.h>


namespace diagnostic
{

	class StatisticInfo
	{

	public:
		typedef std::pair<std::string, std::string> PairString;
		typedef std::vector<PairString> VectorPairString;

		StatisticInfo() :
			mInfo(nullptr)
		{
			const std::string layer = "Statistic";
			if ( ! GUI::LayerManager::GetInstance().IsExist(layer)) return;

			const std::string skin = "StatisticRect";
			if ( ! GUI::SkinManager::GetInstance().IsExist(skin)) return;

			mInfo = GUI::Gui::GetInstance().CreateWidget<GUI::StaticText>(skin, GUI::IntCoord(), GUI::Align::Default, layer);
		}

		~StatisticInfo()
		{
			if (mInfo)
			{
				GUI::Gui::GetInstance().DestroyChildWidget(mInfo);
				mInfo = nullptr;
			}
		}

		template <typename T>
		void Change(const std::string& key, const T & value)
		{
			for (VectorPairString::iterator iter=mParams.begin(); iter!=mParams.end(); ++iter)
			{
				if (iter->first == key)
				{
					iter->second = GUI::utility::ToString<T>(value);
					return;
				}
			}
			mParams.push_back(std::make_pair(key, GUI::utility::ToString<T>(value)));
		}

		void Remove(const std::string& key)
		{
			for (VectorPairString::iterator iter=mParams.begin(); iter!=mParams.end(); ++iter)
			{
				if (iter->first == key)
				{
					mParams.erase(iter);
					return;
				}
			}
		}

		void Update()
		{
			if (mInfo)
			{
				std::ostringstream stream;
				for (VectorPairString::iterator iter=mParams.begin(); iter!=mParams.end(); ++iter)
				{
					if (iter != mParams.begin()) stream << "\n";
					stream << iter->first << " : " << iter->second;
				}

				mInfo->SetCaption(stream.str());

				GUI::ISubWidgetText * text = mInfo->GetSubWidgetText();
				if (text)
				{
					const GUI::IntSize& size = text->GetTextSize() + mInfo->GetSize() - text->GetSize();
					const GUI::IntSize& size_view = GUI::Gui::GetInstance().GetViewSize();
					mInfo->SetCoord(size_view.width - size.width - 20, size_view.height - size.height - 20, size.width, size.height);
				}
			}
		}

		void Clear()
		{
			mParams.clear();
		}

		void Clear(const std::string& key)
		{
			for (VectorPairString::iterator iter=mParams.begin(); iter!=mParams.end(); ++iter)
			{
				if (iter->first == key)
				{
					mParams.erase(iter);
					return;
				}
			}
		}

		void SetVisible(bool value)
		{
			mInfo->SetVisible(value);
		}

	private:
		GUI::StaticTextPtr mInfo;
		VectorPairString mParams;

	};

} // namespace diagnostic

#endif // __STATISTIC_INFO_H__
