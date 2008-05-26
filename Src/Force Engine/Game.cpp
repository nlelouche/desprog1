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
m_hInstance(hInstance)
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

	return onInit();
}

//---------------------------------------------------------------------------
bool Game::Loop()
{
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

	return true;
}

//---------------------------------------------------------------------------