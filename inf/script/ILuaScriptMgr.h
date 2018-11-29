#pragma once

#include <memory.h>
#include <string>
#include "common/Macro.h"

extern "C"
{
	#include "lua/lua.h"
	#include "lua/lualib.h"
	#include "lua/lauxlib.h"
	#include "tolua++/toLua++.h"
}

struct lua_State;

class CLuaParam
{
public:
	void operator = (int nValue)
	{
		m_nDataType = LUA_TNUMBER;
		memcpy(m_szValue, &nValue, sizeof(int));
	}

	void operator = (const char* pszValue)
	{
		m_nDataType = LUA_TSTRING;
		strncpy(m_szValue, pszValue, sizeof(m_szValue) - 1);
	}

	void operator = (const void* pValue)
	{
		m_nDataType = LUA_TLIGHTUSERDATA;		
		memcpy(m_szValue, &pValue, sizeof(void*));
	}

	operator const char*(void)
	{
		return m_szValue;
	}

	operator int(void)
	{
		return*((int*)m_szValue);
	}

	operator void*(void)
	{
		return (void*)(* (int*) m_szValue);
	}

	int GetDataType(void)
	{
		return m_nDataType;
	}

	~CLuaParam(void)
	{
		m_nDataType = LUA_TNUMBER;
		memset(m_szValue, 0, sizeof(m_szValue));
	}

private:
	int				m_nDataType;
	/// 动态生成不好，调用频繁，容易产品内存碎片
	char			m_szValue[1024];	
};

struct ILuaScriptMgr
{
	virtual void			Release(void) = 0;
	virtual lua_State*		GetLuaState(void) = 0;	
	virtual bool			LoadLuaFile(const char* szLuaFileName) = 0;
	virtual bool			RunMemoryLua(const char* pLuaData, int nDataLen = 0) = 0;
	virtual bool			ExcLuaFunction(int iSelf, const std::string& strFunctionName, CLuaParam* pInParam = 0, int nInNum = 0, CLuaParam* pOutParam = 0, int nOutNum = 0) = 0;
	virtual bool			RunLuaFunction(int iSelf, const std::string& strFunctionName, const char* szFmt = "", ...) = 0;
	virtual bool			PushLuaFunction(const std::string& strLbName) = 0;
	virtual const char*		GetLastError(void) = 0;
	virtual void			SetLastError(const char* szFmt, ...) = 0;
};

extern ILuaScriptMgr* g_ILuaScriptMgr;
///////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(_LIB)
	#pragma comment(lib, MakeLibname(Script))
	extern "C" ILuaScriptMgr* GlobalLuaEngine(bool);
	#define	CreateLuaScriptProc	GlobalLuaEngine
#else
	//typedef  ICLuaScript* (RKT_CDECL*procCreateLuaEngine)(bool);
	//#define	CreateLuaScriptProc	rkt::DllApi<procCreateLuaEngine>::load(MAKE_DLL_NAME(LuaEngine), "GlobalLuaEngine")
#endif
