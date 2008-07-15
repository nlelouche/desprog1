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
m_pkChar(NULL),
m_pkCharAnimIzq(NULL),
m_pkCharAnimDer(NULL),
m_pkBack(NULL)
{
	
}
//---------------------------------------------------------------------------
bool MyScene::onInit()
{
	// FMOD INIT LOOPED THEME STAR WARS

	/*FMOD_RESULT result;

	FMOD::Sound * pkSonido;
	FMOD::System * pkSystem;
	FMOD::Channel * pkChannel;

	result = FMOD::System_Create(&pkSystem);
	result = pkSystem->setSoftwareChannels(20);
	result = pkSystem->setHardwareChannels(32, 64, 32, 64);
	result = pkSystem->init(20, FMOD_INIT_NORMAL, 0);
	result = pkSystem->setSpeakerMode(FMOD_SPEAKERMODE_MONO);
	result = pkSystem->createSound("../../res/StarWars.mp3",FMOD_DEFAULT,0,& pkSonido);
	result = pkSystem->playSound(FMOD_CHANNEL_FREE, pkSonido, false, &pkChannel);
	result = pkChannel->setFrequency(44000.0f);
	result = pkChannel->setVolume(0.5f);
	result = pkChannel->setPaused(false);
	result = pkChannel->setLoopCount(2);*/

	// INIT SPRITE Y TEXTURE

	m_pkChar = new Sprite();
	m_pkBack = new Sprite();

	m_pkCharText = Texture::Ptr(new Texture("../../res/character.png",D3DCOLOR_XRGB(0,0,0)));
	if(!m_pkGraphics->loadTexture("../../res/character.png",* m_pkCharText))
	{
		return false;
	}

	m_pkBackText = Texture::Ptr(new Texture("../../res/background.png",NULL));
	if(!m_pkGraphics->loadTexture("../../res/background.png",* m_pkBackText))
	{
		return false;
	}

	m_pkChar->setTexture(m_pkCharText);
	m_pkChar->setTextureArea(0,0,128,128);
	m_pkChar->setDim(64,64);
	m_pkChar->setPosXYZ(0,0,1.0f);

	m_pkBack->setTexture(m_pkBackText);
	m_pkBack->setTextureArea(0,0,512,512);
	m_pkBack->setDim(800,600);
	m_pkBack->setPosXYZ(0,0,0);

	m_pkCharAnimInfoDer = AnimationInfo::Ptr(new AnimationInfo());

	m_pkCharAnimInfoDer->addFrame(0,0,32,32);
	m_pkCharAnimInfoDer->addFrame(32,0,32,32);
	m_pkCharAnimInfoDer->addFrame(64,0,32,32);
	m_pkCharAnimInfoDer->addFrame(32,0,32,32);
	m_pkCharAnimInfoDer->setLength(900.0f);
	m_pkCharAnimInfoDer->setLoopable(true);
	m_pkCharAnimDer = new Animation(m_pkCharAnimInfoDer);

	m_pkCharAnimInfoIzq = AnimationInfo::Ptr(new AnimationInfo());

	m_pkCharAnimInfoIzq->addFrame(0,32,32,32);
	m_pkCharAnimInfoIzq->addFrame(32,32,32,32);
	m_pkCharAnimInfoIzq->addFrame(64,32,32,32);
	m_pkCharAnimInfoIzq->addFrame(32,32,32,32);
	m_pkCharAnimInfoIzq->setLength(900.0f);
	m_pkCharAnimInfoIzq->setLoopable(true);
	m_pkCharAnimIzq = new Animation(m_pkCharAnimInfoIzq);

	m_pkChar->setAnimation(m_pkCharAnimDer);

	addEntity(m_pkBack);
	addEntity(m_pkChar);

	return true;
}
//---------------------------------------------------------------------------
bool MyScene::onUpdate(float fTimeBetweenFrames)
{
	m_pkBack->Update(fTimeBetweenFrames);
	m_pkChar->Update(fTimeBetweenFrames);
	m_pkCharAnimIzq->Update(fTimeBetweenFrames);
	m_pkCharAnimDer->Update(fTimeBetweenFrames);

	if(m_pkInput->getKeyDown(DIK_RIGHTARROW))
	{
		m_pkChar->setAnimation(m_pkCharAnimDer);
		m_pkChar->setMoving(true);
		m_pkChar->setMovingSpeed(50.0f);
		m_pkChar->setMovingAngle(0.0f);
		m_pkCharAnimDer->Play();
	}
	
	if(m_pkInput->getKeyDown(DIK_LEFTARROW))
	{
		m_pkChar->setAnimation(m_pkCharAnimIzq);
		m_pkChar->setMoving(true);
		m_pkChar->setMovingSpeed(50.0f);
		m_pkChar->setMovingAngle(180.0f);
		m_pkCharAnimIzq->Play();
	}

	return true;
}
//---------------------------------------------------------------------------
void MyScene::onDraw(Graphics & rkGraphics) const
{
	/*****/
}
//---------------------------------------------------------------------------
bool MyScene::onDeInit()
{
	delete m_pkChar;
	m_pkChar = NULL;

	delete m_pkBack;
	m_pkBack = NULL;

	delete m_pkCharAnimIzq;
	m_pkCharAnimIzq = NULL;

	delete m_pkCharAnimDer;
	m_pkCharAnimDer = NULL;

	return true;
}
//---------------------------------------------------------------------------
MyScene::~MyScene()
{
	/*****/
}
//---------------------------------------------------------------------------