#include <stdarg.h>
#include <string>
#include <vector>
#include "LuaScriptMgr.h"
#include "ScriptUnit.h"

enum LuaScriptMgrCode
{
    lec_success = 0,
    lec_exception,
    lec_unkown,
    lec_no_function,
    lec_input_type,
    lec_output_type,
	lec_emptyLb,
};

static  char* LuaScriptMgrMsg[] = 
{
    "work well done",
    "exception encountered",
    "unknown error",
    "no such function",
    "invalid input param type",
    "invalid output param type",
	"empty label name"
};

CLuaScriptMgr* g_pLuaScriptMgr = NULL;
ILuaScriptMgr* g_ILuaScriptMgr = NULL;

TOLUA_API int  tolua_main_open (lua_State* tolua_S);


#define RegLuaGlobalFunc(L, func)  lua_register(L, #func, lua_##func)


static int lua_fetch(lua_State* L, bool (*fetchFn)(const char*))
{
	int n = lua_gettop(L);  /* number of arguments*/
	int i;
	lua_getglobal(L, "tostring");
	for (i=1; i<=n; i++) 
	{
		const char* s;
		lua_pushvalue(L, -1);  /* function to be called*/
		lua_pushvalue(L, i);   /* value to print*/
		lua_call(L, 1, 1);
		s = lua_tostring(L, -1);  /* get result*/
		if (s == NULL)
			return luaL_error(L, "'tostring' must return a string to 'print'");
		if (i>1) 
			fetchFn("\t");
		fetchFn(s);
		lua_pop(L, 1);  /* pop result*/
	}
	fetchFn("\n");
	return 0;
}

static int  lua_dofile(lua_State* L)
{
	size_t l;
	const char* sFileName = luaL_checklstring(L, 1, &l);
	if(sFileName != NULL && g_pLuaScriptMgr != NULL)
	{
		g_pLuaScriptMgr->LoadLuaFile(sFileName);
		return 1;
	}

	return 0;
}

static int lua_loadfile(lua_State* L, const char* filename)
{
	int status = -1;
/*
	FileSystem* pFileSystem = getFileSystem();
	if(pFileSystem != NULL)
	{
		Stream* pStream = pFileSystem->open(filename);
		if(pStream != NULL)
		{
			Uint32 nLength = pStream->getLength();
			if(nLength > 0)
			{
				// 把文件读进内存
				char* pData = new char[nLength + 1]; pData[nLength] = 0;
				pStream->read(pData, nLength);
				//pStream->close();
				pStream->release();
				// 通过内存加载文件
				status = luaL_loadbuffer(L, pData, nLength, pData);
				delete[] pData;
			}
		}
	}
*/
	#include <stdio.h>
	FILE* fp = fopen(filename, "rb");
	if(fp)
	{
		fseek(fp, 0, SEEK_END);
		int len = ftell(fp);
		char* pData = new char[len + 1];
		fseek(fp, 0, SEEK_SET);
		fread(pData, len, 1, fp);
		pData[len] = 0;
		fclose(fp);
		status = luaL_loadbuffer(L, pData, len, pData);
		delete[] pData;
	}
	else
	{
		char szErrMsg[256];
		sprintf_s(szErrMsg, "Can not open file: %s!", filename);
		lua_pushstring(L, szErrMsg);
	}
	return status;
}

static int lua_loadlua(lua_State* L)
{
	const char* name = luaL_gsub(L, luaL_checkstring(L, 1), ".", LUA_DIRSEP);
	char filename[MaxPathLen];
	sprintf(filename, "%s.luc", name);
	int status = lua_loadfile(L, filename);
	if (status != 0) 
	{
		sprintf(filename, "%s.lua", name);
		status = lua_loadfile(L, filename);
	}
	if (status != 0) 
	{
		luaL_error(L, "error loading module " LUA_QS " from file " LUA_QS ":\n\t%s",
			lua_tostring(L, 1), name, lua_tostring(L, -1));
	}
	return 1;
}

