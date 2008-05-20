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
#include <d3dx9.h>
#include "Defines.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "GraphicsStructs.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class Texture;
//---------------------------------------------------------------------------

class FORCEENGINE_API Graphics
{
public:

	Graphics();
	~Graphics();

	bool InitDX(Window * g_window);
	bool InitMat();

	void BeginScene();
	void EndScene();

	void Clear();
	void Present();
	void Draw(const ColorVertex * vertexCollection, D3DPRIMITIVETYPE prim, unsigned int uiVertexCount);
	void Draw(const TextureVertex * vertexCollection, D3DPRIMITIVETYPE prim, unsigned int uiVertexCount);

	void loadIdentity ();
	void setMatrixMode(MatrixMode eMode);
	void Translate(float fX, float fY, float fZ = 0.0f);
	void Scale(float fW, float fH, float fD = 1.0f);
	void rotateZ(float fAngle);

	void setViewPosition (float fPosX, float fPosY);

	void unbindTexture();
	bool bindTexture(Texture& rkTexture);
	bool loadTexture(const char * pszFilename, Texture * rkTexture);

protected:

	std::map <std::string, IDirect3DTexture9 *> m_kTextureMap;
	typedef std::map<std::string, IDirect3DTexture9 *>::iterator TextureIterator;

private:

	HWND m_hWnd;
	IDirect3D9 * m_pD3D;
	IDirect3DDevice9 * m_pDevice;

	VertexBuffer <ColorVertex, D3DFVF_COLORVERTEX> m_vtxBufColor;
	VertexBuffer <TextureVertex, D3DFVF_TEXVERTEX> m_vtxBufTexture;

	D3DMATRIX d3dmat;

	MatrixMode m_eCurrentMatMode;
	
	float fX;
	float fY;
	float fAngle;

	friend class Game;
};

#endif /*--- GRAPHICS_H ---*/

//---------------------------------------------------------------------------