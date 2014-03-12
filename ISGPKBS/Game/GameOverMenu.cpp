#include "GameOverMenu.h"

namespace isgp {
	GameOverMenu::GameOverMenu() {
		this->_hFont = CreateFont(36,20,-300,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Times New Roman"));
	}

	GameOverMenu::~GameOverMenu() {
		DeleteObject(this->_hFont);
	}

	void GameOverMenu::Paint(Graphics* g) {
		g->DrawStr(Vector2D(200, 100), "Retry", this->_hFont);
	}
}
