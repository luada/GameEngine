#ifndef __I_WIDGET_FACTORY_H__
#define __I_WIDGET_FACTORY_H__

#include "Prerequest.h"
#include "Types.h"
#include "WidgetStyle.h"
#include "WidgetDefines.h"
#include "ICroppedRectangle.h"

#include "WidgetManager.h"
#include "SkinManager.h"

namespace GUI
{

	//OBSOLETE
	class GUI_EXPORT IWidgetFactory
	{
	public:
		virtual ~IWidgetFactory() { }

		virtual const std::string& GetTypeName() = 0;
		virtual Widget* CreateWidget(WidgetStyle style, const std::string& skin, const IntCoord& coord, Align align, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name) = 0;
	};

	namespace factory
	{

		//OBSOLETE
		template <typename T>
		class GUI_EXPORT BaseWidgetFactory : public IWidgetFactory
		{
		public:
			BaseWidgetFactory()
			{
				GUI::WidgetManager& manager = GUI::WidgetManager::GetInstance();
				manager.RegisterFactory(this);
			}

			~BaseWidgetFactory()
			{
				GUI::WidgetManager& manager = GUI::WidgetManager::GetInstance();
				manager.UnregisterFactory(this);
			}

			const std::string& GetTypeName()
			{
				return T::GetClassTypeName();
			}

			Widget* CreateWidget(WidgetStyle style, const std::string& skin, const IntCoord& coord, Align align, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
			{
				T* instance = new T(style, coord, align, SkinManager::GetInstance().GetByName(skin), parent, croppedParent, creator, name);
				return instance;
			}

			bool IsFalseType(Widget* ptr, const std::string &_key)
			{
				if (!ptr->IsType<T>())
				{
					LOG(Error, "Property '" << _key << "' is not supported by '" << ptr->GetTypeName() << "' widget");
					return true;
				}
				return false;
			}
		};

	} // namespace factory
} // namespace GUI

#endif // __I_WIDGET_FACTORY_H__

