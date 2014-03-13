#pragma once

#include "IMenu.h"
#include <Windows.h>

namespace isgp {

	// Menu to be shown when the player dies.
	// Allows the player to choose to restart the game.
	class GameOverMenu : public IMenu {
	public:
		GameOverMenu();
		~GameOverMenu();
		void Paint(Graphics* g) override;
	private:
		HFONT _hFont;
	};
}
