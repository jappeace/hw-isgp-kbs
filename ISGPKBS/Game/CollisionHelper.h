#pragma once
#include "Size.h"
#include "Vector2D.h"

namespace isgp {
	class CollisionHelper
	{
	public:
		CollisionHelper();
		~CollisionHelper();

		// Executes a bounding box collision on the parameters
		// The information comes in sets of vector2d and size.
		static bool IsColliding(const Vector2D positionA, const Size sizeA, const Vector2D positionB, const Size sizeB);
	};
}
