#pragma once

// My idea was to jam all the custom exceptions in here, usualy you won't get that many..

#include <stdexcept>
#include <string>

using namespace std;
namespace isgp {

	class GridToLargeException : public std::runtime_error {
	public:

		GridToLargeException(const string& message, unsigned width, unsigned height)
		: std::runtime_error(message) {
			Init(width, height);

		};

		GridToLargeException(const string& message)
		: std::runtime_error(message) {
			Init(0, 0);
		};

	private:
		unsigned _width;
		unsigned _height;
		// just keep track of x and y for debuging
		void Init(unsigned width, unsigned height) {
			_width = width;
			_height = height;
		};
	};
}
