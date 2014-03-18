#pragma once

#include "Graphics.h"


using namespace std;

namespace isgp {
	/** 
	* should allow painting on sprites
	*/
	class SpriteGraphics : public Graphics {
	public:
		// creates graphics to draw on a window
		SpriteGraphics(Sprite*);
		// Prepares a sprite for rendering, to render on a sprite a lock has to be created
		void BeginRendering() override;
		// Ends the sprite rendering, releases the lock so the sprite can be drawn on other stuff
		void EndRendering() override;
	protected:
		HDC getHDC() override;
	private:
		Sprite* _target;
	};
}
