#include "MainMenu.h"

namespace isgp {


	MainMenu::~MainMenu() {
	}

	void MainMenu::PaintDecoration(Graphics* g) {
		g->LoadBitmapFile("../tiles/mainmenu.bmp", false);
		g->DrawBitmap("../tiles/mainmenu.bmp", Vector2D(120, 60), Size(560, 83));
	}
}
