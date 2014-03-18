#include "GameCompletedGameState.h"

namespace isgp {
	void GameCompletedGameState::Update(double elapsed) {

	}

	void GameCompletedGameState::Paint(Graphics* g) {
		g->_cam = NULL;
		g->FillStaticRect(0, 0, 800, 600, this->_brush);
		g->DrawBitmap("../tiles/yourock.bmp", Vector2D(95, 122), Size(609, 356));
	}

	void GameCompletedGameState::KeyDown(int keyCode) {

	}
	void GameCompletedGameState::KeyUp(int keyCode) {
		if(keyCode == VK_RETURN || keyCode == VK_SPACE) {
			_window->FullRestart();
		}
	}

	GameCompletedGameState::GameCompletedGameState(Window* window)
	{
		_window = window;
		this->_brush = CreateSolidBrush(RGB(0, 0, 0));
	}


	GameCompletedGameState::~GameCompletedGameState(void)
	{
		DeleteObject(this->_brush);
	}
}