#include "Skeleton.h"

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CSkeleton::CSkeleton()
{
	this->_graphics = NULL;
}

CSkeleton::~CSkeleton()
{
	if (this->_graphics)
		delete this->_graphics;
}

/////////////////////////////////////
// Member functions                //
/////////////////////////////////////

LRESULT CSkeleton::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	switch (uMsg) {
	case WM_CREATE:
		this->_graphics = new Graphics(hWnd);
		break;
	case WM_PAINT:
		this->_graphics->BeginRendering(hWnd, &ps);

		// TODO: Render stuff

		this->_graphics->EndRendering(hWnd, &ps);
		break;
	}
	return CWin::MsgProc(hWnd, uMsg, wParam, lParam);
}
