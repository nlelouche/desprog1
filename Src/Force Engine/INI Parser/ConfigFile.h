/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: ConfigFile.h
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H
//---------------------------------------------------------------------------
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "../Defines/Defines.h"
#include "../Src/Force Engine/Force Engine/ForceEngine.h"
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
#define FORCE_CFG_MAX_CHARACTERS			256
#define FORCE_CFG_START_SECTION_NAME		'['
#define FORCE_CFG_END_SECTION_NAME			']'
#define FORCE_CFG_EQUAL						'='
#define FORCE_CFG_COMMENT					';'
#define FORCE_CFG_STRING					'"'
//---------------------------------------------------------------------------
class FORCEENGINE_API ConfigFile 
{

public:

  	ConfigFile();
	ConfigFile(const char * pszFilename);

	~ConfigFile();

	bool Load(const char * pszFilename);

	int ReadInteger(const char * pszSection, const char * pszOption, int iDefaultValue);

	long ReadLong(const char * pszSection, const char * pszOption, long lDefaultValue);

	DWORD ReadDWord(const char * pszSection, const char * pszOption, DWORD DefaultValue);

	bool ReadBoolean(const char * pszSection, const char * pszOption, bool bDefaultValue);

	float ReadFloat(const char * pszSection, const char * pszOption, float fDefaultValue);

	char * ReadString(const char * pszSection, const char * pszOption, const char * pszDefaultValue);

private:

	ifstream    _ifs;

	char _szString[FORCE_CFG_MAX_CHARACTERS]; 

	void deleteUnneeded(char * pszString);
	void searchSection(const char * pszSection);
	void searchValue(char * pszString, const char * pszOption);

	friend class TileMap;
};

//---------------------------------------------------------------------------

#endif /*--- CONFIG_FILE_H ---*/

//---------------------------------------------------------------------------
