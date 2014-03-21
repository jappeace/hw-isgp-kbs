#pragma once
#include "IPaintable.h"
#include "Window.h"
#include "PlayingGameState.h"
namespace isgp {
	class PlayingGameState;

	class ViewHighscoreMenu :
		public IPaintable
	{
	public:
		ViewHighscoreMenu(int level, PlayingGameState* parentState);
		~ViewHighscoreMenu();
		void Paint(Graphics* g) override;

	private:
		int _level;
		Highscores* _highscore;
		PlayingGameState* _parentState;

		HFONT _highscoreTitleFont;
		HFONT _highscoreListFont;
	};

}