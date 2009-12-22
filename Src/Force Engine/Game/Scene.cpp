/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Scene.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Scene.h"
//---------------------------------------------------------------------------
Scene::Scene()
{
	/***/
}
//---------------------------------------------------------------------------
Scene::Scene(Graphics & rkGraphics)
:
m_pkGraphics(&rkGraphics),
m_pkInput(NULL)
{
	/***/
}
//---------------------------------------------------------------------------
bool Scene::Init(Input * pkInput)
{
	m_pkInput = pkInput;

	sortEntitiesByZ();

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
void Scene::Draw(Graphics & rkGraphics) const
{
	onDraw(rkGraphics);

	for(unsigned int i = 0; i < m_apkEntities.size(); i++)
	{
		m_apkEntities[i]->Draw(rkGraphics);
	}
}
//---------------------------------------------------------------------------
void Scene::sortEntitiesByZ()
{
	sort(m_apkEntities.begin(), m_apkEntities.end(), Scene::entity2DComp);
}
//---------------------------------------------------------------------------
bool Scene::entity2DComp(Entity2D * pkEnt1, Entity2D * pkEnt2)
{
	return (pkEnt1->getPosZ() > pkEnt2->getPosZ());
}
//---------------------------------------------------------------------------
bool Scene::deInit()
{
	return onDeInit();
}
//---------------------------------------------------------------------------
Scene::~Scene()
{
	/***/
}
//---------------------------------------------------------------------------