#include "Window.h"
#include "SimpleLevelFactory.h"
#include "GameOverMenu.h"
#include "DefaultlevelFactory.h"
#include "MenuItem.h"

namespace isgp {

// Constructors / Destructors      //
Window::Window() {
	DefaultlevelFactory factory;
	_level = factory.CreateLevel();
	_gameState = Playing;
	_cam = NULL;
	_currentMenu = NULL;
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
	if (_gameState == Playing) {
		if (_cam != NULL) {
			int imgWidth = 1920;
			int imgHeight1 = 791;
			int imgHeight2 = 321;
			
			double width1 = (GridGraphicTranslator().FromTo(*_level->GetGrid()->GetSize()).X() * 0.5) + AbstractWindow::WindowSize.GetWidth();
			double width2 = (GridGraphicTranslator().FromTo(*_level->GetGrid()->GetSize()).X() * 0.75) + AbstractWindow::WindowSize.GetWidth();

			Vector2D fix = ((AbstractWindow::WindowSize - Player::InitSize) * Vector2D(1.0,1.35)) / Vector2D(2);

			//Draw sky
			for (int i = 0; i < width1; i += imgWidth) {
				g->DrawBitmap("../tiles/mountain.bmp", Vector2D(((_cam->GetPosition().X() - fix.X()) * 0.5) + i, (_cam->GetPosition().Y() - fix.Y()) * 0.5), Size(imgWidth, imgHeight1));
			}
	
			//Draw ground
			for (int i = 0; i < width2; i += imgWidth) {
				g->DrawBitmap("../tiles/ground.bmp", Vector2D(((_cam->GetPosition().X() - fix.X()) * 0.25) + i, (_cam->GetPosition().Y() + 2000) * 0.25), Size(imgWidth, imgHeight2));
			}

			//Draw everything else
			_level->Paint(g);
		}
	}
	else if (_gameState == GameOver) {
		_currentMenu->Paint(g);
	}
}
void Window::GameLoop(double elapsed) { //elapsed time, in MS
	if (_gameState == Playing && !_level->_player->IsAlive()) {
		_gameState = GameOver;
		delete _currentMenu;
		_currentMenu = new GameOverMenu();
		_currentMenu->AddMenuItem(new MenuItem("Retry", this, &Window::RestartGame));
		_currentMenu->AddMenuItem(new MenuItem("Exit", NULL, NULL));
	}
	if (_gameState == Playing) {
		//update all the game objects now
		_level->_player->Update(elapsed);
		
		//Æ÷¹®
		for(unsigned int i=0 ; i< _level->enemies.size(); i++)
		{
			_level->enemies[i]->Update(elapsed);
		}
		_cam->Update(elapsed);
	}
	AbstractWindow::GameLoop(elapsed);
}

void Window::OnKeyDown(int which) {
	switch (which) {
	case VK_LEFT:
		_level->_player->_leftKey = true;
		break;
	case VK_RIGHT:
		_level->_player->_rightKey = true;
		break;
	case VK_UP:
		if (_currentMenu) {
			_currentMenu->MoveCursorUp();
		}
		_level->_player->_upKey = true;
		break;
	case VK_DOWN:
		if (_currentMenu) {
			_currentMenu->MoveCursorDown();
		}
		break;
	case VK_SPACE:
		_level->_player->_spaceKey = true;
		break;
	case VK_RETURN:
		if (_currentMenu) {
			_currentMenu->ExecuteSelection();
		}
		break;
	case VK_BACK:
		_level->_player->Kill();
		break;
	}
}

void Window::OnKeyUp(int which) {
	switch (which) {
	case VK_LEFT:
		_level->_player->_leftKey = false;
		break;
	case VK_RIGHT:
		_level->_player->_rightKey = false;
		break;
	case VK_UP:
	
		_level->_player->_upKey = false;
		break;
	case VK_SPACE:
		_level->_player->_spaceKey = false;
		break;
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
	DefaultlevelFactory factory;
	_level = factory.CreateLevel();
	_gameState = Playing;
	AfterCreate(_hWnd);
	delete _currentMenu;
	_currentMenu = NULL;
}

}
