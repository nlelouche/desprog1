/****************************************************************************

Force Engine v0.5

Creado: 24/06/08
Clase: Input.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef INPUT_H
#define INPUT_H
//---------------------------------------------------------------------------
#include "Defines.h"
//---------------------------------------------------------------------------
class FORCEENGINE_API Input
{

public:

	enum
	{
		POS_X,
		POS_Y,
		POS_Z
	};

	enum MouseButton
	{
		MB_1,
		MB_2,
		MB_3
	};

	enum KeyState
	{
		KS_NONE,
		KS_DOWN,
		KS_UP
	};

	Input();
	virtual ~Input();

	virtual bool Init() = 0;
	virtual void deInit() = 0;

	// Mouse y Keyboard

	virtual void Acquire() = 0;
	virtual void Reacquire() = 0;
	virtual void Unacquire() = 0;

	void getKeyEvent();
	void setMousePosition(long x, long y, long z);
	void eventClean();

	virtual void Reset();

	bool getKeyDown(unsigned int uiKeyID);
	bool getKeyEventDown(unsigned int uiKeyID);
	bool getKeyEventUp(unsigned int uiKeyID);

	bool getMouseButton(unsigned int uiButtonID);
	bool getMouseClick(unsigned int uiButtonID);
	long getMouseScrAbsPosX();
	long getMouseScrAbsPosY();
	long getMouseScrAbsPosZ();
	long getMouseRelPosX();
	long getMouseRelPosY();
	long getMouseRelPosZ();

protected:

	void Update();

	unsigned char m_ucKeyEvent[256];
	unsigned char m_ucKeyBuffer[256];
	unsigned char m_ucKeyPrevBuffer[256];
	
	bool m_bButtonState[3];
	bool m_lMouseButtonClick[3];
	long m_lMouseRelPosition[3];
	long m_lMouseScreenAbsPosition[3];
	unsigned char m_ucMouseButton[3];

};

//---------------------------------------------------------------------------
#include "Input.inl"
//---------------------------------------------------------------------------

#endif /*--- INPUT_H ---*/

//---------------------------------------------------------------------------