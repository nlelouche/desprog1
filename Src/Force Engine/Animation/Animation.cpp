/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Animation.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Animation.h"
//---------------------------------------------------------------------------
Animation::Animation(AnimationInfo::Ptr pkInfo)
:
m_pkInfo(pkInfo),
m_uiCurrentFrame(0),
m_fCurrentFrameTime(0),
m_eCurrentState(STOP)
{
	/***/
}
//---------------------------------------------------------------------------
Animation::~Animation()
{
	/***/
}
//---------------------------------------------------------------------------
void Animation::Play()
{
	m_eCurrentState = PLAY;

	if(m_eCurrentState == STOP)
	{
		m_uiCurrentFrame = 0;
		m_fCurrentFrameTime = 0.0f;
	}
}
//---------------------------------------------------------------------------
void Animation::Stop()
{
	m_eCurrentState = STOP;
}
//---------------------------------------------------------------------------
void Animation::Update(float fTimeBetweenFrames)
{
	assert(m_pkInfo.get());

	if(m_eCurrentState != PLAY)
	{
		return;
	}

	m_fCurrentFrameTime += fTimeBetweenFrames;

	while(m_fCurrentFrameTime > m_pkInfo->getTimePerFrame())
	{
		m_fCurrentFrameTime -= m_pkInfo->getTimePerFrame();

		m_uiCurrentFrame++;

		if(m_uiCurrentFrame >= m_pkInfo->getFrameCount())
		{
			m_uiCurrentFrame = 0;

			if(!m_pkInfo->getLoopable())
			{
				Stop();
			}
		}
	}
}
//---------------------------------------------------------------------------