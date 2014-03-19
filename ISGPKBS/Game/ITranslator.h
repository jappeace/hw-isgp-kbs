#pragma once
#include "Vector2D.h"
namespace isgp{
	class ITranslator {
	public:
		virtual ~ITranslator() {}
		virtual Vector2D FromTo(Vector2D p) = 0;
		virtual Vector2D ToFrom(Vector2D p) = 0;
	};
}