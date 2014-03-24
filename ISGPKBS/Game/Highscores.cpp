#include "Highscores.h"

namespace isgp {
Highscores::Highscores(int level)
{
	_level = level;
	Init();

}


Highscores::~Highscores(void)
{
	for(unsigned i = 0; i < _highscores->size(); i++)
		delete _highscores->at(i);
	delete _highscores;
}

Highscores::Highscores() {
	Init();
}

void Highscores::Init() {
	_highscores = new vector<Highscore*>();
}

bool Highscores::FileExists() {
	ifstream f("highscores/" + StrConverter::IntToString(_level) + ".highscore");
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
	if(_highscores->size() > 0)
		_highscores->clear();
	std::ifstream input("highscores/" + StrConverter::IntToString(_level) + ".highscore");

	while (true) {
		string name;
		int time;
		input >> name;
		input >> time;
		this->InsertHighscore(new Highscore(name, time/1000));
		if( input.eof() ) break;
		
	}
}

void Highscores::SaveHighscores() {
	std::ofstream f;
	f.open(("highscores/" + StrConverter::IntToString(_level) + ".highscore"));
	//f.seekg(0, std::ios::end);
	//f.seekg(0, std::ios::beg);
	for(unsigned i = 0; i < _highscores->size(); i++) {
		Highscore* hs = _highscores->at(i);
		f << hs->GetName() << "\n" << (int)(hs->GetTime() * 1000);
		if(i != _highscores->size() - 1) {
			f << "\n";
		}
	}
	f.flush();
	f.close();
}

bool HighscoreSort(Highscore* h1, Highscore* h2) {
	return h1->GetTime() < h2->GetTime();
}

void Highscores::Sort() {
	vector<Highscore*>* hs = _highscores;
	std::sort(_highscores->begin(), _highscores->end(), HighscoreSort);
	hs = _highscores;
}

void Highscores::InsertHighscore(Highscore* highscore) {
	double time = highscore->GetTime();
	if(!this->IsHighscore(time)) {
		return;
	}

	_highscores->push_back(highscore);
	Sort();
	if(_highscores->size() > 5) {
		_highscores->resize(5);
	}
}



bool Highscores::IsHighscore(double time) {
	if(_highscores->size() < 5)
		return true;
	Highscore* last = _highscores->back();
	return last->GetTime() > time;
}

vector<Highscore*>* Highscores::GetHighscores() {
	return _highscores;
}
}