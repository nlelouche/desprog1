/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Graphics Structs.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef GRAPHICS_STRUCTS_H
#define GRAPHICS_STRUCTS_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#define D3DFVF_COLORVERTEX (D3DFVF_XYZ |D3DFVF_DIFFUSE)

class GraphicsStructs
{
public:

	struct ColorVertex
	{
		float x;	//  
		float y;	// Posicion de los Vertices
		float z;	//

		DWORD Color;	// Color del Vertice
	};
};

#endif  /*--- GRAPHICS_STRUCTS_H ---*/

//---------------------------------------------------------------------------