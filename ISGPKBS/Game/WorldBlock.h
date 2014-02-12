#pragma once
#include "IPaintable.h"
namespace isgp{
	class WorldBlock : IPaintable
	{
	public:
		WorldBlock(Point& position, string texturePath);
		void paint(Graphics*);
	private:
		Point _position;
		string _texturePath;
	};
}