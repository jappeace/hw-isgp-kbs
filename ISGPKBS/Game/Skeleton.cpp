#include "Skeleton.h"

Skeleton::Skeleton()
{
	this->_graphics = NULL;
}

Skeleton::~Skeleton()
{
	if (this->_graphics)
		delete this->_graphics;
}

LRESULT Skeleton::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
	return Win::MsgProc(hWnd, uMsg, wParam, lParam);
}
