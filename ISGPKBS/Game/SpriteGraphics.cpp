#include "SpriteGraphics.h"
#include "AbstractWindow.h" // loopfix
namespace isgp {

	SpriteGraphics::SpriteGraphics(Sprite* sprite) {
		Init();
		_target = sprite;
	}
	void SpriteGraphics::BeginRendering(){
		this->_visibleHdc = CreateCompatibleDC(NULL);
		::SelectObject(this->_visibleHdc, _target->GetBitmap());
		Graphics::FillRect(this->_visibleHdc, Vector2D(), _target->GetSize(), _target->GetTransparant());
	}

	void SpriteGraphics::EndRendering(){
		::DeleteDC(this->_visibleHdc);
	}

	HDC SpriteGraphics::getHDC(){
		return this->_visibleHdc;

	}
}
