#include "Window.h"
#include "GameOverMenu.h"
#include "DefaultlevelFactory.h"
#include "MenuItem.h"
#include "PlayingGameState.h"
#include "GameOverGameState.h"
#include "Theme1.h"
#include "Theme2.h"
#include "Theme3.h"
#include "Theme4.h"
#include "Theme5.h"

namespace isgp {

// Constructors / Destructors      //
Window::Window() {
	_currentLevel = 1;
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
	Theme* tmp;
	switch (_currentLevel) {
	case 1 :
		tmp = new Theme1();
		break;
	case 2 :
		tmp = new Theme2();
		break;
	case 3 :
		tmp = new Theme3();
		break;
	case 4 :
		tmp = new Theme4();
		break;
	case 5 :
		tmp = new Theme5();
		break;
	}
	tmp->LoadContent(_graphics);
	_gameState = new PlayingGameState(_graphics, this, _currentLevel, tmp, &Window::GameOver);
	ClientResize(hWnd, WindowSize.GetWidth(), WindowSize.GetHeight());
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

void Window::FullRestart() {
	_currentLevel = 1;
	RestartGame();
}

void Window::NextLevel() {
	_currentLevel++;
	if(DefaultlevelFactory().LevelExists(_currentLevel)) {
		RestartGame();
	} else { //Completed all levels, wat do?
		_gameState = new GameCompletedGameState(this);
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
	delete _gameState;
	AfterCreate(_hWnd);
}

void Window::GameOver() {
	delete _gameState;
	_graphics->SetTranslator(NULL);
	_gameState = new GameOverGameState(_graphics, this,
		&Window::RestartGame, &Window::QuitGame);
}

void Window::QuitGame() {
	PostQuitMessage(0);
}

}
