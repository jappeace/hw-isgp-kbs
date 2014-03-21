#pragma once

#include "IGameState.h"
#include "Level.h"
#include "Camera.h"
#include "Window.h"
#include "BackgroundArtist.h"
#include "ViewHighscoreGameState.h"

namespace isgp {
	class ViewHighscoreGameState;

	class PlayingGameState : public IGameState {
	public:
		PlayingGameState(Graphics* graphics, Window* window, int level, Theme*,
			void(Window::*gameOver)());
		~PlayingGameState();
		void Paint(Graphics* g) override;
		void Update(double elapsed) override;

		void KeyDown(int keyCode) override;
		void KeyUp(int keyCode) override;

		void Pause();
		void Resume();
	private:
		Level* _level;
		Graphics* _graphics;
		Camera* _camera;
		Window* _window;
		int _currentLevel;
		void(Window::*_gameOver)();
		BackgroundArtist* _artist;
		bool _isPaused;
		ViewHighscoreGameState* _highscoreState;
	};
}
