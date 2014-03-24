#include "GameOverMenu.h"
#include "MenuItem.h"

namespace isgp {

	GameOverMenu::~GameOverMenu() {
	}

	// Paints the menu on the screen.
	void GameOverMenu::PaintDecoration(Graphics* g) {
		g->LoadBitmapFile("tiles/gameover.bmp", false);
		g->DrawBitmap("tiles/gameover.bmp", Vector2D(180, 120), Size(778, 88));
	}
}