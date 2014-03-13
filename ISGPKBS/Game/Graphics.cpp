#include "Graphics.h"
#include "AbstractWindow.h" // loopfix
namespace isgp {

	void Graphics::Init(void){
		_isClearBackbuffer = true;
		_cam = NULL;
		_bitmapCache = new map<string, Sprite*>();
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
		if(_bitmapCache) {
			for (map<string, Sprite*>::iterator it = _bitmapCache->begin(); it != _bitmapCache->end(); ++it) {
				delete it->second;
			}

			delete _bitmapCache;
		}
	}

	void Graphics::BeginRendering(HWND hWnd) {
		_paintStructure = new PAINTSTRUCT();
		// Begin the drawing state of WIN32
		_visibleHdc = BeginPaint(hWnd, _paintStructure);

		
		// allows graphics to be cached
		if(_isClearBackbuffer){
			// Clear the backbuffer.
			BitBlockTransfer(this->_backBuffer, Vector2D(), AbstractWindow::WindowSize, NULL, NULL, WHITENESS);
		}
	}

	void Graphics::EndRendering(HWND hWnd) {
#ifdef _DEBUG
		this->_fpsCounter.Update();
		DrawStr(Vector2D(10, 10), "FPS: " + StrConverter::IntToString(this->_fpsCounter.Get()));
#endif

		// Blit the new frame to the screen
		Update(Vector2D());

		// End the drawing state of WIN32
		EndPaint(hWnd, _paintStructure);
		delete _paintStructure;
	}

	void Graphics::Update(const Vector2D& position){
		// Blit the backbuffer to the visiblehdc
		BitBlockTransfer(_paintStructure->hdc, Vector2D(), AbstractWindow::WindowSize, this->_backBuffer, position, SRCCOPY);
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
	Graphics* Graphics::CreateLinkedGraphics(const Size& size){
		Graphics* result = new Graphics();
		SelectObject(result->_visibleHdc, this->_bitmap);
		result->CreateBackbuffer(result->_visibleHdc, size);
		return result;
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
	void Graphics::DrawSprite(Sprite* sprite, Vector2D& position, Vector2D& offset, Size& size){

		Vector2D correctedVector2D = position;

		if (_cam != NULL) {
			correctedVector2D = _cam->FromTo(position);
		}

		HDC bitmap_hdc = CreateCompatibleDC(NULL);

		// link the bitmap to a device context
		SelectObject(bitmap_hdc, sprite->GetMask());

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
		SelectObject(bitmap_hdc, sprite->GetBitmap());

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
	void Graphics::SetIsClearingBackbuffer(bool is){
		_isClearBackbuffer = is;
	}

}
