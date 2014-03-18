#pragma once
#include "SpriteGraphics.h"
#include "Level.h"
#include "GridGraphicTranslator.h"
#include "Camera.h"

namespace isgp{
	// does the painting of somthing ones and then 
	class BackgroundArtist : IPaintable, IGridTraveller
	{
	public:
		BackgroundArtist(Camera* cam, Level* level, int levelnr);
		~BackgroundArtist(void);
		// renders the actual background, takes a while, and should only be done once per level
		void RenderBackground(void);
		// just bitblocktranfers the cached bacground on the graphics, ignores the given graphics
		void Paint(Graphics* g) override;
		void ReceiveTile(Tile* tile) override;
	private:
		Sprite*	_background;
		Graphics*	_quil;
		Level* _level;
		Camera* _cam;
	};


}