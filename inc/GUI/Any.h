#ifndef __ANY_H__
#define __ANY_H__

#include "Prerequest.h"
#include "Diagnostic.h"
#include <algorithm>
#include <typeinfo>

namespace GUI
{

	/** @example "Class Any usage"
	@code
	void F()
	{
		// EN: test class, with simple types all is similar
		struct Data { int value; };

		// EN: instance and initialization
		Data data;
		data.value = 0xDEAD;

		// EN: copy of class Data will be created
		GUI::Any any = data;
		// EN: copy of class Data
		Data copy_data = *any.CastType<Data>();
		// EN: now value == 0xDEAD
		int value = copy_data.value;


		// EN: copy of pointer on class Data will be created
		any = &data;
		// EN: copy of pointer on class Data and on object data
		Data * copy_ptr = *any.CastType<Data*>();
		// EN: now value == 0
		copy_ptr->value = 0;

	}
	@endcode
	*/

	class GUI_EXPORT Any
	{

	private:
		struct AnyEmpty { };

	public:
		static AnyEmpty Null;

	public:
		Any() :
			mContent(nullptr)
		{
		}

		template<typename ValueType> Any(const ValueType& value) :
			mContent(new Holder<ValueType>(value))
		{
		}

		Any(const Any::AnyEmpty& value) :
			mContent(nullptr)
		{
		}

		Any(const Any& other) :
			mContent(other.mContent ? other.mContent->Clone() : nullptr)
		{
		}

		~Any()
		{
			delete mContent;
		}

		Any& Swap(Any& rhs)
		{
			std::swap(mContent, rhs.mContent);
			return *this;
		}

		template<typename ValueType> Any& operator = (const ValueType& rhs)
		{
			Any(rhs).Swap(*this);
			return *this;
		}

		Any& operator = (const Any::AnyEmpty& rhs)
		{
			delete mContent;
			mContent = nullptr;
			return *this;
		}

		Any& operator = (const Any& rhs)
		{
			Any(rhs).Swap(*this);
			return *this;
		}

		bool empty() const
		{
			return !mContent;
		}

		const std::type_info& GetType() const
		{
			return mContent ? mContent->GetType() : typeid(void);
		}

		template<typename ValueType>
		ValueType * CastType(bool _throw = true) const
		{
			if (this->GetType() == typeid(ValueType))
			{
				return &static_cast<Any::Holder<ValueType> *>(this->mContent)->held;
			}
			ASSERT(!_throw, "Bad cast from type '" << GetType().name() << "' to '" << typeid(ValueType).name() << "'");
			return nullptr;
		}

		void * CastUnsafe() const
		{
			return mContent ? static_cast<Any::Holder<void *> *>(this->mContent)->held : nullptr;
		}

	private:
		class Placeholder
		{
		public:
			virtual ~Placeholder() { }

		public:
			virtual const std::type_info& GetType() const = 0;
			virtual Placeholder * Clone() const = 0;

		};

		template<typename ValueType> class Holder : public Placeholder
		{
		public:
			Holder(const ValueType& value) :
				held(value)
			{
			}

		public:
			virtual const std::type_info& GetType() const
			{
				return typeid(ValueType);
			}

			virtual Placeholder * Clone() const
			{
				return new Holder(held);
			}

		public:
			ValueType held;

		private:
			Holder& operator=(const Holder &);

		};


		private: // representation
			Placeholder * mContent;

	};

} // namespace GUI

#endif // __ANY_H__
