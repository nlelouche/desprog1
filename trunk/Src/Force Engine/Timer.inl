/****************************************************************************

Force Engine v0.1

Creado: 06/05/08
Clase: Timer.inl
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
inline float Timer::getTimeBetweenFrames() const
{	
	return static_cast<float>(m_dTimeBetweenFrames);
}

//---------------------------------------------------------------------------
inline unsigned int Timer::getFPS() const
{
	return m_uiFPS;
}

//---------------------------------------------------------------------------