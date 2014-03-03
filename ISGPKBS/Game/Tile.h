#pragma once

#include <cstdlib>
#include "Point.h"
#include "IPaintable.h"
#include "ITileData.h"
#include <vector>

namespace isgp {
	// a container class for stuff in the grid.
	// this class is for easy navigating the grid, when you get a tile you now
	// its neighbours
	class Tile : IPaintable{
	public:
		// set a tile to the point
		Tile(Point* p);
		// set a tile to x,y
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
		std::vector<Tile*> GetSurroundingTiles() const;
		void Paint(Graphics* g);
		void SetData(ITileData*);
	private:
		void Init(Point* p);
		ITileData* _tiledata;
		Point* _position;
		Tile* _top;
		Tile* _left;
		Tile* _right;
		Tile* _bottom;
	};
	inline int operator<(const Tile& one, const Tile& two) {
		return one.GetPosition()->GetX() * one.GetPosition()->GetY() < two.GetPosition()->GetX() * two.GetPosition()->GetY();
	}
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
