/* 
 * File:   StringConverter.h
 * Author: jappie
 *
 * Created on February 1, 2014, 4:44 PM
 */

#ifndef STRINGCONVERTER_H
#define	STRINGCONVERTER_H

#include <sstream>
using namespace std;
namespace isgp {
	
	/** becuase strings can be quite though to deal with*/
	class StrConverter {
	public:
		StrConverter();
		StrConverter(const StrConverter& orig);
		virtual ~StrConverter();

		/**
		 * its kind of hard to go from int to string
		 * @param num
		 * @return 
		 */
		static string intToString(int num) {
			ostringstream stream;
			string result = "";
			stream << num;
			return stream.str();
		}
	private:

	};
}
#endif	/* STRINGCONVERTER_H */

