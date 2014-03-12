#pragma once

#include "IPaintable.h"
#include <Windows.h>

namespace isgp {

	// Menu to be shown when the player dies.
	// Allows the player to choose to restart the game.
	class GameOverMenu : public IPaintable {
	public:
		GameOverMenu();
		~GameOverMenu();
		void Paint(Graphics* g) override;
	private:
		HFONT _hFont;
	};
}
