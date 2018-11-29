#ifndef __I_STATE_INFO_H__
#define __I_STATE_INFO_H__

#include "Prerequest.h"
#include "ISerializable.h"

namespace GUI
{

	class GUI_EXPORT IStateInfo : public ISerializable
	{
		RTTI_DERIVED(IStateInfo)

	public:
		virtual ~IStateInfo() { }

	};

	typedef std::vector<IStateInfo*> VectorStateInfo;
	typedef std::map<std::string, IStateInfo*> MapStateInfo;
	typedef std::map<std::string, VectorStateInfo> MapWidgetStateInfo;

} // namespace GUI

#endif // __I_STATE_INFO_H__
