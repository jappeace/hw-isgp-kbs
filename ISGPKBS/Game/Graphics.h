#pragma once

#include <windows.h>
#include <string>
#include <map>
#include <cmath>
#include "Vector2D.h"
#include "TimesPerSecondCounter.h"
#include "ITranslator.h"
#include "Size.h"
#include "Sprite.h"
#include "GridGraphicTranslator.h"
#include "StrConverter.h"
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
	public:
		Graphics(HWND);
		~Graphics(void);

		ITranslator* _cam;
		void SetCam(ITranslator*);

		void SetColor(COLORREF color);

		// Prepares the device context to start rendering
		void BeginRendering(HWND);
		// Ends the rendering state and draws the backbuffer onto the screen
		void EndRendering(HWND);
		// get a bitmap from the cache or load it from a file and put it in the cache and return
		Sprite* LoadBitmapFile(string path);

		void SetTextColor(COLORREF color);
		void SetTextBackgroundColor(COLORREF color);

		void DrawStr(Vector2D& position, string str);
		void DrawStr(Vector2D& position, const char* str, int length);
		
		void DrawRect(Vector2D& one, Vector2D& two);
		void DrawRect(int xone, int yone, int xtwo, int ytwo);
		void DrawStaticRect(Vector2D& one, Vector2D& two);

		// Draws a bitmap at the given position with the default tile size
		void DrawBitmap(string path, Vector2D& position);
		// Draws a bitmap at the given position with the default tile size
		// The source rectangle starts at the given offset
		void DrawBitmap(string path, Vector2D& position, Vector2D& offset);
		// Draws a bitmap at the given location with the given size
		void DrawBitmap(string path, Vector2D& position, Size& size);
		// Draws a bitmap at the given location with the given size
		// The source rectangle starts at the given offset
		void DrawBitmap(string path, Vector2D& position, Vector2D& offset, Size& size);

		// draw a sprite from memory instead of path
		void DrawSprite(Sprite* sprite, Vector2D& position, Vector2D& offset, Size& size);

		// link the backbuffer as the current graphics to the front buffer of the created graphics
		Graphics* CreateLinkedGraphics(const Size&);

		// bit block transfeur from the backbuffer onto the visible hdc from the backbuffer position just 0,0 on source
		// allows caching on bigger backbuffer image then source (ie a world)
		void Update(const Vector2D& position);

		// set the backbuffur clearing to a value, it somtimes desirable to not do this (for cashes)
		void SetIsClearingBackbuffer(bool);
	private:
		// create a graphics without initilizing the target hdc
		Graphics(void);

		// commen logic for both constructors
		void Init(void);
		//does the final api call for BitBLT
		BOOL BitBlockTransfer(HDC destination, const Vector2D& destPosition, const Size& bothSize, HDC source, const Vector2D& /** offset */positionSrc , DWORD actionFlag);
		// creates a backbuffer based on
		void CreateBackbuffer(HDC& hdc, const Size& size);

		// The device context which is visible on the screen
		HDC _visibleHdc;
		// The hidden device context on which we render to prevent flickering
		HDC _backBuffer;
		// The bitmap on which we are actually rendering in the background
		HBITMAP _bitmap;
		PAINTSTRUCT* _paintStructure;
		HPEN _pen;
#ifdef _DEBUG
		// FPScounter.
		TimesPerSecondCounter _fpsCounter;
#endif
		map<string, Sprite*>* _bitmapCache;

		bool _isClearBackbuffer;
	};
}
