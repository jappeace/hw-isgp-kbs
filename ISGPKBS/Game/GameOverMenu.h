#pragma once

#include "IMenu.h"
#include <vector>

namespace isgp {
	class GameOverMenu : public IMenu {
	public:
		GameOverMenu();
		~GameOverMenu();
		void AddMenuItem(MenuItem* menuItem) override;
		void MoveCursorUp() override;
		void MoveCursorDown() override;
		void ExecuteSelection() override;
		void Paint(Graphics* g) override;
	private:
		HFONT _font;
		std::vector<MenuItem*> _menuItems;
		int _selectedMenuItem;
	};
}
