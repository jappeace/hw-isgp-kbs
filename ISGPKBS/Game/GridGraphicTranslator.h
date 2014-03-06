#pragma once

#include "ITranslator.h"
#define TILE_WIDTH 16
#define TILE_HEIGHT 16
namespace isgp{
	class GridGraphicTranslator : public ITranslator{
	public:
		Vector2D FromTo(Vector2D p) override;
		Vector2D ToFrom(Vector2D p) override;
	};
}