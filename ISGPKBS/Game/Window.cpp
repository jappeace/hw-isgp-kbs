#include "Window.h"
#include "SimpleLevelFactory.h"
#include "GameOverMenu.h"
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
}

INT_PTR CALLBACK dialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	return NULL;
}

void Window::OnPaint(Graphics* g){
	if (_gameState != NULL) {
		_gameState->Paint(g);
	}
	//if (_gameState == NULL) {
	//	if (_cam != NULL) {
	//		double width1 = (GridGraphicTranslator().FromTo(*_level->GetGrid()->GetSize()).X() * 0.5) + AbstractWindow::WindowSize.GetWidth();
	//		double width2 = (GridGraphicTranslator().FromTo(*_level->GetGrid()->GetSize()).X() * 0.75) + AbstractWindow::WindowSize.GetWidth();

	//		Vector2D fix = ((AbstractWindow::WindowSize - Player::InitSize) * Vector2D(1.0,1.35)) / Vector2D(2);

	//		//Draw sky
	//		for (int i = 0; i < width1; i += 1920) {
	//			//g->DrawBitmap("../tiles/mountain.bmp", Vector2D(((_cam->GetPosition().X() - fix.X()) * 0.5) + i, (_cam->GetPosition().Y() - fix.Y()) * 0.5), Size(1920, 791));
	//		}
	//
	//		//Draw ground
	//		for (int i = 0; i < width2; i += 1920) {
	//			//g->DrawBitmap("../tiles/ground.bmp", Vector2D(((_cam->GetPosition().X() - fix.X()) * 0.25) + i, (_cam->GetPosition().Y() + 2000) * 0.25), Size(1920, 321));
	//		}

	//		//Draw everything else
	//		_level->Paint(g);
	//	}
	//}
	//else if (_gameState == NULL) {
	//	_currentMenu->Paint(g);
	//}
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
