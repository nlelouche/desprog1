/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Texture.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Texture.h"
//---------------------------------------------------------------------------
Texture::Texture(std::string kFilename, unsigned long ulColor)
:
m_uiWidth(0),
m_uiHeight(0),
m_kFilename(kFilename),
m_ulColor(ulColor)
{
	/********/
}
//---------------------------------------------------------------------------
Texture::Texture (std::string kFilename, int iRed, int iGreen, int iBlue)
:
m_uiWidth(0),
m_uiHeight(0),
m_kFilename(kFilename),
m_kColorKey(iRed, iGreen, iBlue)
{

}
//---------------------------------------------------------------------------
Texture::~Texture()
{
	/********/
}
//---------------------------------------------------------------------------