#pragma once
#include "Vector2D.h"
namespace isgp {
	// a positive size of somthing
	// just an extension of vector
	class Size : public Vector2D{
	public:
		// set size to 0,0
		Size();
		// set size to width, height
		Size(unsigned  width,unsigned  height);
		void SetHeight(unsigned);
		unsigned  GetHeight() const;
		void SetWidth(unsigned);
		unsigned  GetWidth() const;
	};
}
