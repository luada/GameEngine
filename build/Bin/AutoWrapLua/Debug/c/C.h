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
	int m_c;
};