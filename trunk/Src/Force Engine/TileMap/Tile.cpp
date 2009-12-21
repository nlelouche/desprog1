/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Tile.cpp
Hecho by: Nahuel Lelouche
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Tile.h"
//---------------------------------------------------------------------------
Tile::Tile()
:
m_iId(0),
m_kCode1(""),
m_kCode2(""),
collides(false)
{

}
//---------------------------------------------------------------------------
Tile::~Tile()
{

}
//---------------------------------------------------------------------------
void Tile::clone(Tile* pkTile)
{
	if(pkTile == this)
	{
		return;
	}

	Sprite::clone(pkTile);

	pkTile->setId(getId());
	pkTile->setDim(getDimWidth(), getDimHeight());
	//pkTile->set2DHFlip(get2DHFlip());
	//pkTile->set2DVFlip(get2DVFlip());
	
	//TO DO: clonar codes y colisiones
}
//---------------------------------------------------------------------------