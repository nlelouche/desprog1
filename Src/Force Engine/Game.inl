/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Game.inl
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
inline void Game::addEntity(Entity2D * pkEntity)
{
	assert(pkEntity);

	m_apkEntities.push_back(pkEntity);
}

//---------------------------------------------------------------------------
inline void Game::setCurrentScene(Scene * pkCurrentScene)
{
	m_pkCurrentScene = pkCurrentScene;
}

//---------------------------------------------------------------------------
inline const Scene * Game::getCurrentScene() const
{
	return m_pkCurrentScene;
}

//---------------------------------------------------------------------------