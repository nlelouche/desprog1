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
m_pSpriteAnim(new Sprite())
{

}

//---------------------------------------------------------------------------
bool ForceGame::onInit()
{
	m_pAnimationInfo = AnimationInfo::Ptr(new AnimationInfo());
	m_pkPacman = Texture::Ptr(new Texture("../../res/Pacman.bmp"));

	if(!m_pGraficos->loadTexture("../../res/Pacman.bmp", * m_pkPacman))
	{
		return false;
	}

	m_pSpriteAnim->setTexture(m_pkPacman);
	m_pSpriteAnim->setDim(128,128);

	m_pAnimationInfo->addFrame(0,0,18,18);
	m_pAnimationInfo->addFrame(18,0,18,18);
	m_pAnimationInfo->addFrame(36,0,18,18);

	m_pAnimationInfo->setLength(350.0f);
	m_pAnimationInfo->setLoopable(true);

	m_pAnimation = new Animation(m_pAnimationInfo);

	m_pSpriteAnim->setAnimation(m_pAnimation);

	m_pAnimation->Play();

	addEntity(m_pSpriteAnim);

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onLoop()
{
	m_pSpriteAnim->Update(m_pkTimer->getTimeBetweenFrames());
	m_pSpriteAnim->Draw(*m_pGraficos);

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onDeInit()
{
	delete m_pSpriteAnim;
	m_pSpriteAnim = NULL;

	delete m_pAnimation;
	m_pAnimation = NULL;

	return true;
}

//---------------------------------------------------------------------------
ForceGame::~ForceGame()
{

}

//---------------------------------------------------------------------------