#include "CollisionHelper.h"

namespace isgp {

	CollisionHelper::CollisionHelper(void)
	{
	}


	CollisionHelper::~CollisionHelper(void)
	{
	}

	bool CollisionHelper::IsColliding(const Vector2D positionA, const Size sizeA, const Vector2D positionB, const Size sizeB) {
		double x = positionA.X();
		double y = positionA.Y();
		double w = sizeA.X();
		double h = sizeA.Y();
		double x0 = positionB.X();
		double y0 = positionB.Y();

		return ((x + w > x0 && y + h > y0 && x < x0 + sizeB.X() && y < y0 + sizeB.Y()));
	}
}
