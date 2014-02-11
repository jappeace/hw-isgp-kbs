// WinMain.cpp: Defines the entry point of the program.
#include "Skeleton.h"

int APIENTRY WinMain(HINSTANCE h_instance,
                     HINSTANCE h_prev_instance,
                     LPSTR cmd_arguments,
                     int cmd_show)
{
	Skeleton app;

	if (!app.Create())
	{
		return 0;
	}

	return app.Run();
}
