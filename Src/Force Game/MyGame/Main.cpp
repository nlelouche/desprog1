/****************************************************************************

Force Engine v0.5

Creado: 28/03/08
Clase: Main
Hecho by: German Battiston AKA Melkor

****************************************************************************/

//---------------------------------------------------------------------------
#include <windows.h>
#include "../Src/Force Game/MyGame/ForceGame.h"
//---------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	Game * pkforceGame = new ForceGame(hInstance);

	if(!pkforceGame->Init())
	{
		return 0;
	}

	bool boolQuit = false;
	MSG kMsg;

	while(!(pkforceGame->Loop()) || !boolQuit)
	{
		// Capturo el mensaje de Windows
		if (PeekMessage(&kMsg,NULL,0,0,PM_REMOVE))
		{
			switch(kMsg.message)
			{
				// Si es un mensaje de salir de la aplicacion
				case WM_QUIT:
				{
					boolQuit = true;
					break;
				}
				// Si es un mensaje de presionar una tecla
				case WM_KEYDOWN:
				{
					int iKeyCode = (int)kMsg.wParam;

					switch (iKeyCode)
					{
						// Si esa tecla es ESC
						case VK_ESCAPE:
						{
   							boolQuit = true;
							break;
						}
					}
					break;
				}
			}

			// Le paso el mensaje de vuelta a Windows
			TranslateMessage(&kMsg);
			DispatchMessage(&kMsg);
		}
	}

	// Termino el Juego

	pkforceGame->deInit();

	return 0;
}

//---------------------------------------------------------------------------