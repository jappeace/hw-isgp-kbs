#pragma once
#include "Point.h"
namespace isgp{
	class ITranslator {
	public:
		virtual Point Translate(Point p) = 0;
	};
}