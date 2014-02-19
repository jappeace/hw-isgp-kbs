#include "WorldBlock.h"
namespace isgp{

	WorldBlock::WorldBlock(Point& position, string texturePath):
		_texturePath(texturePath)
	{
		_position = position;
	}

	void WorldBlock::Paint(Graphics* g){
		g->DrawBitmap(_texturePath, _position);
	}

}