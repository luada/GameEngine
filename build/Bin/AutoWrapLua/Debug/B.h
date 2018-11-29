#pragma once

#include "A.h"
//#include "script/ScriptUnit.h"

class B: public A// , public ScriptUnit
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
	void setB(int v)
	{
		m_b = v;
	}
	//@ExportToLua
	int getB()
	{
		return m_b;
	}
	int m_b;
};