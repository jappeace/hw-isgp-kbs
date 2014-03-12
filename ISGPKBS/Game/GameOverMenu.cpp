#include "GameOverMenu.h"

namespace isgp {
	GameOverMenu::GameOverMenu() {
		this->_hFont = CreateFont(50, 20, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			FF_DONTCARE, "Lucida Console");
	}

	GameOverMenu::~GameOverMenu() {
		DeleteObject(this->_hFont);
	}

	void GameOverMenu::Paint(Graphics* g) {
		g->DrawStr(Vector2D(200, 100), "Retry", this->_hFont);
	}
}
