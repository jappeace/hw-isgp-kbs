#include "GameOverMenu.h"

namespace isgp {
	GameOverMenu::GameOverMenu() {
		this->_menuItemNames.push_back("Retry");
		this->_menuItemNames.push_back("Exit");
		this->_hFont = CreateFont(68, 35, 0, 0, FW_DONTCARE, FALSE, FALSE,
			FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
			NONANTIALIASED_QUALITY, FIXED_PITCH, TEXT("Verdana"));
	}

	GameOverMenu::~GameOverMenu() {
		DeleteObject(this->_hFont);
	}

	void GameOverMenu::Paint(Graphics* g) {
		//g->SetTextColor(RGB(255, 0, 0));
		Vector2D* menuLocation;
		for (auto it = _menuItemNames.begin(); it != _menuItemNames.end(); ++it) {
			menuLocation = new Vector2D(200, 100 *
				std::distance(_menuItemNames.begin(), it));
			g->DrawStr(*menuLocation, *it, this->_hFont);
			delete menuLocation;
		}
	}
}
