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
#include "LoadLevelGameState.h"
#include "InsertNameState.h"

namespace isgp {
	class InsertNameState;

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
		void SaveScore(Highscore* h);
		void StartNextLevel();
		void OpenMainMenu();
		Camera* _cam;
		SpriteCache<int>* GetLevelTileSnapshots();
		void SetPlayerLives(int lives);
		int GetPlayerLives();
	private:
		int _currentLevel;
		// The amount of lives the player has left
		int _lives;
		void ClientResize(HWND hWnd, int nWidth, int nHeight);
		IGameState* _gameState;
		SpriteCache<int>* _levelTileSnapshots;
		void RestartGame();
		void QuitGame();
		void GameOver();
		void FinalGameOver();
		void LoadLevel();
		Highscores _highscores;
		void StartLevel(Level*, Camera*);
		void ClearGameState();
	};
}
