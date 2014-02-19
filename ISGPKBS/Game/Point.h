/* 
 * File:   Point.h
 * Author: jappie
 *
 * Created on January 31, 2014, 7:26 PM
 */

#pragma once

namespace isgp {
	// represents a 2d point (x, y)
	class Point {
	public:
		// sets a Point to (0,0)
		Point();
		// sets a Point to (x, y)
		Point(int x, int y);
		// sets a Point to (x, y)
		Point(double x, double y);
		
		// change the y acces of the point
		void SetY(double);
		// get the y of the point
		double GetY() const;
		void SetX(double);
		double GetX() const;
	private:
		void init(double y, double x);
		double _x;
		double _y;
	};

	inline bool operator==(const Point& l, const Point& r){
		return l.GetX() == r.GetX() && l.GetY() == r.GetY();
	}
	// forward operations to the once that actualy do somthing
	inline bool operator!=(const Point& l, const Point& r){return !operator==(l,r);}
}
