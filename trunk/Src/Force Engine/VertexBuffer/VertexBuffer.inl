/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Vertex Buffer.inl
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
template <class PixelFormatClass, unsigned int FVF>
VertexBuffer<PixelFormatClass,FVF>::VertexBuffer()
:
m_pkDevice(NULL),
m_VertexBuffer(NULL)
{

}
//---------------------------------------------------------------------------
template <class PixelFormatClass, unsigned int FVF>
VertexBuffer<PixelFormatClass,FVF>::~VertexBuffer()
{

}
//---------------------------------------------------------------------------
template <class PixelFormatClass, unsigned int FVF>
bool VertexBuffer<PixelFormatClass,FVF>::Create(IDirect3DDevice9 * pkDevice, bool bDynamic)
{
	m_pkDevice = pkDevice;

	m_uiBase = 0;
	m_uiFlush = 150;
	m_uiVbSize = 450;

	HRESULT hr = pkDevice->CreateVertexBuffer( m_uiVbSize * sizeof(PixelFormatClass),
											 (bDynamic ? D3DUSAGE_WRITEONLY | D3DUSAGE_DYNAMIC : 0),
											 FVF,
											 D3DPOOL_DEFAULT,
											 &m_VertexBuffer,
											 NULL );


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
void VertexBuffer<PixelFormatClass,FVF>::Draw(const PixelFormatClass * pVtxCollection, D3DPRIMITIVETYPE primitiveType, unsigned int uiVtxCount)
{
	m_primitiveType = primitiveType;

	if(m_uiFlush < uiVtxCount)
	{
		m_uiVtxToLock = m_uiFlush;
	}
	else
	{
		m_uiVtxToLock = uiVtxCount;
	}

	if((m_uiBase + m_uiVtxToLock) > m_uiVbSize)
	{
		m_uiBase = 0;
	}

	void * pVertices = NULL;

	HRESULT hr = m_VertexBuffer->Lock(
									  m_uiBase * sizeof(PixelFormatClass),
									  m_uiVtxToLock * sizeof(PixelFormatClass),
									  (void **) (&pVertices),
									  m_uiBase ? D3DLOCK_NOOVERWRITE : D3DLOCK_DISCARD
									  );

	unsigned int uiVtxProcNow = 0;

	while(m_uiVtxToLock > 0)
	{
		memcpy(pVertices, &pVtxCollection[uiVtxProcNow], sizeof(PixelFormatClass)* m_uiVtxToLock);

		uiVtxProcNow += m_uiVtxToLock;
		hr = m_VertexBuffer->Unlock();
		Flush();

		m_uiBase += m_uiVtxToLock;

		if(m_uiBase > (m_uiVbSize - 1))
		{
			m_uiBase = 0;
		}

		if(m_uiFlush < (uiVtxCount - uiVtxProcNow))
		{
			m_uiVtxToLock = m_uiFlush;
		}
		else
		{
			m_uiVtxToLock = uiVtxCount - uiVtxProcNow;
		}

		hr = m_VertexBuffer->Lock(
								   m_uiBase * sizeof(PixelFormatClass), 
								   m_uiVtxToLock * sizeof(PixelFormatClass), 
								   (void **)(&pVertices),
								   m_uiBase ? D3DLOCK_NOOVERWRITE : D3DLOCK_DISCARD
								   );
	}

	m_VertexBuffer->Unlock();
	
}
//---------------------------------------------------------------------------
template <class PixelFormatClass, unsigned int FVF>
void VertexBuffer<PixelFormatClass,FVF>::Flush()
{
	int iPrimitiveCount = 0;

	if(m_primitiveType == D3DPT_POINTLIST)
	{
		iPrimitiveCount = m_uiVtxToLock;
	}
	else if(m_primitiveType == D3DPT_LINELIST)
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
	else if(m_primitiveType == D3DPT_TRIANGLEFAN)
	{
		iPrimitiveCount = m_uiVtxToLock - 2;
	}

	HRESULT hr = m_pkDevice->DrawPrimitive(m_primitiveType, m_uiBase, iPrimitiveCount);

	assert(hr == D3D_OK);
}
//---------------------------------------------------------------------------
template <class PixelFormatClass, unsigned int FVF>
void VertexBuffer<PixelFormatClass,FVF>::Bind(void)
{
	HRESULT hr;
	
	hr = m_pkDevice->SetVertexShader(NULL);
	hr = m_pkDevice->SetFVF(FVF);
	hr = m_pkDevice->SetStreamSource(0, m_VertexBuffer, NULL, sizeof(PixelFormatClass));
}
//---------------------------------------------------------------------------