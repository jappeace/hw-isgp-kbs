#pragma once

#include "ITranslator.h"
#define TILE_WIDTH 16
#define TILE_HEIGHT 16
namespace isgp{
	class GridGraphicTranslator : public ITranslator{
	public:
		Point FromTo(Point p) override;
		Point ToFrom(Point p) override;
	};
}