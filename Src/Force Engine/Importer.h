/****************************************************************************

Force Engine v0.1

Creado: 06/05/08
Clase: Importer.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef IMPORTER_H
#define IMPORTER_H
//---------------------------------------------------------------------------
#include "Sprite.h"
#include "Defines.h"
#include "Graphics.h"
#include "XMLParser.h"
//---------------------------------------------------------------------------

class FORCEENGINE_API Importer
{
private:

	Importer(Graphics * pkGraphics);

public:

	friend class Game;

	~Importer();

	bool importResources(const char * pszFilename);

	Texture * getTexture(const char * pszFilename);
	bool createSprite(const char * pszName, Sprite& rkSprite);

private:

	bool importSprite(XMLNode& rkNode);
	bool importSpriteAnimation(XMLNode& rkNode);
	bool importTexture(const char * pszFilename);

	std::map <std::string, Sprite*> m_kpSpritesMap;
	std::map <std::string, Texture*> m_kpTexturesMap;

	Graphics * m_pkGraphics;

	Sprite * m_pkCurrentSprite;
};

//---------------------------------------------------------------------------

#endif /*--- IMPORTER_H ---*/

//---------------------------------------------------------------------------