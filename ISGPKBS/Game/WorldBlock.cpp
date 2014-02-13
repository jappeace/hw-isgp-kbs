#include "WorldBlock.h"
namespace isgp{

	WorldBlock::WorldBlock(Point& position, string texturePath):
		_texturePath(texturePath)
	{
		_position = position;
	}

	void WorldBlock::paint(Graphics* g){
		g->drawBitmap(_texturePath, _position);
	}

}