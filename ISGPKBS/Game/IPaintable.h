#pragma once

#include "Graphics.h"

namespace isgp {
	// interface to mark classes that can paint
	class IPaintable {
	public:
		virtual void paint(Graphics* g) = 0;
	};
}