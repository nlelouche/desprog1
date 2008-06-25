/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Scene.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef SCENE_H
#define SCENE_H
//---------------------------------------------------------------------------
#include "Input.h"
#include "Defines.h"
#include "Entity2D.h"
//---------------------------------------------------------------------------
class Graphics;
class Texture;
class Entity2D;
class Input;
//---------------------------------------------------------------------------
class FORCEENGINE_API Scene
{

public:

	Scene();
	Scene(Graphics & rkGraphics);
	virtual ~Scene();

	bool Init(Input * pkInput);
	bool Update(float fTimeBetweenFrames);
	void Draw(Graphics & rkGraphics) const;
	bool deInit();

	void addEntity(Entity2D * pkEntity);

protected:

	virtual bool onInit() = 0;
	virtual bool onUpdate(float fTimeBetweenFrames) = 0;
	virtual void onDraw(Graphics& rkGraphics) const = 0;
	virtual bool onDeInit() = 0;

	void sortEntitiesByZ();

	Graphics * m_pkGraphics;

	Input * m_pkInput;

private:

	std::vector<Entity2D*> m_apkEntities;

	static bool entity2DComp(Entity2D* pkEnt1, Entity2D* pkEnt2);

	friend class Graphics;
};

#include "Scene.inl"

//---------------------------------------------------------------------------

#endif /*--- SCENE_H ---*/

//---------------------------------------------------------------------------