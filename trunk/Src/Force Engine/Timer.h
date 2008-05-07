/****************************************************************************

Force Engine v0.1

Creado: 06/05/08
Clase: Timer.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef TIMER_H
#define TIMER_H
//---------------------------------------------------------------------------
#include <windows.h>
#include "Defines.h"
//---------------------------------------------------------------------------

class FORCEENGINE_API Timer
{

public:
	Timer ();
	~Timer ();

	void firstMeasure();
	void measure();

	float getTimeBetweenFrames() const;
	unsigned int getFPS() const;

	double m_dMeasureFpsSample;
	double m_dTimeBetweenFrames;

	unsigned int m_uiFPS;
	unsigned int m_uiFrameCounter;

	LARGE_INTEGER m_kFrequency;
	LARGE_INTEGER m_kPerfCount1;
	LARGE_INTEGER m_kPerfCount2;
};
//---------------------------------------------------------------------------
#include "Timer.inl"
//---------------------------------------------------------------------------
#endif /*--- TIMER_H ---*/

//---------------------------------------------------------------------------