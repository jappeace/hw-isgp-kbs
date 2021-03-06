#include "WindowGraphics.h"
#include "AbstractWindow.h" // loopfix
namespace isgp {

	WindowGraphics::WindowGraphics(HWND hWnd) {
		Init();

		this->_backBuffer = CreateCompatibleDC(NULL);

		//get the DC for the front buffer
		HDC hdc = GetDC(hWnd);

		_windowHandle = hWnd;
		CreateBackbuffer(hdc, AbstractWindow::WindowSize);

		//Don't forget to release the DC
		ReleaseDC(hWnd, hdc); 
	}
	void WindowGraphics::CreateBackbuffer(HDC& hdc, const Size& size){
		this->_bitmap = CreateCompatibleBitmap(hdc, size.GetWidth(), size.GetHeight());
		//select the bitmap into the memory device context
		SelectObject(this->_backBuffer, this->_bitmap);
	}
	WindowGraphics::~WindowGraphics(void) {
		// don't delete the cache, there might be other graphics arround
	}
	void WindowGraphics::BeginRendering() {
		_paintStructure = new PAINTSTRUCT();
		// Begin the drawing state of WIN32
		_visibleHdc = BeginPaint(_windowHandle, _paintStructure);
		
		// Clear the backbuffer.
		BitBlockTransfer(this->_backBuffer, Vector2D(), AbstractWindow::WindowSize, NULL, NULL, WHITENESS);
	}

	void WindowGraphics::EndRendering() {
		this->_fpsCounter.Update();
		SetTextColor(RGB(0, 0, 0));
		DrawStr(Vector2D(10, 10), "FPS: " + StrConverter::IntToString(this->_fpsCounter.Get()));

		// Blit the new frame to the screen
		BitBlockTransfer(_paintStructure->hdc, Vector2D(), AbstractWindow::WindowSize, this->_backBuffer, Vector2D(), SRCCOPY);
		// End the drawing state of WIN32
		EndPaint(_windowHandle, _paintStructure);
		delete _paintStructure;
	}
	HDC WindowGraphics::getHDC(){
		return _backBuffer;
	}
}
