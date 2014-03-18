#pragma once

#include "Graphics.h"


using namespace std;

namespace isgp {
	/** 
	* this class makes it easier to use win32, it has also some internal speed optimizations,
	* basicly you should use an instance of this class instead of win32
	*/
	class WindowGraphics : public Graphics {
	public:
		// creates graphics to draw on a window
		WindowGraphics(HWND);
		~WindowGraphics(void);


		void BeginRendering() override;
		void EndRendering() override;

		void DrawSprite(Sprite* sprite, Vector2D position, Vector2D& offset, Size& size) override;
		void DrawBackground(Sprite* sprite, Vector2D position, Vector2D& offset, Size& size) override;
	protected:
		HDC getHDC() override;
	private:
		// commen logic for both constructors
		void CreateBackbuffer(HDC& hdc, const Size& size);

		// The hidden device context on which we render to prevent flickering
		HDC _backBuffer;
		// The bitmap on which we are actually rendering in the background
		HBITMAP _bitmap;

		// to start and end paints
		PAINTSTRUCT* _paintStructure;
		// FPScounter.
		TimesPerSecondCounter _fpsCounter;

		HWND _windowHandle;
	};
}
