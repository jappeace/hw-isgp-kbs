#include "GameOverMenu.h"
#include "MenuItem.h"

namespace isgp {
	GameOverMenu::GameOverMenu() {
		this->_selectedMenuItem = 0;
		this->_font = CreateFont(48,0,0,0,FW_DONTCARE,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, VARIABLE_PITCH,TEXT("Lucida Console"));
		this->_brush = CreateSolidBrush(RGB(0, 0, 0));
	}

	GameOverMenu::~GameOverMenu() {
		// Delete all menu items.
		for (auto it = _menuItems.begin(); it != _menuItems.end(); ++it) {
			delete (*it);
		}
		DeleteObject(this->_font);
		DeleteObject(this->_brush);
	}

	// Add menu item to the menu.
	// IMPORTANT: GameOverMenu takes ownership of the menuitem.
	void GameOverMenu::AddMenuItem(MenuItem* menuItem) {
		_menuItems.push_back(menuItem);
	}

	// Moves cursor up. Cursor goes to bottom if it can't go up.
	void GameOverMenu::MoveCursorUp() {
		if (_selectedMenuItem == 0) {
			_selectedMenuItem = _menuItems.size() - 1;
		}
		else {
			_selectedMenuItem = (_selectedMenuItem - 1) % _menuItems.size();
		}
	}

	// Moves cursor down. Cursor goes to top if it can't go down.
	void GameOverMenu::MoveCursorDown() {
		_selectedMenuItem = (_selectedMenuItem + 1) % _menuItems.size();
	}

	// Execute action related to the selected menu item.
	void GameOverMenu::ExecuteSelection() {
		MenuItem* item = _menuItems[_selectedMenuItem];
		item->Execute();
	}

	// Paints the menu on the screen.
	void GameOverMenu::Paint(Graphics* g) {
		g->SetTextBackgroundColor(RGB(255, 255, 255));
		g->SetTextBackgroundColor(RGB(0, 0, 0));
		g->FillStaticRect(0, 0, 800, 600, this->_brush);

		Vector2D location(285, 200);
		for (auto item = _menuItems.begin(); item != _menuItems.end(); ++item) {
			if (std::distance(_menuItems.begin(), item) == this->_selectedMenuItem) {
				g->SetTextColor(RGB(255, 255, 255));
				g->DrawStr(location, ">" + (*item)->GetText(), _font);
			}
			else {
				g->SetTextColor(RGB(155, 155, 155));
				g->DrawStr(location, " " + (*item)->GetText(), _font);
			}
			location.Y(location.Y() + 50);
		}
		g->DrawBitmap("../tiles/gameover.bmp", Vector2D(180, 120), Size(778, 88));
	}
}