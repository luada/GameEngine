#ifndef __WRAPS_ATTRIBUTE_H__
#define __WRAPS_ATTRIBUTE_H__

#include <GUI.h>
#include "Attribute.h"

namespace attribute
{

	struct FieldSetterWidget
	{
		typedef GUI::Widget BaseValueType;

		template <typename Type>
		static Type* Convert(BaseValueType* value)
		{
			return value == 0 ? 0 : value->CastType<Type>(false);
		}
	};

	DECLARE_ATTRIBUTE_FIELD(AttributeFieldWidgetName, std::string, FieldSetterWidget);

#define ATTRIBUTE_FIELD_WIDGET_NAME(class, field, value) \
	ATTRIBUTE_FIELD(AttributeFieldWidgetName, class, field, value)



	DECLARE_ATTRIBUTE_CLASS(AttributeSize, GUI::IntSize);

#define ATTRIBUTE_CLASS_SIZE(class, value) \
	ATTRIBUTE_CLASS(AttributeSize, class, value)


	DECLARE_ATTRIBUTE_CLASS(AttributeLayout, std::string);

#define ATTRIBUTE_CLASS_LAYOUT(class, value) \
	ATTRIBUTE_CLASS(AttributeLayout, class, value)

}

#endif // __WRAPS_ATTRIBUTE_H__
