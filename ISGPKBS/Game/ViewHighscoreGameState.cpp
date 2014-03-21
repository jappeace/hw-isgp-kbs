#include "ViewHighscoreGameState.h"
#include <vector>
namespace isgp {
	ViewHighscoreGameState::ViewHighscoreGameState(int level, PlayingGameState* parentState) {
		_level = level;
		_highscore = new Highscores(level);
		_highscore->LoadHighscores();
	}

	ViewHighscoreGameState::~ViewHighscoreGameState() {
		delete _highscore;
	}

	void ViewHighscoreGameState::Paint(Graphics* g) {
		vector<Highscore*>* allScores =  _highscore->GetHighscores();
		unsigned highscoreCount = allScores->size() > 5 ? 5 : allScores->size();
		for(unsigned i = 0; i < highscoreCount; i++) {
			Highscore* score = allScores->at(i);
			
			g->DrawStr(Vector2D(20, 40 + (i * 20)), score->GetName());
			g->DrawStr(Vector2D(200, 40 + (i * 20)), score->GetTimeFormatted());
		}
	}

	void ViewHighscoreGameState::Update(double elapsed) {
	}

	void ViewHighscoreGameState::KeyDown(int keyCode) {
		if(keyCode == VK_RETURN || keyCode == VK_SPACE) {

		}
	}

	void ViewHighscoreGameState::KeyUp(int keyCode) {
		// Nothing to do here!
	}
}