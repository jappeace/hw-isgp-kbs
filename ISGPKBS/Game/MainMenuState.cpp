#include "MainMenuState.h"
#include "GameOverMenu.h"
#include "MenuItem.h"
#include "Window.h"

namespace isgp {
	MainMenuState::MainMenuState(Graphics* graphics, Window* window,
		void (Window::*restart)(),
		void (Window::*continueGame)(),
		void (Window::*exit)()) {
		_menu = new GameOverMenu();
		_menu->AddMenuItem(new MenuItem("Retry", window, restart));
		_menu->AddMenuItem(new MenuItem("Exit", window, exit));
	}

	MainMenuState::~MainMenuState() {
		delete _menu;
	}

	void MainMenuState::Paint(Graphics* g) {
		_menu->Paint(g);
	}

	void MainMenuState::Update(double elapsed) {
	}

	void MainMenuState::KeyDown(int keyCode) {
		switch (keyCode) {
		case VK_UP:
			_menu->MoveCursorUp();
			break;
		case VK_DOWN:
			_menu->MoveCursorDown();
			break;
		case VK_RETURN:
			_menu->ExecuteSelection();
			break;
		}
	}

	void MainMenuState::KeyUp(int keyCode) {
		// Nothing to do here!
	}
}
