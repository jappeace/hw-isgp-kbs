#include "Skeleton.h"

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
Skeleton::Skeleton()
{
}

Skeleton::~Skeleton()
{
}

/////////////////////////////////////
// Member functions                //
/////////////////////////////////////

LRESULT Skeleton::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return Win::MsgProc(hWnd, uMsg, wParam, lParam);
}
