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
//m_pCircle(NULL),
m_pTriangle(NULL)
{

}

//---------------------------------------------------------------------------
ForceGame::~ForceGame()
{

}

//---------------------------------------------------------------------------
bool ForceGame::onInit()
{
	m_pBox = new ForceBOX();

	m_pBox->setDim(100,100);
	m_pBox->setPosXY(0,0);

	/*m_pCircle = new ForceCIRCLE();

	m_pCircle->setDim(100,100);
	m_pCircle->setPosXY(150,150);*/

	m_pTriangle = new ForceTRIANGLE();

	m_pTriangle->setDim(100,100);
	m_pTriangle->setPosXY(200,-100);

	addEntity(m_pBox);
	//addEntity(m_pCircle);
	addEntity(m_pTriangle);

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onLoop()
{
	m_pBox->Draw(*g_graficos);
	//m_pCircle->Draw(*g_graficos);
	m_pTriangle->Draw(*g_graficos);

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onDeInit()
{
	delete m_pBox;
	m_pBox = NULL;

	//delete m_pCircle;
	//m_pCircle = NULL;

	delete m_pTriangle;
	m_pTriangle = NULL;

	return true;
}

//---------------------------------------------------------------------------