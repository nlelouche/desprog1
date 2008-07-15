/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Animation.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef ANIMATION_H
#define ANIMATION_H
//---------------------------------------------------------------------------
#include "../Defines/Defines.h"
#include "../Animation/AnimationInfo.h."
//---------------------------------------------------------------------------
class FORCEENGINE_API Animation
{
public:

	enum PlayState
	{
		STOP,
		PLAY,
		PAUSE
	};

	Animation(AnimationInfo::Ptr pkInfo);
	~Animation();

	void Play();
	void Stop();

	PlayState getState() const;
	unsigned int getCurrentFrame() const;
	const AnimationInfo::Ptr getInfo() const;

	void Update(float fTimeBetweenFrames);

private:

	PlayState m_eCurrentState;
	AnimationInfo::Ptr m_pkInfo;

	float m_fCurrentFrameTime;
	unsigned int m_uiCurrentFrame;
};

//---------------------------------------------------------------------------
#include "Animation.inl"
//---------------------------------------------------------------------------

#endif /*--- ANIMATION_H ---*/

//---------------------------------------------------------------------------