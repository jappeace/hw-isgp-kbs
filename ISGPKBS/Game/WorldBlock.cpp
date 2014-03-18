#ifdef _DEBUG
    #define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
    #define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
    #define new DEBUG_NEW
#endif
#include "WorldBlock.h"
#include "GridGraphicTranslator.h"
namespace isgp {
	ITranslator* WorldBlock::_gridToGraphics = new GridGraphicTranslator();
	WorldBlock::WorldBlock(string texturePath):
		_texturePath(texturePath) {
			_containingTile = NULL;
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