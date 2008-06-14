/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Scene.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Scene.h"
#include "Entity2D.h"
//---------------------------------------------------------------------------
Scene::Scene(Graphics * m_pGraficos)
{
	/***/
}

//---------------------------------------------------------------------------
Scene::~Scene()
{
	/***/
}

//---------------------------------------------------------------------------
bool Scene::Init()
{
	return onInit();
}

//---------------------------------------------------------------------------
bool Scene::Update(float fTimeBetweenFrames)
{
	for(unsigned int i = 0; i < m_apkEntities.size(); i++)
	{
		m_apkEntities[i]->Update(fTimeBetweenFrames);
	}

	return onUpdate(fTimeBetweenFrames);
}

//---------------------------------------------------------------------------
void Scene::Draw(Graphics& rkGraphics) const
{
	for(unsigned int i = 0; i < m_apkEntities.size(); i++)
	{
		m_apkEntities[i]->Draw(rkGraphics);
	}

	onDraw(rkGraphics);
}

//---------------------------------------------------------------------------
bool Scene::deInit()
{
	return onDeInit();
}

//---------------------------------------------------------------------------