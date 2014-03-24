#include "GameCompletedGameState.h"

namespace isgp {
	void GameCompletedGameState::Update(double elapsed) {

	}

	void GameCompletedGameState::Paint(Graphics* g) {
		g->SetTranslator(NULL);
		g->FillRect(Vector2D(), Size(800, 600), RGB(0, 0, 0));
		g->DrawBitmap("tiles/yourock.bmp", Vector2D(95, 122), Size(609, 356));
	}

	void GameCompletedGameState::KeyDown(int keyCode) {
		if(keyCode == VK_RETURN || keyCode == VK_SPACE) {
			_window->OpenMainMenu();
		}
	}
	void GameCompletedGameState::KeyUp(int keyCode) {

	}

	GameCompletedGameState::GameCompletedGameState(Window* window)
	{
		_window = window;
	}


	GameCompletedGameState::~GameCompletedGameState(void)
	{
	}
}