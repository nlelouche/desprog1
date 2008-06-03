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
	m_gGraficos = new Graphics();
	m_wWindow = new Window(m_hInstance);

	if(!m_wWindow->createWindow(800, 600))
	{
		return false;
	}

	if(!m_gGraficos->InitDX(m_wWindow))
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

	for(unsigned int i = 0; i < m_apkEntities.size(); i++)
	{
		m_apkEntities[i]->Update(m_pkTimer->getTimeBetweenFrames());
	}

	m_gGraficos->Clear();
	m_gGraficos->BeginScene();

	onLoop();

	// Nombre del Engine y Frames Per Second

	stringstream s;

	s << "Force Engine v0.5 | FPS: " << m_pkTimer->getFPS();

	m_wWindow->SetWindowTitle(s.str().c_str());

	m_pkTimer->Measure();

	m_gGraficos->EndScene();
	m_gGraficos->Present();

	return true;
}

//---------------------------------------------------------------------------
bool Game::deInit()
{
	onDeInit();

	delete m_gGraficos;
	m_gGraficos = NULL;

	delete m_wWindow;
	m_wWindow = NULL;

	delete m_pkTimer;
	m_pkTimer = NULL;

	return true;
}

//---------------------------------------------------------------------------