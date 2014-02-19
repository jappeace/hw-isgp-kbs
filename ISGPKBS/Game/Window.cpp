#include "Window.h"

namespace isgp {
// amount of tiles
const Size g_tiles = Size(50,50);

// Constructors / Destructors      //
Window::Window() {
	Grid* g = new Grid(g_tiles.GetWidth(),g_tiles.GetHeight());// level handles destruction of grid
	_level = new Level(g);
	Point position = Point(5,5);
	g->GetTileAt(position)->SetData(new WorldBlock(position, "C:\\tiles\\smile.bmp"));
	for(unsigned i = 0; i < 50; i++) {
		Point position = Point(i, 23);
		g->GetTileAt(position)->SetData(new WorldBlock(position, "C:\\tiles\\smile.bmp"));
		Point position2 = Point(i, 22);
		g->GetTileAt(position2)->SetData(new WorldBlock(position2, "C:\\tiles\\smile.bmp"));
		Point position3 = Point(i, 21);
		g->GetTileAt(position2)->SetData(new WorldBlock(position2, "C:\\tiles\\smile.bmp"));
	}
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
void Window::OnPaint(Graphics* g){
	_level->Paint(g);
}


void Window::OnCommand(int from, int command) {
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

LRESULT Window::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	return AbstractWindow::MsgProc(hWnd, uMsg, wParam, lParam);
}

}
