#include "PlayingGameState.h"
#include "GameOverGameState.h"
#include "DefaultlevelFactory.h"
#include "Camera.h"
#include "Theme.h"
#include <Windows.h>

namespace isgp {
	PlayingGameState::PlayingGameState(Window* window, Level* level, Camera* camera, void(Window::*gameOver)()) {
		_window = window;
		_gameOver = gameOver;
		_level = level;
		_window = window;
		_gameOver = gameOver;
		_level = level;
		_camera = camera;
		_artist = new BackgroundArtist(_camera, _level, window->GetLevelTileSnapshots());
		_artist->RenderBackground();
	}

	PlayingGameState::~PlayingGameState() {
		delete _camera;
		delete _level;
		delete _artist;
	}

	void PlayingGameState::Paint(Graphics* g) {
		_level->_theme->Paint(g);
		_artist->Paint(g);
		_level->Paint(g);
	}

	void PlayingGameState::Update(double elapsed) {
		_level->Update(elapsed);
		_camera->Update(elapsed);
		if (!_level->_player->IsAlive()) {
			(_window->*_gameOver)();
		} else if (_level->IsFinished()) {
			_window->NextLevel();
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
