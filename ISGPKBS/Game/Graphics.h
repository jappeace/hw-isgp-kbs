#pragma once

#include <windows.h>

namespace isgp {
	class Graphics
	{
	private:
		/**
		 * The device context which is visible on the screen
		 */
		HDC _hdc;
		/**
		 * The hidden device context on which we render to prevent flickering
		 */
		HDC _backBuffer;
		/**
		 * The bitmap on which we are actually rendering in the background
		 */
		HBITMAP _bitmap;
		/**
		 * Not sure what purpose this one has, need to check that
		 */
		HBITMAP _oldBitmap;

	public:
		Graphics(HWND);
		~Graphics(void);

		/**
		 * Prepares the device context to start rendering
		 */
		void BeginRendering(HWND, PAINTSTRUCT *);
		/**
		 * Ends the rendering state and draws the backbuffer onto the screen
		 */
		void EndRendering(HWND, PAINTSTRUCT *);
	};
}
