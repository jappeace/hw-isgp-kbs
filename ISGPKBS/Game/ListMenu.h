#pragma once

#include "IMenu.h"
#include <vector>

namespace isgp {
	class ListMenu : public IMenu {
	public:
		ListMenu();
		virtual ~ListMenu();
		void AddMenuItem(MenuItem* menuItem) override;
		void MoveCursorUp() override;
		void MoveCursorDown() override;
		void ExecuteSelection() override;
		// Paints the actual menu
		void Paint(Graphics* g) override;
	protected:
		// Paints the extra information around the menu
		virtual void PaintDecoration(Graphics* g) = 0;

		HFONT _font;
		std::vector<MenuItem*> _menuItems;
		int _selectedMenuItem;
	};
}
