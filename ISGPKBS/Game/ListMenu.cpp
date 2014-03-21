#include "ListMenu.h"
#include "MenuItem.h"

namespace isgp {
	ListMenu::ListMenu() {
		this->_selectedMenuItem = 0;
		this->_font = CreateFont(48,0,0,0,FW_DONTCARE,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, VARIABLE_PITCH,TEXT("Lucida Console"));
	}

	ListMenu::~ListMenu() {
		// Delete all menu items.
		for (auto it = _menuItems.begin(); it != _menuItems.end(); ++it) {
			delete (*it);
		}
		DeleteObject(this->_font);
	}

	// Add menu item to the menu.
	// IMPORTANT: GameOverMenu takes ownership of the menuitem.
	void ListMenu::AddMenuItem(MenuItem* menuItem) {
		_menuItems.push_back(menuItem);
	}

	// Moves cursor up. Cursor goes to bottom if it can't go up.
	void ListMenu::MoveCursorUp() {
		if (_selectedMenuItem == 0) {
			_selectedMenuItem = _menuItems.size() - 1;
		}
		else {
			_selectedMenuItem = (_selectedMenuItem - 1) % _menuItems.size();
		}
	}

	// Moves cursor down. Cursor goes to top if it can't go down.
	void ListMenu::MoveCursorDown() {
		_selectedMenuItem = (_selectedMenuItem + 1) % _menuItems.size();
	}

	// Execute action related to the selected menu item.
	void ListMenu::ExecuteSelection() {
		MenuItem* item = _menuItems[_selectedMenuItem];
		item->Execute();
	}

	// Paints the menu on the screen.
	void ListMenu::Paint(Graphics* g) {
		g->SetTextBackgroundColor(RGB(0, 0, 0));
		g->FillRect(Vector2D(0, 0), Size(800, 600),RGB(0, 0, 0));

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
		this->PaintDecoration(g);
		g->SetTextBackgroundColor(RGB(255, 255, 255));
	}
}
