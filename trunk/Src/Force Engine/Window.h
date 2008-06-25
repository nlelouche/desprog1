/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Window.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef WINDOW_H
#define WINDOW_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "Timer.h"
#include "Defines.h"
#include <windows.h>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class FORCEENGINE_API Window
{
public:

	Window(HINSTANCE hInstance);
	~Window();

	bool createWindow(unsigned int uiWidth, unsigned int uiHeight);
	void SetWindowTitle(LPCSTR lpString);

	HWND m_hWnd;
	HINSTANCE m_hInstance;

private:

	Timer * m_pkTimer;

	friend class Graphics;
};

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

#endif /*--- WINDOW_H ---*/

//---------------------------------------------------------------------------
