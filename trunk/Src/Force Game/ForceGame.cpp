/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Force Game.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "ForceGame.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
ForceGame::ForceGame(HINSTANCE hInstance)
:
Game(hInstance),
m_pPhantom(new Sprite()),
m_pPacman(new Sprite()),
m_pShapeBox1(new ForceBOX()),
m_pShapeBox2(new ForceBOX()),
m_pShapeRoof(new ForceBOX()),
m_pShapeFloor(new ForceBOX())
{
	/*****/
}

//---------------------------------------------------------------------------
bool ForceGame::onInit()
{
	m_pAnimationInfoPac = AnimationInfo::Ptr(new AnimationInfo());
	m_pAnimationInfoPacMuerte = AnimationInfo::Ptr(new AnimationInfo());

	m_pkPacman = Texture::Ptr(new Texture("../../res/Pacman.bmp", D3DCOLOR_XRGB(255,255,255)));

	if(!m_pGraficos->loadTexture("../../res/Pacman.bmp", * m_pkPacman))
	{
		return false;
	}

	// COMIENZO SHAPES COMUNES /**********************************************************/

	m_pShapeRoof->setDim(800,20);
	m_pShapeRoof->setPosXY(0,300);

	m_pShapeFloor->setDim(800,20);
	m_pShapeFloor->setPosXY(0,-300);

	m_pShapeBox1->setDim(64,64);
	m_pShapeBox1->setPosXY(-300,-200);

	m_pShapeBox2->setDim(64,64);
	m_pShapeBox2->setPosXY(300,-200);

	// FIN SHAPES COMUNES      /**********************************************************/

	m_pPacman->setDim(64,64);
	m_pPacman->setPosXY(0,-200);
	m_pPacman->setTexture(m_pkPacman);
	m_pPacman->setMoving(true);
	m_pPacman->setMovingSpeed(80.0f);
	m_pPacman->setMovingAngle(0.0f);

	m_pAnimationInfoPac->addFrame(0,0,18,18);
	m_pAnimationInfoPac->addFrame(18,0,18,18);
	m_pAnimationInfoPac->addFrame(36,0,18,18);
	m_pAnimationInfoPac->setLength(350.0f);
	m_pAnimationInfoPac->setLoopable(true);

	m_pPhantom->setDim(64,64);
	m_pPhantom->setPosXY(0,200);
	m_pPhantom->setTexture(m_pkPacman);
	m_pPhantom->setTextureArea(18,18,18,18);
	m_pPhantom->setMoving(true);
	m_pPhantom->setMovingSpeed(80.0f);
	m_pPhantom->setMovingAngle(90.0f);

	m_pAnimationInfoPacMuerte->addFrame(36,0,18,18);
	m_pAnimationInfoPacMuerte->addFrame(90,0,18,18);
	m_pAnimationInfoPacMuerte->addFrame(108,0,18,18);
	m_pAnimationInfoPacMuerte->addFrame(72,0,18,18);
	m_pAnimationInfoPacMuerte->addFrame(54,0,18,18);
	m_pAnimationInfoPacMuerte->addFrame(108,18,18,18);
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

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onLoop()
{
	m_pPacman->Update(m_pkTimer->getTimeBetweenFrames());
	m_pPhantom->Update(m_pkTimer->getTimeBetweenFrames());
	m_pShapeBox1->Update(m_pkTimer->getTimeBetweenFrames());
	m_pShapeBox2->Update(m_pkTimer->getTimeBetweenFrames());
	m_pShapeRoof->Update(m_pkTimer->getTimeBetweenFrames());
	m_pShapeFloor->Update(m_pkTimer->getTimeBetweenFrames());

	m_pAnimationPac->Play();

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

	m_pPacman->Draw(*m_pGraficos);
	m_pPhantom->Draw(*m_pGraficos);
	m_pShapeBox1->Draw(*m_pGraficos);
	m_pShapeBox2->Draw(*m_pGraficos);
	m_pShapeRoof->Draw(*m_pGraficos);
	m_pShapeFloor->Draw(*m_pGraficos);

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onDeInit()
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
ForceGame::~ForceGame()
{

}

//---------------------------------------------------------------------------