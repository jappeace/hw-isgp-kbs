#include "Sprite.h"
#include "Graphics.h"
namespace isgp {

	const int Sprite::kKeyColor = 0xff00ff; // Transparancy key color
	Sprite::Sprite(const Size& s) {
		HDC forCreation = CreateCompatibleDC(NULL);
		BITMAPINFO i;
		ZeroMemory( &i.bmiHeader, sizeof(BITMAPINFOHEADER) );
		i.bmiHeader.biWidth=s.GetWidth(); // Set size you need
		i.bmiHeader.biHeight=s.GetHeight(); // Set size you need
		i.bmiHeader.biPlanes=1;
		i.bmiHeader.biBitCount=24; // Can be 8, 16, 32 bpp or
		// other number
		i.bmiHeader.biSizeImage=0;
		i.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
		i.bmiHeader.biClrUsed= 0;
		i.bmiHeader.biClrImportant= 0;
		VOID *pvBits;
		HBITMAP b = CreateDIBSection(forCreation, &i, DIB_RGB_COLORS, &pvBits, NULL, 0 );
		::BitBlt(forCreation, 0, 0, s.GetWidth(), s.GetHeight(), NULL, NULL, NULL, WHITENESS);
		//Graphics::FillRect(forCreation, Vector2D(0,0),s,kKeyColor);
		DeleteDC(forCreation);
		Init(b);
	}

	Sprite::Sprite(HBITMAP bitmap)
	{
		Init(bitmap);
		GenerateMask();
	}
	void Sprite::Init(HBITMAP bitmapPointer){
		_image = bitmapPointer;
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
		HDC sourceHDC = CreateCompatibleDC(NULL);
		SelectObject(sourceHDC, this->_image);

		// Create variables to create the mask
		HDC maskHDC = CreateCompatibleDC(NULL);
		this->_mask = CreateCompatibleBitmap(maskHDC, from.bmWidth, from.bmHeight);
		SelectObject(maskHDC, this->_mask);

		// Define some constants which contain the values for transparancy correction.
		static const int kPreserveColor  = 0xffffff; // A color which honors the backbuffer data instead of the image
		static const int kOverwriteColor = 0x000000; // A color which honors the image data instead of the backbuffer
		static const int kBlack          = kOverwriteColor; // The hex value of the color black

		// Generate alpha-mask and overwrite image pixels if needed.
		for (int y = 0; y < from.bmHeight; ++y) {
			for (int x = 0; x < from.bmWidth; ++x) {
				int color = GetPixel(sourceHDC, x, y);
				if (color == kKeyColor) {
					SetPixel(sourceHDC, x, y, kBlack); // Set to BLACK to prevent any color merging to happen
					SetPixel(maskHDC, x, y, kPreserveColor);
				} else {
					SetPixel(maskHDC, x, y, kOverwriteColor);
				}
			}
		}

		// Clean up no longer needed resources
		DeleteDC(sourceHDC);
		DeleteDC(maskHDC);
	}
	Size Sprite::GetSize(){
		BITMAP b = DereferenceBitmap(this->_image);
		return Size(b.bmWidth, b.bmHeight);
	}

	COLORREF Sprite::GetTransparant(){
		return Sprite::kKeyColor;
	}
}