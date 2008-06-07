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
m_pPacmanAnim(new Sprite()),
m_pShapeBox(new ForceBOX())
{
	/*****/
}

//---------------------------------------------------------------------------
bool ForceGame::onInit()
{
	m_pAnimationInfo = AnimationInfo::Ptr(new AnimationInfo());
	m_pkPacman = Texture::Ptr(new Texture("../../res/Pacman.bmp", D3DCOLOR_XRGB(255,255,255)));

	if(!m_pGraficos->loadTexture("../../res/Pacman.bmp", * m_pkPacman))
	{
		return false;
	}

	m_pShapeBox->setDim(64,64);
	m_pShapeBox->setPosXY(-200,0);

	m_pPhantom->setDim(64,64);
	m_pPhantom->setPosXY(200,0);
	m_pPhantom->setTexture(m_pkPacman);
	m_pPhantom->setTextureArea(18,18,18,18);

	m_pPacmanAnim->setDim(64,64);
	m_pPacmanAnim->setPosXY(0,0);
	m_pPacmanAnim->setTexture(m_pkPacman);

	m_pAnimationInfo->addFrame(0,0,18,18);
	m_pAnimationInfo->addFrame(18,0,18,18);
	m_pAnimationInfo->addFrame(36,0,18,18);

	m_pAnimationInfo->setLength(350.0f);
	m_pAnimationInfo->setLoopable(true);

	m_pAnimation = new Animation(m_pAnimationInfo);

	m_pPacmanAnim->setMoving(true);
	m_pPacmanAnim->setMovingSpeed(80.0f);
	m_pPacmanAnim->setMovingAngle(0.0f);
	m_pPacmanAnim->setAnimation(m_pAnimation);

	m_pAnimation->Play();

	addEntity(m_pPhantom);
	addEntity(m_pShapeBox);
	addEntity(m_pPacmanAnim);

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onLoop()
{
	m_pPacmanAnim->Update(m_pkTimer->getTimeBetweenFrames());
	m_pPhantom->Update(m_pkTimer->getTimeBetweenFrames());
	m_pShapeBox->Update(m_pkTimer->getTimeBetweenFrames());
	
	m_pPacmanAnim->Draw(*m_pGraficos);
	m_pPhantom->Draw(*m_pGraficos);
	m_pShapeBox->Draw(*m_pGraficos);

	Entity2D::CollisionResult eResult = m_pPacmanAnim->checkCollision(m_pPhantom);

	if(eResult != Entity2D::None)
	{
		m_pPacmanAnim->setPosXY(m_pPacmanAnim->getPrevPosX(), m_pPacmanAnim->getPrevPosY());

		if(eResult == Entity2D::Horizontal)
		{
			float fAngle = m_pPacmanAnim->getMovingAngle();

			m_pPacmanAnim->setMovingAngle(360.0f - fAngle);
			m_pPacmanAnim->setRotationZ(360.0f - fAngle);
		}	
		else if(eResult == Entity2D::Vertical)
		{
			float fAngle = m_pPacmanAnim->getMovingAngle();

			m_pPacmanAnim->setMovingAngle(180.0f - fAngle);
			m_pPacmanAnim->setRotationZ(180.0f - fAngle);
		}	
	}

	eResult = m_pPacmanAnim->checkCollision(m_pShapeBox);
	
	if(eResult != Entity2D::None)
	{
		m_pPacmanAnim->setPosXY(m_pPacmanAnim->getPrevPosX(), m_pPacmanAnim->getPrevPosY());

		if(eResult == Entity2D::Horizontal)
		{
			float fAngle = m_pPacmanAnim->getMovingAngle();

			m_pPacmanAnim->setMovingAngle(360.0f - fAngle);
			m_pPacmanAnim->setRotationZ(360.0f - fAngle);
		}	
		else if(eResult == Entity2D::Vertical)
		{
			float fAngle = m_pPacmanAnim->getMovingAngle();

			m_pPacmanAnim->setMovingAngle(180.0f - fAngle);
			m_pPacmanAnim->setRotationZ(180.0f - fAngle);
		}	
	}

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onDeInit()
{
	delete m_pPacmanAnim;
	m_pPacmanAnim = NULL;
	
	delete m_pShapeBox;
	m_pShapeBox = NULL;

	delete m_pPhantom;
	m_pPhantom = NULL;

	delete m_pAnimation;
	m_pAnimation = NULL;

	return true;
}

//---------------------------------------------------------------------------
ForceGame::~ForceGame()
{

}

//---------------------------------------------------------------------------