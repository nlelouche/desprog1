/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: ConfigFile.cpp
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include "ConfigFile.h"
//---------------------------------------------------------------------------
ConfigFile::ConfigFile()
{

}
//---------------------------------------------------------------------------
ConfigFile::ConfigFile(const char * pszFilename)
{
	_ifs.open(pszFilename);
}
//---------------------------------------------------------------------------
ConfigFile::~ConfigFile()
{
	_ifs.close();
}
//---------------------------------------------------------------------------
bool ConfigFile::Load(const char * pszFilename)
{
	if(_ifs.is_open()) 
	{
		_ifs.close();
	}

	_ifs.open(pszFilename);

	if(_ifs.is_open())
	{
		return true;
	}
	else
	{
		return false;
	}

	return true;
}
//---------------------------------------------------------------------------
void ConfigFile::deleteUnneeded(char * pszString)
{
	char szResult[FORCE_CFG_MAX_CHARACTERS] = "\0";
	char * p;
	char * pszResult;

	pszResult = szResult;
	p = pszString;

	while(*p != 0 && *p != FORCE_CFG_COMMENT)
	{
		if((*p >='0' && *p <= 'z')					||
			 *p == FORCE_CFG_EQUAL					||
			 *p == FORCE_CFG_START_SECTION_NAME		||
			 *p == FORCE_CFG_END_SECTION_NAME		||
			 *p == 'ñ' ||
			 *p == 'Ñ' ||
			 *p == '-' ||
			 *p == '.')
		{
			* pszResult = *p;
			pszResult++;
			* pszResult = 0;

		} 
		else 
		{
			if(* p == FORCE_CFG_STRING)
			{
				p++;

				while(* p != FORCE_CFG_STRING && * p != 0) 
				{
					* pszResult = * p;
					pszResult++;
					* pszResult = 0;

					p++;
				}
			}
		}

		p++;
	}

	strcpy_s(pszString, FORCE_CFG_MAX_CHARACTERS, & szResult[0]);
}
//---------------------------------------------------------------------------
void ConfigFile::searchSection(const char * pszSection)
{
	//char szBuscar[FORCE_CFG_MAX_CHARACTERS]="[\0";
	char szBuscar[FORCE_CFG_MAX_CHARACTERS];
	char szLine[FORCE_CFG_MAX_CHARACTERS] = "\0";

	szBuscar[0] = FORCE_CFG_START_SECTION_NAME;
	szBuscar[1] = '\0';

	strcat_s(szBuscar, FORCE_CFG_MAX_CHARACTERS, pszSection);
	//strcat_s(szBuscar, FORCE_CFG_MAX_CHARACTERS, "]\0");

	int len = (int)strlen(szBuscar);
	szBuscar[len] = FORCE_CFG_END_SECTION_NAME;
	szBuscar[len + 1] = '\0';

	if(_ifs.is_open())
	{
		_ifs.clear();
		_ifs.seekg(0,ios_base::beg);

		while(!_ifs.eof() && strcmp(szBuscar,szLine) != 0) 
		{
			_ifs.getline(szLine, FORCE_CFG_MAX_CHARACTERS);
			deleteUnneeded(szLine);
		}
	}
}
//---------------------------------------------------------------------------
void ConfigFile::searchValue(char * pszString, const char * szOption)
{
	char szResult[FORCE_CFG_MAX_CHARACTERS] = "\0";
	char szString[FORCE_CFG_MAX_CHARACTERS];
	char * p;
	char * pszResult;

	while(!_ifs.eof() && _stricmp(szOption, szResult) != 0 && *szResult != '[') 
	{
		pszResult = szResult;
		_ifs.getline(szString, FORCE_CFG_MAX_CHARACTERS);
		deleteUnneeded(szString);
		p = szString;

		while (*p != 0 && *p != '=') 
		{
			if (*p >='0' && *p <= 'z' || *p == '-') 
			{
				* pszResult = * p;
				pszResult++;
				* pszResult = 0;
			}

			p++;
		}
	}

	if(_stricmp(szOption, szResult) == 0 && * szResult != '[') 
	{
		while (* p != '=' && * p != '\0')
		{
			p++;
		}

		p++;

		strcpy_s(pszString, FORCE_CFG_MAX_CHARACTERS, p);
	} 
	else
	{
		pszString[0] = '\0';
	}
}
//---------------------------------------------------------------------------
int ConfigFile::ReadInteger(const char * pszSection, const char * pszOption, int iDefaultValue)
{
	char szString[FORCE_CFG_MAX_CHARACTERS];
	int iValor = iDefaultValue;
	char * p;

	searchSection(pszSection);
	searchValue(szString,pszOption);

	p = szString;

	if(* p == '-')
	{
		p++;

		if(* p >= '0' && * p <= '9')
		{
			iValor = -atoi(p);
		}
	} 
	else 
	{
		if(* szString >= '0' && * szString <= '9')
		{
			iValor = atoi(szString);
		}
	}

	return iValor;
}
//---------------------------------------------------------------------------
DWORD ConfigFile::ReadDWord(const char * pszSection, const char * pszOption, DWORD DefaultValue)
{
	char szString[FORCE_CFG_MAX_CHARACTERS];
	DWORD  dwValor = DefaultValue;

	searchSection(pszSection);
	searchValue(szString,pszOption);

	if(*szString >= '0' && *szString <= '9')
	{
		dwValor = (DWORD)strtoul(szString,NULL,10);
	}

	return dwValor;
}
//---------------------------------------------------------------------------
long ConfigFile::ReadLong (const char * pszSection, const char * pszOption, long lDefaultValue)
{
	char szString[FORCE_CFG_MAX_CHARACTERS];
	long  lValor = lDefaultValue;

	searchSection(pszSection);
	searchValue(szString,pszOption);

	if(* szString >= '0' && * szString <= '9')
	{
		lValor = atol(szString);
	}

	return lValor;
}
//---------------------------------------------------------------------------
bool ConfigFile::ReadBoolean(const char * pszSection, const char * pszOption, bool bDefaultValue)
{
	char szString[FORCE_CFG_MAX_CHARACTERS];
	char * p;
	bool bValor = bDefaultValue;

	searchSection(pszSection);
	searchValue(szString,pszOption);

	p = szString;

	// To LowerCase
	while(* p != 0) 
	{
		if(*p >= 'A' && *p <= 'Z')
		{
			* p = * p+32;
		}

		p++;
	}

	if(strcmp (szString,"true") == 0)
	{
		bValor = true;
	}
	else
	{
		if(strcmp (szString,"false") == 0)
		{
			bValor = false;
		}
	}

	return bValor;
}
//---------------------------------------------------------------------------
float ConfigFile::ReadFloat(const char * pszSection, const char * pszOption, float fDefaultValue)
{
	char szString[FORCE_CFG_MAX_CHARACTERS];
	float fValor = fDefaultValue;

	searchSection(pszSection);
	searchValue(szString,pszOption);

	if(* szString != 0)
	{
		fValor = (float)atof(szString);
	}
	else
	{
		fValor = fDefaultValue;
	}

	return fValor;
}
//---------------------------------------------------------------------------
char * ConfigFile::ReadString(const char * pszSection, const char * pszOption, const char *pszDefaultValue)
{
	char szString[FORCE_CFG_MAX_CHARACTERS];

	searchSection(pszSection);
	searchValue(szString,pszOption);

	if(* szString == NULL)
	{
		strcpy_s(_szString, FORCE_CFG_MAX_CHARACTERS, pszDefaultValue);
	}
	else
	{
		strcpy_s(_szString, FORCE_CFG_MAX_CHARACTERS, szString);
	}

	return _szString;
}
//---------------------------------------------------------------------------