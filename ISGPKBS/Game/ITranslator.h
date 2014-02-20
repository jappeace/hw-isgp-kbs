#pragma once
#include "Point.h"
namespace isgp{
	class ITranslator {
	public:
		virtual Point FromTo(Point p) = 0;
		virtual Point ToFrom(Point p) = 0;
	};
}