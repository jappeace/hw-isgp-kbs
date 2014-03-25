#pragma once

#include "IGameState.h"
#include "Level.h"
#include "Camera.h"
#include "Window.h"
#include "BackgroundArtist.h"
#include "ViewHighscoreMenu.h"

namespace isgp {
	class ViewHighscoreMenu;

	class PlayingGameState : public IGameState {
	public:
		PlayingGameState(Window* window, Level* level, Camera*, void(Window::*gameOver)(), void(Window::*finalGameOver)(), int levelNumberz, int playerLives);
		~PlayingGameState();
		void Paint(Graphics* g) override;
		void Update(double elapsed) override;

		void KeyDown(int keyCode) override;
		void KeyUp(int keyCode) override;

		static bool _debugMode;
		void Pause();
		void Resume();

	private:
		Level* _level;
		Camera* _camera;
		Window* _window;
		int _currentLevel;
		int _playerLives;
		void(Window::*_gameOver)();
		void(Window::*_finalGameOver)();
		BackgroundArtist* _artist;
		bool _isPaused;
		ViewHighscoreMenu* _highscoreMenu;
	};
}
