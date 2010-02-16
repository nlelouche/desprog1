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
m_bCollides(false)
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

	pkTile->m_bCollides = m_bCollides;
	pkTile->setId(getId());
	pkTile->setDim(getDimWidth(), getDimHeight());
	//pkTile->set2DHFlip(get2DHFlip());
	//pkTile->set2DVFlip(get2DVFlip());
}
//---------------------------------------------------------------------------