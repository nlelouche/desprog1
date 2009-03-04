//-------------------------------------------------------------------//
//*																	*//
//*		Importer.H - Created 04/07/2008								*//
//*						PitBull Engine V0.1							*//
//*								By CalaveraX						*//
//-------------------------------------------------------------------//
				
//----------------------------------------------------------------
#pragma once

//----------------------------------------------------------------
#include "Defines.h"
#include "Sprite.h"
#include "XMLParser.h"
//----------------------------------------------------------------
//----------------------------------------------------------------
class FORCETIENGINE_API Importer
{
// entry point
public:
	static bool ImportSprite (const char* pszName, Sprite& rkSprite,Render *pkRender);
	static bool ImportSpriteAnimation(const char *pszName, Sprite &rkSprite);

};