#ifndef __FACTORY_MANAGER_H__
#define __FACTORY_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"
#include "IObject.h"
#include "GenericFactory.h"

namespace GUI
{

	class GUI_EXPORT FactoryManager
	{
		INSTANCE_HEADER(FactoryManager)

	public:
		typedef delegates::CDelegate1<IObject*&> Delegate;

		void Initialise();
		void Shutdown();

		void RegisterFactory(const std::string& category, const std::string& type, Delegate::IDelegate* delegate);
		void UnregisterFactory(const std::string& category, const std::string& type);
		void UnregisterFactory(const std::string& category);

		bool IsFactoryExist(const std::string& category, const std::string& type);

		template<typename Type>
		void RegisterFactory(const std::string& category)
		{
			RegisterFactory(category, Type::GetClassTypeName(), GenericFactory<Type>::GetFactory());
		}

		template<typename Type>
		void RegisterFactory(const std::string& category, const std::string& type)
		{
			RegisterFactory(category, type, GenericFactory<Type>::GetFactory());
		}

		template<typename Type>
		void UnregisterFactory(const std::string& category)
		{
			UnregisterFactory(category, Type::GetClassTypeName());
		}

		IObject* CreateObject(const std::string& category, const std::string& type);
		void DestroyObject(IObject* object);

	private:
		typedef std::map<std::string, Delegate> MapFactoryItem;
		typedef std::map<std::string, MapFactoryItem> MapRegisterFactoryItem;
		MapRegisterFactoryItem mRegisterFactoryItems;
	};

} // namespace GUI

#endif // __FACTORY_MANAGER_H__
