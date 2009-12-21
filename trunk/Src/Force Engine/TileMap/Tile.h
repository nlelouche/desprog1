/****************************************************************************

Force Engine v0.5

Creado: 28/03/09
Clase: Tile.h
Hecho by: Nahuel Lelouche
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef TILE_H
#define TILE_H
//---------------------------------------------------------------------------
#include "../Entity2D/Sprite.h"
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
class FORCEENGINE_API Tile : public Sprite
{
public:

	Tile();
	~Tile();

	enum COLLITION_TYPE
	{
		NONE,
		FULL
	};

	bool collides;

	void setId(int iId);
	int getId();

	void clone(Tile* pkTile);

private:

	int m_iId;
	COLLITION_TYPE m_kCollisionType;

	string m_kCode1;
	string m_kCode2;
};
//---------------------------------------------------------------------------
#include "Tile.inl"
//---------------------------------------------------------------------------

#endif /*--- TILE_H ---*/

//---------------------------------------------------------------------------
