#include "Graphics.h"
namespace isgp {

	Graphics::Graphics(HWND hWnd) {
		this->_backBuffer = CreateCompatibleDC(NULL);

		//get the DC for the front buffer
		HDC hdc = GetDC(hWnd);

		// TODO: Retrieve actual window size
		this->_bitmap = CreateCompatibleBitmap(hdc, 800, 600);


		//select the bitmap into the memory device context
		this->_oldBitmap = (HBITMAP)SelectObject(this->_backBuffer, this->_bitmap);

		//don't forget to release the DC
		ReleaseDC(hWnd, hdc); 
	}


	Graphics::~Graphics(void)
	{
	}

	void Graphics::BeginRendering(HWND hWnd, PAINTSTRUCT *ps) {
		// Begin the drawing state of WIN32
		this->_hdc = BeginPaint(hWnd, ps);

		// Clear the backbuffer.
		BitBlt(this->_backBuffer,0, 0, 800, 600, NULL, NULL, NULL, WHITENESS);
	}

	void Graphics::EndRendering(HWND hWnd, PAINTSTRUCT *ps) {
		// Blit the new frame to the screen
		BitBlt(ps->hdc, 0, 0, 800, 600, this->_backBuffer, 0, 0, SRCCOPY);

		// End the drawing state of WIN32
		EndPaint(hWnd, ps);
	}
}
