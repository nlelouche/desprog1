/****************************************************************************

Force Engine v0.5

Creado: 24/06/08
Clase: Input.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Input.h"
//---------------------------------------------------------------------------
Input::Input()
{
	Reset();
}

//---------------------------------------------------------------------------
Input::~Input()
{
	/***/
}

//---------------------------------------------------------------------------
void Input::Update()
{
	// Button 1

	if(m_ucMouseButton[MB_1]) 
	{
		if(!m_bButtonState[MB_1])
		{
			m_lMouseButtonClick[MB_1] = true;
			m_bButtonState[MB_1] = true;
		} 
		else 
		{
			m_lMouseButtonClick[MB_1] = false;
		}
	} 
	else if(m_bButtonState[MB_1])
	{
		m_bButtonState[MB_1] = false;
	}

	// Button 2

	if(m_ucMouseButton[MB_2])
	{
		if(!m_bButtonState[MB_2])
		{
			m_lMouseButtonClick[MB_2] = true;
			m_bButtonState[MB_2] = true;
		} 
		else 
		{
			m_lMouseButtonClick[MB_2] = false;
		}
	} 
	else if(m_bButtonState[MB_2])
	{
		m_bButtonState[MB_2] = false;
	}

	// Button 3

	if(m_ucMouseButton[MB_3])
	{
		if(!m_bButtonState[MB_3])
		{
			m_lMouseButtonClick[MB_3] = true;
			m_bButtonState[MB_3] = true;
		} 
		else 
		{
			m_lMouseButtonClick[MB_3] = false;
		}
	} 
	else if(m_bButtonState[MB_3])
	{
		m_bButtonState[MB_3] = false;
	}
}

//---------------------------------------------------------------------------
void Input::getKeyEvent()
{
	static int i;

	for(i = 0; i < 256; i++)
	{
		if (m_ucKeyBuffer[i] != m_ucKeyPrevBuffer[i])
		{
			if (getKeyDown(i)) 
			{
				m_ucKeyEvent[i] = KS_DOWN;
			}
			else 
			{
				m_ucKeyEvent[i] = KS_UP;
			}
		}
		else 
		{
			m_ucKeyEvent[i] = KS_NONE;
		}
	}
}

//---------------------------------------------------------------------------
void Input::setMousePosition(long x, long y, long z)
{
	m_lMouseScreenAbsPosition[POS_X] = x;
	m_lMouseScreenAbsPosition[POS_Y] = y;
	m_lMouseScreenAbsPosition[POS_Z] = z;

	m_lMouseRelPosition[POS_X] = 0;
	m_lMouseRelPosition[POS_Y] = 0;
	m_lMouseRelPosition[POS_Z] = 0;
}

//---------------------------------------------------------------------------
void Input::Reset()
{
	memset(&m_ucKeyBuffer, 0, sizeof(m_ucKeyBuffer));

	m_lMouseScreenAbsPosition[0] = 0;
	m_lMouseScreenAbsPosition[1] = 0;
	m_lMouseScreenAbsPosition[2] = 0;

	m_lMouseRelPosition[0] = 0;	m_lMouseRelPosition[1] = 0;	m_lMouseRelPosition[2] = 0;

	m_ucMouseButton[0] = 0;	m_ucMouseButton[1] = 0;	m_ucMouseButton[2] = 0;

	m_lMouseButtonClick[0] = false;	m_lMouseButtonClick[1] = false;	m_lMouseButtonClick[2] = false;

	m_bButtonState[0] = false;	m_bButtonState[1] = false;	m_bButtonState[2] = false;
}

//---------------------------------------------------------------------------