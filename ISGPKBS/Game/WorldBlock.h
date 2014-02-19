#pragma once

#include "IPaintable.h"

namespace isgp {
	// a block you can collide with in the level. ground for example
	class WorldBlock : public IPaintable {
	public:
		WorldBlock(Point& position, string texturePath);
		void Paint(Graphics*);
	private:
		Point _position;
		// the sprite that will be renderd for this block
		string _texturePath;
	};
}