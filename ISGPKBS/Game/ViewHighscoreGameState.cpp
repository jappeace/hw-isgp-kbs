#include "ViewHighscoreGameState.h"
#include <vector>
namespace isgp {
	ViewHighscoreGameState::ViewHighscoreGameState(int level, PlayingGameState* parentState) {
		_level = level;
		_highscore = new Highscores(level);
		_highscore->LoadHighscores();


		_highscoreTitleFont = CreateFont(48,0,0,0,FW_DONTCARE,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, VARIABLE_PITCH,TEXT("Lucida Console"));
		_highscoreListFont = CreateFont(32,0,0,0,FW_DONTCARE,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, VARIABLE_PITCH,TEXT("Lucida Console"));
	}

	ViewHighscoreGameState::~ViewHighscoreGameState() {
		delete _highscore;
		DeleteObject(_highscoreTitleFont);
		DeleteObject(_highscoreListFont);
	}

	void ViewHighscoreGameState::Paint(Graphics* g) {
		g->SetTextBackgroundColor(RGB(0, 0, 0));
		g->FillStaticRect(Vector2D(0, 0), Size(800, 600),RGB(0, 0, 0));
		g->SetTextColor(RGB(255, 255, 255));
		g->DrawStr(Vector2D(240, 100), "Highscores", _highscoreTitleFont);

		vector<Highscore*>* allScores =  _highscore->GetHighscores();
		unsigned highscoreCount = allScores->size() > 5 ? 5 : allScores->size();
		for(unsigned i = 0; i < highscoreCount; i++) {
			Highscore* score = allScores->at(i);
			
			g->DrawStr(Vector2D(50, 180 + (i * 32)), score->GetName(), _highscoreListFont);
			g->DrawStr(Vector2D(500, 180 + (i * 32)), score->GetTimeFormatted(), _highscoreListFont);
		}
		g->SetTextBackgroundColor(RGB(255, 255, 255));
	}

	void ViewHighscoreGameState::Update(double elapsed) {
	}

	void ViewHighscoreGameState::KeyDown(int keyCode) {
	}

	void ViewHighscoreGameState::KeyUp(int keyCode) {
		// Nothing to do here!
	}
}