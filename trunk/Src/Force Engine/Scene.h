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
#include "Defines.h"
#include "Texture.h"
//---------------------------------------------------------------------------
class Graphics;
class Texture;
class Entity2D;
//---------------------------------------------------------------------------
class FORCEENGINE_API Scene
{

public:
	Scene(Graphics * m_pGraficos);
	virtual ~Scene();

	bool Init();
	bool Update(float fTimeBetweenFrames);
	void Draw(Graphics& rkGraphics) const;
	bool deInit();

	void addEntity(Entity2D* pkEntity);

protected:

	virtual bool onInit() = 0;
	virtual bool onUpdate(float fTimeBetweenFrames) = 0;
	virtual void onDraw(Graphics& rkGraphics) const = 0;
	virtual bool onDeInit() = 0;

private:

	std::vector<Entity2D*> m_apkEntities;

	friend class Graphics;
};

//---------------------------------------------------------------------------
#include "Scene.inl"
//---------------------------------------------------------------------------

#endif /*--- SCENE_H ---*/

//---------------------------------------------------------------------------