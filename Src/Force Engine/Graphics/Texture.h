/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Texture.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef TEXTURE_H
#define TEXTURE_H
//---------------------------------------------------------------------------
#include "../Defines/Defines.h"
#include "../Graphics/Graphics.h"
#include "../Graphics/GraphicsStructs.h"
//---------------------------------------------------------------------------
class Graphics;
//---------------------------------------------------------------------------
class FORCEENGINE_API Texture
{
	DECLARE_SMART_POINTER(Texture);

public:

	Texture(std::string kFilename, unsigned long ulColor);
	Texture(std::string kFilename, int iRed, int iGreen, int iBlue);
	~Texture();

	unsigned int getWidth() const;
	unsigned int getHeight() const;

	std::string getFileName() const;

	void setWidth(unsigned int uiWidth);
	void setHeight(unsigned int uiHeight);

	unsigned long getColorKey() const;

private:

	unsigned int m_uiWidth;
	unsigned int m_uiHeight;

	unsigned long m_ulColor;

	std::string m_kFilename;
	RGBColor m_kColorKey;
};

//---------------------------------------------------------------------------
#include "Texture.inl"
//---------------------------------------------------------------------------

#endif /*--- TEXTURE_H ---*/

//---------------------------------------------------------------------------

