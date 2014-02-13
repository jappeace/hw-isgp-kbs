#include "Window.h"

namespace isgp {
// amount of tiles
const Size g_tiles = Size(50,50);
/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
Window::Window() {
	Grid* g = new Grid(g_tiles.GetWidth(),g_tiles.GetHeight());// level handles destruction of grid
	_level = new Level(g);
	Point position = Point(5,5);
	g->getTileAt(position)->setIpaintalbe(new WorldBlock(position, "C:\\\\smile.bmp"));
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
