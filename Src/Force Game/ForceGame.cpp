/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: ForceGame.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "ForceGame.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
ForceGame::ForceGame(HINSTANCE hInstance)
:
Game(hInstance),
m_pkMyScene(NULL)
{

}

//---------------------------------------------------------------------------
bool ForceGame::onInit()
{
	m_pkMyScene = new MyScene(*m_pGraficos);

	setCurrentScene(m_pkMyScene);

	m_pkMyScene->Init();

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onLoop()
{
	m_pkMyScene->Update(m_pkTimer->getTimeBetweenFrames());
	m_pkMyScene->Draw(*m_pGraficos);

	return true;
}

//---------------------------------------------------------------------------
bool ForceGame::onDeInit()
{
	m_pkMyScene->onDeInit();

	return true;
}

//---------------------------------------------------------------------------
ForceGame::~ForceGame()
{
	delete m_pkMyScene;	
	m_pkMyScene = NULL;
}

//---------------------------------------------------------------------------