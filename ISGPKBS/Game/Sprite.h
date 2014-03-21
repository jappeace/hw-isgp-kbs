#pragma once

#include <Windows.h>
#include "Size.h"
namespace isgp {

	class Sprite
	{
	public:
		Sprite(const Size&);
		Sprite(HBITMAP bitmap);
		~Sprite(void);

		HBITMAP GetBitmap();
		HBITMAP GetMask();
		// calls the size of bitmap
		Size GetSize();
		// Creates an empty mask for the alpha
		void CreateMaskBitmap();
		// render an alpha mask, this is a O(bitmap.width * bitmap.height) operation, beware
		void GenerateMask();
		void GenerateMask(Vector2D topleft, Size size);
		COLORREF GetTransparant();
		static BITMAP DereferenceBitmap(HBITMAP);
	private:
		HBITMAP _image;
		HBITMAP _mask;
		static const int Sprite::kKeyColor;
		void Init(HBITMAP);
	
	};
}
