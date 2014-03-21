#include "SpriteGraphics.h"
#include "AbstractWindow.h" // loopfix
namespace isgp {

	SpriteGraphics::SpriteGraphics(Sprite* sprite) {
		Init();
		_target = sprite;
	}
	void SpriteGraphics::BeginRendering(){
		this->_target->CreateMaskBitmap();
		this->_visibleHdc = CreateCompatibleDC(NULL);
		this->_maskHdc = CreateCompatibleDC(NULL);
		::SelectObject(this->_maskHdc, _target->GetMask());
		BitBlockTransfer(this->_maskHdc, Vector2D(), _target->GetSize(), NULL, NULL, WHITENESS);

		::SelectObject(this->_visibleHdc, _target->GetBitmap());
		BitBlockTransfer(this->_visibleHdc, Vector2D(), _target->GetSize(), NULL, NULL, BLACKNESS);
	}

	void SpriteGraphics::EndRendering(){
		::DeleteDC(this->_maskHdc);
		::DeleteDC(this->_visibleHdc);
	}

	HDC SpriteGraphics::getHDC(){
		return this->_visibleHdc;
	}
	void SpriteGraphics::DrawSprite(Sprite* sprite, Vector2D position, Vector2D& offset, Size& size) {
		HDC img_hdc = CreateCompatibleDC(NULL);
		// link the bitmap to a device context
		::SelectObject(img_hdc, sprite->GetMask());
		BitBlockTransfer(
			// Dest Context
			this->_maskHdc, 
			// Position
			position,
			size, 
			// Source Context
			img_hdc, 
			offset,
			SRCCOPY);
		::SelectObject(img_hdc, sprite->GetBitmap());
		BitBlockTransfer(
			// Dest Context
			this->_visibleHdc, 
			// Position
			position,
			size, 
			// Source Context
			img_hdc, 
			offset,
			SRCCOPY);
		::DeleteDC(img_hdc);
	}
}
