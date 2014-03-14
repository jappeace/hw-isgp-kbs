#include "GameOverMenu.h"
#include "MenuItem.h"

namespace isgp {
	GameOverMenu::GameOverMenu() {
		this->_selectedMenuItem = 0;
		this->_font = CreateFont(48,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Arial"));
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
		g->FillStaticRect(100, 100, 300, 300, this->_brush);
		g->SetTextColor(RGB(255, 0, 0));
		g->DrawStr(Vector2D(200, 100), "You are dead!", _font);

		Vector2D location(300, 200);
		for (auto item = _menuItems.begin(); item != _menuItems.end(); ++item) {
			if (std::distance(_menuItems.begin(), item) == this->_selectedMenuItem) {
				g->SetTextColor(RGB(0, 200, 150));
			}
			else {
				g->SetTextColor(RGB(0, 0, 0));
			}
			g->DrawStr(location, (*item)->GetText(), _font);
			location.Y(location.Y() + 50);
		}
	}
}