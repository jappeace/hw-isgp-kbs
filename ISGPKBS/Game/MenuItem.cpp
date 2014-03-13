#include "MenuItem.h"

namespace isgp {
	// Constructor that takes the menu items text, window reference and window's action.
	// action and window can be NULL.
	MenuItem::MenuItem(std::string text, Window* window, void (Window::*action)()) {
		this->_text = text;
		this->_window = window;
		this->_action = action;
	}

	// Nothing to destruct.
	MenuItem::~MenuItem() {
	}

	// Executes action. Does nothing if _window or _action == NULL.
	void MenuItem::Execute() {
		if (_window && this->_action) {
			(_window->*_action)();
		}
	}

	// Gets the menuitem's text.
	std::string MenuItem::GetText() {
		return this->_text;
	}
}