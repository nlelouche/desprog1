/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Graphics.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "Graphics.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
Graphics::Graphics()
{
	
}

//---------------------------------------------------------------------------
Graphics::~Graphics()
{

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
							  &_pDevice);

	if(!m_vtxBufColor.Create(_pDevice, true))
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

	_pDevice->SetTransform(D3DTS_WORLD, &d3dmatMundo);

	// Matriz de Vista

	D3DXMATRIX d3dmatVista;
	D3DXMatrixIdentity(&d3dmatVista);

	D3DXVECTOR3 eyePos(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 lookPos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 upVec(0.0f, 1.0f, 0.0f); 

	D3DXMatrixLookAtLH(&d3dmatVista, &eyePos, &lookPos, &upVec);
	_pDevice->SetTransform(D3DTS_VIEW, &d3dmatVista);

	// Matriz de Proyeccion

	D3DVIEWPORT9 viewport;
	_pDevice->GetViewport(&viewport);

	float viewportWidth = static_cast <float> (viewport.Width);
	float viewportHeight = static_cast <float> (viewport.Height);

	D3DXMATRIX d3dmatProy;
	D3DXMatrixOrthoLH(&d3dmatProy, viewportWidth, viewportHeight, -25, 25);
	HRESULT hr = _pDevice->SetTransform(D3DTS_PROJECTION, &d3dmatProy);	
	
	_pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	_pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);



	return true;
}

//---------------------------------------------------------------------------
bool Graphics::CheckModes()
{
	return true;
}

//---------------------------------------------------------------------------
void Graphics::Clear()
{
	_pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
}

//---------------------------------------------------------------------------
void Graphics::SetupScene()
{
	
}

//---------------------------------------------------------------------------
void Graphics::BeginScene()
{
	_pDevice->BeginScene();
}

//---------------------------------------------------------------------------
void Graphics::EndScene()
{
	_pDevice->EndScene();
}

//---------------------------------------------------------------------------

void Graphics::Present()
{
	_pDevice->Present(NULL, NULL, NULL, NULL);
}

//---------------------------------------------------------------------------
void Graphics::Draw(ColorVertex * vertexCollection, D3DPRIMITIVETYPE prim, unsigned int uiVertexCount)
{
	m_vtxBufColor.Bind();
	m_vtxBufColor.Draw(vertexCollection, prim, uiVertexCount);
}

//---------------------------------------------------------------------------