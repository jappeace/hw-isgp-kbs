#pragma once

#include "ITileData.h"
#include "Tile.h"
#include "ITranslator.h"

namespace isgp {
	// a block you can collide with in the level. ground for example
	class WorldBlock : public ITileData{
	public:
		WorldBlock(string texturePath);
		void Paint(Graphics*);
		// In this case receive tile allows a Tile to tell the data on which tile it is
		void ReceiveTile(Tile* tile);
	private:
		// the sprite that will be renderd for this block
		static ITranslator* _worldblockTranslator;
		string _texturePath;
		Tile* _containingTile;
	};
}