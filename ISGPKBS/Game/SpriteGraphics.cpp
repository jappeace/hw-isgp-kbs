#include "SpriteGraphics.h"
#include "AbstractWindow.h" // loopfix
namespace isgp {

	SpriteGraphics::SpriteGraphics(Sprite* sprite) {
		Init();
		_target = sprite;
	}
	void SpriteGraphics::BeginRendering(){
		this->_visibleHdc = CreateCompatibleDC(NULL);
		HGDIOBJ h = ::SelectObject(this->_visibleHdc, _target->GetBitmap());
		BitBlockTransfer(this->_visibleHdc, Vector2D(), _target->GetSize(), NULL, NULL, WHITENESS);
	}

	void SpriteGraphics::EndRendering(){
		::DeleteDC(this->_visibleHdc);
	}

	HDC SpriteGraphics::getHDC(){
		return this->_visibleHdc;

	}

	void SpriteGraphics::DrawSprite(Sprite* sprite, Vector2D& position, Vector2D& offset, Size& size){

		Vector2D correctedVector2D = position;

		if (_translator != NULL) {
			correctedVector2D = _translator->FromTo(position);
		}

		HDC bitmap_hdc = CreateCompatibleDC(NULL);

		// link the bitmap to a device context
		::SelectObject(bitmap_hdc, sprite->GetMask());

		// OR the image on the mask to apply transparancy
		BitBlockTransfer(
			// Dest Context
			getHDC(), 
			// Position
			correctedVector2D,
			size, 
			// Source Context
			bitmap_hdc, 
			offset,
			SRCAND);

		// link the bitmap to a device context
		::SelectObject(bitmap_hdc, sprite->GetBitmap());

		// OR the image on the mask to apply transparancy
		BitBlockTransfer(
			// Dest Context
			getHDC(), 
			// Position
			correctedVector2D,
			size,
			// Source Context
			bitmap_hdc, 
			offset,
			// Operation
			SRCPAINT);

		// release the resource
		DeleteDC(bitmap_hdc);
	}
}
