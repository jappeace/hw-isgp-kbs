#include "PlayingGameState.h"
#include "GameOverGameState.h"
#include "DefaultlevelFactory.h"
#include "Camera.h"
#include "Theme.h"
#include <Windows.h>

namespace isgp {
	bool PlayingGameState::_debugMode=false;
	PlayingGameState::PlayingGameState(Window* window, Level* level, Camera* camera,
		void(Window::*gameOver)(), void(Window::*finalGameOver)(), int levelNumber, int playerLives) {

		_window = window;
		_gameOver = gameOver;
		_level = level;
		_playerLives = playerLives;
		_window = window;
		_gameOver = gameOver;
		_finalGameOver = finalGameOver;
		_level = level;
		_camera = camera;
		_artist = new BackgroundArtist(_camera, _level, window->GetLevelTileSnapshots());
		_artist->RenderBackground();
		_highscoreMenu = new ViewHighscoreMenu(levelNumber, this);
		_isPaused = false;
	}

	PlayingGameState::~PlayingGameState() {
		delete _camera;
		delete _level;
		delete _highscoreMenu;
		delete _artist;
	}

	void PlayingGameState::Paint(Graphics* g) {
		if(_isPaused) {
			_highscoreMenu->Paint(g);
		} else {
			_level->_theme->Paint(g);
			_artist->Paint(g);
			_level->Paint(g);

			// Paint Lives
			for (int i = 0; i < _playerLives; ++i) {
				g->DrawStaticBitmap("./tiles/live.bmp", Vector2D(8 + (i * 24), 32), Size(16, 16));
			}
		}
	}

	void PlayingGameState::Pause() {
		_isPaused = true;
	}

	void PlayingGameState::Resume() {
		_isPaused = false;
	}

	void PlayingGameState::Update(double elapsed) {
		if(!_isPaused) {
			_level->Update(elapsed);
			_camera->Update(elapsed);
			if (!_level->_player->IsAlive()) {
				_window->SetPlayerLives(_window->GetPlayerLives() - 1);

				if (_window->GetPlayerLives() > 0) {
					(_window->*_gameOver)();
				} else {
					(_window->*_finalGameOver)();
				}
			} else if (_level->IsFinished()) {
				_window->NextLevel(_level->GetPlayTime());
			}
		}
	}

	void PlayingGameState::KeyDown(int keyCode) {
		if(_isPaused) {
			if(keyCode == VK_TAB) {
				Resume();
			}
		} else {
			switch (keyCode) {
			case VK_TAB:
				Pause();
				break;
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
			case VK_F1:
				if(PlayingGameState::_debugMode)
					PlayingGameState::_debugMode=false;
				else
					PlayingGameState::_debugMode=true;
			}
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
