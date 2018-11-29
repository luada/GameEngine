#ifndef __GENERIC_FACTORY_H__
#define __GENERIC_FACTORY_H__

#include "Prerequest.h"
#include "Types.h"
#include "Delegate.h"

namespace GUI
{

	template <typename Type>
	class GenericFactory
	{
	public:
		typedef delegates::CDelegate1<IObject*&> Delegate;
		static typename Delegate::IDelegate* GetFactory()
		{
			return NewDelegate(CreateFromFactory);
		}

	private:
		static void CreateFromFactory(IObject*& instance)
		{
			instance = new Type();
		}
	};

}

#endif // __GENERIC_FACTORY_H__
