#include "Window.h"
#include "SimpleLevelFactory.h"
#include "GameOverMenu.h"
#include "DefaultlevelFactory.h"
#include "MenuItem.h"
#include "PlayingGameState.h"
#include "GameOverGameState.h"

namespace isgp {

// Constructors / Destructors      //
Window::Window() {
	_cam = NULL;
	_currentMenu = NULL;
	_gameState = NULL;
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
	_gameState = new PlayingGameState(_graphics, this, &Window::GameOver);
	ClientResize(hWnd, WindowSize.GetWidth(), WindowSize.GetHeight());
	
	_graphics->LoadBitmapFile("../tiles/mountain.bmp");
	_graphics->LoadBitmapFile("../tiles/ground.bmp");

	_graphics->LoadBitmapFile("../tiles/megaman.bmp");
	_graphics->LoadBitmapFile("../tiles/boo.bmp");
	_graphics->LoadBitmapFile("../tiles/link.bmp");
	_graphics->LoadBitmapFile("../tiles/boots.bmp");
	_graphics->LoadBitmapFile("../tiles/smile.bmp");
}

INT_PTR CALLBACK dialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	return NULL;
}

void Window::OnPaint(Graphics* g){
	if (_gameState != NULL) {
		_gameState->Paint(g);
	}
}
void Window::GameLoop(double elapsed) { //elapsed time, in MS
	if (_gameState != NULL) {
		_gameState->Update(elapsed);
	}
}

void Window::OnKeyDown(int which) {
	if (_gameState != NULL) {
		_gameState->KeyDown(which);
	}
}

void Window::OnKeyUp(int which) {
	if (_gameState != NULL) {
		_gameState->KeyUp(which);
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

void Window::RestartGame() {
	SimpleLevelFactory factory;
	_level = factory.CreateLevel();
	_gameState = NULL;
	AfterCreate(_hWnd);
	delete _currentMenu;
	_currentMenu = NULL;
}

void Window::GameOver() {
	delete _gameState;
	_graphics->SetCam(NULL);
	_gameState = new GameOverGameState(_graphics, this,
		&Window::RestartGame, &Window::QuitGame);
}

void Window::QuitGame() {
	PostQuitMessage(0);
}

}
