/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Game.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Game.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
Game::Game()
{
	
}

//---------------------------------------------------------------------------
Game::~Game()
{

}

//---------------------------------------------------------------------------
bool Game::Init()
{
	g_window = new Window(hInstance);
	g_graficos = new Graphics();

	if(!g_window->createWindow(800, 600))
	{
		return false;
	}

	if(!g_graficos->InitDX(g_window))
	{
		return false;
	}

	onInit();

	return true;
}

//---------------------------------------------------------------------------
bool Game::Loop()
{
	g_graficos->Clear();
	g_graficos->BeginScene();
	g_graficos->Present();

	m_Shape.Draw(*g_graficos);

	onLoop();

	g_graficos->EndScene();

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