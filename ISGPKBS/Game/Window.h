#pragma once

#include <cstdlib>
#include "AbstractWindow.h"
#include "resource2.h"
#include "ILevelFactory.h"
#include "WorldBlock.h"
#include "Camera.h"
#include "IMenu.h"
#include "GameState.h"

namespace isgp {
	class Window : public AbstractWindow {
	public:
		Window();
		~Window();
		void OnPaint(Graphics* graphics);
		void OnCommand(int from, int command);
		LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
		void OnKeyDown(int which) override;
		void OnKeyUp(int which) override;
		void GameLoop(double) override;
		void AfterCreate(HWND) override;
		Camera* _cam;
	private:
		Level* _level;
		void ClientResize(HWND hWnd, int nWidth, int nHeight);
		IMenu* _currentMenu;
		GameState _gameState;
		void RestartGame();
		void QuitGame();
	};
}
