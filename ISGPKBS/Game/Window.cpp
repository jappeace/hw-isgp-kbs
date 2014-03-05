#include "Window.h"
#include "SimpleLevelFactory.h"

namespace isgp {

// Constructors / Destructors      //
Window::Window() {
	ILevelFactory* factory = new SimpleLevelFactory();
	_level = factory->CreateLevel();
	delete factory;
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
	_cam->Update(elapsed);

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
