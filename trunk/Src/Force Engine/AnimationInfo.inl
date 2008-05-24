/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: AnimationInfo.inl
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------

inline void AnimationInfo::setLength(float fLenght)
{
	m_fLength = fLenght;
	m_fTimePerFrame = m_fLength / getFrameCount();
}

//---------------------------------------------------------------------------
inline float AnimationInfo::getLength() const
{
	return m_fLength;
}

//---------------------------------------------------------------------------
inline float AnimationInfo::getTimePerFrame() const
{
	return m_fTimePerFrame;
}

//---------------------------------------------------------------------------
inline size_t AnimationInfo::getFrameCount() const
{
	return m_akFramesInfo.size();
}

//---------------------------------------------------------------------------
inline void AnimationInfo::setLoopable(bool bIsLoopable)
{
	m_bIsLoopable = bIsLoopable;
}

//---------------------------------------------------------------------------
inline bool AnimationInfo::getLoopable() const
{
	return m_bIsLoopable;
}

//---------------------------------------------------------------------------
inline const FrameInfo& AnimationInfo::getFrameInfo(unsigned int uiIndex) const
{
	return m_akFramesInfo[uiIndex];
}

//---------------------------------------------------------------------------