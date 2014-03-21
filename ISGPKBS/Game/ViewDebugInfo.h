#pragma once
#include "SpriteGraphics.h"
#include "Level.h"
#include "GridGraphicTranslator.h"
#include "Camera.h"

namespace isgp{
	class ViewDebugInfo
		:IPaintable, IGridTraveller
	{

	public :
		ViewDebugInfo(Camera* cam,Level *level);
		~ViewDebugInfo(void);
		void ReceiveTile(Tile *tile) override;
		void Paint(Graphics* g) override;

		bool _f1;
	private:
		Sprite*	_background;
		Graphics*	_quil;
		Level * _level;
		Camera* _cam;


	};

}