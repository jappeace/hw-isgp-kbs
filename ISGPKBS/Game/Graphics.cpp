#include "Graphics.h"
#include "StrConverter.h"
#include "AbstractWindow.h"
#include "GridGraphicTranslator.h"

namespace isgp {
	Graphics::Graphics(HWND hWnd) {
		_cam = NULL;
		
		_bitmapCache = new map<string,  HBITMAP>();

		this->_backBuffer = CreateCompatibleDC(NULL);

		//get the DC for the front buffer
		HDC hdc = GetDC(hWnd);

		this->_bitmap = CreateCompatibleBitmap(hdc, AbstractWindow::WindowSize.GetWidth(), AbstractWindow::WindowSize.GetHeight());

		//select the bitmap into the memory device context
		SelectObject(this->_backBuffer, this->_bitmap);

		//Don't forget to release the DC
		ReleaseDC(hWnd, hdc); 
	}

	Graphics::~Graphics(void) {
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
		DrawStr(Point(10, 10), "FPS: " + StrConverter::IntToString(this->_fpsCounter.Get()));
#endif

		// Blit the new frame to the screen
		BitBlt(ps->hdc, 0, 0, AbstractWindow::WindowSize.GetWidth(), AbstractWindow::WindowSize.GetHeight(), this->_backBuffer, 0, 0, SRCCOPY);

		// End the drawing state of WIN32
		EndPaint(hWnd, ps);
	}

	void Graphics::SetCam(ITranslator* cam) {
		_cam = cam;
	}

	void Graphics::DrawStr(Point& position, string str) {
		this->DrawStr(position,str.c_str(), str.length());
	}

	void Graphics::DrawStr(Point& position, const char* str, int length) {
		TextOut(_backBuffer, (int) position.GetX(), (int) position.GetY(), str, length);
	}

	void Graphics::SetTextColor(COLORREF color) {
		::SetTextColor(_backBuffer, color);
	}

	void Graphics::SetTextBackgroundColor(COLORREF color) {
		SetBkColor(_backBuffer, color);
	}

	void Graphics::DrawRect(Point& one, Point& two) {
		if (_cam != NULL) {
			Point one1 = _cam->FromTo(one);
			Point two1 = _cam->FromTo(two);
			this->DrawRect((int)one1.GetX(),(int) one1.GetY(),(int) two1.GetX(),(int) two1.GetY());
		} else {
			this->DrawRect((int)one.GetX(),(int) one.GetY(),(int) two.GetX(),(int) two.GetY());
		}
	}

	void Graphics::DrawRect(int xone, int yone, int xtwo, int ytwo) {
		Rectangle(_backBuffer, xone, yone, xtwo, ytwo);
	}
	HBITMAP Graphics::LoadBitmapFile(string path, int offsetX, int offsetY) {
		string key = path + StrConverter::IntToString(offsetX) + StrConverter::IntToString(offsetY);
		if(_bitmapCache->count(key)) {
			return _bitmapCache->find(key)->second;
		}
		HBITMAP bitmap = (HBITMAP)LoadImage(NULL, path.c_str(), IMAGE_BITMAP, offsetX, offsetY, LR_LOADFROMFILE);
		(*_bitmapCache)[key] = bitmap;
		return bitmap;
	}
	HBITMAP Graphics::LoadBitmapFile(string path) {
		return this->LoadBitmapFile(path, 0, 0);	
	}
	HBITMAP Graphics::LoadBitmapFile(string path, Point& offset) {
		return this->LoadBitmapFile(path, (int) offset.GetX(), (int) offset.GetY());
	}

	void Graphics::DrawBitmap(string path, Point& position) {
		DrawBitmap(path,(int) position.GetX(),(int) position.GetY(), 0, 0);
	}
	void Graphics::DrawBitmap(string path, Point& position, Point& offset) {
		DrawBitmap(path,(int) position.GetX(),(int) position.GetY(),(int) offset.GetX(),(int) offset.GetY());
	}
	void Graphics::DrawBitmap(string path, int x, int y) {
		DrawBitmap(path, x, y, 0, 0);
	}
	void Graphics::DrawBitmap(string path, int x, int y, int offsetx, int offsety) {
		if (_cam != NULL) {
			Point one1 = _cam->FromTo(Point(x,y));
			x = (int)one1.GetX();
			y = (int)one1.GetY();
		}
		
		HBITMAP bitmap = this->LoadBitmapFile(path, offsetx, offsety);
		HDC bitmap_hdc = CreateCompatibleDC(NULL);

		// link the bitmap to a device context
		SelectObject(bitmap_hdc,bitmap);

		// copy the bitmap on the backbuffer
		int bltResult =  BitBlt(
			_backBuffer, 
			x, 
			y,
			TILE_WIDTH, 
			TILE_HEIGHT, 
			bitmap_hdc, 
			0, 
			0, 
			SRCCOPY
		);

		// release the resource
		DeleteDC(bitmap_hdc);
	}
}

