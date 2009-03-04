/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Graphics Structs.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef GRAPHICS_STRUCTS_H
#define GRAPHICS_STRUCTS_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define D3DFVF_COLORVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE)
//---------------------------------------------------------------------------

struct ColorVertex
{
	float x;	//  
	float y;	// Posicion de los Vertices
	float z;	//

	DWORD Color;	// Color del Vertice
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define D3DFVF_TEXVERTEX (D3DFVF_XYZ | D3DFVF_TEX1)
//---------------------------------------------------------------------------

struct TextureVertex
{
	float x;	//  
	float y;	// Posicion de los Vertices
	float z;	//
	
	float tu;	
	float tv;
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <d3dx9.h>

enum MatrixMode
{
	WORLD = D3DTS_WORLDMATRIX(0),
	VIEW = D3DTS_VIEW,
	PROJECTION = D3DTS_PROJECTION
};
//---------------------------------------------------------------------------
struct RGBColor {
	int iRed;
	int iGreen;
	int iBlue;

	RGBColor(int iR, int iG, int iB)
	{
		iRed = iR;
		iGreen = iG;
		iBlue = iB;
	}
	RGBColor()
	{
		/***/
	}
};
//---------------------------------------------------------------------------

#endif  /*--- GRAPHICS_STRUCTS_H ---*/

//---------------------------------------------------------------------------