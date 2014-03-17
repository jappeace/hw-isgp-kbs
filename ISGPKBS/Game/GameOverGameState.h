#pragma once

#include "IMenu.h"
#include "IGameState.h"
#include "Window.h"

namespace isgp {

	// Gamestate for when the player is dead.
	// Includes a menu that allows the player to restart the game.
	class GameOverGameState : public IGameState {
	public:
		GameOverGameState(Graphics* graphics, Window* window,
			void (Window::*restart)(), void (Window::*exit)());
		~GameOverGameState();
		void Paint(Graphics* g) override;
		void Update(double elapsed) override;
	private:
		IMenu* _menu;
	};
}
