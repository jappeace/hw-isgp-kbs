#pragma once
#include <string>
#include "StrConverter.h"

using namespace std;
namespace isgp {
	class TimeFormatter
	{
	public:
		static string FormatLessThanTen(int time) {
			string str;
			if(time < 10)
				str = "0";
			str += StrConverter::IntToString(time);
			return str;
		}

		static string FormatTime(double time) {
			string elapsedString = "";
			int timeInSeconds = time/1000;
			int minutes = (int) (timeInSeconds / 60) % 60;
			int seconds = (int)timeInSeconds  % 60;
			int ms = (int)time % 60;
			return FormatLessThanTen(minutes) + ":" + FormatLessThanTen(seconds) + ":" + FormatLessThanTen(ms);
		}

	};

}