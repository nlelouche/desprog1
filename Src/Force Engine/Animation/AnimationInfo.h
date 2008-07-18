/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: AnimationInfo.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef ANIMATIONINFO_H
#define ANIMATIONINFO_H
//---------------------------------------------------------------------------
#include "../Defines/Defines.h"
//---------------------------------------------------------------------------
class Sprite;
//---------------------------------------------------------------------------
struct FrameInfo
{
	unsigned int uiOffsetX;
	unsigned int uiOffsetY;
	unsigned int uiWidth;
	unsigned int uiHeight;
};
//---------------------------------------------------------------------------
class FORCEENGINE_API AnimationInfo
{
	DECLARE_SMART_POINTER(AnimationInfo);

public:
	
	// Agrega Cuadros de Animacions
	void addFrame(
				 unsigned int uiOffsetX,
				 unsigned int uiOffsetY, 
				 unsigned int uiWidth, 
				 unsigned int uiHeight
				 );

	void setLength(float fLenght);
	float getLength() const;

	float getTimePerFrame() const;

	size_t getFrameCount() const;

	const FrameInfo& getFrameInfo(unsigned int uiIndex) const;

	void setLoopable(bool bIsLoopable);
	bool getLoopable() const;

private:

	bool m_bIsLoopable;

	float m_fLength;
	float m_fTimePerFrame;

	std::vector <FrameInfo> m_akFramesInfo;
};

//---------------------------------------------------------------------------
#include "AnimationInfo.inl"
//---------------------------------------------------------------------------

#endif /*--- ANIMATIONINFO_H ---*/

//---------------------------------------------------------------------------
