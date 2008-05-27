/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Game.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Game.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
Game::Game(HINSTANCE hInstance)
:
m_hInstance(hInstance),
m_pkTimer(NULL)
{
	
}

//---------------------------------------------------------------------------
Game::~Game()
{

}

//---------------------------------------------------------------------------
bool Game::Init()
{
	g_window = new Window(m_hInstance);
	g_graficos = new Graphics();

	if(!g_window->createWindow(800, 600))
	{
		return false;
	}

	if(!g_graficos->InitDX(g_window))
	{
		return false;
	}

	m_pkTimer = new Timer();

	m_pkTimer->FirstMeasure();

	return onInit();
}

//---------------------------------------------------------------------------
bool Game::Loop()
{
	assert(m_pkTimer);

	m_pkTimer->Measure();

	for(unsigned int i = 0; i < m_apkEntities.size(); i++)
	{
		m_apkEntities[i]->Update(m_pkTimer->getTimeBetweenFrames());
	}

	g_graficos->Clear();
	g_graficos->BeginScene();

	onLoop();

	g_graficos->EndScene();
	g_graficos->Present();

	return true;
}

//---------------------------------------------------------------------------
bool Game::deInit()
{
	onDeInit();

	delete g_graficos;
	g_graficos = NULL;

	delete g_window;
	g_window = NULL;

	delete m_pkTimer;
	m_pkTimer = NULL;

	return true;
}

//---------------------------------------------------------------------------