#pragma once

#include <windows.h>
#include <string>
#include <map>
#include "Point.h"
#include "TimesPerSecondCounter.h"

// to breack an include loop This class can't use the static Level::tilesize
// that is why the macro where the size is based on is moved to here
// this also gives a small speed optimization (less function calls)
// and yes putting this definition here is quite weird


using namespace std;

namespace isgp {
	/** 
	* this class makes it easier to use win32, it has also some internal speed optimizations,
	* basicly you should use an instance of this class instead of win32
	*/
	class Graphics {
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
		map<string, HBITMAP>* _bitmapCache;
	public:
		Graphics(HWND);
		~Graphics(void);

		// Prepares the device context to start rendering
		void BeginRendering(HWND, PAINTSTRUCT *);
		// Ends the rendering state and draws the backbuffer onto the screen
		void EndRendering(HWND, PAINTSTRUCT *);
		// get a bitmap from the cache or load it from a file and put it in the cache and return
		HBITMAP LoadBitmapFile(string path);
		HBITMAP LoadBitmapFile(string path, int offsetX, int offsetY);
		HBITMAP LoadBitmapFile(string path, Point& offset);

		void SetColor(COLORREF color);

		void SetTextColor(COLORREF color);
		void SetTextBackgroundColor(COLORREF color);

		void DrawStr(Point& position, string str);
		void DrawStr(Point& position, const char* str, int length);

		void DrawRect(Point& one, Point& two);
		void DrawRect(int xone, int yone, int xtwo, int ytwo);

		void DrawBitmap(string path, Point& position);
		void DrawBitmap(string path, Point& position, Point& offset);
		void DrawBitmap(string path, int x, int y);
		void DrawBitmap(string path, int x, int y, int offsetx, int offsety);
	};
}
