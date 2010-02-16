/****************************************************************************

Force Engine v0.5

Creado: 28/03/09
Clase: Map.h
Hecho by: Nahuel Lelouche
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef MAP_H
#define MAP_H
//---------------------------------------------------------------------------
#include "../Defines/Defines.h"
#include "../Graphics/GraphicsStructs.h"
#include "Tile.h"
#include "../Xml Parser/XMLParser.h"
#include "../Graphics/Graphics.h"
//---------------------------------------------------------------------------
class FORCEENGINE_API Map
{
public:

	Map(Graphics* pkGraphics);
	~Map();

	bool loadMap(std::string kTileSetFile, std::string kTileMapFile);
	void draw();
	void update(float fTimeBetweenFrames);
	void setPos(float fX, float fY, float fZ=0);

	float getPosX();
	float getPosY();
	float getPosZ();

	int getTileWidth();
	int getTileHeight();

	void setLayerVisible(int iLayerId, bool bVisible=true);
	bool getLayerVisible(int iLayerId);
	void setLayerUpdateable(int iLayerId, bool bUpdatable);
	bool getLayerUpdateable(int iLayerId);

	Entity2D::CollisionResult checkMapCollision(Entity2D* pkEntity);

private:

	std::string m_kName;

	int m_iLayers;
	int m_iRows;
	int m_iCols;
	int m_iTileWidth;
	int m_iTileHeight;
	float m_fPosX;
	float m_fPosY;
	float m_fPosZ;

	RGBColor m_kBackgroundColor;

	std::map<int, Tile*> m_kpTileMap;
	typedef std::map<int, Tile*>::iterator TileMapIterator;

	std::map<std::string, Texture::Ptr> m_kpTileSetMap;
	typedef std::map<std::string, Texture::Ptr>::iterator TileSetMapIterator;
	std::map<std::string, std::string> m_kkTileSetNamesMap;
	typedef std::map<string, std::string>::iterator TileSetNamesMapIterator;
	
	typedef std::vector<Tile*> TileVector;
	std::map<std::string, TileVector*> m_kkLayerMap;
	typedef std::map<std::string, TileVector*>::iterator LayerMapIterator;
	
	struct LayerData
	{
		std::string kName;
		bool bVisible;
		bool bUpdatable;
	};

	std::map<int, LayerData> m_ikLayerIdMap;
	typedef std::map<int, LayerData>::iterator LayerIdMapIterator;

	Graphics* m_pkGraphics;

	void parseBackgroundColor(std::string kStringToParse);
	void getMapAttributes(XMLNode kMapNode);
	void loadTileSet(XMLNode kTileSet, std::string kParentPath);
	void loadTile(XMLNode kTile);
	void createTile(int iId, Tile* pkTile);
	void loadLayer(XMLNode kLayer);
	void processData(std::string kData, vector<int> &kDataVector);
	void moveMap();

	Tile* m_pkCurrentTile;
};
//---------------------------------------------------------------------------
#include "Map.inl"
//---------------------------------------------------------------------------

#endif /*-- MAP_H --*/

//---------------------------------------------------------------------------