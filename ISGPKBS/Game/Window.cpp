#include "Window.h"
#include "GameOverMenu.h"
#include "DefaultlevelFactory.h"
#include "MenuItem.h"
#include "PlayingGameState.h"
#include "GameOverGameState.h"

namespace isgp {

// Constructors / Destructors      //
Window::Window() {
	_currentLevel = 1;
	_cam = NULL;
	_currentMenu = NULL;
	_gameState = NULL;
	_levelTileSnapshots = new SpriteCache<int>();
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
	
	_graphics->LoadBitmapFile("../tiles/mountain.bmp");
	_graphics->LoadBitmapFile("../tiles/ground.bmp");

	_graphics->LoadBitmapFile("../tiles/megaman.bmp");
	_graphics->LoadBitmapFile("../tiles/boo.bmp");
	_graphics->LoadBitmapFile("../tiles/link.bmp");
	_graphics->LoadBitmapFile("../tiles/gravityBoots.bmp");
	_graphics->LoadBitmapFile("../tiles/smile.bmp");

	LoadLevel();
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
	ClearGameState();
	LoadLevel();
}
void Window::ClearGameState(){

	if(_gameState){
		delete _gameState;
	}
	_gameState = NULL;
}

void Window::GameOver() {
	ClearGameState();
	_graphics->SetTranslator(NULL);
	_gameState = new GameOverGameState(_graphics, this,
		&Window::RestartGame, &Window::QuitGame);
}

void Window::QuitGame() {
	// deleting stuff is irrelevant, kernel will handle it
	PostQuitMessage(0);
}

void Window::LoadLevel(){
	ClearGameState();
	_gameState = new LoadLevelGameState(this, _currentLevel,_levelTileSnapshots, &Window::StartLevel);
}
void Window::StartLevel(Level* which, Camera* cam){
	ClearGameState();
	_gameState = new PlayingGameState(this, which, cam, &Window::GameOver);
}
SpriteCache<int>* Window::GetLevelTileSnapshots(){
	return _levelTileSnapshots;
}
}
