#include "Size.h"

namespace isgp {
	Size::Size(unsigned  width,unsigned  height) {
		_width = width;
		_height = height;
	}
	Size::Size() {
		_width =0;
		_height=0;
	}

	void Size::SetHeight(unsigned  _height) {
		this->_height = _height;
	}

	unsigned  Size::GetHeight() const {
		return _height;
	}

	void Size::SetWidth(unsigned  _width) {
		this->_width = _width;
	}

	unsigned  Size::GetWidth() const {
		return _width;
	}
}
