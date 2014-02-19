// WinClass.cpp : Defines the entry point for the application.
//
#include "Window.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	isgp::Window app;

	if (!app.Create())
		return 0;
	
	return app.Run();
}
