#pragma once

#include <Windows.h>

class Sprite
{
public:
	Sprite(void);
	Sprite(HBITMAP bitmap);
	~Sprite(void);

	HBITMAP GetBitmap();
	HBITMAP GetMask();

private:
	HBITMAP _image;
	HBITMAP _mask;
	
};

