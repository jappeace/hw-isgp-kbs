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

	private:
		HBITMAP _image;
		HBITMAP _mask;

		void RenderMask(BITMAP& from);
		BITMAP dereferenceBitmap(HBITMAP);
		void init(HBITMAP);
	
	};
}
