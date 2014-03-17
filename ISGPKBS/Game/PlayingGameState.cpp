#include "PlayingGameState.h"
#include "GameOverGameState.h"
#include "DefaultlevelFactory.h"
#include "Camera.h"
#include <Windows.h>

namespace isgp {
	PlayingGameState::PlayingGameState(Graphics* graphics, Window* window,
		void(Window::*gameOver)()) {
		_window = window;
		_gameOver = gameOver;
		_graphics = graphics;
		_graphics->SetTextBackgroundColor(RGB(255, 255, 255));
		DefaultlevelFactory factory;
		for (int i = 0; i < 100; i++) {
		_level = factory.CreateLevel();
		delete _level;
		}
		_level = factory.CreateLevel();
		_camera = new Camera(_level->_player, _level->GetGrid());
		_graphics->SetCam(_camera);
	}

	PlayingGameState::~PlayingGameState() {
		delete _camera;
		delete _level;
	}

	void PlayingGameState::Paint(Graphics* g) {
		_level->Paint(g);
	}

	void PlayingGameState::Update(double elapsed) {
		_level->Update(elapsed);
		_camera->Update(elapsed);
		if (!_level->_player->IsAlive()) {
			(_window->*_gameOver)();
		}
	}

	void PlayingGameState::KeyDown(int keyCode) {
		switch (keyCode) {
		case VK_LEFT:
			_level->_player->_leftKey = true;
			break;
		case VK_UP:
			_level->_player->_upKey = true;
			break;
		case VK_RIGHT:
			_level->_player->_rightKey = true;
			break;
		case VK_SPACE:
			_level->_player->_spaceKey = true;
			break;
		}
	}

	void PlayingGameState::KeyUp(int keyCode) {
		switch (keyCode) {
		case VK_LEFT:
			_level->_player->_leftKey = false;
			break;
		case VK_UP:
			_level->_player->_upKey = false;
			break;
		case VK_RIGHT:
			_level->_player->_rightKey = false;
			break;
		case VK_SPACE:
			_level->_player->_spaceKey = false;
			break;
		}
	}
}