
#include "GridGraphicTranslator.h"

namespace isgp{

	Point GridGraphicTranslator::translate(Point p){
		return Point(p.GetX() * TILE_WIDTH, p.GetY() * TILE_HEIGHT);
	}

}