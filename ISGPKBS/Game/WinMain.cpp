// WinClass.cpp : Defines the entry point for the application.
//
#ifdef _DEBUG
    #define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
    #define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
    #define new DEBUG_NEW
#endif
#include "Window.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	isgp::Window app;

	if (!app.Create())
		return 0;

	app.Run();
	_CrtDumpMemoryLeaks();
	return 0;
}
