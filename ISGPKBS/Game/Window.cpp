#include "Window.h"
#include "SimpleLevelFactory.h"

namespace isgp {

// Constructors / Destructors      //
Window::Window() {
	ILevelFactory* factory = new SimpleLevelFactory();
	_level = factory->CreateLevel();
	delete factory;
	this->_gameState = Playing;
}

Window::~Window()
{
}

/////////////////////////////////////
// Member functions                //
/////////////////////////////////////

void Window::AfterCreate() {
	_cam = new Camera(_level->_player);
	_graphics->SetCam(_cam);
}

INT_PTR CALLBACK dialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	return NULL;
}
void Window::OnPaint(Graphics* g){
	if (_gameState == Playing) {
		_level->Paint(g);
	}
	else {
		this->_gameOverMenu.Paint(g);
	}
}
void Window::GameLoop(double elapsed) { //elapsed time, in MS
	if (_gameState == Playing) {
		//update all the game objects now
		_level->_player->Update(elapsed);
		_level->_enemy->Update(elapsed);
		_level->_enemy2->Update(elapsed);
		_cam->Update(elapsed);
		if (!_level->_player->IsAlive()) {
			_gameState = GameOver;
		}

	} else if (_gameState == GameOver) {
		// TODO
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
#ifdef _DEBUG
	if (which == VK_ESCAPE) {
		_gameState = GameOver;
	}
	if (which == VK_RETURN) {
		_gameState = Playing;
	}
	// 0x51 = q key.
	if (which == 0x51) {
		_level->_player->Kill();
	}
#endif
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
