#include "DeathMenu.h"
#include "MenuItem.h"

namespace isgp {

	DeathMenu::~DeathMenu() {
	}

	// Paints the menu on the screen.
	void DeathMenu::PaintDecoration(Graphics* g) {
		g->LoadBitmapFile("tiles/deathmenu.bmp", false);
		g->DrawBitmap("tiles/deathmenu.bmp", Vector2D(225, 30), Size(350, 158));
	}
}