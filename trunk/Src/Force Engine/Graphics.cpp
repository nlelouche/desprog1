/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Graphics.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Graphics.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
Graphics::Graphics()
:
m_pD3D(NULL),
m_pDevice(NULL),
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
bool Graphics::InitDX(Window * g_window)
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
	d3DPresentParameters.AutoDepthStencilFormat = D3DFMT_D24S8; 
	d3DPresentParameters.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3DPresentParameters.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	hr = m_pD3D->CreateDevice(
							  D3DADAPTER_DEFAULT,
 							  D3DDEVTYPE_HAL,							
							  g_window->m_hWnd,
							  D3DCREATE_HARDWARE_VERTEXPROCESSING,
							  &d3DPresentParameters,
							  &m_pDevice
							  );

	if(!m_vtxBufColor.Create(m_pDevice, true))
	{
		return false;
	}

	if(!m_vtxBufTexture.Create(m_pDevice, true))
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

	m_pDevice->SetTransform(D3DTS_WORLD, &d3dmatMundo);

	// Matriz de Vista

	D3DXMATRIX d3dmatVista;
	D3DXMatrixIdentity(&d3dmatVista);

	D3DXVECTOR3 eyePos(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 lookPos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 upVec(0.0f, 1.0f, 0.0f); 

	D3DXMatrixLookAtLH(&d3dmatVista, &eyePos, &lookPos, &upVec);
	m_pDevice->SetTransform(D3DTS_VIEW, &d3dmatVista);

	// Matriz de Proyeccion

	D3DVIEWPORT9 viewport;
	m_pDevice->GetViewport(&viewport);

	float viewportWidth = static_cast <float> (viewport.Width);
	float viewportHeight = static_cast <float> (viewport.Height);

	D3DXMATRIX d3dmatProy;
	D3DXMatrixOrthoLH(&d3dmatProy, viewportWidth, viewportHeight, -25, 25);
	HRESULT hr = m_pDevice->SetTransform(D3DTS_PROJECTION, &d3dmatProy);	
	
	m_pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	m_pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	return true;
}

//---------------------------------------------------------------------------
void Graphics::Clear()
{
	m_pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,0), 1.0f, 0);
}

//---------------------------------------------------------------------------
void Graphics::BeginScene()
{
	m_pDevice->BeginScene();
}

//---------------------------------------------------------------------------
void Graphics::EndScene()
{
	m_pDevice->EndScene();
}

//---------------------------------------------------------------------------
void Graphics::Present()
{
	m_pDevice->Present(NULL, NULL, NULL, NULL);
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
	
	m_pDevice->SetTransform(eMatMode, &kTempMatrix);
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

	m_pDevice->MultiplyTransform(eMatMode, &kTempMatrix);
}

//---------------------------------------------------------------------------
void Graphics::Scale(float fW, float fH, float fD)
{
	D3DXMATRIX kTempMatrix;

	fD = 1.00000f;

	D3DXMatrixScaling(&kTempMatrix, fW, fH, fD);

	D3DTRANSFORMSTATETYPE eMatMode = static_cast<D3DTRANSFORMSTATETYPE>(m_eCurrentMatMode);

	m_pDevice->MultiplyTransform(eMatMode, &kTempMatrix);
}

//---------------------------------------------------------------------------
void Graphics::rotateZ(float fAngle)
{
	D3DXMATRIX kTempMatrix;

	D3DXMatrixRotationZ(&kTempMatrix, fAngle);

	D3DTRANSFORMSTATETYPE eMatMode = static_cast<D3DTRANSFORMSTATETYPE>(m_eCurrentMatMode);

	m_pDevice->MultiplyTransform(eMatMode, &kTempMatrix);
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
	m_pDevice->SetTransform(D3DTS_VIEW, &kMatrix);
}

//---------------------------------------------------------------------------
void Graphics::unbindTexture()
{
	m_pDevice->SetTexture(0, NULL);
}

//---------------------------------------------------------------------------
bool Graphics::bindTexture(Texture &rkTexture)
{
	IDirect3DTexture9 * pkDXTexture = m_kTextureMap[rkTexture.getFileName()];
	assert(pkDXTexture);
	
	HRESULT hr = m_pDevice->SetTexture(0, pkDXTexture);
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
		D3DXIMAGE_INFO kInfo;
		
		hr = D3DXCreateTextureFromFileEx(
										m_pDevice,
										pszFilename, 
										0, 0, 0, 0,
										D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
										D3DX_FILTER_NONE, D3DX_FILTER_NONE,
										0, //pTexInfo->texColorKey,
										&kInfo,
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