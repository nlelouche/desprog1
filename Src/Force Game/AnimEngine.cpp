/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: AnimEngine.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "AnimEngine.h"
//---------------------------------------------------------------------------
AnimEngine::AnimEngine(Graphics & rkGraphics)
:
Scene(rkGraphics),
m_pkAnimationLogo(NULL),
m_pkSpriteLogoFist(NULL),
m_pkSpriteLogoGear(NULL)
{
	/***/
}
//---------------------------------------------------------------------------
bool AnimEngine::onInit()
{
	// FMOD INIT INTRO AUDIO TRANSFORMERS

	FMOD_RESULT result;

	FMOD::Sound * pkSonido;
	FMOD::System * pkSystem;
	FMOD::Channel * pkChannel;

	result = FMOD::System_Create(&pkSystem);
	result = pkSystem->setSoftwareChannels(100);
	result = pkSystem->setHardwareChannels(32, 64, 32, 64);
	result = pkSystem->init(1, FMOD_INIT_NORMAL, 0);
	result = pkSystem->setSpeakerMode(FMOD_SPEAKERMODE_STEREO);
	result = pkSystem->createSound("../../res/transform.wav",FMOD_DEFAULT,0,& pkSonido);
	result = pkSystem->playSound(FMOD_CHANNEL_FREE,pkSonido, false, &pkChannel);
	result = pkChannel->setVolume(0.5f);
	result = pkChannel->setPaused(false);

	// INIT SPRITE Y TEXTURE LOGO

	m_pkSpriteLogoFist = new Sprite();
	m_pkSpriteLogoGear = new Sprite();

	m_pkTextureLogoFist = Texture::Ptr(new Texture("../../res/Force Logo.png", D3DCOLOR_XRGB(255,255,255)));
	m_pkTextureLogoGear = Texture::Ptr(new Texture("../../res/Force Logo 2.png", D3DCOLOR_XRGB(255,255,255)));

	if(!m_pkGraphics->loadTexture("../../res/Force Logo.png", * m_pkTextureLogoFist))
	{
		return false;
	}

	if(!m_pkGraphics->loadTexture("../../res/Force Logo 2.png", * m_pkTextureLogoGear))
	{
		return false;
	}

	m_pkSpriteLogoFist->setTexture(m_pkTextureLogoFist);
	m_pkSpriteLogoFist->setDim(256,256);
	m_pkSpriteLogoFist->setPosXYZ(0,0,1);

	m_pkSpriteLogoGear->setTexture(m_pkTextureLogoGear);
	m_pkSpriteLogoGear->setDim(256,256);
	m_pkSpriteLogoGear->setPosXYZ(0,0,0);

	addEntity(m_pkSpriteLogoGear);
	addEntity(m_pkSpriteLogoFist);

	return true;
}
//---------------------------------------------------------------------------
bool AnimEngine::onUpdate(float fTimeBetweenFrames)
{
	rotateLogo(fTimeBetweenFrames);

	return true;
}
//---------------------------------------------------------------------------
void AnimEngine::rotateLogo(float fTimeBetweenFrames)
{
	static float m_fAngle = 0.0f;
	static float m_fAccel = 0.001f;

	m_fAngle += fTimeBetweenFrames * m_fAccel;
	
	m_pkSpriteLogoFist->setRotationZ(m_fAngle);

	m_pkSpriteLogoFist->Update(fTimeBetweenFrames);
	m_pkSpriteLogoGear->Update(fTimeBetweenFrames);

	if(m_fAccel < 0.5f)
	{
		m_fAccel += 0.001f;
	}
}
//---------------------------------------------------------------------------
void AnimEngine::onDraw(Graphics & rkGraphics) const
{
	/***/
}
//---------------------------------------------------------------------------
bool AnimEngine::onDeInit()
{
	delete m_pkSpriteLogoFist;
	m_pkSpriteLogoFist = NULL;

	delete m_pkSpriteLogoGear;
	m_pkSpriteLogoGear = NULL;

	return true;
}
//---------------------------------------------------------------------------
AnimEngine::~AnimEngine()
{
	/***/
}
//---------------------------------------------------------------------------