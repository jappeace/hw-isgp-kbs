#include "Window.h"
#include "SimpleLevelFactory.h"

namespace isgp {

// Constructors / Destructors      //
Window::Window() {
	ILevelFactory* factory = new SimpleLevelFactory();
	_level = factory->CreateLevel();
	delete factory;
	_gameState = 1;
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
	_artist = new BackgroundArtist(_graphics, _cam, _level);
	_artist->RenderBackground();
}

INT_PTR CALLBACK dialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	return NULL;
}
void Window::OnPaint(Graphics* g){
	_level->Paint(g);
	_artist->Paint(g);
}
void Window::GameLoop(double elapsed) { //elapsed time, in MS
	if (_gameState == 1) {
		//update all the game objects now
		_level->_player->Update(elapsed);
		_level->_enemy->Update(elapsed);
		_level->_enemy2->Update(elapsed);
		_cam->Update(elapsed);
	} else if (_gameState == 2) {
		
	}

	AbstractWindow::GameLoop(elapsed);
}

void Window::OnKeyDown(int which) {
	if (which == VK_LEFT) {
		_level->_player->_leftKey = true;
	}
	if (which == VK_RIGHT) {
		_level->_player->_rightKey = true;
	}
	if (which == VK_UP) {
		_level->_player->_upKey = true;
	}
	if (which == VK_SPACE) {
		_level->_player->_spaceKey = true;
	}
}

void Window::OnKeyUp(int which) {
	if (which == VK_LEFT) {
		_level->_player->_leftKey = false;
	}
	if (which == VK_RIGHT) {
		_level->_player->_rightKey = false;
	}
	if (which == VK_UP) {
		_level->_player->_upKey = false;
	}
	if (which == VK_SPACE) {
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
