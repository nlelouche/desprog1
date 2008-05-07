/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Texture.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef TEXTURE_H
#define TEXTURE_H
//---------------------------------------------------------------------------
#include "Defines.h"
//---------------------------------------------------------------------------
class Graphics;
//---------------------------------------------------------------------------
class FORCEENGINE_API Texture
{

public:

	Texture (std::string kFilename, Graphics& g_graphics);
	~Texture();

	unsigned int getWidth() const;
	unsigned int getHeight() const;

	void setWidth(unsigned int uiWidth);
	void setHeight(unsigned int uiHeight);

	std::string getFileName() const;

private:

	unsigned int m_uiWidth;
	unsigned int m_uiHeight;

	std::string m_kFilename;
};

//---------------------------------------------------------------------------
#include "Texture.inl"
//---------------------------------------------------------------------------

#endif /*--- TEXTURE_H ---*/

//---------------------------------------------------------------------------

