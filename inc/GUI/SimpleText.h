#ifndef __SIMPLE_TEXT_H__
#define __SIMPLE_TEXT_H__

#include "Prerequest.h"
#include "XmlDocument.h"
#include "Types.h"
#include "ISubWidgetText.h"
#include "EditText.h"

namespace GUI
{

	class GUI_EXPORT SimpleText : public EditText
	{
		RTTI_DERIVED(SimpleText)

	public:
		SimpleText();
		virtual ~SimpleText();

		virtual void SetViewOffset(const IntPoint& point);

		virtual void DoRender();

	};

} // namespace GUI

#endif // __SIMPLE_TEXT_H__
