#pragma once

#include <string>
#include "script/ScriptUnit.h"

class B: public CScriptObject
{
public:
	//@ExportToLua
	B():m_b(0)
	{
	}
	//@ExportToLua
	virtual ~B()
	{
	}

	//@ExportToLua
	void DDDD(int mj)
	{
		m_b = 66666;
	}

	virtual const char* GetModuleName() const
	{
		static std::string moduleName = "B";
		return moduleName.c_str();
	}

	virtual void* GetThis(const char* className = NULL)
	{
		if (className == NULL)
		{
			return this;
		}
		return _getThis(className);
	}

	void* _getThis(const char* className)
	{
		if (strcmp(className, B::GetModuleName()) == 0)
		{
			return this;
		}
		return CScriptObject::_getThis(className);
	}

	//@ExportToLua
	void setB(int v)
	{
		m_b = v;
	} 
	//@ExportToLua
	int getB()
	{
		return m_b;
	}

	virtual void* GetThis()
	{
		return this;
	}

	int m_b;
};