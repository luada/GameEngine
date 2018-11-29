#pragma once

#include "script/ScriptUnit.h"
#include "script/LuaFunctor.h"
#include "IObject.h"
#include "B.h"
#include "c/C.h"

extern ILuaScriptMgr* g_pLuaScriptMgr;
 
namespace T
{
//@ExportToLua
extern CScriptObject* GetObj();


//template<typename T>
class CNT
{
	////////@TOLUA_TEMPLATE_BIND(T, T::A, B)
public:
	////@ExportToLua
	static CScriptObject* GetObjEx()
	{
		return (GetObj());
	}
};

class A: public C
{
public:
	//@ExportToLua
	A(): m_a(0) {}

	virtual ~A(){}

	//@ExportToLua
	void DDDD(int mj)
	{
		m_a = 66666;
	}
/*
	//@ExportToLua
	virtual void TestFn(int a)
	{
		std::string funName = m_scriptClass + ".onTest1"; 
		static LuaFunctor<TypeNull,int> onActionCallback(g_pLuaScriptMgr->GetLuaState(), funName.c_str());
		//onActionCallback(ScriptObjID(), NIL, 123);
		g_pLuaScriptMgr->RunLuaFunction(GetScriptObjID(), funName, "si>", "Luada", a);
		m_a = a;
	}
*/

	virtual const char* GetModuleName() const
	{
		static std::string moduleName = "T::A";
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
		if (strcmp(className, A::GetModuleName()) == 0)
		{
			return this;
		}
		return C::_getThis(className);
	}

	int m_a;
};

//@ExportToLua
CScriptObject* GetObj();

}