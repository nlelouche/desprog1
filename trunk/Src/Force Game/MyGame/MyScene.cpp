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
m_pkBack(NULL),
m_pkFloor(),
fGravity(0),
fPosX(0),
fPosY(0),
fVelocityX(0),
fVelocityY(0)
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

	// INIT SHAPES

	m_pkFloor = new ForceBOX();
	m_pkFloor->setDim(800,10);
	m_pkFloor->setPosXYZ(0,-285,1.0f);

	// FIN SHAPES

	// INIT SPRITE Y TEXTURE

	m_pkChar = new Sprite();
	m_pkBack = new Sprite();

	m_pkCharText = Texture::Ptr(new Texture("../../res/characterFinal.bmp",D3DCOLOR_XRGB(255,0,255)));
	if(!m_pkGraphics->loadTexture("../../res/characterFinal.bmp",* m_pkCharText))
	{
		return false;
	}
	
	m_pkChar->setTexture(m_pkCharText);
	m_pkChar->setTextureArea(0,0,128,128);
	m_pkChar->setDim(64,64);
	m_pkChar->setPosXYZ(0,0,1.0f);

	m_pkBackText = Texture::Ptr(new Texture("../../res/background.png",D3DCOLOR_XRGB(0,0,0)));
	if(!m_pkGraphics->loadTexture("../../res/background.png",* m_pkBackText))
	{
		return false;
	}

	m_pkBack->setTexture(m_pkBackText);
	m_pkBack->setTextureArea(0,0,512,512);
	m_pkBack->setDim(800,600);
	m_pkBack->setPosXYZ(0,0,-1.0f);

	// FIN TEXTURE Y SPRITES

	// INIT ANIMATION Y ANIMATION INFO

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

	m_pkChar->setAnimation(m_pkCharAnimIzq);
	m_pkChar->setAnimation(m_pkCharAnimDer);

	// FIN ANIMATION Y ANIMATION INFO

	// ADDING ENTITIES Y SET VELOCIDAD Y GRAVEDAD

	addEntity(m_pkBack);
	addEntity(m_pkChar);
	addEntity(m_pkFloor);

	fVelocityX = 0.0f;
	fVelocityY = 0.0f;
	fGravity = 0.006f;

	return true;
}
//---------------------------------------------------------------------------
bool MyScene::onUpdate(float fTimeBetweenFrames)
{
	m_pkBack->Update(fTimeBetweenFrames);
	m_pkChar->Update(fTimeBetweenFrames);
	m_pkCharAnimIzq->Update(fTimeBetweenFrames);
	m_pkCharAnimDer->Update(fTimeBetweenFrames);
	m_pkFloor->Update(fTimeBetweenFrames);

	updateCollisionChar();

	fPosX = m_pkChar->getPosX();
	fPosY = m_pkChar->getPosY();

	if(m_pkInput->getKeyDown(DIK_RIGHTARROW))
	{
		m_pkChar->setAnimation(m_pkCharAnimDer);
		m_pkChar->setMovingAngle(0.0f);
		fVelocityX += 0.005f;
		m_pkCharAnimDer->Play();
	}
	
	if(m_pkInput->getKeyDown(DIK_LEFTARROW))
	{
		m_pkChar->setAnimation(m_pkCharAnimIzq);
		m_pkChar->setMovingAngle(180.0f);
		fVelocityX -= 0.005f;
		m_pkCharAnimIzq->Play();
	}

	if (m_pkInput->getKeyDown(DIK_UPARROW) && fVelocityY == 0.0f) 
	{
		fVelocityY = 2.0f;
	}

	fVelocityY -= fGravity * fTimeBetweenFrames;

	fPosX += fVelocityX;
	fPosY += fVelocityY;

	m_pkChar->setPosXY(fPosX,fPosY);

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

	delete m_pkFloor;
	m_pkFloor = NULL;

	return true;
}
//---------------------------------------------------------------------------
void MyScene::updateCollisionChar()
{
	Entity2D::CollisionResult eResult;
	eResult = m_pkChar->checkCollision(m_pkFloor);

	if(eResult != Entity2D::None)
	{
		if(eResult == Entity2D::Vertical)
		{
			if(fVelocityY < 0.0f)
			{
				fVelocityY = 0.0f;
				m_pkChar->setPosY(m_pkFloor->getPosY() + m_pkFloor->getDimHeight() / 2 + m_pkChar->getDimHeight() / 2);
			}
		}
	}
}
//---------------------------------------------------------------------------
MyScene::~MyScene()
{
	/*****/
}
//---------------------------------------------------------------------------