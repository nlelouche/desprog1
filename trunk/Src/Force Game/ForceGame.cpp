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
m_pSprite(new Sprite()),
m_pSpriteAnim(new Sprite())
{

}

//---------------------------------------------------------------------------
bool ForceGame::onInit()
{
	m_pTexture = Texture::Ptr(new Texture("../../res/Force Logo.png"));
	m_pAnimationInfo = AnimationInfo::Ptr(new AnimationInfo());

	if(!g_graficos->loadTexture("../../res/Force Logo.png", * m_pTexture))
	{
		return false;
	}

	m_pSprite->setTexture(m_pTexture);
	m_pSprite->setDim(256,256);
	m_pSprite->setTextureArea(0,0,256,256);

	m_pSpriteAnim->setTexture(m_pTexture);
	m_pSpriteAnim->setDim(800,600);

	for(int i = 256; i > 0; i--)
	{
		m_pAnimationInfo->addFrame(0,0,i,i);
	}

	m_pAnimationInfo->setLength(5000.0f);
	m_pAnimationInfo->setLoopable(false);

	m_pAnimation = new Animation(m_pAnimationInfo);

	m_pSpriteAnim->setAnimation(m_pAnimation);

	m_pAnimation->Play();

	addEntity(m_pSprite);
	addEntity(m_pSpriteAnim);

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onLoop()
{
	m_pSpriteAnim->Update(m_pkTimer->getTimeBetweenFrames());

	//m_pSprite->Draw(*g_graficos);
	m_pSpriteAnim->Draw(*g_graficos);

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onDeInit()
{
	delete m_pSprite;
	m_pSprite = NULL;

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