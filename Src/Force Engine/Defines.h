/****************************************************************************

Force Engine v0.1

Creado: 28/03/08
Clase: Defines.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef DEFINES_H
#define DEFINES_H
//---------------------------------------------------------------------------
#pragma warning(disable : 4251)
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifdef FORCEENGINE_EXPORTS
	#define FORCEENGINE_API __declspec(dllexport)
#else
	#define FORCEENGINE_API __declspec(dllimport)
#endif /*--- SUPERENGINE_EXPORTS ---*/
	
#endif /*--- DEFINES_H ---*/

//---------------------------------------------------------------------------