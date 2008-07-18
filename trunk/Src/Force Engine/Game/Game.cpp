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
m_pkInput(NULL),
m_pkTimer(new Timer()),
m_pkGraphics(new Graphics()),
m_pkWindow(new Window(hInstance))
{
	/*****/
}
//---------------------------------------------------------------------------
Game::~Game()
{
	/*****/
}
//---------------------------------------------------------------------------
bool Game::Init()
{
	if(!m_pkWindow->createWindow(800,600))
	{
		return false;
	}

	if(!m_pkGraphics->InitDX(m_pkWindow))
	{
		return false;
	}

	m_pkInput = new DirectInput(m_pkWindow->m_hInstance, m_pkWindow->m_hWnd);

	if(!m_pkInput->Init())
	{
		return false;
	}

	if(!onInit())
	{
		return false;
	}

	m_pkTimer->firstMeasure();

	return onInit();
}
//---------------------------------------------------------------------------
bool Game::Loop()
{
	assert(m_pkTimer);

	m_pkTimer->Measure();

	m_pkInput->Reacquire();

	m_pkGraphics->Clear();
	m_pkGraphics->BeginScene();

	onLoop();

	// Nombre del Engine y Frames Per Second

	stringstream s;

	s << "Force Engine v0.5 Beta | FPS: " << m_pkTimer->getFPS();

	m_pkWindow->SetWindowTitle(s.str().c_str());

	m_pkGraphics->EndScene();
	m_pkGraphics->Present();

	return true;
}
//---------------------------------------------------------------------------
bool Game::deInit()
{
	delete m_pkGraphics;
	m_pkGraphics = NULL;

	delete m_pkWindow;
	m_pkWindow = NULL;

	delete m_pkTimer;
	m_pkTimer = NULL;

	m_pkInput->deInit();
	delete m_pkInput;
	m_pkInput = NULL;

	return true;
}

//---------------------------------------------------------------------------