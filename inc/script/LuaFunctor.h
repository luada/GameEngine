#pragma once

#include <string>
#include <vector>
#include <map>
#include "common/Any.h"

//Lua
extern "C"
{
	#include "lua/lua.h"
	#include "lua/lualib.h"
	#include "lua/lauxlib.h"
	#include "tolua++/toLua++.h"
}

#pragma warning(disable : 4083)
#pragma warning(disable : 4244)


#ifdef _LIB
	#define  LUASCRIPT_AIP
#else
	#ifdef LUASCRIPT_EXPORTS
		#define LUASCRIPT_AIP __declspec(dllexport)
	#else
		#define LUASCRIPT_AIP __declspec(dllimport)
	#endif
#endif


#ifdef LUA_FUNCTOR_IMPL
#define IMPL_TYPE
#else
#define IMPL_TYPE extern
#endif

LUASCRIPT_AIP int  PushMethod(lua_State* L, const std::string& handlerName);
LUASCRIPT_AIP bool FindMethod(lua_State* L, const std::string& handlerName);
LUASCRIPT_AIP bool GetPropValueFromLua(lua_State* L, CAny& value);

struct TypeLTable
{
	int self;
};

struct TypeNull{};
LUASCRIPT_AIP extern TypeNull NIL;

struct UserType
{
	void* m_pData;
	const char* m_pszTypeName;
	UserType(void* pData, const char* pszTypeName) : m_pData(pData), m_pszTypeName(pszTypeName) {};
};

struct NumTable
{
	const lua_Number* m_pData;
	short			m_nLen;
	NumTable(const lua_Number* pData, short nLen) : m_pData(pData), m_nLen(nLen) {};
};

struct StrTable
{
	const char**	m_pData;
	short			m_nLen;
	StrTable(const char** pData, short nLen) : m_pData(pData), m_nLen(nLen) {};
};

struct UserTypeTable
{
	void**		m_pData;
	short		m_nLen;
	const char* m_pszTypeName;
	UserTypeTable(void** pData, short nLen, const char* pszTypeName) : m_pData(pData), m_nLen(nLen), m_pszTypeName(m_pszTypeName) {};
};


///////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T> void PushParam(lua_State* L, T param)
{
	ASSERT(0);
}

template<> inline void PushParam(lua_State* L, UserTypeTable param)
{
	lua_newtable(L);
	for (int i=0; i<param.m_nLen; ++i) 
	{
		tolua_pushusertype(L, param.m_pData[i], param.m_pszTypeName);
		lua_rawseti(L, -2, i + 1);
	}	
}

template<> inline void PushParam(lua_State* L, StrTable param)
{
	lua_newtable(L);
	for (int i=0; i<param.m_nLen; ++i) 
	{
		lua_pushstring(L, param.m_pData[i]);
		lua_rawseti(L, -2, i + 1);
	}	
}

template<> inline void PushParam(lua_State* L, NumTable param)
{
	lua_newtable(L);
	for (int i=0; i<param.m_nLen; ++i) 
	{
		lua_pushnumber(L, param.m_pData[i]);
		lua_rawseti(L, -2, i + 1);
	}
}

template<> inline void PushParam(lua_State* L, UserType param)
{
	tolua_pushusertype(L, param.m_pData, param.m_pszTypeName);
}

/*
template<> inline void PushParam(lua_State* L, HANDLE param)
{
	lua_pushnumber(L, (long)param);
}
*/

template<> inline void PushParam(lua_State* L, const char* param)
{
	lua_pushstring(L, param);
}

template<> inline void PushParam(lua_State* L, std::string param)
{
	lua_pushstring(L, param.c_str());
}

template<> inline void PushParam(lua_State* L, char param)
{
	lua_pushnumber(L, param);
}

template<> inline void PushParam(lua_State* L, int param)
{
	lua_pushnumber(L, param);
}

template<> inline void PushParam(lua_State* L, float param)
{
	lua_pushnumber(L, param);
}

