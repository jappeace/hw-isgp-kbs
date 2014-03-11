#pragma once

#include <windows.h>
#include <string>
#include <map>
#include "Vector2D.h"
#include "TimesPerSecondCounter.h"
#include "ITranslator.h"

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
		
		HPEN _pen;
#ifdef _DEBUG
		// FPScounter.
		TimesPerSecondCounter _fpsCounter;
#endif
		map<string, HBITMAP>* _bitmapCache;
	public:
		Graphics(HWND);
		~Graphics(void);

		ITranslator* _cam;
		void SetCam(ITranslator*);

		void SetColor(COLORREF color);

		// Prepares the device context to start rendering
		void BeginRendering(HWND, PAINTSTRUCT *);
		// Ends the rendering state and draws the backbuffer onto the screen
		void EndRendering(HWND, PAINTSTRUCT *);
		// get a bitmap from the cache or load it from a file and put it in the cache and return
		HBITMAP LoadBitmapFile(string path);
		HBITMAP LoadBitmapFile(string path, int offsetX, int offsetY);
		HBITMAP LoadBitmapFile(string path, Vector2D& offset);

		void SetTextColor(COLORREF color);
		void SetTextBackgroundColor(COLORREF color);

		void DrawStr(Vector2D& position, string str);
		void DrawStr(Vector2D& position, const char* str, int length);
		
		void DrawRect(Vector2D& one, Vector2D& two);
		void DrawRect(int xone, int yone, int xtwo, int ytwo);
		void DrawStaticRect(Vector2D& one, Vector2D& two);

		void DrawBitmap(string path, Vector2D& position);
		void DrawBitmap(string path, Vector2D& position, Vector2D& offset);
		void DrawBitmap(string path, int x, int y);
		void DrawBitmap(string path, int x, int y, int offsetx, int offsety);
	};
}
