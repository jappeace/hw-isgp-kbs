#include "GameOverGameState.h"
#include "GameOverMenu.h"
#include "MenuItem.h"
#include "Window.h"

namespace isgp {
	GameOverGameState::GameOverGameState(Graphics* graphics, Window* window,
		void (Window::*restart)(),
		void (Window::*exit)()) {
		_menu = new GameOverMenu();
		_menu->AddMenuItem(new MenuItem("Retry", window, restart));
		_menu->AddMenuItem(new MenuItem("Exit", window, exit));
	}

	GameOverGameState::~GameOverGameState() {
		delete _menu;
	}

	void GameOverGameState::Paint(Graphics* g) {
		_menu->Paint(g);
	}

	void GameOverGameState::Update(double elapsed) {
	}

	void GameOverGameState::KeyDown(int keyCode) {
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

	void GameOverGameState::KeyUp(int keyCode) {
		// Nothing to do here!
	}
}
