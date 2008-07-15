/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Animation.inl
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
inline const AnimationInfo::Ptr Animation::getInfo() const
{
	return m_pkInfo;
}
//---------------------------------------------------------------------------
inline Animation::PlayState Animation::getState() const
{
	return m_eCurrentState;
}
//---------------------------------------------------------------------------
inline unsigned int Animation::getCurrentFrame() const
{
	return m_uiCurrentFrame;
}
//---------------------------------------------------------------------------