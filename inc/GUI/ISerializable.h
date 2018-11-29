#ifndef __I_SERIALIZABLE_H__
#define __I_SERIALIZABLE_H__

#include "Prerequest.h"
#include "IObject.h"
#include "XmlDocument.h"
#include "Version.h"

namespace GUI
{

	class GUI_EXPORT ISerializable : public IObject
	{
		RTTI_DERIVED(ISerializable)

	public:
		ISerializable() { }
		virtual ~ISerializable() { }

		virtual void Serialization(xml::ElementPtr node, Version version) { }
		virtual void Deserialization(xml::ElementPtr node, Version version) { }

	};

} // namespace GUI

#endif // __I_SERIALIZABLE_H__
