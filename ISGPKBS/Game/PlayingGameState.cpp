#include "PlayingGameState.h"
#include "GameOverGameState.h"
#include "DefaultlevelFactory.h"
#include "Camera.h"
#include <Windows.h>

namespace isgp {
	PlayingGameState::PlayingGameState(Window* window, Level* level, Camera* camera, void(Window::*gameOver)()) {
		_window = window;
		_gameOver = gameOver;
		DefaultlevelFactory factory;
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
		static double mountainWidth = (GridGraphicTranslator().FromTo(*_level->GetGrid()->GetSize()).X() * 0.5) + AbstractWindow::WindowSize.GetWidth();
		static double groundWidth = (GridGraphicTranslator().FromTo(*_level->GetGrid()->GetSize()).X() * 0.5) + AbstractWindow::WindowSize.GetWidth();
		static Vector2D fix = ((AbstractWindow::WindowSize - Player::InitSize) * Vector2D(1.0,1.35)) / Vector2D(2);
		for (int i = 0; i < mountainWidth; i += 1920) {
			g->DrawBitmap("../tiles/mountain.bmp",
				Vector2D(((_camera->GetPosition().X() - fix.X()) * 0.5) + i,
				(_camera->GetPosition().Y() - fix.Y()) * 0.5),
				Size(1920, 791));
		}

		//Draw ground
		for (int i = 0; i < groundWidth; i += 1920) {
			g->DrawBitmap("../tiles/ground.bmp",
				Vector2D(((_camera->GetPosition().X() - fix.X()) * 0.25) + i,
				(_camera->GetPosition().Y() + 2000) * 0.25),
				Size(1920, 321));
		}
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