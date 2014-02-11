/* 
 * File:   Point.h
 * Author: jappie
 *
 * Created on January 31, 2014, 7:26 PM
 */

#ifndef POINT_H
#define	POINT_H
namespace isgp {
	class Point {
	public:
		Point();
		Point(int x, int y);
		void SetY(double _y);
		double GetY() const;
		void SetX(double _x);
		double GetX() const;

	private:
		double _x;
		double _y;
	};

	inline bool operator==(const Point& l, const Point& r){
		return l.GetX() == r.GetX() && l.GetY() == r.GetY();
	}
	// forward operations to the once that actualy do somthing
	inline bool operator!=(const Point& l, const Point& r){return !operator==(l,r);}
}
#endif	/* POINT_H */

