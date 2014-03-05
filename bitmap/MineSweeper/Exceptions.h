/* 
 * File:   Exceptions.h
 * Author: jappie
 *
 * Created on February 2, 2014, 2:09 PM
 */

#ifndef EXCEPTIONS_H
#define	EXCEPTIONS_H
/*
 * My idea was to jam all the custom exceptions in here, usualy you won't get that many..
 */
#include <stdexcept>
#include <string>
using namespace std;
namespace isgp {

	class GridToLargeException : public std::runtime_error {
	public:

		GridToLargeException(const string& message, unsigned width, unsigned height)
		: std::runtime_error(message) {
			init(width, height);

		};

		GridToLargeException(const string& message)
		: std::runtime_error(message) {
			init(0, 0);
		};

	private:
		unsigned _width;
		unsigned _height;
		// just keep track of x and y for debuging
		void init(unsigned width, unsigned height) {
			_width = width;
			_height = height;
		};
	};
}
#endif	/* EXCEPTIONS_H */

