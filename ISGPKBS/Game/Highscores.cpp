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

bool Highscores::FileExists() {
	ifstream f("./highscores/" + StrConverter::IntToString(_level) + ".highscore");
	if (f.good()) {
		f.close();
		return true;
	} else {
		f.close();
		return false;
	}  
}

void Highscores::LoadHighscores() {
	if(!FileExists())
		return;
	_highscores.clear();
	std::ifstream input("./highscores/" + StrConverter::IntToString(_level) + ".highscore");
	for(unsigned i = 0; i < 5; i++) {
		string name;
		double time;
		input >> name >> time;
		Highscore h(name, time);
		this->InsertHighscore(h);
	}
}

void Highscores::SaveHighscores() {
	std::fstream f;
	f.open(("./highscores/" + StrConverter::IntToString(_level) + ".highscore"), ios_base::in|ios_base::out|ios_base::trunc );
	f.seekg(0, std::ios::end);
	f.seekg(0, std::ios::beg);
	for(unsigned i = 0; i < _highscores.size(); i++) {
		Highscore hs = _highscores.at(i);
		f << hs.GetName() << "\n" << hs.GetTime() << "\n";
	}
	f.flush();
	f.close();
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