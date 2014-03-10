#include "Sprite.h"

Sprite::Sprite(void) {
	this->_image = NULL;
	this->_mask = NULL;
}

Sprite::Sprite(HBITMAP bitmap)
{
	this->_image = bitmap;

	// Create mask
	BITMAP image;
	GetObject(this->_image, sizeof(BITMAP), &image);

	BITMAP mask = BITMAP();
	HDC imgHDC = CreateCompatibleDC(NULL);
	HDC tmpHDC = CreateCompatibleDC(NULL);
	this->_mask = CreateCompatibleBitmap(tmpHDC, image.bmWidth, image.bmHeight);
	GetObject(this->_mask, sizeof(BITMAP), &mask);

	SelectObject(imgHDC, this->_image);
	SelectObject(tmpHDC, this->_mask);

	static const int kKeyColor       = 0xff00ff; // Transparancy key color
	static const int kPreserveColor  = 0xffffff; // A color which honors the backbuffer data instead of the image
	static const int kOverwriteColor = 0x000000; // A color which honors the image data instead of the backbuffer
	static const int kBlack          = 0x000000; // The hex value of the color black

	for (int y = 0; y < image.bmHeight; ++y) {
		for (int x = 0; x < image.bmWidth; ++x) {
			int color = GetPixel(imgHDC, x, y);
			if (color == kKeyColor) {
				SetPixel(imgHDC, x, y, kBlack); // Set to BLACK to prevent any color merging to happen
				SetPixel(tmpHDC, x, y, kPreserveColor);
			} else {
				SetPixel(tmpHDC, x, y, kOverwriteColor);
			}
		}
	}

	DeleteDC(imgHDC);
	DeleteDC(tmpHDC);
}


Sprite::~Sprite(void)
{
}

HBITMAP Sprite::GetBitmap() {
	return _image;
}

HBITMAP Sprite::GetMask() {
	return _mask;
}