template<> inline void PushParam(lua_State* L, short param)
{
	lua_pushnumber(L, param);
}

template<> inline void PushParam(lua_State* L, double param)
{
	lua_pushnumber(L, param);
}

template<> inline void PushParam(lua_State* L, long param)
{
	lua_pushnumber(L, param);
}

template<> inline void PushParam(lua_State* L, unsigned int param)
{
	lua_pushnumber(L, param);
}

template<> inline void PushParam(lua_State* L, unsigned short param)
{
	lua_pushnumber(L, param);
}

template<> inline void PushParam(lua_State* L, unsigned long param)
{
	lua_pushnumber(L, param);
}

template<> inline void PushParam(lua_State* L, bool param)
{
	lua_pushboolean(L, param);
}


//////////////////////////////////////////////////////////////////////////
template<class T1 = TypeNull,class T2= TypeNull, class T3= TypeNull>
class ParamPusher
{
public:
	static void Push(lua_State* L, short& index, const T1& t1=NIL,
		const T2& t2 = NIL, const T3& t3 = NIL)
	{
		PushParam(L, t1);
		ParamPusher<T2, T3>::Push(L, ++index, t2, t3);
	}
};

template<>
class ParamPusher<TypeNull, TypeNull, TypeNull>
{
public:
	static void Push(lua_State* L, short& index, const TypeNull& t1=NIL
		,const TypeNull& t2 = NIL, const TypeNull& t3 = NIL)
	{
	}
};


//////////////////////////////////////////////////////////////////////////
template<class T>
inline bool IsNull(const T& obj){ return false; }
template<>
inline bool IsNull(const TypeNull& obj){ return true; }


//////////////////////////////////////////////////////////////////////////
typedef std::vector<lua_Number> LuaNumVect;
typedef std::vector<const char*> LuaCharVect;

template <class Value>
LUASCRIPT_AIP bool GetLuaTable(lua_State* L, short tableIndex, std::vector<Value>& result);
LUASCRIPT_AIP bool GetLuaString(lua_State* L, int iStackIndex, const char* & result);
LUASCRIPT_AIP bool GetLuaNumber(lua_State* L, int iStackIndex, lua_Number& result);
LUASCRIPT_AIP bool GetLuaString(lua_State* L, int iStackIndex, const char* & result);
LUASCRIPT_AIP bool GetLuaNumber(lua_State* L, int iStackIndex, lua_Number& result);


template<class T> bool PopResult(lua_State* L, T& result){ return false; }
template<> inline bool PopResult(lua_State* L, const char* &result)
{
	return GetLuaString(L, -1, result);
}
template<> inline bool PopResult(lua_State* L, std::string &result)
{
	const char* temp;
	bool bRet = GetLuaString(L, -1, temp);
	result = temp;
	return bRet;
}
template<> inline bool PopResult(lua_State* L, double& result)
{
	return GetLuaNumber(L, -1, result);
}
template<> inline bool PopResult(lua_State* L, int& result)
{
	lua_Number temp;
	bool bRet = GetLuaNumber(L, -1, temp);
	result = temp;
	return bRet;
}
template<> inline bool PopResult(lua_State* L, float& result)
{
	lua_Number temp;
	bool bRet = GetLuaNumber(L, -1, temp);
	result = temp;
	return bRet;
}
template<> inline bool PopResult(lua_State* L, long& result)
{
	lua_Number temp;
	bool bRet = GetLuaNumber(L, -1, temp);
	result = temp;
	return bRet;
}
template<> inline bool PopResult(lua_State* L, char& result)
{
	lua_Number temp;
	bool bRet = GetLuaNumber(L, -1, temp);
	result = temp;
	return bRet;
}
template<> inline bool PopResult(lua_State* L, short& result)
{
	lua_Number temp;
	bool bRet = GetLuaNumber(L, -1, temp);
	result = temp;
	return bRet;
}
template<> inline bool PopResult(lua_State* L, bool& result)
{
	if(lua_isboolean(L, -1))
	{
		result = !!lua_toboolean(L, -1);
		lua_pop(L, 1);
		return true;
	} 
	else 
	{
		lua_pop(L, 1);
		return false;
	}
}
template<> inline bool PopResult(lua_State* L, TypeLTable& result)
{
	if(lua_istable(L, -1))
	{
		result.self = luaL_ref(L, LUA_REGISTRYINDEX);
		return true;
	} 
	else 
	{
		return false;
	}
}
template<> inline bool PopResult(lua_State* L, LuaCharVect& result)
{
	return GetLuaTable(L, -1, result);
}
template<> inline bool PopResult(lua_State* L, LuaNumVect& result)
{
	return GetLuaTable(L, -1, result);
}


