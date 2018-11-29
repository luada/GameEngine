#ifndef __BASE_LAYOUT_H__
#define __BASE_LAYOUT_H__

#include <GUI.h>
#include "WrapsAttribute.h"

namespace wraps
{

	class BaseLayout
	{
	protected:
		BaseLayout() : mMainWidget(nullptr)
		{
		}

		BaseLayout(const std::string& layout, GUI::WidgetPtr parent = nullptr) : mMainWidget(nullptr)
		{
			Initialise(layout, parent);
		}

		template <typename T>
		void AssignWidget(T * & widget, const std::string& name, bool bThrow = true)
		{
			widget = nullptr;
			for (GUI::VectorWidgetPtr::iterator iter=mListWindowRoot.begin(); iter!=mListWindowRoot.end(); ++iter)
			{
				GUI::WidgetPtr find = (*iter)->FindWidget(mPrefix + name);
				if (nullptr != find)
				{
					T * cast = find->CastType<T>(false);
					if (nullptr != cast)
					{
						widget = cast;
					}
					else if (bThrow)
					{
							EXCEPT("Error cast : dest type = '" << T::GetClassTypeName()
							<< "' source curName = '" << find->GetName()
							<< "' source type = '" << find->GetTypeName() << "' in layout '" << mLayoutName << "'");
					}
					return;

				}
			}
			ASSERT( ! bThrow, "widget curName '" << name << "' in layout '" << mLayoutName << "' not found.");
		}

		template <typename T>
		void AssignBase(T * & widget, const std::string& name, bool bThrow = true)
		{
			widget = nullptr;
			for (GUI::VectorWidgetPtr::iterator iter=mListWindowRoot.begin(); iter!=mListWindowRoot.end(); ++iter)
			{
				GUI::WidgetPtr find = (*iter)->FindWidget(mPrefix + name);
				if (nullptr != find)
				{
					widget = new T(find);
					mListBase.push_back(widget);
					return;
				}
			}
			ASSERT( ! bThrow, "widget curName '" << name << "' in layout '" << mLayoutName << "' not found.");
		}

		void Initialise(const std::string& layout, GUI::WidgetPtr parent = nullptr)
		{
			const std::string MAIN_WINDOW = "_Main";
			mLayoutName = layout;

			
			if (mLayoutName.empty())
			{
				mMainWidget = parent;
			}
			
			else
			{
				mPrefix = GUI::utility::ToString(this, "_");
				mListWindowRoot = GUI::LayoutManager::GetInstance().LoadLayout(mLayoutName, mPrefix, parent);

				const std::string main_name = mPrefix + MAIN_WINDOW;
				for (GUI::VectorWidgetPtr::iterator iter=mListWindowRoot.begin(); iter!=mListWindowRoot.end(); ++iter)
				{
					if ((*iter)->GetName() == main_name)
					{
						mMainWidget = (*iter);
						break;
					}
				}
				ASSERT(mMainWidget, "root widget name '" << MAIN_WINDOW << "' in curLayout '" << mLayoutName << "' not found.");
			}
		}

		void Shutdown()
		{
			
			for (VectorBasePtr::iterator iter=mListBase.begin(); iter!=mListBase.end(); ++iter)
			{
				delete (*iter);
			}
			mListBase.clear();

			
			GUI::LayoutManager::GetInstance().UnloadLayout(mListWindowRoot);
			mListWindowRoot.clear();
		}

		template <typename Type>
		void InitialiseByAttributes(Type* owner, GUI::WidgetPtr parent = nullptr)
		{
			Initialise(attribute::AttributeLayout<Type>::GetData(), parent);

			typename attribute::AttributeFieldWidgetName<Type>::VectorBindPair& data = attribute::AttributeFieldWidgetName<Type>::GetData();
			for (typename attribute::AttributeFieldWidgetName<Type>::VectorBindPair::iterator item=data.begin(); item!=data.end(); ++item)
			{
				GUI::Widget* value = 0;
				AssignWidget(value, item->second, false);

				item->first->Set(owner, value);
			}
		}

	public:
		virtual ~BaseLayout()
		{
			Shutdown();
		}

	protected:
		GUI::WidgetPtr mMainWidget;

	private:
		std::string mPrefix;
		std::string mLayoutName;
		GUI::VectorWidgetPtr mListWindowRoot;
		typedef std::vector<BaseLayout*> VectorBasePtr;
		VectorBasePtr mListBase;
	};

} // namespace wraps

#endif // __BASE_LAYOUT_H__
