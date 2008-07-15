/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Window.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Window.h"
//---------------------------------------------------------------------------
Window::Window(HINSTANCE hInstance)
:
m_hInstance(hInstance),
m_pkTimer(NULL)
{
	m_pkTimer = new Timer();
}
//---------------------------------------------------------------------------
bool Window::createWindow(unsigned int uiWidth, unsigned int uiHeight)
{
	WNDCLASS kWC;

	memset(static_cast <void *> (&kWC), 0, sizeof(WNDCLASS));

	kWC.style = CS_HREDRAW | CS_VREDRAW;
	kWC.lpfnWndProc = (WNDPROC) WndProc;
	kWC.hInstance = m_hInstance;
	kWC.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
	kWC.lpszClassName = "Force Window";

	if(!RegisterClass(&kWC))
	{
		return false;
	}

	m_hWnd = CreateWindow(
						  "Force Window",
						  "",
						  WS_OVERLAPPEDWINDOW,
						  CW_USEDEFAULT,
						  CW_USEDEFAULT,
						  uiWidth + 8,
						  uiHeight + 30,
						  NULL,
						  NULL,
						  m_hInstance,
						  NULL
						  );

	if (!m_hWnd)
	{
		return false;
	}

	ShowWindow(m_hWnd,SW_SHOW);
	UpdateWindow(m_hWnd);

	return true;
}
//---------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message) 
	{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}
//---------------------------------------------------------------------------
void Window::SetWindowTitle(LPCSTR lpString)
{
	SetWindowText(m_hWnd, lpString);
}
//---------------------------------------------------------------------------
Window::~Window()
{
	delete m_pkTimer;
	m_pkTimer = NULL;
}
//---------------------------------------------------------------------------