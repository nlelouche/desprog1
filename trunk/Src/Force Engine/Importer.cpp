/****************************************************************************

Force Engine v0.1

Creado: 06/05/08
Clase: Importer.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Importer.h"
//---------------------------------------------------------------------------

Importer::Importer(Graphics* pkGraphics)
:
m_pkGraphics(pkGraphics)
{
	/***/
}

//---------------------------------------------------------------------------
Importer::~Importer()
{
/*
	for(std::vector<Sprite*>::iterator it = m_kpSpritesVector.begin(); it != m_kpSpritesVector.end(); it++)
	{
		Sprite *p = *it;
		delete p;
		p = NULL;
	}
	m_kpSpritesVector.clear();
*/
	// delete all the prototype sprites
	for(std::map<std::string, Sprite*>::iterator it = m_kpSpritesMap.begin(), e = m_kpSpritesMap.end(); it != e; )
	{
		Sprite * pkSprite = it->second;
		
		m_kpSpritesMap.erase(it++);
		
		delete pkSprite;
		pkSprite = NULL;
	}
}

//---------------------------------------------------------------------------
bool Importer::importResources(const char * pszFilename)
{
	XMLNode kMainNode = XMLNode::openFileHelper(pszFilename,"PMML");

	int iSpriteCount = kMainNode.nChildNode("SPRITE");	

	int iIterator = 0;

	for(int i = 0; i < iSpriteCount; i++)
	{
		XMLNode& rkSprite = kMainNode.getChildNode("SPRITE",&iIterator);
		importSprite(rkSprite);
	}

	return true;
}

//---------------------------------------------------------------------------
bool Importer::importSprite(XMLNode& rkNode)
{
	const char* pszName = rkNode.getAttribute("Name");

	Sprite* pkSprite = m_kpSpritesMap[pszName];
	
	if(pkSprite)
	{
		return true;
	}

	pkSprite = new Sprite();
	m_pkCurrentSprite = pkSprite;

	m_kpSpritesMap[pszName] = pkSprite;

	const char * pszTexFile = rkNode.getAttribute("TextureFile");
	const char * pszTexPosX = rkNode.getAttribute("TexPosX");
	const char * pszTexPosY = rkNode.getAttribute("TexPosY");
	const char * pszWidth = rkNode.getAttribute("Width");
	const char * pszHeight = rkNode.getAttribute("Height");

	unsigned int uiTexPosX = atoi(pszTexPosX);
	unsigned int uiTexPosY = atoi(pszTexPosY);
	unsigned int uiWidth = atoi(pszWidth);
	unsigned int uiHeight = atoi(pszHeight);

	importTexture(pszTexFile);

	pkSprite->setTexture( m_kpTexturesMap[pszTexFile] );
	pkSprite->setName(pszName);
	pkSprite->setTextureArea(uiTexPosX, uiTexPosY, uiWidth, uiHeight);

	int iTotalAnims = rkNode.nChildNode("SPRITE_ANIMATION");	

	int iIterator = 0;
	for(int i = 0; i < iTotalAnims; i++)
	{
		XMLNode& rkAnim = rkNode.getChildNode("SPRITE_ANIMATION",&iIterator);
		importSpriteAnimation(rkAnim);
	}

	return true;
}

//---------------------------------------------------------------------------
bool Importer::importSpriteAnimation(XMLNode& rkNode)
{
/*
	const char* pszName = rkNode.getAttribute("Name");

	// find the animation
	AnimationInfo::Ptr pkAnimInfo = m_kpSpriteAnimsMap[pszName];
	
	// if it was found, return
	if(pkAnimInfo.get())
		return true;

	// create the new animation
	pkAnimInfo = AnimationInfo::Ptr( new AnimationInfo() );

	// add to map and to sprite
	m_kpSpriteAnimsMap[pszName] = pkAnimInfo;
	m_pkCurrentSprite->addAnimationInfo(pszName, pkAnimInfo);

	// get animation attibutes
	const char* pszTime = rkNode.getAttribute("Time");

	// convert animation attibutes
	float fTime = (float)(strtod(pszTime,NULL));
	pkAnimInfo->setLength(fTime);
	
	// load frames
	int iTotalFrames = rkNode.nChildNode("FRAME");	

	int iIterator = 0;
	for(int i=0; i<iTotalFrames; i++)
	{
		XMLNode& rkFrame = rkNode.getChildNode("FRAME",&iIterator);
		
		// get frame data
		const char* pszTexPosX = rkFrame.getAttribute("TexPosX");
		const char* pszTexPosY = rkFrame.getAttribute("TexPosY");
		const char* pszWidth = rkFrame.getAttribute("Width");
		const char* pszHeight = rkFrame.getAttribute("Height");

		// convert frame data
		unsigned int uiTexPosX = atoi(pszTexPosX);
		unsigned int uiTexPosY = atoi(pszTexPosY);
		unsigned int uiWidth = atoi(pszWidth);
		unsigned int uiHeight = atoi(pszHeight);

		pkAnimInfo->addFrame(uiTexPosX, uiTexPosY, uiWidth, uiHeight);
	}
*/
	return true;
}

//---------------------------------------------------------------------------
bool Importer::importTexture(const char * pszFilename)
{
	assert(m_pkGraphics);

	Texture * pkTexture = m_kpTexturesMap[pszFilename];
	
	if(pkTexture)
	{
		return true;
	}

	pkTexture = new Texture(pszFilename);

	m_kpTexturesMap[pszFilename] = pkTexture;

	if(!m_pkGraphics->loadTexture(pszFilename, pkTexture))
	{
		return false;
	}

	return true;
}

//---------------------------------------------------------------------------
bool Importer::createSprite(const char * pszName, Sprite& rkSprite)
{
	Sprite * pkSprite = m_kpSpritesMap[pszName];

	if(!pkSprite)
	{
		return false;
	}

	pkSprite->Clone(rkSprite);

	return true;
}

//---------------------------------------------------------------------------
Texture * Importer::getTexture (const char * pszFilename)
{
	Texture * pkTexture = m_kpTexturesMap[pszFilename];
	Texture * pkNewTexture(new Texture(*pkTexture));

	return pkNewTexture;
}

//---------------------------------------------------------------------------