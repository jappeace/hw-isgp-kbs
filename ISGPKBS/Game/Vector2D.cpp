#include "Vector2D.h"
namespace isgp{
	Vector2D::Vector2D(void)
	{
		init(0,0);
	}

	Vector2D::Vector2D(double x, double y){
		init(x, y);
	}
	Vector2D::Vector2D(int x, int y){
		init(x, y);
	}
	Vector2D::~Vector2D(void)
	{
	}
	void Vector2D::init(double x, double y){
		_x = x;
		_y = y;
	}
	double Vector2D::X() const{
		return _x;
	}
	double Vector2D::Y() const{
		return _y;
	}
	void Vector2D::X(const double x){
		_x = x;
	}
	void Vector2D::Y(const double y){
		_y = y;
	}
	Vector2D& Vector2D::operator=(Vector2D rhs){
		swap(rhs);
		return *this;
	}

	Vector2D& Vector2D::operator+=(const Vector2D& rhs){
		this->_x += rhs._x;
		this->_y += rhs._y;
		return *this;
	}
	Vector2D& Vector2D::operator-=(const Vector2D& rhs){
		this->_x -= rhs._x;
		this->_y -= rhs._y;
		return *this;
	}
	Vector2D& Vector2D::operator*=(const Vector2D& rhs){
		this->_x *= rhs._x;
		this->_y *= rhs._y;
		return *this;
	}
	Vector2D& Vector2D::operator/=(const Vector2D& rhs){
		this->_x /= rhs._x;
		this->_y /= rhs._y;
		return *this;
	}
	inline bool operator==(const Vector2D& lhs,const Vector2D& rhs){
		/* do actual comparison */ 
		return lhs.X() == rhs.X() && lhs.Y() == rhs.Y();
	}
	inline bool operator!=(const Vector2D& lhs, const Vector2D& rhs){return !operator==(lhs,rhs);}
	inline bool operator< (const Vector2D& lhs, const Vector2D& rhs){
		/* do actual comparison */
		return lhs.X() * lhs.Y() < rhs.X() * rhs.Y();
	}
	inline bool operator> (const Vector2D& lhs, const Vector2D& rhs){return  operator< (rhs,lhs);}
	inline bool operator<=(const Vector2D& lhs, const Vector2D& rhs){return !operator> (lhs,rhs);}
	inline bool operator>=(const Vector2D& lhs, const Vector2D& rhs){return !operator< (lhs,rhs);}
	inline Vector2D operator+(Vector2D lhs, const Vector2D& rhs)
	{
		lhs += rhs;
		return lhs;
	}
	inline Vector2D operator-(Vector2D lhs, const Vector2D& rhs)
	{
		lhs -= rhs;
		return lhs;
	}
	inline Vector2D operator*(Vector2D lhs, const Vector2D& rhs)
	{
		lhs *= rhs;
		return lhs;
	}
	inline Vector2D operator/(Vector2D lhs, const Vector2D& rhs)
	{
		lhs /= rhs;
		return lhs;
	}
}