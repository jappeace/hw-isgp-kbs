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

	for (int y = 0; y < image.bmHeight; ++y) {
		for (int x = 0; x < image.bmWidth; ++x) {
			int color = GetPixel(imgHDC, x, y);
			if (color == 0xff00ff) {
				SetPixel(imgHDC, x, y, 0x000000);
				SetPixel(tmpHDC, x, y, 0xffffff);
			} else {
				SetPixel(tmpHDC, x, y, 0x000000);
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
