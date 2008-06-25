/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: MyScene.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "MyScene.h"
//---------------------------------------------------------------------------
MyScene::MyScene(Graphics & rkGraphics)
:
Scene(rkGraphics),
m_pkGhost(NULL)
{
	
}

//---------------------------------------------------------------------------
bool MyScene::onInit()
{
	m_pkGhost = new Sprite();

	FMOD_RESULT result;

	FMOD::Sound * pkSonido;
	FMOD::System * pkSystem;
	FMOD::Channel * pkChannel;

	result = FMOD::System_Create(&pkSystem);
	result = pkSystem->setSoftwareChannels(100);
	result = pkSystem->setHardwareChannels(32, 64, 32, 64);
	result = pkSystem->init(200, FMOD_INIT_NORMAL, 0);
	result = pkSystem->setSpeakerMode(FMOD_SPEAKERMODE_STEREO);
	result = pkSystem->createSound("../../res/transform.wav",FMOD_DEFAULT,0,& pkSonido);
	result = pkSystem->playSound(FMOD_CHANNEL_FREE,pkSonido, false, &pkChannel);
	result = pkChannel->setVolume(0.5f);
	result = pkChannel->setPaused(false);

	m_pkPacman = Texture::Ptr(new Texture("../../res/Pacman.bmp", D3DCOLOR_XRGB(255,255,255)));

	if(!m_pkGraphics->loadTexture("../../res/Pacman.bmp", * m_pkPacman))
	{
		return false;
	}

	m_pkGhost->setDim(64,64);
	m_pkGhost->setPosXY(0,200);
	m_pkGhost->setTexture(m_pkPacman);
	m_pkGhost->setTextureArea(18,18,18,18);

	addEntity(m_pkGhost);

	return true;
}

//---------------------------------------------------------------------------
bool MyScene::onUpdate(float fTimeBetweenFrames)
{
	updateGhostInput();

	return true;
}

//---------------------------------------------------------------------------
void MyScene::onDraw(Graphics & rkGraphics) const
{
	/***/
}

//---------------------------------------------------------------------------
bool MyScene::onDeInit()
{
	delete m_pkGhost;
	m_pkGhost = NULL;

	return true;
}

//---------------------------------------------------------------------------
void MyScene::updateGhostInput()
{
	m_pkGhost->setPosXY(
		m_pkGhost->getPosX() + m_pkInput->getMouseRelPosX(),
		m_pkGhost->getPosY() - m_pkInput->getMouseRelPosY()
		);
}

//---------------------------------------------------------------------------
MyScene::~MyScene()
{
	/***/
}

//---------------------------------------------------------------------------