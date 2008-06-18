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
m_pPacman(NULL),
m_pPhantom(NULL),
m_pShapeBox1(NULL),
m_pShapeBox2(NULL),
m_pShapeRoof(NULL),
m_pShapeFloor(NULL),
m_pAnimationPac(NULL),
m_pAnimationPacMuerte(NULL)
{
	
}

//---------------------------------------------------------------------------
bool MyScene::onInit()
{
	m_pPacman = new Sprite();
	m_pPhantom = new Sprite();

	m_pShapeBox1 = new ForceBOX();
	m_pShapeBox2 = new ForceBOX();
	m_pShapeRoof = new ForceBOX();
	m_pShapeFloor = new ForceBOX();

	FMOD_RESULT result;

	FMOD::System * system;
	FMOD::Sound * m_pSonido;
	FMOD::Channel *channel;

	result = FMOD::System_Create(&system);
	result = system->setSoftwareChannels(100);
	result = system->setHardwareChannels(32, 64, 32, 64);
	result = system->init(200, FMOD_INIT_NORMAL, 0);
	result = system->setSpeakerMode(FMOD_SPEAKERMODE_STEREO);
	result = system->createSound("../../res/transform.wav",FMOD_DEFAULT,0,& m_pSonido);
	result = system->playSound(FMOD_CHANNEL_FREE,m_pSonido, false, &channel);
	result = channel->setVolume(0.5f);
	result = channel->setPaused(false);

	m_pAnimationInfoPac = AnimationInfo::Ptr(new AnimationInfo());
	m_pAnimationInfoPacMuerte = AnimationInfo::Ptr(new AnimationInfo());

	m_pkPacman = Texture::Ptr(new Texture("../../res/Pacman.bmp", D3DCOLOR_XRGB(255,255,255)));

	if(!m_pkGraphics->loadTexture("../../res/Pacman.bmp", * m_pkPacman))
	{
		return false;
	}

	m_pShapeRoof->setDim(800,20);
	m_pShapeRoof->setPosXY(0,300);

	m_pShapeFloor->setDim(800,20);
	m_pShapeFloor->setPosXY(0,-300);

	m_pShapeBox1->setDim(64,64);
	m_pShapeBox1->setPosXY(-300,-200);

	m_pShapeBox2->setDim(64,64);
	m_pShapeBox2->setPosXY(300,-200);

	m_pPacman->setDim(64,64);
	m_pPacman->setPosXY(0,-200);
	m_pPacman->setTexture(m_pkPacman);
	m_pPacman->setMoving(true);
	m_pPacman->setMovingSpeed(80.0f);
	m_pPacman->setMovingAngle(0.0f);

	m_pAnimationInfoPac->addFrame(0,0,18,18);
	m_pAnimationInfoPac->addFrame(18,0,18,18);
	m_pAnimationInfoPac->addFrame(36,0,18,18);
	m_pAnimationInfoPac->setLength(200.0f);
	m_pAnimationInfoPac->setLoopable(true);

	m_pPhantom->setDim(64,64);
	m_pPhantom->setPosXY(0,200);
	m_pPhantom->setTexture(m_pkPacman);
	m_pPhantom->setTextureArea(18,18,18,18);
	m_pPhantom->setMoving(true);
	m_pPhantom->setMovingSpeed(80.0f);
	m_pPhantom->setMovingAngle(90.0f);

	m_pAnimationInfoPacMuerte->addFrame(108,18,18,18);
	m_pAnimationInfoPacMuerte->addFrame(36,0,18,18);
	m_pAnimationInfoPacMuerte->addFrame(90,0,18,18);
	m_pAnimationInfoPacMuerte->addFrame(108,0,18,18);
	m_pAnimationInfoPacMuerte->addFrame(72,0,18,18);
	m_pAnimationInfoPacMuerte->addFrame(54,0,18,18);
	m_pAnimationInfoPacMuerte->setLength(250.0f);
	m_pAnimationInfoPacMuerte->setLoopable(false);

	m_pAnimationPac = new Animation(m_pAnimationInfoPac);
	m_pAnimationPacMuerte = new Animation(m_pAnimationInfoPacMuerte);

	m_pPacman->setAnimation(m_pAnimationPac);

	addEntity(m_pPacman);
	addEntity(m_pPhantom);
	addEntity(m_pShapeRoof);
	addEntity(m_pShapeFloor);
	addEntity(m_pShapeBox1);
	addEntity(m_pShapeBox2);

	m_pAnimationPac->Play();

	return true;
}

