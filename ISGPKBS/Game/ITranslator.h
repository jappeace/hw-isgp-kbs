#pragma once
#include "Point.h"
namespace isgp{
	class ITranslator {
	public:
		virtual Point translate(Point p) = 0;
	};
}