#pragma once

#include <Windows.h>
#include "Size.h"
namespace isgp {

	class Sprite
	{
	public:
		Sprite(const Size&);
		// Creates a sprite with an optional bitmask
		// If set to false sprite will not have an alpha channel
		Sprite(HBITMAP bitmap, bool generateMask);
		Sprite(HBITMAP bitmap);
		~Sprite(void);

		HBITMAP GetBitmap();
		HBITMAP GetMask();
		// calls the size of bitmap
		Size GetSize();
		// render an alpha mask, this is a O(bitmap.width * bitmap.height) operation, beware
		void GenerateMask();
		void GenerateMask(Vector2D topleft, Size size);
		COLORREF GetTransparant();
		static BITMAP DereferenceBitmap(HBITMAP);
	private:
		HBITMAP _image;
		HBITMAP _mask;
		// Creates an empty mask for the alpha
		void CreateMaskBitmap();
		static const int Sprite::kKeyColor;
		void Init(HBITMAP, bool);
	
	};
}
