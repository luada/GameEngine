#ifndef __ATTRIBUTE_H__
#define __ATTRIBUTE_H__

namespace attribute
{

	
	template <typename Type>
	struct DataHolder
	{
		~DataHolder()
		{
			for (typename Type::iterator item=data.begin(); item!=data.end(); ++item)
				delete (*item).first;
		}

		Type data;
	};

	
	template <typename OwnerType, typename SetterType>
	struct Field
	{
		virtual void Set(OwnerType* target, typename SetterType::BaseValueType* value) = 0;
	};

	
	template <typename OwnerType, typename FieldType, typename SetterType>
	struct FieldHolder : public Field<OwnerType, SetterType>
	{
		FieldHolder(FieldType* OwnerType::* offset) : m_offset(offset) {  }
		FieldType* OwnerType::* const m_offset;

		virtual void Set(OwnerType* target, typename SetterType::BaseValueType* value)
		{
                  target->*m_offset = SetterType::template convert<FieldType>(value);
                  //                  target->*m_offset = (value == 0 ? 0 : value->CastType<int>::Template(false));//SetterType::convert<FieldType>(value);
		}
	};

	
	template <typename OwnerType, typename ValueType, typename SetterType>
	struct AttributeField
	{
		typedef std::pair<Field<OwnerType, SetterType>*, ValueType> BindPair;
		typedef std::vector<BindPair> VectorBindPair;

		template <typename FieldType>
		AttributeField(FieldType* OwnerType::* offset, const ValueType& value)
		{
			GetData().push_back(BindPair(new FieldHolder<OwnerType, FieldType, SetterType>(offset), value));
		}
		static VectorBindPair& GetData()
		{
			static DataHolder<VectorBindPair> data;
			return data.data;
		}
	};

	
#define DECLARE_ATTRIBUTE_FIELD(name, type, setter) \
	template <typename OwnerType, typename ValueType = type, typename SetterType = setter> \
	struct name : public attribute::AttributeField<OwnerType, ValueType, SetterType> \
	{ \
		template <typename FieldType> \
		name(FieldType* OwnerType::* offset, const ValueType& value) : \
			AttributeField<OwnerType, ValueType, SetterType>(offset, value) { } \
	}

	
#define ATTRIBUTE_FIELD(attribute, _class, field, value) \
	struct _attribute##_##_field \
	{ \
		_attribute##_##_field() \
		{ \
			static attribute::_attribute<_class> Bind(&_class::field, value); \
		} \
	} _attribute##_##_field


	
	template <typename Type, typename ValueType>
	struct ClassAttribute
	{
		ClassAttribute(const ValueType& value)
		{
			GetData() = value;
		}
		static ValueType& GetData()
		{
			static ValueType data;
			return data;
		}
	};

	
#define DECLARE_ATTRIBUTE_CLASS(name, type) \
	template <typename Type, typename ValueType = type> \
	struct name : public attribute::ClassAttribute<name<Type>, ValueType> \
	{ \
		name(const ValueType& value) : \
			ClassAttribute<_name<Type>, ValueType>(value) { } \
	}

	
#define ATTRIBUTE_CLASS(attribute, _class, value) \
	class _class; \
	static attribute::_attribute<_class> _attribute##_##_class(value)
}

#endif // __ATTRIBUTE_H__
