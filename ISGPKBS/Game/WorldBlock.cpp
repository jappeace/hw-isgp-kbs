#include "WorldBlock.h"
#include "GridGraphicTranslator.h"
namespace isgp {
	ITranslator* WorldBlock::_gridToGraphics = new GridGraphicTranslator();
	WorldBlock::WorldBlock(string texturePath):
		_texturePath(texturePath) {
	}

	void WorldBlock::Paint(Graphics* g) {
		g->DrawBitmap(_texturePath, 
				_gridToGraphics->FromTo(
					*_containingTile->GetPosition()
				)
			);
	}

	void WorldBlock::ReceiveTile(Tile* t){
		_containingTile = t;
	}
}