#include "Highscore.h"

namespace isgp {
	Highscore::Highscore(string name, double time)
	{
		_name = name;
		_time = time;
	}

	Highscore::Highscore() {

	}

	Highscore::~Highscore() {

	}

	double Highscore::GetTime() {
		return _time;
	}

	string Highscore::GetName() {
		return _name;
	}

	string Highscore::GetTimeFormatted() {
		return TimeFormatter::FormatTime(_time);
	}

	void Highscore::SetName(string name) {
		_name = name;
	}

	void Highscore::SetTime(double time) {
		_time = time;
	}
}