#pragma once

#include <string>
#include "Window.h"

namespace isgp {
	class MenuItem {
	public:
		MenuItem(std::string text, Window* window, void (Window::*action)());
		~MenuItem();
		void Execute();
		std::string GetText();
	private:
		std::string _text;
		Window* _window;
		void (Window::*_action)();
	};
}
