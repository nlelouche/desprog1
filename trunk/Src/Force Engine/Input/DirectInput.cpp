/****************************************************************************

Force Engine v0.5

Creado: 24/06/08
Clase: DirectInput.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "DirectInput.h"
//---------------------------------------------------------------------------
DirectInput::DirectInput(HINSTANCE hInstance, HWND hWnd)
:
m_lpObjectOne(NULL),
m_lpObjectTwo(NULL),
m_lpKeyboard(NULL),
m_lpMouse(NULL),
m_hInstance(hInstance),
m_hWnd(hWnd)
{
	/***/
}
//---------------------------------------------------------------------------
DirectInput::~DirectInput()
{
	/***/
}
//---------------------------------------------------------------------------
bool DirectInput::Init()
{
	POINT kCursorPos;
	GetCursorPos(&kCursorPos);

	m_lMouseScreenAbsPosition[0] = kCursorPos.x;
	m_lMouseScreenAbsPosition[1] = kCursorPos.y;
	m_lMouseScreenAbsPosition[2] = 0;

	static HRESULT hr;

	// Objeto del Input
	hr = DirectInput8Create(
							m_hInstance, 
							DIRECTINPUT_VERSION, 
							IID_IDirectInput8,
							(void**)&m_lpObjectOne, 
							NULL 
							);

	if(hr != D3D_OK)
	{
		return false;
	}

	// Direct Input Objeto Dispositivo
	hr = m_lpObjectOne->CreateDevice( GUID_SysKeyboard, &m_lpKeyboard, NULL );

	if(hr != D3D_OK)
	{
		return false;
	}

	// Setear el Formato de Datos del Teclado
	hr = m_lpKeyboard->SetDataFormat(&c_dfDIKeyboard);

	if(hr != D3D_OK)
	{
		return false;
	}

	hr = m_lpKeyboard->SetCooperativeLevel(m_hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

	if(hr != D3D_OK)
	{
		return false;
	}

	m_lpKeyboard->Acquire();		

	hr = DirectInput8Create( 
							m_hInstance, 
							DIRECTINPUT_VERSION, 
							IID_IDirectInput8,
							(void**)&m_lpObjectTwo,	
							NULL 
							);

	if(hr != D3D_OK)
	{
		return false;
	}

	hr = m_lpObjectTwo->CreateDevice(GUID_SysMouse, &m_lpMouse, NULL);

	if(hr != D3D_OK)
	{
		return false;
	}

	hr = m_lpMouse->SetDataFormat(&c_dfDIMouse);

	if(hr != D3D_OK)
	{
		return false;
	}

	hr = m_lpMouse->SetCooperativeLevel(m_hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

	if(hr != D3D_OK)
	{
		return false;
	}

	m_lpMouse->Acquire();

	if(hr != D3D_OK)
	{
		return false;
	}

	return true;
}
//---------------------------------------------------------------------------
void DirectInput::deInit()
{
	m_lpKeyboard->Unacquire();
	m_lpKeyboard->Release();
	m_lpKeyboard = NULL;
	m_lpObjectOne->Release();
	m_lpObjectOne = NULL;

	m_lpMouse->Unacquire();
	m_lpMouse->Release();
	m_lpMouse = NULL;
	m_lpObjectTwo->Release();
	m_lpObjectTwo = NULL;
}
//---------------------------------------------------------------------------
void DirectInput::Reacquire()
{
	//Readquirir Todos los Dispositivos de Input
	//Reset();

	m_lpMouse->Acquire();
	m_lpKeyboard->Acquire();

	Acquire();
}
//---------------------------------------------------------------------------
void DirectInput::Unacquire()
{
	//Desdquirir Todos los Dispositivos de Input

	ZeroMemory(&m_ucKeyBuffer, sizeof(m_ucKeyBuffer));
	ZeroMemory(&m_kMouseTaken, sizeof(m_kMouseTaken));
	m_lpMouse->Unacquire();
	m_lpKeyboard->Unacquire();
}
//---------------------------------------------------------------------------
void DirectInput::Acquire()
{
	// Traer el Estado del Teclado
	memcpy(m_ucKeyPrevBuffer, m_ucKeyBuffer, 256);
	ZeroMemory(&m_ucKeyBuffer, sizeof(m_ucKeyBuffer));
	m_lpKeyboard->GetDeviceState(sizeof(m_ucKeyBuffer), &m_ucKeyBuffer);

	// Traer el Estado del Mouse
	ZeroMemory(&m_kMouseTaken, sizeof(m_kMouseTaken));
	m_lpMouse->GetDeviceState( sizeof(m_kMouseTaken), &m_kMouseTaken);

	// Update de la Posicion Absoluta del Mouse
	m_lMouseScreenAbsPosition[POS_X] += m_kMouseTaken.lX;
	m_lMouseScreenAbsPosition[POS_Y] -= m_kMouseTaken.lY;
	m_lMouseScreenAbsPosition[POS_Z] += m_kMouseTaken.lZ;

	// Setear la Posicion Relativa del Mouse
	m_lMouseRelPosition[POS_X] = m_kMouseTaken.lX;
	m_lMouseRelPosition[POS_Y] = m_kMouseTaken.lY;
	m_lMouseRelPosition[POS_Z] = m_kMouseTaken.lZ;

	// Update los Estados de los Botones del Mouse
	m_ucMouseButton[MB_1] = m_kMouseTaken.rgbButtons[MB_1] & 0x80;
	m_ucMouseButton[MB_2] = m_kMouseTaken.rgbButtons[MB_2] & 0x80;
	m_ucMouseButton[MB_3] = m_kMouseTaken.rgbButtons[MB_3] & 0x80;

	// Update el Estado General
	Update();
}
//---------------------------------------------------------------------------
void DirectInput::Reset()
{
	// Resetear Todos los Buffers de Estado de los Dispositivos
	Input::Reset();
	ZeroMemory(&m_kMouseTaken, sizeof(m_kMouseTaken));
}
//---------------------------------------------------------------------------