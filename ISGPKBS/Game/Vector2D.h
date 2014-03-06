#pragma once
#include <algorithm>
namespace isgp{
// base class for cartesian calculations, holds two numbers and suports a lot of operator
// overloads for easy calculations
class Vector2D
{
public:
	Vector2D(int x, int y);
	Vector2D(double x, double y);
	Vector2D(void);
	~Vector2D(void);
	double X() const;
	double Y() const;
	void X(const double value);
	void Y(const double value);
	void swap(Vector2D& with){
		// enable ADL (not necessary in our case, but good practice)
		using std::swap; 

		// by swapping the members of two classes,
		// the two classes are effectively swapped
		swap(_x, with._x); 
		swap(_y, with._y);
	}
	Vector2D& operator=(Vector2D rhs);
	Vector2D& operator+=(const Vector2D& rhs);
	Vector2D& operator-=(const Vector2D& rhs);
	Vector2D& operator*=(const Vector2D& rhs);
	Vector2D& operator/=(const Vector2D& rhs);
private:
	double _x, _y;
	// constructors call this
	void init(double x, double y);
};
}