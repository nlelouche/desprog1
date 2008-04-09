/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Graphics.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef GRAPHICS_H
#define GRAPHICS_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <d3d9.h>
#include <d3dx9.h>
#include "Window.h"
#include "Defines.h"
#include "VertexBuffer.h"
#include "GraphicsStructs.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
//---------------------------------------------------------------------------

class Graphics : public GraphicsStructs
{
public:

	Graphics();
	~Graphics();

private:

	bool InitDX(Window g_window);
	bool CheckModes();

	void SetupScene();
	void BeginScene(void);
	void EndScene(void);

	void Clear();
	void Present(void);
	void Draw(ColorVertex * vertexCollection, D3DPRIMITIVETYPE prim, unsigned int uiVertexCount);

	HRESULT DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount);

	HWND m_hWnd;
	IDirect3D9 * m_pD3D;
	IDirect3DDevice9 * _pDevice;

	VertexBuffer <ColorVertex, D3DFVF_COLORVERTEX> m_vtxBufColor;

	friend class Game;
};

#endif /*--- GRAPHICS_H ---*/

//---------------------------------------------------------------------------