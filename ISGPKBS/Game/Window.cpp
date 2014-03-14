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

void Window::ClientResize(HWND hWnd, int nWidth, int nHeight)
{
  RECT rcClient, rcWind;
  POINT ptDiff;
  GetClientRect(hWnd, &rcClient);
  GetWindowRect(hWnd, &rcWind);
  ptDiff.x = (rcWind.right - rcWind.left) - rcClient.right;
  ptDiff.y = (rcWind.bottom - rcWind.top) - rcClient.bottom;
  MoveWindow(hWnd,rcWind.left, rcWind.top, nWidth + ptDiff.x, nHeight + ptDiff.y, TRUE);
}

void Window::AfterCreate(HWND hWnd) {
	ClientResize(hWnd, WindowSize.GetWidth(), WindowSize.GetHeight());
	
	_cam = new Camera(_level->_player, _level->GetGrid());
	_graphics->SetCam(_cam);
}

INT_PTR CALLBACK dialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	return NULL;
}
void Window::OnPaint(Graphics* g){
	//g->DrawBitmap("./tiles/mountain.bmp", Vector2D((_cam->GetPosition().X() - 384) * 0.5, (_cam->GetPosition().Y() - 384) * 0.5), Size(1920, 791));
	//g->DrawBitmap("./tiles/ground.bmp", Vector2D((_cam->GetPosition().X() - 384) * 0.25, (_cam->GetPosition().Y() + 2000) * 0.25), Size(1920, 321));

	_level->Paint(g);
}
void Window::GameLoop(double elapsed) { //elapsed time, in MS
	if (_gameState == 1) {
		//update all the game objects now
		_level->_player->Update(elapsed);
		_level->_enemy->Update(elapsed);
		_level->_enemy2->Update(elapsed);
		_level->_gadget->Update(elapsed);
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
