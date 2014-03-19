#pragma once

#include "IGameState.h"
#include "Level.h"
#include "Camera.h"
#include "Window.h"
#include "BackgroundArtist.h"

namespace isgp {
	class PlayingGameState : public IGameState {
	public:
		PlayingGameState(Window* window, Level* level, void(Window::*gameOver)());
		~PlayingGameState();
		void Paint(Graphics* g) override;
		void Update(double elapsed) override;

		void KeyDown(int keyCode) override;
		void KeyUp(int keyCode) override;
	private:
		Level* _level;
		Camera* _camera;
		Window* _window;
		int _currentLevel;
		void(Window::*_gameOver)();
		BackgroundArtist* _artist;
	};
}
