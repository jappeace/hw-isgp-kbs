#include "Point.h"

namespace isgp{
	Point::Point(): _x(), _y(){}
	Point::Point(int x, int y){
		init((double) x,(double) y);
	}

	Point::Point(double x, double y) {
		init(x, y);
	}

	void Point::init(double x, double y) {
		_x = x;
		_y = y;
	}

	void Point::SetY(double _y) {
		this->_y = _y;
	}

	double Point::GetY() const {
		return _y;
	}

	void Point::SetX(double _x) {
		this->_x = _x;
	}

	double Point::GetX() const {
		return _x;
	}
}
