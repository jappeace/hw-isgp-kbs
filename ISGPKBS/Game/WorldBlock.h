#pragma once

#include "ITileData.h"

namespace isgp {
	// a block you can collide with in the level. ground for example
	class WorldBlock : public ITileData{
	public:
		WorldBlock(Point& position, string texturePath);
		void Paint(Graphics*);
		// In this case receive tile allows a Tile to tell the data on which tile it is
		void ReceiveTile(Tile* tile);
	private:
		Point _position;
		// the sprite that will be renderd for this block
		string _texturePath;
		Tile* _containingTile;
	};
}