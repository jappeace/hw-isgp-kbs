#pragma once

#include <windows.h>
#include <string>
#include "Point.h"
#include "TimesPerSecondCounter.h"
using namespace std;
namespace isgp {
	class Graphics
	{
	private:
		// The device context which is visible on the screen
		HDC _hdc;
		// The hidden device context on which we render to prevent flickering
		HDC _backBuffer;
		// The bitmap on which we are actually rendering in the background
		HBITMAP _bitmap;

#ifdef _DEBUG
		// FPScounter.
		TimesPerSecondCounter _fpsCounter;
#endif

	public:
		Graphics(HWND);
		~Graphics(void);

		// Prepares the device context to start rendering
		void BeginRendering(HWND, PAINTSTRUCT *);
		// Ends the rendering state and draws the backbuffer onto the screen
		void EndRendering(HWND, PAINTSTRUCT *);
		void drawStr(Point& position, string str);
		void drawStr(Point& position, const char* str, int length);
		void setTextColor(COLORREF color);
		void setTextBackgroundColor(COLORREF color);
		void drawRect(Point& one, Point& two);
		void drawRect(int xone, int yone, int xtwo, int ytwo);
	};
}
