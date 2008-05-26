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
m_pBox(NULL),
m_pCircle(NULL),
m_pTriangle(NULL),
m_pSprite(new Sprite()),
m_pAnimation(new Sprite())
{

}

//---------------------------------------------------------------------------
bool ForceGame::onInit()
{
	m_pBox = new ForceBOX();
	m_pCircle = new ForceCIRCLE(130);
	m_pTriangle = new ForceTRIANGLE();
	m_pTexture = Texture::Ptr(new Texture("../../res/Force Logo.png"));

	if(!g_graficos->loadTexture("../../res/Force Logo.png", * m_pTexture))
	{
		return false;
	}

	m_pSprite->setDim(512,512);
	m_pSprite->setTexture(m_pTexture);
	m_pSprite->setTextureArea(0,0,512,512);
	m_pSprite->setPosXY(0,0);

	/*m_pBox->setDim(50,50);
	m_pBox->setPosXY(-325,200);

	m_pCircle->setPosXY(-325,0);
	m_pCircle->setDim(50,50);

	m_pTriangle->setDim(50,50);
	m_pTriangle->setPosXY(-325,-200);

	addEntity(m_pBox);
	addEntity(m_pCircle);
	addEntity(m_pTriangle);*/
	addEntity(m_pSprite);

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onLoop()
{
	//m_pBox->Draw(*g_graficos);
	//m_pCircle->Draw(*g_graficos);
	//m_pTriangle->Draw(*g_graficos);
	m_pSprite->Draw(*g_graficos);

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onDeInit()
{
	delete m_pBox;
	m_pBox = NULL;

	delete m_pCircle;
	m_pCircle = NULL;

	delete m_pTriangle;
	m_pTriangle = NULL;

	delete m_pSprite;
	m_pSprite = NULL;

	delete m_pAnimation;
	m_pAnimation = NULL;

	return true;
}

//---------------------------------------------------------------------------
ForceGame::~ForceGame()
{

}

//---------------------------------------------------------------------------