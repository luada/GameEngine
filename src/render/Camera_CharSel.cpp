#include "StdAfx.h"
#include "render/RenderSystem.h"
#include "Camera_CharSel.h"
#include "ccom/TDMath.h"
#include <OgreCamera.h>
#include <OgreRoot.h>
#include "ccom/TDUtil.h"
#include "ccom/TDException.h"


CCamera_CharSel::CCamera_CharSel(Ogre::Camera* pOgreCamera)
	: CCamera(pOgreCamera)
{
	m_fvLookatPos = fVector3(0.0f, 80.0f, 0.0f);
	m_fPitch = 0.0f;
	m_fDistance = 250.0f;
	m_fDirection = TDU_PI;

	Update();
}

CCamera_CharSel::~CCamera_CharSel()
{
}

VOID CCamera_CharSel::Update(VOID)
{
	CCamera::Update();
	//ÉèÖÃOGREÏñ»ú
	m_pOgreCamera->setFarClipDistance(100000.0f);
}
