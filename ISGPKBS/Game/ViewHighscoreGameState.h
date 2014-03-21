#pragma once
#include "IGameState.h"
#include "Window.h"
#include "PlayingGameState.h"
namespace isgp {
	class PlayingGameState;

	class ViewHighscoreGameState :
		public IGameState
	{
	public:
		ViewHighscoreGameState(int level, PlayingGameState* parentState);
		~ViewHighscoreGameState();
		void Paint(Graphics* g) override;
		void Update(double elapsed) override;

		void KeyDown(int keyCode) override;
		void KeyUp(int keyCode) override;
	private:
		int _level;
		Highscores* _highscore;
		PlayingGameState* _parentState;

		HFONT _highscoreTitleFont;
		HFONT _highscoreListFont;
	};

}