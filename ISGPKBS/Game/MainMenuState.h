#pragma once
#include "IGameState.h"
#include "Window.h"

namespace isgp {

	class MainMenuState :
		public IGameState
	{
	public:
		MainMenuState(Window* window,
			void (Window::*start)(), void (Window::*continueFunc)(), void (Window::*exit)());
		~MainMenuState();
		void Paint(Graphics* g) override;
		void Update(double elapsed) override;

		void KeyDown(int keyCode) override;
		void KeyUp(int keyCode) override;
	private:
		IMenu* _menu;
	};

}