#include "GameOverGameState.h"
#include "GameOverMenu.h"
#include "MenuItem.h"

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
}
