/****************************************************************************

Force Engine v0.5

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
#ifdef FORCEENGINE_EXPORTS
	#define FORCEENGINE_API __declspec(dllexport)
#else
	#define FORCEENGINE_API __declspec(dllimport)
#endif /*--- SUPERENGINE_EXPORTS ---*/

// Sin Esto NO ANDA NADA
// Includes Basicos

#include <map>
#include <string>
#include <vector>
#include <cassert>
#include <windows.h>

//---------------------------------------------------------------------------

// Smart Pointers Boost

#include <boost/shared_ptr.hpp>

#define DECLARE_SMART_POINTER(classname) \
	public:	\
	typedef boost::shared_ptr <classname> Ptr;

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

// Fmod Sound System

#include <fmod/fmod.hpp>

//---------------------------------------------------------------------------
	
#endif /*--- DEFINES_H ---*/

//---------------------------------------------------------------------------