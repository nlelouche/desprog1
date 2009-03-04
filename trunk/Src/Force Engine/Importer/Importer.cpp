//-------------------------------------------------------------------//
//*																	*//
//*		Importer.cpp - Created 04/07/2008							*//
//*						PitBull Engine V0.1							*//
//*								By CalaveraX						*//
//-------------------------------------------------------------------//

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <fstream>
#include "Importer.h"
//---------------------------------------------------------------------------
bool Importer::ImportSprite(const char *pszName, Sprite &rkSprite,Render *pkRender){

	// Creamos el MainNode que usaremos para leer los Encabezados XML
	XMLNode rkNode = XMLNode::openFileHelper(pszName,"PMML");
	// Creamos el node desde Sprite
	XMLNode rkSpriteNode = rkNode.getChildNode("SPRITE");	
	
	// load sprite attributes
	const char* pszFile			= rkSpriteNode.getAttribute("File");
	const char* pszColorkeyR	= rkSpriteNode.getAttribute("ColorkeyR");
	const char* pszColorkeyG	= rkSpriteNode.getAttribute("ColorkeyG");
	const char* pszColorkeyB	= rkSpriteNode.getAttribute("ColorkeyB");
	const char* pszTexPosX		= rkSpriteNode.getAttribute("TexPosX");
	const char* pszTexPosY		= rkSpriteNode.getAttribute("TexPosY");
	const char* pszWidth		= rkSpriteNode.getAttribute("Width");
	const char* pszHeight		= rkSpriteNode.getAttribute("Height");

	// Creamos una nueva Textura desde el archivo pszFile
	Texture::Ptr m_pkTexture(new Texture(pszFile));

	// Indicamos al render cargar la textura
	pkRender->loadTexture(m_pkTexture,
		D3DCOLOR_XRGB(
		atoi(pszColorkeyR),
		atoi(pszColorkeyG),
		atoi(pszColorkeyB))
		);

	// Seteamos las propiedades del Sprite
	rkSprite.SetTexture(m_pkTexture);
	rkSprite.SetDim(float(atoi(pszWidth)),float(atoi(pszHeight)));
	rkSprite.SetName(pszName);
	rkSprite.SetPos(0,0);
	rkSprite.setTextureArea(atoi(pszTexPosX),
							atoi(pszTexPosY),
							atoi(pszWidth),
							atoi(pszHeight));

	return true;
}
//---------------------------------------------------------------------------

bool Importer::ImportSpriteAnimation (const char *pszName, Sprite &rkSprite)
{
	// Creamos el MainNode que usaremos para leer los Encabezados XML
	XMLNode rkNode = XMLNode::openFileHelper(pszName,"PMML");
	
	// Creamos el nodo desde SPRITE_ANIMATION
	XMLNode rkAnimationNode = rkNode.getChildNode("SPRITE_ANIMATION");
	
	// Get total of Animations
	int iTotalAnims = rkNode.nChildNode("SPRITE_ANIMATION");	
	
	// For Each Animation:
	int iIterator = 0;
	for(int i=0; i<iTotalAnims; i++){


		// Create the New AnimationInfo
		AnimationInfo::Ptr pkAnimInfo = AnimationInfo::Ptr( new AnimationInfo() );

		// get animation attibutes
		const char* pszTime = rkAnimationNode.getAttribute("Time");

		// convert animation attibutes
		float fTime = (float)(strtod(pszTime,NULL));
		pkAnimInfo->setLength(fTime);

		// Get Animation Name
		const char* pszName = rkAnimationNode.getAttribute("Name");

		// load frames
		int iTotalFrames = rkAnimationNode.nChildNode("FRAME");	

		// For each Frame
		int iIterator = 0;
		for(int i=0; i<iTotalFrames; i++){
			// Creamos el Nodo a partir de FRAME
			XMLNode& rkFrame = rkAnimationNode.getChildNode("FRAME",&iIterator);

			// get frame data
			const char* pszTexPosX  = rkFrame.getAttribute("TexPosX");
			const char* pszTexPosY  = rkFrame.getAttribute("TexPosY");
			const char* pszWidth	= rkFrame.getAttribute("Width");
			const char* pszHeight	= rkFrame.getAttribute("Height");

			// convert frame data
			unsigned int uiTexPosX	= atoi(pszTexPosX);
			unsigned int uiTexPosY	= atoi(pszTexPosY);
			unsigned int uiWidth	= atoi(pszWidth);
			unsigned int uiHeight	= atoi(pszHeight);

			// Agregamos el Frame a AnimationInfo
			pkAnimInfo->addFrame(uiTexPosX, uiTexPosY, uiWidth, uiHeight);
		}
		
		//Animation *pkAnimation = new Animation(pkAnimInfo);
		//Agregamos AnimationInfo al Sprite
		rkSprite.addAnimationInfo(pszName, pkAnimInfo);
	}
	return true;
}

//---------------------------------------------------------------------------