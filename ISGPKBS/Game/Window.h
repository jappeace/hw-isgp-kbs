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
#include "LoadLevelGameState.h"
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
		void NextLevel();
		void FullRestart();
		Camera* _cam;
		SpriteCache<int>* GetLevelTileSnapshots();
	private:
		int _currentLevel;
		void ClientResize(HWND hWnd, int nWidth, int nHeight);
		IGameState* _gameState;
		SpriteCache<int>* _levelTileSnapshots;
		void RestartGame();
		void QuitGame();
		void GameOver();
		void LoadLevel();
		void StartLevel(Level*, Camera*);
		void ClearGameState();
		Theme* _theme;
	};
}
