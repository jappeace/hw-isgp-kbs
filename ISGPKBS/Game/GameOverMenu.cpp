#include "GameOverMenu.h"

namespace isgp {
	GameOverMenu::GameOverMenu() {
		this->_hFont = CreateFont(68,35,0,0,FW_DONTCARE,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS,NONANTIALIASED_QUALITY, FIXED_PITCH,TEXT("Verdana"));
	}

	GameOverMenu::~GameOverMenu() {
		DeleteObject(this->_hFont);
	}

	void GameOverMenu::Paint(Graphics* g) {
		g->DrawStr(Vector2D(200, 100), "Retry", this->_hFont);
	}
}
