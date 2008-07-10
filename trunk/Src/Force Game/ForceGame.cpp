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
m_pkMyScene(new MyScene(* m_pkGraphics))
{
	setCurrentScene(m_pkMyScene);
}
//---------------------------------------------------------------------------
bool ForceGame::onInit()
{
	m_pkMyScene->Init(m_pkInput);

	return true;
}
//---------------------------------------------------------------------------
bool ForceGame::onLoop()
{
	m_pkMyScene->Update(m_pkTimer->getTimeBetweenFrames());

	m_pkMyScene->Draw(* m_pkGraphics);

	return true;
}
//---------------------------------------------------------------------------
bool ForceGame::onDeInit()
{
	m_pkMyScene->deInit();

	return true;
}
//---------------------------------------------------------------------------
ForceGame::~ForceGame()
{

}
//---------------------------------------------------------------------------