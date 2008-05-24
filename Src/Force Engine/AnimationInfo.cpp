/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: AnimationInfo.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "AnimationInfo.h"
#include "Sprite.h"
//---------------------------------------------------------------------------

void AnimationInfo::addFrame(
							unsigned int uiOffsetX, 
							unsigned int uiOffsetY, 
							unsigned int uiWidth, 
							unsigned int uiHeight
							)
{
	FrameInfo kInfo;
	kInfo.uiOffsetX = uiOffsetX;
	kInfo.uiOffsetY = uiOffsetY;
	kInfo.uiWidth = uiWidth;
	kInfo.uiHeight = uiHeight;

	m_akFramesInfo.push_back(kInfo);

	m_fTimePerFrame = m_fLength / getFrameCount();
}