
#include "GridGraphicTranslator.h"

namespace isgp{

	Point GridGraphicTranslator::FromTo(Point p){
		return Point(p.GetX() * TILE_WIDTH, p.GetY() * TILE_HEIGHT);
	}
	Point GridGraphicTranslator::ToFrom(Point p){
		return Point(p.GetX() / TILE_WIDTH, p.GetY() / TILE_HEIGHT);
	}

}