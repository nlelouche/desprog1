/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Graphics.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Graphics.h"
//---------------------------------------------------------------------------
Graphics::Graphics()
:
m_pD3D(NULL),
m_pkDevice(NULL),
m_hWnd(NULL),
m_eCurrentMatMode(VIEW)
{
	
}
//---------------------------------------------------------------------------
Graphics::~Graphics()
{
	m_vtxBufColor.Release();
	m_vtxBufTexture.Release();
}
//---------------------------------------------------------------------------
bool Graphics::InitDX(Window * m_pkWindow)
{
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if(!m_pD3D)
	{
		return false;
	}

	D3DDISPLAYMODE displayMode;
	HRESULT hr;

	hr = m_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode);

	if(hr != D3D_OK)
	{
		return false;
	}

	D3DPRESENT_PARAMETERS d3DPresentParameters;
	ZeroMemory(&d3DPresentParameters, sizeof(d3DPresentParameters));

	d3DPresentParameters.BackBufferFormat = displayMode.Format;
	d3DPresentParameters.Windowed = true;
	d3DPresentParameters.BackBufferCount = 1; 
	d3DPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3DPresentParameters.hDeviceWindow = 0; 
	d3DPresentParameters.Flags = 0;
	d3DPresentParameters.EnableAutoDepthStencil = TRUE;
	d3DPresentParameters.AutoDepthStencilFormat = D3DFMT_D16;
	d3DPresentParameters.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3DPresentParameters.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	hr = m_pD3D->CreateDevice(
							  D3DADAPTER_DEFAULT,
 							  D3DDEVTYPE_HAL,							
							  m_pkWindow->m_hWnd,
							  D3DCREATE_HARDWARE_VERTEXPROCESSING,
							  &d3DPresentParameters,
							  &m_pkDevice
							  );

	if(!m_vtxBufColor.Create(m_pkDevice, true))
	{
		return false;
	}

	if(!m_vtxBufTexture.Create(m_pkDevice, true))
	{
		return false;
	}

	InitMat();

	return true;
}
//---------------------------------------------------------------------------
bool Graphics::InitMat()
{	
	// Matriz de Mundo

	D3DXMATRIX d3dmatMundo;
	D3DXMatrixIdentity(&d3dmatMundo);
	D3DXMatrixTranslation(&d3dmatMundo, 0,  0, 1.0f);
	D3DXMatrixRotationZ(&d3dmatMundo, 0);

	m_pkDevice->SetTransform(D3DTS_WORLD, &d3dmatMundo);

	// Matriz de Vista

	D3DXMATRIX d3dmatVista;
	D3DXMatrixIdentity(&d3dmatVista);

	D3DXVECTOR3 eyePos(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 lookPos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 upVec(0.0f, 1.0f, 0.0f); 

	D3DXMatrixLookAtLH(&d3dmatVista, &eyePos, &lookPos, &upVec);
	m_pkDevice->SetTransform(D3DTS_VIEW, &d3dmatVista);

	// Matriz de Proyeccion

	D3DVIEWPORT9 viewport;
	m_pkDevice->GetViewport(&viewport);

	float viewportWidth = static_cast <float> (viewport.Width);
	float viewportHeight = static_cast <float> (viewport.Height);

	D3DXMATRIX d3dmatProy;
	D3DXMatrixOrthoLH(&d3dmatProy, viewportWidth, viewportHeight, -25, 25);
	
	HRESULT hr = m_pkDevice->SetTransform(D3DTS_PROJECTION, &d3dmatProy);	
	
	m_pkDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_pkDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);

	m_pkDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	m_pkDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

	return true;
}
//---------------------------------------------------------------------------
void Graphics::Clear()
{
	m_pkDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0,0,0), 1.0f, 0);
}
//---------------------------------------------------------------------------
void Graphics::BeginScene()
{
	m_pkDevice->BeginScene();
}
//---------------------------------------------------------------------------
void Graphics::EndScene()
{
	m_pkDevice->EndScene();
}
//---------------------------------------------------------------------------
void Graphics::Present()
{
	m_pkDevice->Present(NULL, NULL, NULL, NULL);
}
//---------------------------------------------------------------------------
void Graphics::Draw(const ColorVertex * vertexCollection, D3DPRIMITIVETYPE prim, unsigned int uiVertexCount)
{
	m_vtxBufColor.Bind();
	m_vtxBufColor.Draw(vertexCollection, prim, uiVertexCount);
}
//---------------------------------------------------------------------------
void Graphics::Draw(const TextureVertex * vertexCollection, D3DPRIMITIVETYPE prim, unsigned int uiVertexCount)
{
	m_vtxBufTexture.Bind();
	m_vtxBufTexture.Draw(vertexCollection, prim, uiVertexCount);
}
//---------------------------------------------------------------------------
void Graphics::loadIdentity()
{
	D3DXMATRIX kTempMatrix;

	D3DXMatrixIdentity(&kTempMatrix);

	if (m_eCurrentMatMode == VIEW) 
	{		
		D3DXVECTOR3 kEyePos(0,0,-1);
		D3DXVECTOR3 kLookPos(0,0,0);
		D3DXVECTOR3 kUpVector(0,1,0);
		
		D3DXMatrixLookAtLH(&kTempMatrix, &kEyePos, &kLookPos, &kUpVector);
	}

	D3DTRANSFORMSTATETYPE eMatMode = static_cast<D3DTRANSFORMSTATETYPE>(m_eCurrentMatMode);
	
	m_pkDevice->SetTransform(eMatMode, &kTempMatrix);
}
//---------------------------------------------------------------------------
void Graphics::setMatrixMode(MatrixMode eMode)
{
	m_eCurrentMatMode = eMode;
}
//---------------------------------------------------------------------------
void Graphics::Translate(float fX, float fY, float fZ)
{
	D3DXMATRIX kTempMatrix;

	D3DXMatrixTranslation(&kTempMatrix, fX,  fY, 1.0f);

	D3DTRANSFORMSTATETYPE eMatMode = static_cast <D3DTRANSFORMSTATETYPE>(m_eCurrentMatMode);

	m_pkDevice->MultiplyTransform(eMatMode, &kTempMatrix);
}
//---------------------------------------------------------------------------
void Graphics::Scale(float fW, float fH, float fD)
{
	D3DXMATRIX kTempMatrix;

	fD = 1.00000f;

	D3DXMatrixScaling(&kTempMatrix, fW, fH, fD);

	D3DTRANSFORMSTATETYPE eMatMode = static_cast<D3DTRANSFORMSTATETYPE>(m_eCurrentMatMode);

	m_pkDevice->MultiplyTransform(eMatMode, &kTempMatrix);
}
//---------------------------------------------------------------------------
void Graphics::rotateZ(float fAngle)
{
	D3DXMATRIX kTempMatrix;

	D3DXMatrixRotationZ(&kTempMatrix, fAngle);

	D3DTRANSFORMSTATETYPE eMatMode = static_cast<D3DTRANSFORMSTATETYPE>(m_eCurrentMatMode);

	m_pkDevice->MultiplyTransform(eMatMode, &kTempMatrix);
}
//---------------------------------------------------------------------------
void Graphics::setViewPosition(float fPosX, float fPosY)
{
	D3DXMATRIX kMatrix;

	D3DXVECTOR3 kEyePos;
	D3DXVECTOR3 kLookPos;
	D3DXVECTOR3 kUpVector;

	kEyePos.x = fPosX;	
	kEyePos.y = fPosY;	
	kEyePos.z = -5.0f;

	kLookPos.x = fPosX;
	kLookPos.y = fPosY;	
	kLookPos.z = 0.0f;

	kUpVector.x = 0.0f;	
	kUpVector.y = 1.0f;	
	kUpVector.z = 0.0f;

	D3DXMatrixLookAtLH(&kMatrix, &kEyePos, &kLookPos, &kUpVector);
	m_pkDevice->SetTransform(D3DTS_VIEW, &kMatrix);
}
//---------------------------------------------------------------------------
void Graphics::unbindTexture()
{
	m_pkDevice->SetTexture(0, NULL);
}
//---------------------------------------------------------------------------
bool Graphics::bindTexture(Texture & rkTexture)
{
	IDirect3DTexture9 * pkDXTexture = m_kTextureMap[rkTexture.getFileName()];
	assert(pkDXTexture);
	
	HRESULT hr = m_pkDevice->SetTexture(0, pkDXTexture);

	return (hr == D3D_OK);
}
//---------------------------------------------------------------------------
bool Graphics::loadTexture(const char * pszFilename, Texture & rkTexture)
{
	D3DSURFACE_DESC kDescription;
	IDirect3DTexture9 * pkDXTexture = NULL;

	pkDXTexture = m_kTextureMap[rkTexture.getFileName()];

	if(!pkDXTexture)
	{
		HRESULT hr;
		
		hr = D3DXCreateTextureFromFileEx(
										m_pkDevice,
										rkTexture.getFileName().c_str(), 
										0, 0, 0, 0,
										D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
										D3DX_FILTER_NONE, D3DX_FILTER_NONE,
										rkTexture.getColorKey(),
										NULL,
										NULL,
										&pkDXTexture
										);

		if (hr != D3D_OK)
		{
			return false;
		}

		m_kTextureMap[rkTexture.getFileName()] = pkDXTexture;
	}

	pkDXTexture->GetLevelDesc(0,&kDescription);

	rkTexture.setWidth(kDescription.Width);
	rkTexture.setHeight(kDescription.Height);

	return true;
}
//---------------------------------------------------------------------------