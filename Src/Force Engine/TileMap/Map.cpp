/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: MyScene.h
Hecho by: Nahuel Lelouche
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Map.h"
//---------------------------------------------------------------------------
Map::Map(Graphics* pkGraphics)
:
m_pkGraphics(pkGraphics),
m_kName(""),
m_iLayers(0),
m_iRows(0),
m_iCols(0),
m_iTileWidth(0),
m_iTileHeight(0),
m_fPosX(0),
m_fPosY(0),
m_fPosZ(0),
m_kBackgroundColor(0,0,0),
m_pkCurrentTile(NULL)
{

}
//---------------------------------------------------------------------------
Map::~Map()
{

}
//---------------------------------------------------------------------------
bool Map::loadMap(std::string kTileSetFile, std::string kTileMapFile)
{
	if (kTileSetFile == "" || kTileMapFile == "")
	{
		return false;
	}

	//abro el archivo del mapa
	XMLNode kMapFileMainNode = XMLNode::openFileHelper(kTileMapFile.c_str(),"TilemapFile");

	XMLNode kMapNode = kMapFileMainNode.getChildNode("tilemap");
	
	//obtengo los atributos
	getMapAttributes(kMapNode);

	//abro el archivo de tiles
	XMLNode kTileSetFileMainNode = XMLNode::openFileHelper(kTileSetFile.c_str(),"tilesetFile");

	//cargo las texturas
	XMLNode kTileSets = kTileSetFileMainNode.getChildNode("tilesets");

	int iTileSetsCount = kTileSets.nChildNode("tileset");

	int iIteratorTileSets = 0;
	for(int i = 0; i < iTileSetsCount; i++)
	{
		XMLNode kTileSet = kTileSets.getChildNode("tileset",&iIteratorTileSets);
		loadTileSet(kTileSet, kTileSetFile);
	}

	//cargo los tiles
	XMLNode kTiles = kTileSetFileMainNode.getChildNode("tiles");

	int iTilesCount = kTiles.nChildNode("tilesetTile");

	int iIteratorTiles = 0;
	for(int i = 0; i < iTilesCount; i++)
	{
		XMLNode kTile = kTiles.getChildNode("tilesetTile",&iIteratorTiles);
		loadTile(kTile);
	}

	//TO DO: tiles animados, null tiles

	//cargo los layers del mapa
	int iLayersCount = kMapNode.nChildNode("layer");

	int iIteratorLayers = 0;
	for(int i = 0; i < iLayersCount; i++)
	{
		XMLNode kLayer = kMapNode.getChildNode("layer",&iIteratorLayers);
		loadLayer(kLayer);
	}

	moveMap();

	return true;
}
//---------------------------------------------------------------------------
void Map::parseBackgroundColor(std::string kStringToParse)
{
	int iPos = (int)(kStringToParse.find(',',0));
	m_kBackgroundColor.iRed = atoi((kStringToParse.substr(0,iPos)).c_str());
	kStringToParse = kStringToParse.substr(iPos + 1,kStringToParse.length() - iPos);

	iPos = (int)(kStringToParse.find(',',0));
	m_kBackgroundColor.iGreen = atoi((kStringToParse.substr(0,iPos)).c_str());
	kStringToParse = kStringToParse.substr(iPos + 1,kStringToParse.length() - iPos);

	m_kBackgroundColor.iBlue = atoi(kStringToParse.c_str());

}
//---------------------------------------------------------------------------
void Map::getMapAttributes(XMLNode kMapNode)
{
	m_kName = kMapNode.getAttribute("name");
	std::string kBackgroundRGB = kMapNode.getAttribute("backgroundRGB");
	parseBackgroundColor(kBackgroundRGB);

	const char* pszLayers = kMapNode.getAttribute("layers");
	const char* pszRows = kMapNode.getAttribute("rows");
	const char* pszCols = kMapNode.getAttribute("columns");
	const char* pszTileWidth = kMapNode.getAttribute("tileWidth");
	const char* pszTileHeight = kMapNode.getAttribute("tileHeight");

	m_iLayers = atoi(pszLayers);
	m_iRows = atoi(pszRows);
	m_iCols = atoi(pszCols);
	m_iTileWidth = atoi(pszTileWidth);
	m_iTileHeight = atoi(pszTileHeight);
}
//---------------------------------------------------------------------------
void Map::loadTileSet(XMLNode kTileSet, std::string kParentPath)
{
	assert(m_pkGraphics);

	std::string kTextureFile = kTileSet.getAttribute("file");

	TileSetMapIterator itTexture;
	itTexture = m_kpTileSetMap.find(kTextureFile);

	if(itTexture != m_kpTileSetMap.end())
	{
		return;
	}

	int iRed = m_kBackgroundColor.iRed;
	int iGreen = m_kBackgroundColor.iGreen;
	int iBlue = m_kBackgroundColor.iBlue;

	if(kParentPath[0] == '.')
	{
		int iPos = (int)(kParentPath.find_last_of('/'));
		kParentPath = kParentPath.substr(0, iPos + 1);
		kParentPath.append("images/");
		kParentPath.append(kTextureFile);
	}
	else
	{
		int iPos = (int)(kParentPath.find_last_of('\\'));
		kParentPath = kParentPath.substr(0, iPos + 1);
		kParentPath.append("images\\");
		kParentPath.append(kTextureFile);
	}

	// create the new texture
	Texture::Ptr pkTexture = Texture::Ptr( new Texture(kParentPath, iRed, iGreen, iBlue) );

	// add to map
	m_kpTileSetMap[kParentPath] = pkTexture;
	// add to name map
	m_kkTileSetNamesMap[kTextureFile] = kParentPath;

	m_pkGraphics->loadTexture(kParentPath.c_str(), *pkTexture);
}
//---------------------------------------------------------------------------
void Map::loadTile(XMLNode kTile)
{
	// cargo el Id
	const char* pszId = kTile.getAttribute("id");
	int iId = atoi(pszId);

	// busco el tile
	TileMapIterator itTile;
	itTile = m_kpTileMap.find(iId);

	// si lo encontre no hago nada
	if(itTile != m_kpTileMap.end())
	{
		return;
	}

	// creo el nuevo tile
	Tile* pkTile = new Tile();
	m_pkCurrentTile = pkTile;

	// lo agrego al mapa
	m_kpTileMap[iId] = pkTile;

	// cargo el resto de los atributos
	const char* pszWidth = kTile.getAttribute("width");
	const char* pszHeight = kTile.getAttribute("height");

	XMLNode kTextureNode = kTile.getChildNode("tilesetImage");
	std::string kTextureFile = kTextureNode.getAttribute("file");
	const char* pszTexPosX = kTextureNode.getAttribute("posX");
	const char* pszTexPosY = kTextureNode.getAttribute("posY");

	XMLNode kFlipNode = kTile.getChildNode("flip");
	std::string kVFlip = kFlipNode.getAttribute("vertically");
	std::string kHFlip = kFlipNode.getAttribute("horizontally");

	//Colisiones
	XMLNode kCollisionNode = kTile.getChildNode("collision");
	std::string kCollisionArea = kCollisionNode.getAttribute("area");

	// convierto los atributos
	unsigned int uiTexPosX = atoi(pszTexPosX);
	unsigned int uiTexPosY = atoi(pszTexPosY);
	unsigned int uiWidth = atoi(pszWidth);
	unsigned int uiHeight = atoi(pszHeight);

	// seteo los stributos del sprite
	std::string kTileSetPath = m_kkTileSetNamesMap[kTextureFile];
	pkTile->setTexture(m_kpTileSetMap[kTileSetPath]);
	pkTile->setId(iId);
	pkTile->setTextureArea(uiTexPosX, uiTexPosY, uiWidth, uiHeight);
	pkTile->setDim((float)(m_iTileWidth), (float)(m_iTileHeight));
	pkTile->setPosZ(0.0f);

	if(kCollisionArea == "full")
	{
		// Tiene Full collision desde el XML
		pkTile->collides = true;
	}
	else if(kCollisionArea == "none")
	{
		// Tiene None collision desde el XML
		pkTile->collides = false;
	}

	return;
}
//---------------------------------------------------------------------------
void Map::createTile(int iId, Tile* pkTile)
{
	//busco el tile
	TileMapIterator itTile;
	itTile = m_kpTileMap.find(iId);

	// si no lo encontre salgo
	if(itTile == m_kpTileMap.end())
	{
		return;
	}

	Tile* pkTileAux = m_kpTileMap[iId];
	pkTileAux->clone(pkTile);
}
//---------------------------------------------------------------------------
void Map::loadLayer(XMLNode kLayer)
{
	// cargo el Id
	const char* pszId = kLayer.getAttribute("index");
	int iId = atoi(pszId);

	// cargo el nombre
	std::string kName = kLayer.getAttribute("name");

	// busco el layer por nombre
	LayerMapIterator itLayer;
	itLayer = m_kkLayerMap.find(kName);

	// si lo encontre no hago nada
	if(itLayer != m_kkLayerMap.end())
	{
		return;
	}

	// busco el layer por id
	LayerIdMapIterator itLayerId;
	itLayerId = m_ikLayerIdMap.find(iId);

	// si lo encontre no hago nada
	if(itLayerId != m_ikLayerIdMap.end())
	{
		return;
	}

	// cargo el id en el mapa de ids
	LayerData kLayerData;
	kLayerData.kName = kName;
	kLayerData.bVisible = true;
	kLayerData.bUpdatable = true;
	
	m_ikLayerIdMap[iId] = kLayerData;

	// creo el vector del layer
	XMLNode kLayerDataNode = kLayer.getChildNode("data");

	std::string kData = kLayerDataNode.getText();

	TileVector* pkNewLayer = new TileVector();

	vector<int> kDataVector;
	processData(kData, kDataVector);

	for(int i = 0; i < (int)(kDataVector.size()); i++)
	{
		Tile* pkTile = new Tile();
		createTile(kDataVector[i], pkTile);
		pkNewLayer->push_back(pkTile);
	}

	m_kkLayerMap[kName] = pkNewLayer;
}
//---------------------------------------------------------------------------
void Map::processData(std::string kData, vector<int> &kDataVector)
{
	//borro los saltos de linea de la data
	//borro el ASCII 13
	int iPos = (int)(kData.find(13));
	while(iPos != (int)(kData.npos))
	{
		kData.replace(iPos, 1, "");
		iPos = (int)(kData.find(13,iPos + 1));
	}
	//borro el ASCII 10
	iPos = (int)(kData.find(10));
	while(iPos != (int)(kData.npos))
	{
		kData.replace(iPos, 1, "");
		iPos = (int)(kData.find(10,iPos + 1));
	}
	//borro el ASCII 9
	iPos = (int)(kData.find(9));
	while(iPos != (int)(kData.npos))
	{
		kData.replace(iPos, 1, "");
		iPos = (int)(kData.find(9,iPos + 1));
	}

	//extraigo los indices
	iPos = (int)(kData.find(','));
	while(iPos != (int)(kData.npos))
	{
		kDataVector.push_back(atoi((kData.substr(0,iPos)).c_str()));
		kData = kData.substr(iPos + 1,kData.length() - iPos);
		iPos = (int)(kData.find(','));
	}

	kDataVector.push_back(atoi((kData.substr(0,kData.length())).c_str()));
}
//---------------------------------------------------------------------------
void Map::moveMap()
{
	//accedo a cada layer
	LayerMapIterator itLPos;
	LayerMapIterator itLEnd;

	for(itLPos = m_kkLayerMap.begin(), itLEnd = m_kkLayerMap.end();
		itLPos != itLEnd; itLPos++)
	{
		//para cada layer seteo la pos de mundo de sus tiles
		TileVector* kLayer = itLPos->second;
		for(int i=0; i < (int)(kLayer->size()); i++)
		{
			Tile* kTile = kLayer->at(i);
			//posiciones respecto al mapa
			float fPosX = (float)((i % m_iRows));
			float fPosY = (float)(m_iRows - 1 - (i / m_iRows));
			fPosX = fPosX * m_iTileWidth - m_iTileHeight / 2;
			fPosY = fPosY * m_iTileHeight - m_iTileHeight / 2;
			float fPosZ = 0.0f;

			//posiciones en el mundo
			fPosX += m_fPosX;
			fPosY += m_fPosY;
			fPosX -= (float)((m_iRows * m_iTileWidth) / 2);
			fPosY -= (float)((m_iCols * m_iTileHeight) / 2);
			fPosZ += m_fPosZ;

			kTile->setPosXYZ(fPosX, fPosY, fPosZ);
		}
	}
}
//---------------------------------------------------------------------------
void Map::draw()
{
	//accedo a cada layer id
	for(int i = 0; i < (int)(m_ikLayerIdMap.size()); i++)
	{
		// e fijo si la tengo que dibujar
		LayerData kLayerData = m_ikLayerIdMap[i];
		if(kLayerData.bVisible)
		{
			//dibujo sus tiles
			TileVector* kLayer = m_kkLayerMap[kLayerData.kName];
			for(int i = 0; i < (int)(kLayer->size()); i++)
			{
				Tile* kTile = kLayer->at(i);
				if(kTile->getId() != 0)
				{
					kTile->Draw(*m_pkGraphics);
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
void Map::update(float fTimeBetweenFrames)
{
	for(int i = 0; i < (int)(m_ikLayerIdMap.size()); i++)
	{
		// me fijo si la tengo que updatear
		LayerData kLayerData = m_ikLayerIdMap[i];
		if (kLayerData.bUpdatable)
		{
			//updateo los tiles
			TileVector* kLayer = m_kkLayerMap[kLayerData.kName];
			for(int i=0; i < (int)(kLayer->size()); i++)
			{
				Tile* kTile = kLayer->at(i);
				if (kTile->getId() != 0)
				{
					kTile->Update(fTimeBetweenFrames);
				}				
			}
		}
	}
}
//---------------------------------------------------------------------------
void Map::setLayerVisible(int iLayerId, bool bVisible)
{
	// me fijo si existe el layer con ese id
	LayerIdMapIterator itLayer;
	itLayer = m_ikLayerIdMap.find(iLayerId);

	if(itLayer == m_ikLayerIdMap.end())
	{
		return;
	}

	//seteo el nuevo valor
	LayerData kLayerData = m_ikLayerIdMap[iLayerId];
	kLayerData.bVisible = bVisible;
	m_ikLayerIdMap[iLayerId] = kLayerData;
}
//---------------------------------------------------------------------------
bool Map::getLayerVisible(int iLayerId)
{
	// me fijo si existe el layer con ese id
	LayerIdMapIterator itLayer;
	itLayer = m_ikLayerIdMap.find(iLayerId);

	if(itLayer == m_ikLayerIdMap.end())
	{
		return false;
	}

	//devuelvo el valor
	LayerData kLayerData = m_ikLayerIdMap[iLayerId];
	return kLayerData.bVisible;
}
//---------------------------------------------------------------------------
void Map::setLayerUpdateable(int iLayerId, bool bUpdatable)
{
	// me fijo si existe el layer con ese id
	LayerIdMapIterator itLayer;
	itLayer = m_ikLayerIdMap.find(iLayerId);

	if(itLayer == m_ikLayerIdMap.end())
	{
		return;
	}

	//seteo el nuevo valor
	LayerData kLayerData = m_ikLayerIdMap[iLayerId];
	kLayerData.bUpdatable = bUpdatable;
	m_ikLayerIdMap[iLayerId] = kLayerData;
}
//---------------------------------------------------------------------------
bool Map::getLayerUpdateable(int iLayerId)
{
	// me fijo si existe el layer con ese id
	LayerIdMapIterator itLayer;
	itLayer = m_ikLayerIdMap.find(iLayerId);

	if(itLayer == m_ikLayerIdMap.end())
	{
		return false;
	}

	//devuelvo el valor
	LayerData kLayerData = m_ikLayerIdMap[iLayerId];

	return kLayerData.bUpdatable;
}
//---------------------------------------------------------------------------
Entity2D::CollisionResult Map::checkMapCollision(Entity2D* pkEntity)
{
	LayerMapIterator itLPos;
	LayerMapIterator itLEnd;

	Entity2D::CollisionResult eResult = Entity2D::CollisionResult::None;

	for(itLPos = m_kkLayerMap.begin(), itLEnd = m_kkLayerMap.end();
		itLPos != itLEnd; itLPos++)
	{
		TileVector* kLayer = itLPos->second;

		for(int i = 0; i < (int)(kLayer->size()); i++)
		{
			Tile* kTile = kLayer->at(i);

			if(kTile->collides)
			{
				eResult = kTile->checkCollision(pkEntity);

				if(eResult != Entity2D::None)
				{
					return eResult;
				}
			}
		}
	}

	return eResult;
}
//---------------------------------------------------------------------------