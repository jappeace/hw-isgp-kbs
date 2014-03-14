#include "Graphics.h"
#include "AbstractWindow.h" // loopfix
namespace isgp {

	map<string, Sprite*>* Graphics::_bitmapCache = NULL;
	void Graphics::Init(void){
		_cam = NULL;
		if(_bitmapCache == NULL){
			_bitmapCache = new map<string, Sprite*>();
		}
	}
	Graphics::Graphics(HWND hWnd) {
		Init();

		this->_backBuffer = CreateCompatibleDC(NULL);

		//get the DC for the front buffer
		HDC hdc = GetDC(hWnd);

		CreateBackbuffer(hdc, AbstractWindow::WindowSize);

		//Don't forget to release the DC
		ReleaseDC(hWnd, hdc); 
	}
	Graphics::Graphics(void){
		Init();
	}
	void Graphics::CreateBackbuffer(HDC& hdc, const Size& size){
		this->_bitmap = CreateCompatibleBitmap(hdc, size.GetWidth(), size.GetHeight());
		//select the bitmap into the memory device context
		SelectObject(this->_backBuffer, this->_bitmap);
	}
	Graphics::~Graphics(void) {
		// don't delete the cache, there might be other graphics arround
	}
	void Graphics::BeginRendering(Sprite* sprite){
		this->_backBuffer = CreateCompatibleDC(NULL);
		HGDIOBJ h = ::SelectObject(this->_backBuffer, sprite->GetBitmap());
		BitBlockTransfer(this->_backBuffer, Vector2D(), sprite->GetSize(), NULL, NULL, WHITENESS);
	}
	void Graphics::BeginRendering(HWND hWnd) {
		_paintStructure = new PAINTSTRUCT();
		// Begin the drawing state of WIN32
		_visibleHdc = BeginPaint(hWnd, _paintStructure);
		
		// Clear the backbuffer.
		BitBlockTransfer(this->_backBuffer, Vector2D(), AbstractWindow::WindowSize, NULL, NULL, WHITENESS);
	}

	void Graphics::EndRendering(){
		::DeleteDC(this->_backBuffer);
	}
	void Graphics::EndRendering(HWND hWnd) {
		this->_fpsCounter.Update();
		SetTextColor(RGB(0, 0, 0));
		DrawStr(Vector2D(10, 10), "FPS: " + StrConverter::IntToString(this->_fpsCounter.Get()));

		// Blit the new frame to the screen
		BitBlockTransfer(_paintStructure->hdc, Vector2D(), AbstractWindow::WindowSize, this->_backBuffer, Vector2D(), SRCCOPY);
		// End the drawing state of WIN32
		EndPaint(hWnd, _paintStructure);
		delete _paintStructure;
	}

	void Graphics::SetCam(ITranslator* cam) {
		_cam = cam;
	}

	void Graphics::DrawStr(Vector2D& position, string str) {
		this->DrawStr(position,str.c_str(), str.length());
	}

	void Graphics::DrawStr(Vector2D& position, string str, HFONT font) {
		this->DrawStr(position,str.c_str(), str.length(), font);
	}

	void Graphics::DrawStr(Vector2D& position, const char* str, int length) {
		TextOut(_backBuffer, (int) position.X(), (int) position.Y(), str, length);
	}

	void Graphics::DrawStr(Vector2D& position, const char* str, int length, HFONT font) {
		HGDIOBJ oldFont = SelectObject(this->_backBuffer, font);
		RECT rect;
		SetRect(&rect, (int)position.X(), (int)position.Y(), 200, 200);
		DrawText(this->_backBuffer, str, length, &rect, DT_NOCLIP);
		//TextOut(_backBuffer, (int) position.X(), (int) position.Y(), str, length);
		SelectObject(this->_backBuffer, oldFont);
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
		::SetBkColor(_backBuffer, color);
	}

	void Graphics::DrawRect(Vector2D one, Vector2D two) {
		if (_cam != NULL) {
			one = _cam->FromTo(one);
			two = _cam->FromTo(two);
		} 
		this->DrawRect((int)one.X(),(int) one.Y(),(int) two.X(),(int) two.Y());
		
	}

	void Graphics::DrawStaticRect(Vector2D& one, Vector2D& two) {
		this->DrawRect((int)one.X(),(int) one.Y(),(int) two.X(),(int) two.Y());
	}

	void Graphics::DrawRect(int xone, int yone, int xtwo, int ytwo) {
		::Rectangle(_backBuffer, xone, yone, xtwo, ytwo);
	}
	void Graphics::FillRect(Vector2D position, const Size& size, COLORREF color){
		if (_cam != NULL) {
			position = _cam->FromTo(position);
		}
		RECT r;
		r.left = (LONG)position.X();
		r.top = (LONG)position.Y();
		position += size;
		r.right = (LONG)position.X();
		r.bottom = (LONG)position.Y();
		::FillRect(_backBuffer, &r, CreateSolidBrush(color));
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
		if(_cam != NULL){
			one = _cam->FromTo(one);
			two = _cam->FromTo(two);
		}
		POINT points[2];
		points[0].x = (long) one.X();
		points[0].y = (long) one.Y();
		points[1].x = (long) two.X();
		points[1].y = (long) two.Y();
		::Polyline(_backBuffer, points, 2);
	}
	void Graphics::DrawSprite(Sprite* sprite, Vector2D& position, Vector2D& offset, Size& size){

		Vector2D correctedVector2D = position;

		if (_cam != NULL) {
			correctedVector2D = _cam->FromTo(position);
		}

		HDC bitmap_hdc = CreateCompatibleDC(NULL);

		// link the bitmap to a device context
		::SelectObject(bitmap_hdc, sprite->GetMask());

		// OR the image on the mask to apply transparancy
		BitBlockTransfer(
			// Dest Context
			_backBuffer, 
			// Position
			correctedVector2D,
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
			_backBuffer, 
			// Position
			correctedVector2D,
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
