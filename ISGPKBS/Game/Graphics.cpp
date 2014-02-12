#include "Graphics.h"
#include "StrConverter.h"
#include "AbstractWindow.h"
namespace isgp {

	Graphics::Graphics(HWND hWnd) {
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

	void Graphics::drawStr(Point& position, string str){
		this->drawStr(position,str.c_str(), str.length());
	}

	void Graphics::drawStr(Point& position, const char* str, int length){
		TextOut(_backBuffer, (int) position.GetX(), (int) position.GetY(), str, length);
	}

	void Graphics::setTextColor(COLORREF color){
		SetTextColor(_backBuffer, color);
	}

	void Graphics::setTextBackgroundColor(COLORREF color){
		SetBkColor(_backBuffer, color);
	}

	void Graphics::drawRect(Point& one, Point& two){
		this->drawRect((int)one.GetX(),(int) one.GetY(),(int) two.GetX(),(int) two.GetY());
	}

	void Graphics::drawRect(int xone, int yone, int xtwo, int ytwo){
		Rectangle(_backBuffer, xone, yone, xtwo, ytwo);
	}
}
