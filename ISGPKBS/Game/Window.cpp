#include "DefaultlevelFactory.h"
#include "GameOverGameState.h"
#include "GameOverMenu.h"
#include "MenuItem.h"
#include "MainMenuState.h"
#include "PlayingGameState.h"

#include "SaveGame.h"
#include "Sound.h"
#include "Theme1.h"
#include "Theme2.h"
#include "Theme3.h"
#include "Theme4.h"
#include "Theme5.h"
#include "Window.h"
namespace isgp {

// Constructors / Destructors      //
Window::Window() {
	_currentLevel = 1;
	_cam = NULL;
	_gameState = NULL;
	_levelTileSnapshots = new SpriteCache<int>();
}

Window::~Window()
{
	delete _gameState;
	delete _cam;
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
	_currentLevel = SaveGame().ReadCurrentLevel();
	_gameState = new MainMenuState(this, &Window::FullRestart, &Window::LoadLevel, &Window::QuitGame);
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

void Window::NextLevel(double playtime) {
	Sound().Play(END_WIN);

	Highscores _highscores = Highscores(_currentLevel);
	_highscores.LoadHighscores();

	if(_highscores.IsHighscore(playtime)) {
		_gameState = new InsertNameState(this, playtime);
	} else {
		StartNextLevel();
	}
	



}

void Window::StartNextLevel() {
	_currentLevel++;
	if(DefaultlevelFactory().LevelExists(_currentLevel)) {
		SaveGame().WriteCurrentLevel(_currentLevel);
		RestartGame();
	} else { //Completed all levels, wat do?
		delete _gameState;
		_gameState = new GameCompletedGameState(this);
	}
}

void Window::SaveScore(Highscore* h) {
	Highscores _highscores = Highscores(_currentLevel);
	_highscores.LoadHighscores();
	_highscores.InsertHighscore(h);
	_highscores.SaveHighscores();
	StartNextLevel();
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
