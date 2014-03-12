#pragma once

#include "IPaintable.h"

namespace isgp {

	// Menu to be shown when the player dies.
	// Allows the player to choose to restart the game.
	class GameOverMenu : public IPaintable {
		public:
			void Paint(Graphics* g) override;
	};
}
