#include "Window.h"

namespace isgp {
// amount of tiles
const Size g_tiles = Size(50,50);

// Constructors / Destructors      //
Window::Window() {
	Grid* g = new Grid(g_tiles.GetWidth(),g_tiles.GetHeight());// level handles destruction of grid
	_level = new Level(g);
	Point position = Point(5,5);
	g->GetTileAt(position)->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
	for(unsigned i = 0; i < 50; i++) {
		Point position = Point(i, 23);
		g->GetTileAt(position)->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
		Point position2 = Point(i, 22);
		g->GetTileAt(position2)->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
		Point position3 = Point(i, 21);
		g->GetTileAt(position2)->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
	}
}

Window::~Window()
{
}

/////////////////////////////////////
// Member functions                  //
/////////////////////////////////////

void Window::AfterCreate() {
	_cam = new Camera(_level->_player);
	_graphics->SetCam(_cam);
}

INT_PTR CALLBACK dialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	return NULL;
}
void Window::OnPaint(Graphics* g){
	_level->Paint(g);
}
void Window::GameLoop(double elapsed) { //elapsed time, in MS
	//update all the game objects now
	_level->_player->Update(elapsed);
	_cam->Update();

	AbstractWindow::GameLoop(elapsed);
}

void Window::OnKeyDown(int which) {
	if (which == 37) {
		_level->_player->_leftKey = true;
	}
	if (which == 39) {
		_level->_player->_rightKey = true;
	}
	if (which == 38) {
		_level->_player->_upKey = true;
	}
	if (which == 32) {
		_level->_player->_spaceKey = true;
	}
}

void Window::OnKeyUp(int which) {
	if (which == 37) {
		_level->_player->_leftKey = false;
	}
	if (which == 39) {
		_level->_player->_rightKey = false;
	}
	if (which == 38) {
		_level->_player->_upKey = false;
	}
	if (which == 32) {
		_level->_player->_spaceKey = false;
	}
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
