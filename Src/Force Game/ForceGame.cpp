/****************************************************************************

Force Engine v0.1

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
m_pTexture(NULL),
m_pTriangle(NULL),
m_pSprite(new Sprite())
{

}

//---------------------------------------------------------------------------
ForceGame::~ForceGame()
{

}

//---------------------------------------------------------------------------
bool ForceGame::onInit()
{
	m_pTexture = new Texture("../../res/mierda.png");

	if(!g_graficos->loadTexture("../../res/mierda.png", m_pTexture))
	{
		return false;
	}

	m_pSprite->setTexture(m_pTexture);

	m_pSprite->setTextureArea(0,0,0,0);

	m_pBox = new ForceBOX();
	m_pBox->setDim(100,100);
	m_pBox->setPosXY(-200,200);

	m_pCircle = new ForceCIRCLE(130);
	m_pCircle->setPosXY(0,0);
	m_pCircle->setDim(100,100);

	m_pTriangle = new ForceTRIANGLE();
	m_pTriangle->setDim(100,100);
	m_pTriangle->setPosXY(200,-200);

	addEntity(m_pBox);
	addEntity(m_pCircle);
	addEntity(m_pTriangle);
	
	addEntity(m_pSprite);

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onLoop()
{
	m_pBox->Draw(*g_graficos);
	m_pCircle->Draw(*g_graficos);
	m_pTriangle->Draw(*g_graficos);

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

	delete m_pTexture;
	m_pTexture = NULL;

	return true;
}

//---------------------------------------------------------------------------