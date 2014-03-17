#pragma once

#include "IMenu.h"
#include "IGameState.h"
#include "Window.h"
#include <functional>

namespace isgp {

	// Gamestate for when the player is dead.
	// Includes a menu that allows the player to restart the game.
	class GameOverGameState : public IGameState {
	public:
		GameOverGameState(void (Window::*restart)(), void (Window::*exit)());
		~GameOverGameState();
	private:
		void Paint(Graphics* g) override;
		void Update(double elapsed) override;
		IMenu* _menu;
	};
}
