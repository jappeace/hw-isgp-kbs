#pragma once

#include "Graphics.h"

namespace isgp {
	class IPaintable {
	public:
		virtual void Paint(Graphics* g) = 0;
	};
}