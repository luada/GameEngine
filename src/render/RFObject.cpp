#include "StdAfx.h"
#include "RFObject.h"
#include "render/RenderSystem.h"
#include "moo/System.h"
#include "moo/System.h"
#include <OgreSceneManager.h>

CWXObject::CWXObject()
{
	m_nRayQueryLevel = RL_UNKNOWN;
	m_nData = 0;
}

CWXObject::~CWXObject()
{
}

VOID CWXObject::Destroy(VOID)
{
	//ɾ������
	CRenderSystem::GetMe()->Destroy_EntityObject(this);
	return;
	//֮���ܵ����κδ���
	//...
}

