
#include "GridGraphicTranslator.h"

namespace isgp{

	Point GridGraphicTranslator::Translate(Point p){
		return Point(p.GetX() * TILE_WIDTH, p.GetY() * TILE_HEIGHT);
	}

}