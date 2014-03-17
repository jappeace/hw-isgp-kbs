#pragma once

#include "Graphics.h"


using namespace std;

namespace isgp {
	/** 
	* this class makes it easier to use win32, it has also some internal speed optimizations,
	* basicly you should use an instance of this class instead of win32
	*/
	class SpriteGraphics : public Graphics {
	public:
		// creates graphics to draw on a window
		SpriteGraphics(Sprite*);
		// Prepares a sprite for rendering, to render on a sprite a lock has to be created
		void BeginRendering() override;
		// Ends the sprite rendering, releases the lock so the sprite can be drawn on other stuff
		void EndRendering() override;

		// draw a sprite from memory instead of path
		void DrawSprite(Sprite* sprite, Vector2D& position, Vector2D& offset, Size& size) override;
	protected:
		HDC getHDC() override;
	private:
		Sprite* _target;
	};
}
