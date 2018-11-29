#include "script/ILuaScriptMgr.h"
#include "A.h"

ILuaScriptMgr* g_pLuaScriptMgr = NULL;

TOLUA_API int tolua_Test_open (lua_State* tolua_S);
TOLUA_API int tolua_script_open (lua_State* tolua_S);

int tolua_main_open(lua_State* tolua_S)
{
	tolua_script_open (tolua_S);
	tolua_Test_open(tolua_S);
	return 0;
}

namespace T
{
	static CScriptObject* s_obj;

	void AddObj(CScriptObject* obj)
	{
		s_obj = obj;
	}

	CScriptObject* GetObj()
	{
		return s_obj;
	}
}

void main()
{
	
	g_pLuaScriptMgr = CreateLuaScriptProc(1);
	g_pLuaScriptMgr->LoadLuaFile("test.lua");

	T::A* a = new T::A();
	a->CreateScriptObj("AA");
	AddObj(a);

	g_pLuaScriptMgr->LoadLuaFile("test1.lua");

	CLuaParam tick;
	tick = 1234;
	g_pLuaScriptMgr->ExcLuaFunction(LUA_NOREF, "update", &tick, 1);
	g_pLuaScriptMgr->Release();

	void* ptr = new T::A();
	CScriptObject* ptrMM = (CScriptObject*) ptr;
	void* ptrC = ptrMM->GetThis("C");
	void* ptrB = ptrMM->GetThis("B");
	void* ptrTA = ptrMM->GetThis("T::A");
	void* ptroo = ptrMM->GetThis("oo");
	return;
} 