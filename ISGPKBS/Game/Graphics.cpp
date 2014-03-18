#include "Graphics.h"
#include "AbstractWindow.h" // loopfix
namespace isgp {

	void Graphics::Init(void){
		_translator = NULL;
		_visibleHdc = NULL;
		_pen = NULL;
		_bitmapCache = new map<string, Sprite*>();
	}

	void Graphics::SetTranslator(ITranslator* cam) {
		_translator = cam;
	}

	void Graphics::DrawStr(Vector2D& position, string str) {
		this->DrawStr(position,str.c_str(), str.length());
	}

	void Graphics::DrawStr(Vector2D& position, string str, HFONT font) {
		this->DrawStr(position,str.c_str(), str.length(), font);
	}

	void Graphics::DrawStr(Vector2D& position, const char* str, int length) {
		TextOut(getHDC(), (int) position.X(), (int) position.Y(), str, length);
	}

	void Graphics::DrawStr(Vector2D& position, const char* str, int length, HFONT font) {
		HGDIOBJ oldFont = SelectObject(getHDC(), font);
		RECT rect;
		SetRect(&rect, (int)position.X(), (int)position.Y(), 200, 200);
		DrawText(getHDC(), str, length, &rect, DT_NOCLIP);
		//TextOut(getHDC(), (int) position.X(), (int) position.Y(), str, length);
		SelectObject(getHDC(), oldFont);
	}

	void Graphics::SetColor(COLORREF color) {
		if(_pen)
			DeleteObject(_pen);
		_pen = CreatePen(PS_SOLID, 1, color);
		SelectObject(getHDC(), _pen);
	}

	void Graphics::SetTextColor(COLORREF color) {
		::SetTextColor(getHDC(), color);
	}

	void Graphics::SetTextBackgroundColor(COLORREF color) {
		::SetBkColor(getHDC(), color);
	}

	void Graphics::DrawRect(Vector2D one, Vector2D two) {
		if (_translator != NULL) {
			one = _translator->FromTo(one);
			two = _translator->FromTo(two);
		} 
		this->DrawRect((int)one.X(),(int) one.Y(),(int) two.X(),(int) two.Y());
		
	}

	void Graphics::FillStaticRect(int x1, int y1, int x2, int y2, HBRUSH brush) {
		RECT r;
		r.left = x1;
		r.top = y1;
		r.right = x2;
		r.bottom = y2;
		FillRect(this->_backBuffer, &r, brush);
	}

	void Graphics::DrawStaticRect(Vector2D& one, Vector2D& two) {
		this->DrawRect((int)one.X(),(int) one.Y(),(int) two.X(),(int) two.Y());
	}

	void Graphics::DrawRect(int xone, int yone, int xtwo, int ytwo) {
		::Rectangle(getHDC(), xone, yone, xtwo, ytwo);
	}
	void Graphics::FillRect(Vector2D position, const Size& size, COLORREF color){
		if (_translator != NULL) {
			position = _translator->FromTo(position);
		}
		// pass into the static method
		Graphics::FillRect(getHDC(), position, size, color);
	}
	void Graphics::FillRect(HDC hdc, Vector2D position, const Size& size, COLORREF color){
		RECT r;
		r.left = (LONG)position.X();
		r.top = (LONG)position.Y();
		position += size;
		r.right = (LONG)position.X();
		r.bottom = (LONG)position.Y();
		::FillRect(hdc, &r, CreateSolidBrush(color));
	}

	Sprite* Graphics::LoadBitmapFile(string path) {
		if(Graphics::_bitmapCache->count(path)) {
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
	BOOL Graphics::BitBlockTransfer(HDC destination, const Vector2D& destPosition, const Size& bothSize, HDC source, const Vector2D& positionSrc, DWORD actionFlag){
		return BitBlt(
			// Dest Context
			destination, 
			// Position
			(int) destPosition.X(), (int) destPosition.Y(),
			// Size
			bothSize.GetWidth(), bothSize.GetHeight(), 
			// Source Context
			source, 
			// Image offset
			(int) positionSrc.X(), (int) positionSrc.Y(),
			// Operation
			actionFlag);
	}
	void Graphics::DrawLine(Vector2D one, Vector2D two){
		if(_translator != NULL){
			one = _translator->FromTo(one);
			two = _translator->FromTo(two);
		}
		POINT points[2];
		points[0].x = (long) one.X();
		points[0].y = (long) one.Y();
		points[1].x = (long) two.X();
		points[1].y = (long) two.Y();
		::Polyline(getHDC(), points, 2);
	}
	void Graphics::DrawSprite(Sprite* sprite, Vector2D position, Vector2D& offset, Size& size){
		if (_translator != NULL) {
			position = _translator->FromTo(position);
		}

		HDC bitmap_hdc = CreateCompatibleDC(NULL);

		// link the bitmap to a device context
		::SelectObject(bitmap_hdc, sprite->GetMask());

		// OR the image on the mask to apply transparancy
		BitBlockTransfer(
			// Dest Context
			getHDC(), 
			// Position
			position,
			size, 
			// Source Context
			bitmap_hdc, 
			offset,
			SRCAND);

		// link the bitmap to a device context
		::SelectObject(bitmap_hdc, sprite->GetBitmap());

		// OR the image on the mask to apply transparancy
		BitBlockTransfer(
			// Dest Context
			getHDC(), 
			// Position
			position,
			size,
			// Source Context
			bitmap_hdc, 
			offset,
			// Operation
			SRCPAINT);

		// release the resource
		DeleteDC(bitmap_hdc);
	}
}
