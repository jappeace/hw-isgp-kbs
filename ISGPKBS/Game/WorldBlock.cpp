#include "WorldBlock.h"

namespace isgp {
	WorldBlock::WorldBlock(Point& position, string texturePath):
		_texturePath(texturePath) {
		_position = position;
	}

	void WorldBlock::Paint(Graphics* g) {
		g->DrawBitmap(_texturePath, _position);
	}

	void WorldBlock::ReceiveTile(Tile* t){
		_containingTile = t;
	}
}