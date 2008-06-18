/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Game.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Game.h"
#include <sstream>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
Game::Game(HINSTANCE hInstance)
:
m_hInstance(hInstance),
m_pkTimer(new Timer()),
m_pGraficos(new Graphics()),
m_pWindow(new Window(hInstance))
{
	
}

//---------------------------------------------------------------------------
Game::~Game()
{

}

//---------------------------------------------------------------------------
bool Game::Init()
{
	if(!m_pWindow->createWindow(800, 600))
	{
		return false;
	}

	if(!m_pGraficos->InitDX(m_pWindow))
	{
		return false;
	}

	m_pkTimer->FirstMeasure();

	return onInit();
}

//---------------------------------------------------------------------------
bool Game::Loop()
{
	assert(m_pkTimer);

	m_pkTimer->Measure();

	m_pGraficos->Clear();
	m_pGraficos->BeginScene();

	onLoop();

	// Nombre del Engine y Frames Per Second

	stringstream s;

	s << "Force Engine v0.5 | FPS: " << m_pkTimer->getFPS();

	m_pWindow->SetWindowTitle(s.str().c_str());

	m_pGraficos->EndScene();
	m_pGraficos->Present();

	return true;
}

//---------------------------------------------------------------------------
bool Game::deInit()
{
	delete m_pGraficos;
	m_pGraficos = NULL;

	delete m_pWindow;
	m_pWindow = NULL;

	delete m_pkTimer;
	m_pkTimer = NULL;

	return true;
}

//---------------------------------------------------------------------------