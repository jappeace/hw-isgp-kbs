/* 
 * File:   Tile.h
 * Author: jappie
 *
 * Created on January 31, 2014, 11:16 AM
 */

#pragma once
#include <cstdlib>
#include "Point.h"
#include "IPaintable.h"
namespace isgp {
	class Tile : IPaintable{
	public:
		Tile(Point* p);
		Tile(int x, int y);
		~Tile();
		void SetBottom(Tile* bottom);
		Tile* GetBottom() const;
		void SetRight(Tile* right);
		Tile* GetRight() const;
		void SetLeft(Tile* left);
		Tile* GetLeft() const;
		void SetTop(Tile* top);
		Tile* GetTop() const;
        Point* GetPosition() const;
		void paint(Graphics* g);
		void setIpaintalbe(IPaintable*);
	private:
		void init(Point* p);
		IPaintable* _paintable;
		Point* _position;
		Tile* _top;
		Tile* _left;
		Tile* _right;
		Tile* _bottom;
	};
	inline bool operator==(const Tile& l, const Tile& r){
		if(l.GetPosition() != r.GetPosition()){
			return false;
		}
		// don't compare the actual states of the neighbours,
		// because it will recusrivle call their == operators as well
		// just checking their identity trough pointers is way faster
		// and sort of reliable (not for pointer pointers, but this may be
		// handled by the type system)
		if(l.GetTop() != r.GetTop()){
			return false;
		}
		if(l.GetLeft() != r.GetLeft()){
			return false;
		}
		if(l.GetBottom() != r.GetBottom()){
			return false;
		}
		if(l.GetRight() != r.GetRight()){
			return false;
		}
		return true;
	}
	// forward operations to the once that actualy do somthing
	inline bool operator!=(const Tile& l, const Tile& r){return !operator==(l,r);}
}
