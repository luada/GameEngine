#pragma once

class A
{
public:
	//@ExportToLua
	A()
	{
		m_a = 0;
	}
	//@ExportToLua
	~A()
	{
		m_a = -1;
	}
	//@ExportToLua
	void setA(int v)
	{
		m_a  = v;
	}
	//@ExportToLua
	int getA()
	{
		return m_a;
	}
	int m_a;
};


//@ExportToLua
void Set(int v)
{
	static int s_v;
	s_v = v;
}