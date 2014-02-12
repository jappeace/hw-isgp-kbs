#include "Graphics.h"
#include "StrConverter.h"
#include "AbstractWindow.h"
namespace isgp {

	Graphics::Graphics(HWND hWnd) {
		_bitmapCache = new map<string,  HBITMAP>();

		this->_backBuffer = CreateCompatibleDC(NULL);

		//get the DC for the front buffer
		HDC hdc = GetDC(hWnd);

		// TODO: Retrieve actual window size
		this->_bitmap = CreateCompatibleBitmap(hdc, AbstractWindow::WindowSize.GetWidth(), AbstractWindow::WindowSize.GetHeight());

		//select the bitmap into the memory device context
		SelectObject(this->_backBuffer, this->_bitmap);

		//Don't forget to release the DC
		ReleaseDC(hWnd, hdc); 
	}


	Graphics::~Graphics(void)
	{
		if(_bitmapCache) {
			delete _bitmapCache;
		}
	}

	void Graphics::BeginRendering(HWND hWnd, PAINTSTRUCT *ps) {
		// Begin the drawing state of WIN32
		this->_hdc = BeginPaint(hWnd, ps);

		// Clear the backbuffer.
		BitBlt(this->_backBuffer,0, 0, AbstractWindow::WindowSize.GetWidth(), AbstractWindow::WindowSize.GetHeight(), NULL, NULL, NULL, WHITENESS);
	}

	void Graphics::EndRendering(HWND hWnd, PAINTSTRUCT *ps) {
#ifdef _DEBUG
		this->_fpsCounter.Update();
		drawStr(Point(10, 10), "FPS: " + StrConverter::intToString(this->_fpsCounter.Get()));
#endif

		// Blit the new frame to the screen
		BitBlt(ps->hdc, 0, 0, AbstractWindow::WindowSize.GetWidth(), AbstractWindow::WindowSize.GetHeight(), this->_backBuffer, 0, 0, SRCCOPY);

		// End the drawing state of WIN32
		EndPaint(hWnd, ps);
	}

	void Graphics::drawStr(Point& position, string str) {
		this->drawStr(position,str.c_str(), str.length());
	}

	void Graphics::drawStr(Point& position, const char* str, int length) {
		TextOut(_backBuffer, (int) position.GetX(), (int) position.GetY(), str, length);
	}

	void Graphics::setTextColor(COLORREF color) {
		SetTextColor(_backBuffer, color);
	}

	void Graphics::setTextBackgroundColor(COLORREF color) {
		SetBkColor(_backBuffer, color);
	}

	void Graphics::drawRect(Point& one, Point& two) {
		this->drawRect((int)one.GetX(),(int) one.GetY(),(int) two.GetX(),(int) two.GetY());
	}

	void Graphics::drawRect(int xone, int yone, int xtwo, int ytwo) {
		Rectangle(_backBuffer, xone, yone, xtwo, ytwo);
	}
	HBITMAP Graphics::loadBitmap(string path, int offsetX, int offsetY) {
		string key = path + StrConverter::intToString(offsetX) + StrConverter::intToString(offsetY);
		if(_bitmapCache->count(key)) {
			return _bitmapCache->find(key)->second;
		}
		HBITMAP bitmap = (HBITMAP)LoadImage(NULL, path.c_str(), IMAGE_BITMAP, offsetX, offsetY, LR_LOADFROMFILE);
		(*_bitmapCache)[key] = bitmap;
		return bitmap;
	}
	HBITMAP Graphics::loadBitmap(string path) {
		return this->loadBitmap(path, 0, 0);	
	}
	HBITMAP Graphics::loadBitmap(string path, Point& offset) {
		return this->loadBitmap(path, (int) offset.GetX(), (int) offset.GetY());
	}

	void Graphics::drawBitmap(string path, Point& position) {
		drawBitmap(path,(int) position.GetX(),(int) position.GetY(), 0, 0);
	}
	void Graphics::drawBitmap(string path, Point& position, Point& offset) {
		drawBitmap(path,(int) position.GetX(),(int) position.GetY(),(int) offset.GetX(),(int) offset.GetY());
	}
	void Graphics::drawBitmap(string path, int x, int y) {
		drawBitmap(path, x, y, 0, 0);
	}
	void Graphics::drawBitmap(string path, int x, int y, int offsetx, int offsety) {
		HBITMAP bitmap = this->loadBitmap(path, offsetx, offsety);
		HDC bitmap_hdc = CreateCompatibleDC(NULL);
		SelectObject(bitmap_hdc,bitmap);
		BitBlt(_hdc, x, y, Level::tileSize.GetWidth(), Level::tileSize.GetHeight(), bitmap_hdc, 0, 0, SRCCOPY);
	}
}

