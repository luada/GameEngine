#pragma once

#include "script/ILuaScriptMgr.h"
#include <string>

class CScriptObject
{
public:
    CScriptObject();
    virtual ~CScriptObject();
    
	//@ExportToLua
	bool IsScriptObjValid(){ return m_scriptObjID != LUA_NOREF; }

	//@ExportToLua
	int  GetScriptObjID() const {  return m_scriptObjID; }

	//@ExportToLua
	void SetScriptObjID(int objID);

	//@ExportToLua
	bool CreateScriptObj(std::string scriptPath);

	//@ExportToLua
	void SetScriptClass(std::string scriptClass) { m_scriptClass = scriptClass; }

	//@ExportToLua
	const std::string& GetScriptClass() { return m_scriptClass; }

	virtual const char* GetModuleName() const = 0;
	virtual void* GetThis(const char* className = NULL) = 0;
	bool OnLoaded();

protected:
	void* _getThis(const char* className) { return NULL; }
	
protected:
	int m_scriptObjID;
	lua_State* m_L;
	std::string m_scriptClass;
};


class CLuaTopStackRecover
{
public:
	CLuaTopStackRecover(lua_State* L);
	CLuaTopStackRecover();
	~CLuaTopStackRecover();
	
	void DisableRecover();

private:
	lua_State* m_L;
	int m_saveTopStack;
};

class CLuaUserData
{
public:
	CLuaUserData(lua_State* L, void* data, const char* type);
	~CLuaUserData();
	operator int() const { return m_ref; }
	int Ref() const		 { return m_ref; }
private:
	lua_State*	m_L;
	int			m_ref;
	void*		m_value;
	const char* m_type;
};