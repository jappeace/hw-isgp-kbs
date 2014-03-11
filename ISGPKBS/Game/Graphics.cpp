#include "AbstractWindow.h"
#include "Graphics.h"
#include "GridGraphicTranslator.h"
#include "Sprite.h"
#include "StrConverter.h"

namespace isgp {

	Graphics::Graphics(HWND hWnd) {
		_cam = NULL;
		
		_bitmapCache = new map<string, Sprite*>();

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
			for (map<string, Sprite*>::iterator it = _bitmapCache->begin(); it != _bitmapCache->end(); ++it) {
				delete it->second;
			}

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

	void Graphics::DrawStaticRect(Point& one, Point& two) {
		this->DrawRect((int)one.GetX(),(int) one.GetY(),(int) two.GetX(),(int) two.GetY());
	}

	void Graphics::DrawRect(int xone, int yone, int xtwo, int ytwo) {
		Rectangle(_backBuffer, xone, yone, xtwo, ytwo);
	}

	Sprite* Graphics::LoadBitmapFile(string path) {
		if(_bitmapCache->count(path)) {
			// Return cached item
			return _bitmapCache->find(path)->second;
		}

		HBITMAP bitmap = (HBITMAP)LoadImage(NULL, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		Sprite* sprite = new Sprite(bitmap);

		(*_bitmapCache)[path] = sprite;

		return sprite;
	}

	void Graphics::DrawBitmap(string path, Point& position) {
		this->DrawBitmap(path, position, Size(TILE_WIDTH, TILE_HEIGHT));
	}
	
	void Graphics::DrawBitmap(string path, Point& position, Point& offset) {
		this->DrawBitmap(path, position, offset, Size(TILE_WIDTH, TILE_HEIGHT));
	}

	void Graphics::DrawBitmap(string path, Point& position, Size& size) {
		this->DrawBitmap(path, position, Point(0, 0), size);
	}

	void Graphics::DrawBitmap(string path, Point& position, Point& offset, Size& size) {
		Point correctedPoint = position;

		if (_cam != NULL) {
			correctedPoint = _cam->FromTo(position);
		}
		
		Sprite* sprite = this->LoadBitmapFile(path);
		HDC bitmap_hdc = CreateCompatibleDC(NULL);

		// link the bitmap to a device context
		SelectObject(bitmap_hdc, sprite->GetMask());

		// OR the image on the mask to apply transparancy
		BitBlt(
			// Dest Context
			_backBuffer, 
			// Posotion
			(int) correctedPoint.GetX(), (int) correctedPoint.GetY(),
			// Size
			size.GetWidth(), size.GetHeight(), 
			// Source Context
			bitmap_hdc, 
			// Image offset
			(int) offset.GetX(), (int) offset.GetY(),
			// Operation
			SRCAND);

		// link the bitmap to a device context
		SelectObject(bitmap_hdc, sprite->GetBitmap());

		// OR the image on the mask to apply transparancy
		BitBlt(
			// Dest Context
			_backBuffer, 
			// Posotion
			(int) correctedPoint.GetX(), (int) correctedPoint.GetY(),
			// Size
			size.GetWidth(), size.GetHeight(), 
			// Source Context
			bitmap_hdc, 
			// Image offset
			(int) offset.GetX(), (int) offset.GetY(),
			// Operation
			SRCPAINT);

		// release the resource
		DeleteDC(bitmap_hdc);
	}
}

