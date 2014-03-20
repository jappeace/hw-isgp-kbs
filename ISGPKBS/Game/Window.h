#pragma once

#include <cstdlib>
#include "AbstractWindow.h"
#include "resource2.h"
#include "ILevelFactory.h"
#include "WorldBlock.h"
#include "Camera.h"
#include "IMenu.h"
#include "IGameState.h"
#include "DefaultLevelFactory.h"
#include "GameCompletedGameState.h"
#include "Highscores.h"

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
		void NextLevel(double playtime);
		void FullRestart();
		Camera* _cam;
	private:
		Level* _level;
		int _currentLevel;
		void ClientResize(HWND hWnd, int nWidth, int nHeight);
		IMenu* _currentMenu;
		IGameState* _gameState;
		void RestartGame();
		void QuitGame();
		void GameOver();
		Theme* _theme;
		Highscores _highscores;
	};
}