//---------------------------------------------------------------------------
bool MyScene::onUpdate(float fTimeBetweenFrames)
{
	Entity2D::CollisionResult eResult = m_pPacman->checkCollision(m_pPhantom);

	if(eResult != Entity2D::None)
	{
		if(eResult == Entity2D::Horizontal)
		{
			float fSpeed = m_pPhantom->getMovingSpeed();

			m_pPhantom->setMovingSpeed(fSpeed * -1);

			m_pPacman->setAnimation(m_pAnimationPacMuerte);
			m_pAnimationPacMuerte->Play();
		}
		else if (eResult == Entity2D::Vertical)
		{
			float fSpeed = m_pPhantom->getMovingSpeed();

			m_pPhantom->setMovingSpeed(fSpeed * -1);

			m_pPacman->setAnimation(m_pAnimationPacMuerte);
			m_pAnimationPacMuerte->Play();
		}
	}

	eResult = m_pPhantom->checkCollision(m_pShapeRoof);

	if(eResult != Entity2D::None)
	{
		if(eResult == Entity2D::Horizontal)
		{
			float fSpeed = m_pPhantom->getMovingSpeed();

			m_pPhantom->setMovingSpeed(fSpeed * -1);
		}
		else if(eResult == Entity2D::Vertical)
		{
			float fSpeed = m_pPhantom->getMovingSpeed();

			m_pPhantom->setMovingSpeed(fSpeed * -1);
		}
	}

	eResult = m_pPhantom->checkCollision(m_pShapeFloor);

	if(eResult != Entity2D::None)
	{
		if(eResult == Entity2D::Horizontal)
		{
			float fSpeed = m_pPhantom->getMovingSpeed();

			m_pPhantom->setMovingSpeed(fSpeed * -1);
		}
		else if(eResult == Entity2D::Vertical)
		{
			float fSpeed = m_pPhantom->getMovingSpeed();

			m_pPhantom->setMovingSpeed(fSpeed * -1);
		}
	}

	eResult = m_pPacman->checkCollision(m_pShapeBox2);

	if(eResult != Entity2D::None)
	{
		m_pPacman->setPosXY(m_pPacman->getPrevPosX(), m_pPacman->getPrevPosY());

		if(eResult == Entity2D::Horizontal)
		{
			float fAngle = m_pPacman->getMovingAngle();

			m_pPacman->setMovingAngle(360.0f - fAngle);
			m_pPacman->setRotationZ(360.0f - fAngle);
		}	
		else if(eResult == Entity2D::Vertical)
		{
			float fAngle = m_pPacman->getMovingAngle();

			m_pPacman->setMovingAngle(180.0f - fAngle);
			m_pPacman->setRotationZ(180.0f - fAngle);
		}	
	}

	eResult = m_pPacman->checkCollision(m_pShapeBox1);

	if(eResult != Entity2D::None)
	{
		m_pPacman->setPosXY(m_pPacman->getPrevPosX(), m_pPacman->getPrevPosY());

		if(eResult == Entity2D::Horizontal)
		{
			float fAngle = m_pPacman->getMovingAngle();

			m_pPacman->setMovingAngle(360.0f - fAngle);
			m_pPacman->setRotationZ(360.0f - fAngle);
		}	
		else if(eResult == Entity2D::Vertical)
		{
			float fAngle = m_pPacman->getMovingAngle();

			m_pPacman->setMovingAngle(180.0f - fAngle);
			m_pPacman->setRotationZ(180.0f - fAngle);
		}	
	}

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
	delete m_pPacman;
	m_pPacman = NULL;

	delete m_pShapeBox1;
	m_pShapeBox1 = NULL;

	delete m_pShapeBox2;
	m_pShapeBox2 = NULL;

	delete m_pPhantom;
	m_pPhantom = NULL;

	delete m_pAnimationPac;
	m_pAnimationPac = NULL;

	delete m_pShapeRoof;
	m_pShapeRoof = NULL;

	delete m_pShapeFloor;
	m_pShapeFloor = NULL;

	return true;
}

//---------------------------------------------------------------------------
MyScene::~MyScene()
{
	/***/
}

//---------------------------------------------------------------------------