/* 
 * File:   StringConverter.h
 * Author: jappie
 *
 * Created on February 1, 2014, 4:44 PM
 */

#pragma once

#include <sstream>

using namespace std;

namespace isgp {
	// becuase strings can be quite though to deal with
	class StrConverter {
	public:
		StrConverter();
		StrConverter(const StrConverter& orig);
		virtual ~StrConverter();

		static string DoubleToString(double num) {
			ostringstream stream;
			stream << num;
			return stream.str();
		}

		// its kind of hard to go from int to string
		static string IntToString(int num) {
			ostringstream stream;
			stream << num;
			return stream.str();
		}
	private:
	};
}
