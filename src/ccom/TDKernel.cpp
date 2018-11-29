/****************************************\
*										*
*			    ���ݺ���				*
*										*
\****************************************/
#include "StdAfx.h"
#include "TDKernel.h"
#include "TDException.h"
#include "TDUtil.h"
#include "TDPlugin.h"
#include "TDObjectSystem.h"

tKernel* tKernel::s_pMe = NULL;
tKernel::tKernel(VOID)
	: m_theRoot(_T("root"))
	, m_pFirstClass(NULL)
{
	s_pMe = this;
}

tKernel::~tKernel(VOID)
{
}

//��ĳ����ע�ᵽȫ�������������
VOID tKernel::ReisgerClass(tClass* pNewClass)
{
	TDAssert(pNewClass);

	if(m_ClassMap[STRING(pNewClass->szClassName)] != NULL)
	{
		TDThrow(_T("Multi register class:%s"), pNewClass->szClassName);
	}
	pNewClass->pNextClass = m_pFirstClass;
	m_pFirstClass = pNewClass;
	//���µ�����뵽�������
	(m_ClassMap)[pNewClass->szClassName] = pNewClass;
}

//����������Ƿ���м̳й�ϵ
BOOL tKernel::IsKindOf(const tClass* pThisClass, const tClass* pBaseClass) const
{
	if(!pBaseClass || !pThisClass) return FALSE;

	register const tClass *pClass = pThisClass;

	while(pClass != NULL)
	{
		if(pClass == pBaseClass)
		{
			return TRUE;
		}
		pClass = pClass->pBaseClass;
	}
	return FALSE;
}
//�����ַ�����ʽ����ȡ��ĳ������
tClass* tKernel::OpenClass(LPCTSTR szClassName)
{
	std::map< STRING, tClass* >::iterator it = m_ClassMap.find(szClassName);
	if(it == m_ClassMap.end()) return 0;
	else return it->second;
}

//�����ַ�����ʽ��·���������½ڵ�
tNode*	tKernel::NewNode(LPCTSTR szClassName, LPCTSTR szPosition, LPCTSTR szNodeName)
{
	TDAssert(szClassName && szPosition && szNodeName);

	//����
	tClass *pClass = OpenClass(szClassName);
	if(!pClass)
	{
		TDThrow(_T("(tKernel::NewNode)Can't create new Node[%s]"), szClassName);
	}
	
	std::vector< STRING > vPathSplitBuf;
	TDU_ConvertStringToVector(szPosition, vPathSplitBuf, _T("\\/"));

	tNode *pCurrentNode = &m_theRoot;
	tNode *pFindNode = NULL;

	//�������ڵ�
	for(register INT i=0; i<(INT)vPathSplitBuf.size(); i++)
	{
		tNode *pFindNode = pCurrentNode->LookUpChild((LPCTSTR)vPathSplitBuf[i].c_str());
		if(pFindNode == NULL)
		{
			tNode *pNewNode = new tNode(vPathSplitBuf[i].c_str());
			pCurrentNode->AddChild(pNewNode);
			pFindNode = pNewNode;
		}
		pCurrentNode = pFindNode;
	}

	//�����Ƿ�ýڵ��Ѿ�����
	if(pCurrentNode->LookUpChild(szNodeName))
	{
		TDThrow(_T("(tKernel::NewNode)The Node[%s] has exist!"), szNodeName);
	}

	tNode *pNewNode = (tNode *)pClass->CreateObject(szNodeName);
	pCurrentNode->AddChild(pNewNode);
	return pNewNode;
}

//���ݸ��ڵ�����µĽڵ�
tNode*	tKernel::NewNode(LPCTSTR szClassName, tNode* pParentNode, LPCTSTR szNodeName)
{
	TDAssert(szClassName && pParentNode && szNodeName);

	//����
	tClass *pClass = OpenClass(szClassName);
	if(!pClass)
	{
		TDThrow(_T("(tKernel::NewNode)Can't create new Node[%s]"), szClassName);
	}

	//�����Ƿ�ýڵ��Ѿ�����
	if(pParentNode->LookUpChild(szNodeName))
	{
		TDThrow(_T("(tKernel::NewNode)The Node[%s] has exist!"), szNodeName);
	}

	tNode *pNewNode = (tNode *)pClass->CreateObject(szNodeName);
	pParentNode->AddChild(pNewNode);

	return pNewNode;
}


tNode*	tKernel::GetNode(LPCTSTR szPathName)
{
	TDAssert(szPathName);

	std::vector< STRING > vPathSplitBuf;
	TDU_ConvertStringToVector(szPathName, vPathSplitBuf, _T("\\/"));

	if(vPathSplitBuf.empty()) return NULL;

	tNode *pCurrentNode = &m_theRoot;
	for(register INT i=0; i<(INT)vPathSplitBuf.size(); i++)
	{
		tNode *pFindNode = pCurrentNode->LookUpChild((LPCTSTR)vPathSplitBuf[i].c_str());
		if(pFindNode == NULL)
		{
			return NULL;
		}
		pCurrentNode = pFindNode;
	}

	return pCurrentNode;
}

BOOL tKernel::LoadPlugin(LPCTSTR szPluginName, LPVOID pParam)
{
	if(!szPluginName) return FALSE;

	HMODULE hModule = NULL;
	FUNC_DLLINIT pfnDllInit = NULL;
	FUNC_DLLRELEASE pfnDllRelease = NULL;

	try
	{
		//����Load��dll
		hModule = ::LoadLibrary(szPluginName);
		if(!hModule)
		{
			DWORD dLastError = ::GetLastError();
			TDThrow(_T("Load plugin dll(%s) failed!"), szPluginName);
			return FALSE;
		}

		//�鿴�Ƿ��кϷ��ĵ�������
		pfnDllInit = (FUNC_DLLINIT)::GetProcAddress(hModule, "DllInit");
		pfnDllRelease = (FUNC_DLLRELEASE)::GetProcAddress(hModule, "DllRelease");
		if(!pfnDllInit || !pfnDllRelease)
		{ 
			::FreeLibrary(hModule); hModule = NULL; 
			TDThrow(_T("Wrong plugin dll(%s) export function!"), szPluginName);
			return FALSE; 
		}
	}
	catch(...) 
	{
		if(hModule) ::FreeLibrary(hModule);
		throw;
		return FALSE;
	}

	//�ǺϷ��Ĳ����ִ�м��غ���
	(*pfnDllInit)(pParam);

	PLUGIN_INFO newPlugin;
	newPlugin.strPluginFile = szPluginName;
	newPlugin.hModule = hModule;
	newPlugin.pfnDllInit = pfnDllInit;
	newPlugin.pfnDllRelease = pfnDllRelease;

	m_vAllPlugin.push_back(newPlugin);

	return TRUE;
}


VOID tKernel::FreeAllPlugin(VOID)
{
	//�ͷ����в��
	for(INT i=0; i<(INT)m_vAllPlugin.size(); i++)
	{
		//ִ���ͷź���
		(*(m_vAllPlugin[i].pfnDllRelease))();

		::FreeLibrary(m_vAllPlugin[i].hModule);
		m_vAllPlugin[i].hModule = NULL;
	}

	m_vAllPlugin.clear();
}

//�رպ���
VOID tKernel::ShutDown(VOID)
{
	//�ͷŽڵ���
	m_theRoot.Release();

	//�ͷ����в��
	FreeAllPlugin();
}