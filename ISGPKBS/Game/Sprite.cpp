#include "Sprite.h"

namespace isgp {

	const int Sprite::kKeyColor = 0xff00ff; // Transparancy key color
	Sprite::Sprite(const Size& s) {
		HDC forCreation = CreateCompatibleDC(NULL);
		Init(
			CreateCompatibleBitmap(
				forCreation,
				s.GetWidth(),
				s.GetHeight()
			)
		);
		DeleteDC(forCreation);
	}

	Sprite::Sprite(HBITMAP bitmap)
	{
		Init(bitmap);
	}
	void Sprite::Init(HBITMAP bitmapPointer){
		_image = bitmapPointer;
		GenerateMask();
	}

	BITMAP Sprite::DereferenceBitmap(HBITMAP pointer){
		BITMAP result;
		GetObject(pointer, sizeof(BITMAP), &result);
		return result;
	}

	Sprite::~Sprite(void) {
		DeleteObject(this->_image);
		DeleteObject(this->_mask);
	}

	HBITMAP Sprite::GetBitmap() {
		return _image;
	}

	HBITMAP Sprite::GetMask() {
		return _mask;
	}
	void Sprite::GenerateMask(){
		BITMAP from = DereferenceBitmap(_image);
		HDC imgHDC = CreateCompatibleDC(NULL);
		SelectObject(imgHDC, this->_image);

		// Create variables to create the mask
		BITMAP mask;
		HDC tmpHDC = CreateCompatibleDC(NULL);
		this->_mask = CreateCompatibleBitmap(tmpHDC, from.bmWidth, from.bmHeight);
		GetObject(this->_mask, sizeof(BITMAP), &mask);
		SelectObject(tmpHDC, this->_mask);

		// Define some constants which contain the values for transparancy correction.
		static const int kPreserveColor  = 0xffffff; // A color which honors the backbuffer data instead of the image
		static const int kOverwriteColor = 0x000000; // A color which honors the image data instead of the backbuffer
		static const int kBlack          = 0x000000; // The hex value of the color black

		// Generate alpha-mask and overwrite image pixels if needed.
		for (int y = 0; y < from.bmHeight; ++y) {
			for (int x = 0; x < from.bmWidth; ++x) {
				int color = GetPixel(imgHDC, x, y);
				if (color == kKeyColor) {
					SetPixel(imgHDC, x, y, kBlack); // Set to BLACK to prevent any color merging to happen
					SetPixel(tmpHDC, x, y, kPreserveColor);
				} else {
					SetPixel(tmpHDC, x, y, kOverwriteColor);
				}
			}
		}

		// Clean up no longer needed resources
		DeleteDC(imgHDC);
		DeleteDC(tmpHDC);
	}
	Size Sprite::GetSize(){
		BITMAP b = DereferenceBitmap(this->_image);
		return Size(b.bmWidth, b.bmHeight);
	}

	COLORREF Sprite::GetTransparant(){
		return Sprite::kKeyColor;
	}
}