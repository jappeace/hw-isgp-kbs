#pragma once

namespace isgp {
	// a positive size of somthing
	class Size {
	public:
		// set size to 0,0
		Size();
		// set size to width, height
		Size(unsigned  width,unsigned  height);
		void SetHeight(unsigned);
		unsigned  GetHeight() const;
		void SetWidth(unsigned);
		unsigned  GetWidth() const;
	private:
		unsigned  _width;
		unsigned  _height;
	};
}
