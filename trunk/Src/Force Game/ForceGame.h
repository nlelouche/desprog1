/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: ForceGame.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef FORCE_GAME_H
#define FORCE_GAME_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "../Force Engine/ForceEngine.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class ForceGame: public Game
{
public:

	ForceGame(HINSTANCE hInstance);
	~ForceGame();

protected:

	bool onInit();
	bool onLoop();
	bool onDeInit();

private:

	Texture::Ptr m_pkPacman;

	Sprite * m_pPacman;
	Sprite * m_pPhantom;

	ForceBOX * m_pShapeBox1;
	ForceBOX * m_pShapeBox2;
	ForceBOX * m_pShapeRoof;
	ForceBOX * m_pShapeFloor;
	
	Animation * m_pAnimationPac;
	Animation * m_pAnimationPacMuerte;

	AnimationInfo::Ptr m_pAnimationInfoPac;
	AnimationInfo::Ptr m_pAnimationInfoPacMuerte;

	friend class Graphics;
};

//---------------------------------------------------------------------------

#endif /*--- FORCE_GAME_H ---*/

//---------------------------------------------------------------------------