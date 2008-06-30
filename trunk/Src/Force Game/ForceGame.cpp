/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: ForceGame.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "ForceGame.h"
//---------------------------------------------------------------------------
ForceGame::ForceGame(HINSTANCE hInstance)
:
Game(hInstance),
m_pkAnimEngine(NULL)
{
	
}
//---------------------------------------------------------------------------
bool ForceGame::onInit()
{
	m_pkAnimEngine = new AnimEngine(* m_pkGraficos);

	setCurrentScene(m_pkAnimEngine);

	m_pkAnimEngine->Init(m_pkInput);

	return true;
}
//---------------------------------------------------------------------------
bool ForceGame::onLoop()
{
	m_pkAnimEngine->Update(m_pkTimer->getTimeBetweenFrames());

	if(m_pkInput->getKeyDown(DIK_ESCAPE))
	{
		return true;
	}

	m_pkAnimEngine->Draw(* m_pkGraficos);

	return true;
}
//---------------------------------------------------------------------------
bool ForceGame::onDeInit()
{
	m_pkAnimEngine->onDeInit();

	return true;
}
//---------------------------------------------------------------------------
ForceGame::~ForceGame()
{
	delete m_pkAnimEngine;
	m_pkAnimEngine = NULL;
}
//---------------------------------------------------------------------------