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


		static string FormatTime(double milliseconds) {

			int millis  = (int) ((int)milliseconds % 1000);
			int seconds = (int) (milliseconds / 1000) % 60;
			int minutes = (int) ((int)milliseconds / (1000*60) % 60);
			return FormatLessThanTen(minutes) + ":" + FormatLessThanTen(seconds) + ":" + FormatLessThanTen(millis / 10);
		}

	};

}