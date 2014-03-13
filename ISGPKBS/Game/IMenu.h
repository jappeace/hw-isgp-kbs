#pragma once

#include "IPaintable.h"
#include <vector>

namespace isgp {
	// A generic abstract class for menu's.
	class IMenu : public IPaintable {
	protected:
		// Collection of the names of menu items.
		std::vector<string> _menuItemNames;

		// Index of the currently selected menu item.
		int _selectedMenuItem;
	};
}
