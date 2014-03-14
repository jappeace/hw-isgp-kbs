#pragma once

#include "IPaintable.h"

namespace isgp {
	class MenuItem;
	// Interface for simple menus with several menu items.
	// Provides methods for adding menu items and moving the cursor up/down.
	class IMenu : public IPaintable {
	public:
		virtual void AddMenuItem(MenuItem* menuItem) = 0;
		virtual void MoveCursorUp() = 0;
		virtual void MoveCursorDown() = 0;
		virtual void ExecuteSelection() = 0;
	};
}