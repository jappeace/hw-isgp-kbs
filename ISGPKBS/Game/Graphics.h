#pragma once

#include <windows.h>

namespace isgp {
	class Graphics
	{
	private:
		HDC _hdc;
		HDC _backBuffer;
		HBITMAP _bitmap;
		HBITMAP _oldBitmap;

	public:
		Graphics(HWND);
		~Graphics(void);

		void BeginRendering(HWND, PAINTSTRUCT *);
		void EndRendering(HWND, PAINTSTRUCT *);
	};
}
