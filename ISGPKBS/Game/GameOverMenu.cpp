#include "GameOverMenu.h"
#include "MenuItem.h"

namespace isgp {
	GameOverMenu::GameOverMenu() {
		this->_selectedMenuItem = 0;
	}

	GameOverMenu::~GameOverMenu() {
		// Delete all menu items.
		for (auto it = _menuItems.begin(); it != _menuItems.end(); ++it) {
			delete (*it);
		}
	}

	// Add menu item to the menu.
	// IMPORTANT: GameOverMenu takes ownership of the menuitem.
	void GameOverMenu::AddMenuItem(MenuItem* menuItem) {
		_menuItems.push_back(menuItem);
	}

	// Moves cursor up. Cursor goes to bottom if it can't go up.
	void GameOverMenu::MoveCursorUp() {
		_selectedMenuItem = (_selectedMenuItem - 1) % _menuItems.size();
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
		Vector2D location(300, 100);
		for (auto item = _menuItems.begin(); item != _menuItems.end(); ++item) {
			g->DrawStr(location, (*item)->GetText());
			location.Y(location.Y() + 20);
		}
	}
}