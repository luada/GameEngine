#pragma once
 
#include "B.h"

class C: public B
{
public:
	//@ExportToLua
	C():m_c(0)
	{
	}
	//@ExportToLua
	~C()
	{

	}
	//@ExportToLua
	void setC(int v)
	{
		m_c = v;
	}
	//@ExportToLua
	int getC()
	{
		return m_c;
	}

	virtual const char* GetModuleName() const
	{
		static std::string moduleName = "C";
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
		if (strcmp(className, C::GetModuleName()) == 0)
		{
			return this;
		}
		return B::_getThis(className);
	}
	int m_c;
};