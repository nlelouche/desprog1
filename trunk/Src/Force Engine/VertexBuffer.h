/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Vertex Buffer.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <d3d9.h>
#include <d3dx9.h>
#include <cassert>
#include "Window.h"
#include "Defines.h"
#include "GraphicsStructs.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
//---------------------------------------------------------------------------

template <class PixelFormatClass, unsigned int FVF>
class VertexBuffer
{
public:

	VertexBuffer();
	~VertexBuffer();

	bool Create(IDirect3DDevice9 * m_pDevice, bool bDynamic);
	void Bind(void);
	void Flush(void);
	void Draw(const PixelFormatClass * pVtxCollection, D3DPRIMITIVETYPE primitiveType, unsigned int uiVtxCount);
	void Release();

private:

	// Tamaño de Vertex Buffer
	unsigned int m_uiVbSize;

	// Cantidad de Vertices cada cuanto se realizara un Draw Primitive
	unsigned int m_uiFlush;

	// Indice en el cual se deja el Vertex Buffer
	unsigned int m_uiBase;

	// Cantidad de Vertices a Trabar en Draw
	unsigned int m_uiVtxToLock;

	// Primitiva pasada a Draw como Parametro
	D3DPRIMITIVETYPE m_primitiveType;

	// El Vertex Buffer creado queda encapsulado dentro de la clase
	LPDIRECT3DVERTEXBUFFER9 m_pVertexBuffer;

	// Almaceno Temporalmente el Dispositivo que pase como parametro en Draw
	IDirect3DDevice9 * m_pkDevice;
};

//---------------------------------------------------------------------------
#include "VertexBuffer.inl"
//---------------------------------------------------------------------------

#endif  /*--- VERTEX_BUFFER_H ---*/

//---------------------------------------------------------------------------