#pragma once

#include "Graphics.h"

namespace isgp {
	class IPaintable {
	public:
		virtual void paint(Graphics* g) = 0;
	};
}