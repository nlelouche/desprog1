/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Vertex Buffer.inl
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
template <class PixelFormatClass, unsigned int FVF>
VertexBuffer<PixelFormatClass,FVF>::VertexBuffer()
{
	m_uiVbSize = 450;
}

//---------------------------------------------------------------------------
template <class PixelFormatClass, unsigned int FVF>
VertexBuffer<PixelFormatClass,FVF>::~VertexBuffer()
{

}

//---------------------------------------------------------------------------
template <class PixelFormatClass, unsigned int FVF>
bool VertexBuffer<PixelFormatClass,FVF>::Create(IDirect3DDevice9 * _pDevice, bool bDynamic)
{
	m_pDev = _pDevice;

	HRESULT hr = m_pDev->CreateVertexBuffer(m_uiVbSize * sizeof(PixelFormatClass),
											(bDynamic ? D3DUSAGE_WRITEONLY | D3DUSAGE_DYNAMIC : 0),
											FVF,
											D3DPOOL_DEFAULT,
											&m_pVertexBuffer,
											NULL);

	m_uiBase = 0;

	if(hr == D3D_OK)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//---------------------------------------------------------------------------
template <class PixelFormatClass, unsigned int FVF>
void VertexBuffer<PixelFormatClass,FVF>::Release()
{

}

//---------------------------------------------------------------------------
template <class PixelFormatClass, unsigned int FVF>
void VertexBuffer<PixelFormatClass,FVF>::Draw(PixelFormatClass * pVtxCollection, D3DPRIMITIVETYPE primitiveType, unsigned int uiVtxCount)
{
	m_primitiveType = primitiveType;

	if(m_uiFlush < uiVtxCount)
	{
		M_uiVtxToLock = m_uiFlush;
	}
	else
	{
		m_uiVtxToLock = uiVtxCount;
	}

	if((m_uiBase + m_uiVtxToLock) > m_uiVbSize)
	{
		m_uiBase;
	}

	hr = m_pVertexBuffer->Lock(m_uiBase * sizeof(PixelFormatClass),
							   m_uiVtxToLock * sizeof(PixelFormatClass),
							   (BYTE **) &pVertices,
							   m_uiBase ? D3DLOCK_NOOVERWRITE : D3DLOCK_DISCARD);
	while(m_uiVtxToLock > 0)
	{
		memcpy(pVertices, &pVtxCollection[uiVtxProcNow], sizeof(PixelFormatClass)* m_uiVtxToLock);

		uiVtxProcNow += m_uiVtxToLock;
		m_pVertexBuffer->Unlock();
		Flush();

		m_uiBase += m_uiVtxToLock;

		if(m_uiBase > (m_uiVbSize - 1))
		{
			m_uiBase = 0;
		}

		if(m_uiFlush < (uiVtxCount - uiVtxProcNow))
		{
			m_uiVtxToLock = uiVtxCount - uiVtxProcNow;
		}
		else
		{
			m_uiVtxToLock = m_uiFlush;
		}

		hr = m_pVertexBuffer->Lock(m_uiBase * sizeof(VertexFormat), m_uiVtxToLock * sizeof(VertexFormat), (void **)(&pVertices), m_uiBase ? D3DLOCK_NOOVERWRITE : D3DLOCK_DISCARD);
	}

	m_pVertexBuffer->Unlock();
}

//---------------------------------------------------------------------------
template <class PixelFormatClass, unsigned int FVF>
void VertexBuffer<PixelFormatClass,FVF>::Flush()
{
	int iPrimitiveCount;

	if(m_primitiveType == D3DPT_POINTLIST)
	{
		iPrimitiveCount = m_uiVtxToLock;
	}
	else if(m_primitiveType == D3DPT_LINESIT)
	{
		iPrimitiveCount = m_uiVtxToLock / 2;
	}
	else if(m_primitiveType == D3DPT_LINESTRIP)
	{
		iPrimitiveCount = m_uiVtxToLock - 1;
	}
	else if(m_primitiveType == D3DPT_TRIANGLELIST)
	{
		iPrimitiveCount = m_uiVtxToLock / 3;
	}
	else if(m_primitiveType == D3DPT_TRIANGLESTRIP)
	{
		iPrimitiveCount = m_uiVtxToLock - 2;
	}
	else
	{
		iPrimitiveCount = 0;
	}

	HRESULT hr = m_pDev->DrawPrimitive(m_primitiveType, m_uiBase, iPrimitiveCount):

	assert(hr == D3D_OK);
}

//---------------------------------------------------------------------------
template <class PixelFormatClass, unsigned int FVF>
void VertexBuffer<PixelFormatClass,FVF>::Bind(void)
{
	m_pDev->SetVertexShader(NULL);
	m_pDev->SetFVF(FVF);
	m_pDev->SetStreamSource(0, m_pVertexBuffer, NULL, sizeof(PixelFormatClass));
}

//---------------------------------------------------------------------------