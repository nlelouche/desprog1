//----------------------------------------------------------------
#include "Tile.h"
//----------------------------------------------------------------
Tile::Tile():
m_iId(0),
m_kCode1(""),
m_kCode2("")
{

}
//----------------------------------------------------------------
Tile::~Tile()
{

}
//----------------------------------------------------------------
void Tile::clone(Tile* pkTile)
{
	if(pkTile == this)
		return;

	Sprite::clone(pkTile);

	pkTile->setId(getId());
	pkTile->setDim(getDimWidth(), getDimHeight());
	//pkTile->set2DHFlip(get2DHFlip());
	//pkTile->set2DVFlip(get2DVFlip());
	
	//TO DO: clonar codes y colisiones
}
//----------------------------------------------------------------
