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
		DrawStr(Vector2D(10, 10), "FPS: " + StrConverter::IntToString(this->_fpsCounter.Get()));
#endif

		// Blit the new frame to the screen
		BitBlt(ps->hdc, 0, 0, AbstractWindow::WindowSize.GetWidth(), AbstractWindow::WindowSize.GetHeight(), this->_backBuffer, 0, 0, SRCCOPY);

		// End the drawing state of WIN32
		EndPaint(hWnd, ps);
	}

	void Graphics::SetCam(ITranslator* cam) {
		_cam = cam;
	}

	void Graphics::DrawStr(Vector2D& position, string str) {
		this->DrawStr(position,str.c_str(), str.length());
	}

	void Graphics::DrawStr(Vector2D& position, const char* str, int length) {
		TextOut(_backBuffer, (int) position.X(), (int) position.Y(), str, length);
	}

	void Graphics::SetColor(COLORREF color) {
		if(_pen)
			DeleteObject(_pen);
		_pen = CreatePen(PS_SOLID, 1, color);
		SelectObject(this->_backBuffer, _pen);
	}

	void Graphics::SetTextColor(COLORREF color) {
		::SetTextColor(_backBuffer, color);
	}

	void Graphics::SetTextBackgroundColor(COLORREF color) {
		SetBkColor(_backBuffer, color);
	}

	void Graphics::DrawRect(Vector2D& one, Vector2D& two) {
		if (_cam != NULL) {
			Vector2D one1 = _cam->FromTo(one);
			Vector2D two1 = _cam->FromTo(two);
			this->DrawRect((int)one1.X(),(int) one1.Y(),(int) two1.X(),(int) two1.Y());
		} else {
			this->DrawRect((int)one.X(),(int) one.Y(),(int) two.X(),(int) two.Y());
		}
	}

	void Graphics::DrawStaticRect(Vector2D& one, Vector2D& two) {
		this->DrawRect((int)one.X(),(int) one.Y(),(int) two.X(),(int) two.Y());
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

	void Graphics::DrawBitmap(string path, Vector2D& position) {
		this->DrawBitmap(path, position, Size(TILE_WIDTH, TILE_HEIGHT));
	}
	
	void Graphics::DrawBitmap(string path, Vector2D& position, Vector2D& offset) {
		this->DrawBitmap(path, position, offset, Size(TILE_WIDTH, TILE_HEIGHT));
	}

	void Graphics::DrawBitmap(string path, Vector2D& position, Size& size) {
		this->DrawBitmap(path, position, Vector2D(0, 0), size);
	}

	void Graphics::DrawBitmap(string path, Vector2D& position, Vector2D& offset, Size& size) {
		
		Sprite* sprite = this->LoadBitmapFile(path);
		DrawSprite(sprite, position, offset, size);
	}
	void Graphics::DrawSprite(Sprite* sprite, Vector2D& position, Vector2D& offset, Size& size){

		Vector2D correctedVector2D = position;

		if (_cam != NULL) {
			correctedVector2D = _cam->FromTo(position);
		}

		HDC bitmap_hdc = CreateCompatibleDC(NULL);

		// link the bitmap to a device context
		SelectObject(bitmap_hdc, sprite->GetMask());

		// OR the image on the mask to apply transparancy
		BitBlt(
			// Dest Context
			_backBuffer, 
			// Posotion
			(int) correctedVector2D.X(), (int) correctedVector2D.Y(),
			// Size
			size.GetWidth(), size.GetHeight(), 
			// Source Context
			bitmap_hdc, 
			// Image offset
			(int) offset.X(), (int) offset.Y(),
			// Operation
			SRCAND);

		// link the bitmap to a device context
		SelectObject(bitmap_hdc, sprite->GetBitmap());

		// OR the image on the mask to apply transparancy
		BitBlt(
			// Dest Context
			_backBuffer, 
			// Posotion
			(int) correctedVector2D.X(), (int) correctedVector2D.Y(),
			// Size
			size.GetWidth(), size.GetHeight(), 
			// Source Context
			bitmap_hdc, 
			// Image offset
			(int) offset.X(), (int) offset.Y(),
			// Operation
			SRCPAINT);

		// release the resource
		DeleteDC(bitmap_hdc);
	}
}
