#include "Highscores.h"

namespace isgp {
Highscores::Highscores(int level)
{
	_level = level;
	for(unsigned i = 0; i < 5; i++) {
		_highscores.push_back(Highscore("None", DBL_MAX));
	}
	LoadHighscores();
}


Highscores::~Highscores(void)
{
}

Highscores::Highscores() {}

void Highscores::LoadHighscores() {

}

void Highscores::SaveHighscores() {

}

bool HighscoreSort(Highscore h1, Highscore h2) {
	return h1.GetTime() < h2.GetTime();
}

void Highscores::InsertHighscore(Highscore highscore) {
	if(!IsHighscore(highscore.GetTime())) {
		return;
	}

	_highscores.push_back(highscore);
	std::sort(_highscores.begin(), _highscores.end(), HighscoreSort);
	_highscores.resize(5);
}



bool Highscores::IsHighscore(double time) {
	if(_highscores.size() == 0)
		return true;
	Highscore last = _highscores.back();
	return last.GetTime() > time;
}

vector<Highscore> Highscores::GetHighscores() {
	return _highscores;
}



}