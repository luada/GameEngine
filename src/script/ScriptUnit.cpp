#include "ScriptUnit.h"
#include "LuaScriptMgr.h"

CScriptObject::~CScriptObject()
{
	if (m_scriptObjID != LUA_NOREF)
	{
		lua_unref(m_L, m_scriptObjID);
	}
}

CScriptObject::CScriptObject() :
	m_scriptObjID(LUA_NOREF)
{
	m_L = g_pLuaScriptMgr->GetLuaState();
}

void CScriptObject::SetScriptObjID(int objID)
{
	if (IsScriptObjValid())
	{
		lua_unref(m_L, m_scriptObjID);
	}
	m_scriptObjID = objID;
}

bool CScriptObject::CreateScriptObj(std::string scriptPath)
{
	std::string scriptFn;
	if (IsScriptObjValid())
	{
		//oldScriptObj:__onEngineObjLost()
		scriptFn = (m_scriptClass + ".__onEngineObjLost");
		if(!g_pLuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn))
		{
			//LOG<<g_pLuaScriptMgr->GetLastError();
		}
	}

	int splitIndex = scriptPath.rfind('/');
	if (splitIndex != std::string::npos)
	{
		const std::string moduleName = "require \"" + scriptPath.substr(0, splitIndex) + "\"";
		g_pLuaScriptMgr->RunMemoryLua(moduleName.c_str(), moduleName.length());
		m_scriptClass = scriptPath.substr(splitIndex + 1);
	}
	else
	{
		m_scriptClass = scriptPath;
	}

	//newScriptObj = NewScriptName.New() 
	int newScriptObjID = LUA_NOREF;
	scriptFn = m_scriptClass + ".New";
	if(!g_pLuaScriptMgr->RunLuaFunction(LUA_NOREF, scriptFn, ">r", &newScriptObjID))
	{
		SetScriptObjID(LUA_NOREF);
		//LOG<<g_pLuaScriptMgr->GetLastError();
		return false;
	}
	SetScriptObjID(newScriptObjID);

	//newScriptObj:__onEngineObjAttach(ref)
	scriptFn = m_scriptClass + ".__onEngineObjAttach";
	bool result = g_pLuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn, "o", this);

	return result;
}

bool CScriptObject::OnLoaded()
{
	bool result = true;  //default is true
	if (IsScriptObjValid())
	{
		std::string scriptFn = m_scriptClass + ".__onLoaded";
		result = g_pLuaScriptMgr->RunLuaFunction(GetScriptObjID(), scriptFn);
	}
	return result;
}


//----------------------------------------------------------------------------------------------------
CLuaTopStackRecover::CLuaTopStackRecover(lua_State* L):m_L(L)
{
	m_saveTopStack = m_L ? lua_gettop(m_L) : 0;
}

CLuaTopStackRecover::CLuaTopStackRecover()
{
	m_L = g_pLuaScriptMgr ? g_pLuaScriptMgr->GetLuaState() : NULL;
	m_saveTopStack = m_L ? lua_gettop(m_L) : 0;
}

CLuaTopStackRecover::~CLuaTopStackRecover()
{
	if (m_L)
	{
		lua_settop(m_L, m_saveTopStack);
	}
}

void CLuaTopStackRecover::DisableRecover()
{
	m_L = NULL;
}


//----------------------------------------------------------------------------------------------------
CLuaUserData::CLuaUserData(lua_State* L, void* value, const char* type):
	m_L(L), m_value(value), m_type(type)
{
	tolua_pushusertype(m_L, m_value, m_type);
	m_ref = luaL_ref(m_L, LUA_REGISTRYINDEX);
}

CLuaUserData::~CLuaUserData()
{
	luaL_unref(m_L, LUA_REGISTRYINDEX, m_ref);
}