#include "Window.h"
namespace isgp {
const int fieldWidth = 50;
const int fieldHeight = 50;
/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
Window::Window() {
	_level = new Level(fieldWidth,fieldHeight);
}

Window::~Window()
{
}

/////////////////////////////////////
// Member functions                  //
/////////////////////////////////////

INT_PTR CALLBACK dialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	return NULL;
}
void Window::onPaint(Graphics* g){
	_level->setTileSize(
		&Size(
			(_windowSize->right  - _windowSize->left)	/ _level->getSize()->GetWidth(),
			(_windowSize->bottom - _windowSize->top)	/ _level->getSize()->GetHeight()
		)
		);
	_level->paint(g);
}

void Window::onCommand(int from, int command){
	switch(from){
	case ID_FILE_NEWGAME:
		this->repaint();
		break;
	case ID_HELP_ABOUT:
		MessageBox(
			_hWnd,
			// message:
			"Copyright Team Awesome, Program version: Awesome",
			// title:
			"Licensed under GPL v3",
			MB_OK | MB_ICONEXCLAMATION
		);
		break;
	case ID_FILE_EXIT:
		PostQuitMessage(0);
		break;
	}
}
LRESULT Window::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return AbstractWindow::MsgProc(hWnd, uMsg, wParam, lParam);
}


}
