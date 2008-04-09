/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Defines
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef DEFINES_H
#define DEFINES_H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifdef FORCEENGINE_EXPORTS
	#define FORCEENGINE_API __declspec(dllexport)
#else
	#define FORCEENGINE_API __declspec(dllimport)
#endif /*--- SUPERENGINE_EXPORTS ---*/
	
#endif /*--- DEFINES_H ---*/

//---------------------------------------------------------------------------