#pragma once

#include "IGameState.h"
#include "Level.h"
#include "Camera.h"
#include "Window.h"

namespace isgp {
	class PlayingGameState : public IGameState {
	public:
		PlayingGameState(Graphics* graphics, Window* window,
			void(Window::*gameOver)());
		~PlayingGameState();
		void Paint(Graphics* g) override;
		void Update(double elapsed) override;

		void KeyDown(int keyCode) override;
		void KeyUp(int keyCode) override;
	private:
		Level* _level;
		Graphics* _graphics;
		Camera* _camera;
		Window* _window;
		void(Window::*_gameOver)();
	};
}
