#pragma once

#include "script/ILuaScriptMgr.h"


class CLuaScriptMgr : public ILuaScriptMgr
{
public:
	virtual void			Release(void);
	virtual lua_State*		GetLuaState(void);
	virtual bool			LoadLuaFile(const char* szLuaFileName);
	virtual bool			RunMemoryLua(const char* pLuaData, int nDataLen = 0);
	virtual bool			ExcLuaFunction(int iSelf, const std::string& strFunctionName, CLuaParam* pInParam = NULL, int nInNum = 0, CLuaParam* pOutParam = NULL, int nOutNum = 0);
	virtual bool			RunLuaFunction(int iSelf, const std::string& strFunctionName, const char* szFmt = "", ...);
	virtual bool			PushLuaFunction(const std::string& strLbName);
	virtual const char*		GetLastError(void);
	virtual void			SetLastError(const char* szFmt, ...);

	bool					Create(bool bFromPackLoadLua);
	CLuaScriptMgr(void);
	virtual ~CLuaScriptMgr(void);

private:
	int						ParserInputArgs(CLuaParam* pInParam, int nInNum);
	int						ParserInputArgs(const char* szFmt, va_list vl);
	int						ParserOutputArgs(CLuaParam* pOutParam, int nOutNum);
	int						ParserOutputArgs(const char* szFmt, va_list vl);
	
private:
	lua_State*				m_L;
	bool					m_bFromPackLoadLua;
	std::string				m_sLastErr;
};

extern CLuaScriptMgr*	g_pLuaScriptMgr;
