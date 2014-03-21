#pragma once
#include <string>
#include "TimeFormatter.h"
using namespace std;

namespace isgp {
class Highscore
{
public:
	Highscore(string, double);
	Highscore();
	~Highscore();
	void SetName(string);
	void SetTime(double);
	string GetTimeFormatted();
	double GetTime();
	string GetName();
private:
	double _time;
	string _name;
};

}