//////////////////////////////////////////////////////////////////////////
template<class RT>
class ResultPoper
{
public:
	static bool Pop(lua_State* L, RT& result)
	{
		return PopResult(L, result);
	}
};


////////////////////////////////////////////////////////////////////////////
template<class RT = TypeNull, class PT1 = TypeNull, class PT2 = TypeNull, class PT3 = TypeNull>
class LuaFunctor
{
private:
	LuaFunctor& operator=(const LuaFunctor& fun);
public:
	LuaFunctor(lua_State* state, int func)
	  : m_L(state), m_iFunc(func)
	{
	}

	LuaFunctor(lua_State* state, const std::string& func)
	   : m_L(state), m_iFunc(LUA_NOREF), m_strFunctionName(func)
	{
	}

	LuaFunctor(const LuaFunctor& cp)
	   : m_L(cp.m_L), m_iFunc(cp.m_iFunc), m_strFunctionName(cp.m_strFunctionName)
	{
	}

	~LuaFunctor()
	{
		if (m_iFunc != LUA_NOREF)
		{
			luaL_unref(m_L, LUA_REGISTRYINDEX, m_iFunc);
		}
	}

	bool operator()(int selfIndex = LUA_NOREF, RT& pResult = NIL, const PT1& param1 = NIL, 
						const PT2& param2 = NIL, const PT3& param3 = NIL);

	const char* GetLastError(){ return m_strError.c_str(); }

private:
	lua_State* m_L;
	mutable int m_iFunc;
	mutable std::string m_strFunctionName;
	std::string m_strError;
};


template<class RT, class PT1, class PT2, class PT3>
bool LuaFunctor<RT, PT1, PT2, PT3>::operator()(int selfIndex,  RT& result, 
						const PT1& param1, const PT2& param2, const PT3& param3)
{
	// is this a late binding?
	if (m_strFunctionName.length() > 0)
	{
		m_iFunc = PushMethod(m_L, m_strFunctionName);
		m_strFunctionName.clear();
		if (m_iFunc == LUA_NOREF)
		{
			return false;
		}
	}

	// retrieve function
	lua_rawgeti(m_L, LUA_REGISTRYINDEX, m_iFunc);

	// possibly self as well?
	short nargs = 0;
	short nResult = 0;
	if (selfIndex != LUA_NOREF)
	{
		//push self
		lua_rawgeti(m_L, LUA_REGISTRYINDEX, selfIndex);
		++nargs;
	}
	//push param
	ParamPusher<PT1, PT2, PT3>::Push(m_L, nargs, param1, param2, param3);
	if (!IsNull(result))
	{
		nResult++;
	}

	// call it
	int error = lua_pcall(m_L, nargs, nResult, 0);

	// handle errors
	if (error)
	{
		const char* pszErrInfor = lua_tostring(m_L, -1);
		m_strError = pszErrInfor ? pszErrInfor : "";
		lua_pop(m_L, 1);
		//DebugConsole::out("Call Lua function failed!:\n %s\n", pcszErr);
		return false;
	}

	if (!IsNull(result))
	{
		bool bRet = ResultPoper<RT>::Pop(m_L, result);
		return bRet;
	}

	return true;
}
