#pragma once

#include <windows.h>
#include <string>
#include <map>
#include "Point.h"
#include "TimesPerSecondCounter.h"
#include "ITranslator.h"
#include "Size.h"
#include "Sprite.h"

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
		map<string, Sprite>* _bitmapCache;
	public:
		Graphics(HWND);
		~Graphics(void);

		ITranslator* _cam;
		void SetCam(ITranslator*);

		// Prepares the device context to start rendering
		void BeginRendering(HWND, PAINTSTRUCT *);
		// Ends the rendering state and draws the backbuffer onto the screen
		void EndRendering(HWND, PAINTSTRUCT *);
		// get a bitmap from the cache or load it from a file and put it in the cache and return
		Sprite LoadBitmapFile(string path);

		void SetTextColor(COLORREF color);
		void SetTextBackgroundColor(COLORREF color);

		void DrawStr(Point& position, string str);
		void DrawStr(Point& position, const char* str, int length);
		
		void DrawRect(Point& one, Point& two);
		void DrawRect(int xone, int yone, int xtwo, int ytwo);
		void DrawStaticRect(Point& one, Point& two);

		// Draws a bitmap at the given position with the default tile size
		void DrawBitmap(string path, Point& position);
		// Draws a bitmap at the given position with the default tile size
		// The source rectangle starts at the given offset
		void DrawBitmap(string path, Point& position, Point& offset);
		// Draws a bitmap at the given location with the given size
		void DrawBitmap(string path, Point& position, Size& size);
		// Draws a bitmap at the given location with the given size
		// The source rectangle starts at the given offset
		void DrawBitmap(string path, Point& position, Point& offset, Size& size);
	};
}
