
#include "GridGraphicTranslator.h"

namespace isgp{

	Vector2D GridGraphicTranslator::FromTo(Vector2D p){
		return Vector2D(p.X() * TILE_WIDTH, p.Y() * TILE_HEIGHT);
	}
	Vector2D GridGraphicTranslator::ToFrom(Vector2D p){
		return p / Vector2D(TILE_WIDTH, TILE_HEIGHT);
	}

}