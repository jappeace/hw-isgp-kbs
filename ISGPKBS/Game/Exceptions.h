#pragma once

// My idea was to jam all the custom exceptions in here, usualy you won't get that many..

#include <stdexcept>
#include <string>

using namespace std;
namespace isgp {

	class AbstractGridException : public std::runtime_error {
	public:

		AbstractGridException(const string& message, unsigned width, unsigned height)
		: std::runtime_error(message) {
			Init(width, height);

		};

		AbstractGridException(const string& message)
		: std::runtime_error(message) {
			Init(0, 0);
		};

	private:
		// just to view in debug, does not need to be pulic
		unsigned _x;
		unsigned _y;
	protected:
		// just keep track of x and y for debuging
		void Init(unsigned x, unsigned y) {
			_x = x;
			_y = y;
		};
	};
	class GridToLargeException : public AbstractGridException {
	public:

		GridToLargeException(const string& message, unsigned width, unsigned height)
		: AbstractGridException(message) {
			AbstractGridException::Init(width, height);

		};

		GridToLargeException(const string& message)
		: AbstractGridException(message) {
			Init(0, 0);
		};
	};
}