static int lua_setLoader(lua_State*L, lua_CFunction fn)
{
	lua_getglobal(L, LUA_LOADLIBNAME);
	if (lua_istable(L, -1)) 
	{
		lua_getfield(L, -1, "loaders");
		if (lua_istable(L, -1)) 
		{
			lua_pushcfunction(L, fn);
			lua_rawseti(L, -2, 2);
			return 0;
		}
	}
	return -1;
}

static int lua_NewRegistryRef(lua_State *L)
{
	int r = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_pushnumber(L, r);
	return 1;
}

static int lua_ReleaseRegistryRef(lua_State* L)
{
	int ref = (int) luaL_checknumber(L, -1);
	luaL_unref(L, LUA_REGISTRYINDEX, ref);
	return 0;
}

static int lua_GetRegistryObj(lua_State* L)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isnumber(L,1,0,&tolua_err) ||
		!tolua_isnoobj(L,2,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		int iSelf = ((int)  tolua_tonumber(L,1,0));
		{
			lua_rawgeti(L, LUA_REGISTRYINDEX, iSelf);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(L,"#ferror in function 'GetRegistryObj'.",&tolua_err);
	return 0;
#endif
}

static int lua_ObjectDynamicCast(lua_State* L)
{
	int top = lua_gettop(L);
	if (lua_isuserdata(L, 1) && (lua_isstring(L, 2) || top < 2) && top < 3)
	{
		CScriptObject* paramObj = (CScriptObject*)  tolua_tousertype(L,1,0);
		const char* moduleName = NULL;
		if (lua_isstring(L, 2))
		{
			moduleName = tolua_tostring(L, 2, NULL);
		}
		void * lst = paramObj->GetThis(moduleName);
		if (paramObj != NULL)
		{
			moduleName = moduleName == NULL ? paramObj->GetModuleName() : moduleName;
			tolua_pushusertype(L, paramObj, moduleName);
			return 1;
		}
	}
	luaL_error(L, "invalid 'arguments' in function 'ObjectDownCast(CScriptObject, moduleName = nil)'");
	return 0;
}

static int lua_DoBuffer(lua_State* L)
{
	if (lua_isstring(L, 1) && lua_gettop(L) < 2)
	{
		const char* buffer = lua_tostring(L, 1);
		bool result = g_pLuaScriptMgr->RunMemoryLua(buffer);
		lua_pushboolean(L, result);
		return 1;
	}
	luaL_error(L, "invalid 'arguments' in function 'DoBuffer(buffer)'");
	return 0;
}

static void RegLuaGlobalFuncs(lua_State* L)
{
	RegLuaGlobalFunc(L, NewRegistryRef);
	RegLuaGlobalFunc(L, ReleaseRegistryRef);
	RegLuaGlobalFunc(L, ObjectDynamicCast);
	RegLuaGlobalFunc(L, GetRegistryObj);
	RegLuaGlobalFunc(L, DoBuffer);
}


//------------------------------------------------------------------------------------------------

CLuaScriptMgr::CLuaScriptMgr(void) : 
	m_sLastErr(""), m_L(NULL), m_bFromPackLoadLua(false)
{
}

CLuaScriptMgr::~CLuaScriptMgr(void)
{
}

void CLuaScriptMgr::Release(void)
{
	if(m_L != NULL)
	{
		lua_close(m_L);
	}
	delete this;
}

bool CLuaScriptMgr::Create(bool bFromPackLoadLua)
{
	// 是否从包里载入lua
	m_bFromPackLoadLua = bFromPackLoadLua;

	// 初始化LUA库
	m_L = lua_open();
	if(m_L == NULL)
	{
		return false;
	}

	// 初始化所有的标准库
	luaL_openlibs(m_L);

	// 初始化tolua导出的lua接口
	tolua_main_open(m_L);
	
	// 初始化LuaScriptMgr模块的Lua接口
	RegLuaGlobalFuncs(m_L);
	

	if (bFromPackLoadLua)
	{
		// 替换缺省的Lua加载函数
		lua_setLoader(m_L, lua_loadlua);
	}

	// 华夏II曾经有过此问题，堆栈太小，出现了频繁的当机
	lua_checkstack(m_L, 512);

	/*
	// 初始化一些基本的api
	lua_register(m_L, "dofile", luaA_DoFile);
	lua_register(m_L, "print", lua_trace);
	lua_register(m_L, "trace", lua_trace);
	lua_register(m_L, "error", lua_error);
	lua_register(m_L, "warning", lua_warning);
	*/

	return true;
}

lua_State*	CLuaScriptMgr::GetLuaState(void)
{
	return m_L;
}

bool CLuaScriptMgr::LoadLuaFile(const char* szLuaFileName)
{
	if(szLuaFileName == NULL)
	{
		return false;
	}
    
    CLuaTopStackRecover topStackRecover(m_L);
    
    int nResult = 0;
    try
	{
        nResult = m_bFromPackLoadLua ? lua_loadfile(m_L, szLuaFileName) : luaL_loadfile(m_L, szLuaFileName);
        if(nResult == 0)
        {
            nResult = lua_pcall(m_L, 0, 0, 0);
        }
        //If something goes wrong, try to find the reason
        if(nResult !=0 )
		{
            SetLastError(lua_tostring(m_L, -1));
        }
    }
	catch(...)
	{
       SetLastError(LuaScriptMgrMsg[nResult = lec_exception]);
    }

    if(nResult !=0)
        ERROR_MSG("[LuaScript] load and execute file %s failed, because of %s \n", szLuaFileName, m_sLastErr.c_str());
    return (nResult == 0);
}

bool CLuaScriptMgr::RunMemoryLua(const char* pLuaData, int nDataLen)
{
	if(!pLuaData)	return false;
	if(nDataLen <= 0) nDataLen = strlen(pLuaData);
	if(nDataLen <= 0) return false;
    
    CLuaTopStackRecover topStackRecover(m_L);
    int nResult = 0;
    try
	{
	    nResult = luaL_loadbuffer(m_L, pLuaData, nDataLen, pLuaData);
	    if(nResult == 0)
	    {
		    nResult = lua_pcall(m_L, 0, 0, 0);
	    }
        if(nResult != 0)
		{
	        SetLastError(lua_tostring(m_L, -1));
        }
    }
	catch(...)
	{
        SetLastError(LuaScriptMgrMsg[nResult = lec_exception]);
    }

    if(nResult !=0) 
        ERROR_MSG("[LuaScript] execute in memory lua block failed, because of %s\n", m_sLastErr.c_str());
    return (nResult == 0);
}

bool CLuaScriptMgr::ExcLuaFunction(int iSelf, const std::string& strFunctionName, CLuaParam* pInParam, int nInNum, CLuaParam* pOutParam, int nOutNum)
{
    CLuaTopStackRecover topStackRecover(m_L);
	int nResult = -1;
	if (PushLuaFunction(strFunctionName))
	{
		try
		{
			if (iSelf != LUA_NOREF)
			{
				lua_rawgeti(m_L, LUA_REGISTRYINDEX, iSelf);
			}
			if (ParserInputArgs(pInParam, nInNum) >= 0)
			{
				nResult = lua_pcall(m_L, nInNum + (iSelf != LUA_NOREF), nOutNum, 0);
			}
			if(nResult == 0)
			{
				nResult = (ParserOutputArgs(pOutParam, nOutNum) >= 0) ? 0 : -1;
			}
			else
			{
				SetLastError(lua_tostring(m_L, -1));
			}
		}
		catch (...)
		{
			SetLastError(LuaScriptMgrMsg[nResult = lec_exception]);
		}
	}

    if(nResult != 0)
        SetLastError("[LuaScript] call %s(...) failed, reason is : %s\n", strFunctionName, m_sLastErr.c_str());        
	return (nResult == 0);
}

//Notice: func szFmt: "ifbsodrpn>ifbsodrpn"
bool CLuaScriptMgr::RunLuaFunction(int iSelf, const std::string& strFunctionName, const char* szFmt, ...)
{
	CLuaTopStackRecover topStackRecover(m_L);
	int nResult = -1;
	if (PushLuaFunction(strFunctionName))
	{
		va_list vl;
		va_start(vl, szFmt);
		try
		{	
			int nInNum, nOutNum; /* number of arguments and results */
			/* push arguments */
			nInNum = 0;
			if (iSelf != LUA_NOREF)
			{
				lua_rawgeti(m_L, LUA_REGISTRYINDEX, iSelf);
				++nInNum;
			}

			int curInNum = ParserInputArgs(szFmt, vl);
			if (curInNum >= 0)
			{
				nInNum += curInNum;
				szFmt += curInNum;
				if (*szFmt == '>')
				{
					++szFmt;
				}
				nOutNum = strlen(szFmt); /* number of expected results */
				nResult = lua_pcall(m_L, nInNum, nOutNum, 0);/* do the call */
			}
			if (nResult == 0)
			{
				nResult = (ParserOutputArgs(szFmt, vl) >= 0) ? 0 : -1;
			}
			else
			{
				SetLastError(lua_tostring(m_L, -1));
			}
		}
		catch (...)
		{
			SetLastError(LuaScriptMgrMsg[nResult = lec_exception]);
		}
		va_end(vl);
	}

	if(nResult != 0)
		SetLastError("[LuaScript] call %s(...) failed, reason is : %s\n", strFunctionName, m_sLastErr.c_str());        
	return (nResult == 0);
}

int CLuaScriptMgr::ParserInputArgs(CLuaParam* pInParam, int nInNum)
{
	for(int i = 0; i < nInNum; i++)
	{
		switch(pInParam[i].GetDataType())
		{
		case LUA_TNUMBER:
			{
				lua_pushnumber(m_L, (int)pInParam[i]);
				break;	
			}			
		case LUA_TSTRING:
			{
				lua_pushstring(m_L, (const char*)pInParam[i]);
				break;
			}			
		case LUA_TLIGHTUSERDATA:
			{
				lua_pushlightuserdata(m_L, (void*)pInParam[i]);
				break;
			}
		default:
			{
				SetLastError(LuaScriptMgrMsg[lec_input_type]);
				return -1;
			}
		}
	}
	return nInNum;
}

int CLuaScriptMgr::ParserInputArgs(const char *szFmt, va_list vl)
{
	int nInNum = 0;
	while (*szFmt) 
	{ 
		switch (*szFmt++) 
		{
		case 'i': /* int argument */
			{
				lua_pushnumber(m_L, va_arg(vl, int));
				break;
			}
		case 'f': /* float argument */
			{
				lua_pushnumber(m_L, va_arg(vl, float));
				break;
			}
		case 'b': /* bool argument */
			{
				lua_pushboolean(m_L, va_arg(vl, bool));
				break;
			}
		case 's': /* string argument */
			{
				lua_pushstring(m_L, va_arg(vl, char*));
				break;
			}
		case 'o': /* CScriptObject argument */
			{
				CScriptObject* obj = (CScriptObject*) va_arg(vl, void*);
				tolua_pushusertype(m_L, obj->GetThis(), obj->GetModuleName());
				break;
			}
		case 'd': /* double argument */
			{
				lua_pushnumber(m_L, va_arg(vl, double));
				break;
			}
		case 'r': /* LUA_REGISTRYINDEX value */
			{
				lua_rawgeti(m_L, LUA_REGISTRYINDEX, va_arg(vl, int));
				break;
			}
		case 'p': /* light user data argument */
			{
				lua_pushlightuserdata(m_L, va_arg(vl, void*));
				break;
			}
		case 'n': /* nil argument */
			{
				lua_pushnil(m_L);
				break;
			}
		case '>': /* separate from input and output */
			{
				return nInNum;
			}
		default:
			{
				SetLastError("invalid option (%c)", *(szFmt - 1));
				return -1;
			}
		}
		++nInNum;
	}
	return nInNum;
}

int CLuaScriptMgr::ParserOutputArgs(CLuaParam* pOutParam, int nOutNum)
{
	for(int n = 0; n < nOutNum; n++)
	{
		int nType = lua_type(m_L, -1);
		switch(nType)
		{
		case LUA_TNUMBER:
			{
				pOutParam[n] = (int)lua_tonumber(m_L, -1);
				lua_pop(m_L, 1);
				break;
			}
		case LUA_TSTRING:
			{
				pOutParam[n] = (const char*)lua_tostring(m_L, -1);
				lua_pop(m_L, 1);
				break;
			}
		case LUA_TLIGHTUSERDATA:
			{
				pOutParam[n] = (const void*)lua_topointer(m_L, -1);
				lua_pop(m_L, 1);
				break;
			}
		default:
			{
				SetLastError(LuaScriptMgrMsg[lec_output_type]);
				return -1;
			}
		}
	}
	return nOutNum;
}

int CLuaScriptMgr::ParserOutputArgs(const char* szFmt, va_list vl)
{
	bool isParserArgOK = true;
	int nOutNum = strlen(szFmt);
	int nResult = nOutNum;
	nOutNum = -nOutNum; //inverse, from the top stack of lua
	/* retrieve results */
	/* stack index of first result */
	while (*szFmt) 
	{ 
		switch (*szFmt++) 
		{
		case 'i': /* int result */
			{
				if (isParserArgOK = !!lua_isnumber(m_L, nOutNum))
				{
					*va_arg(vl, int*) = (int)lua_tonumber(m_L, nOutNum);
				}
				break;
			}
		case 'f': /* float result */
			{
				if (isParserArgOK == !!lua_isnumber(m_L, nOutNum))
				{
					*va_arg(vl, float*) = (float)lua_tonumber(m_L, nOutNum);
				}
				break;
			}
		case 'b': /* bool result */
			{
				if (isParserArgOK == !!lua_isboolean(m_L, nOutNum))
				{
					*va_arg(vl, bool*) = !!lua_toboolean(m_L, nOutNum);
				}
			}
		case 's': /* string result */
			{
				if (isParserArgOK = !!lua_isstring(m_L, nOutNum))
				{
					*va_arg(vl, const char**) = lua_tostring(m_L, nOutNum);
				}
				break;
			}
		case 'o': /* CScriptObject result */
			{
				tolua_Error tolua_err;
				if (isParserArgOK = !!tolua_isusertype(m_L, nOutNum, "CScriptObject", NULL, &tolua_err))
				{
					*va_arg(vl, void**) = tolua_tousertype(m_L, nOutNum, NULL);
				}
				break;
			}
		case 'd': /* double result */
			{
				if (isParserArgOK = !!lua_isnumber(m_L, nOutNum))
				{
					*va_arg(vl, double*) = lua_tonumber(m_L, nOutNum);
				}
				break;
			}
		case 'r': /* LUA_REGISTRYINDEX value */
			{
				lua_pushvalue(m_L, nOutNum);
				*va_arg(vl, int*) = luaL_ref(m_L, LUA_REGISTRYINDEX);
				break;
			}
		case 'p': /* light user data result */
			{
				if (isParserArgOK = !!lua_islightuserdata(m_L, nOutNum))
				{
					*va_arg(vl, const void**) = lua_topointer(m_L, nOutNum);
				}
				break;
			}
		case 'n': /* nil result */
			{
				if (isParserArgOK = !!lua_isnil(m_L, nOutNum))
				{
					*va_arg(vl, const void**) = 0;
				}
				break;
			}
		default:
			{
				SetLastError("invalid option (%c)", *(szFmt - 1));
				return -1;
			}
		}
		
		if (!isParserArgOK)
		{
			SetLastError("wrong result type (%c)", *(szFmt - 1));
			return -1;
		}

		++nOutNum;
	}
	return nResult;
}

bool CLuaScriptMgr::PushLuaFunction(const std::string& strLbName)
{
	//format for strFunctionName: global.*(table).lbName
	//				  Notice: *(table), none or more tables
	
	CLuaTopStackRecover topStackRecover(m_L);
	if (strLbName.length() == 0)
	{
		SetLastError(LuaScriptMgrMsg[lec_emptyLb]);
		return false;
	}

	// do we have any dots in the handler name? if so we grab the function as a table field
	std::string::size_type i = strLbName.find_first_of('.');
	if (i!=std::string::npos)
	{
		// split the rest of the string up in parts seperated by '.'
		// TODO: count the dots and size the vector accordingly from the beginning.
		std::vector<std::string> parts;
		std::string::size_type start = 0;
		do
		{
			parts.push_back(strLbName.substr(start,i-start));
			start = i+1;
			i = strLbName.find_first_of('.',start);
		} while(i!=std::string::npos);

		// add last part
		parts.push_back(strLbName.substr(start));

		// first part is the global
		lua_getglobal(m_L, parts[0].c_str());
		if (!lua_istable(m_L, -1))
		{
			SetLastError("Unable to get : '%s'\n", strLbName.c_str());
			return false;
		}

		// if there is more than two parts, we have more tables to go through
		std::vector<std::string>::size_type visz = parts.size();
		if (visz-- > 2) // avoid subtracting one later on
		{
			// go through all the remaining parts to (hopefully) have a valid Lua function in the end
			std::vector<std::string>::size_type vi = 1;
			while (vi < visz)
			{
				// push key, and get the next table
				lua_pushstring(m_L, parts[vi].c_str());
				lua_gettable(m_L, -2);
				if (!lua_istable(m_L, -1))
				{
					SetLastError("Unable to get : '%s'\n", strLbName.c_str());
					return false;
				}
				// get rid of the last table and move on
				lua_remove(m_L, -2);
				vi++;
			}
		}
		lua_pushstring(m_L,parts[visz].c_str());
		lua_gettable(m_L, -2);
		lua_remove(m_L, -2); // get rid of the table
	}
	// just a regular global function
	else
	{
		lua_getglobal(m_L, strLbName.c_str());
	}

	if (!lua_isfunction(m_L, -1))
	{
		SetLastError(LuaScriptMgrMsg[lec_no_function]);
		return false;
	}

	topStackRecover.DisableRecover();
	return true;
}

const char* CLuaScriptMgr::GetLastError(void)
{
	return m_sLastErr.c_str();
}

void CLuaScriptMgr::SetLastError(const char* szFmt, ...)
{
	va_list vl;
	char szErrorMsg[256];
	va_start(vl, szFmt);
	sprintf(szErrorMsg, szFmt, vl);
	m_sLastErr = szErrorMsg;
	va_end(vl);
}

ILuaScriptMgr* GlobalLuaEngine(bool bfromPackLoadLua)
{
	if(g_pLuaScriptMgr != NULL)
	{
		return g_pLuaScriptMgr;
	}
	g_pLuaScriptMgr = new CLuaScriptMgr();
	if(!g_pLuaScriptMgr->Create(bfromPackLoadLua))
	{
		SafeDelete(g_pLuaScriptMgr);
	}
	g_ILuaScriptMgr = g_pLuaScriptMgr;
	return g_pLuaScriptMgr;
}
