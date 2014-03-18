#include "Finish.h"

namespace isgp {

	Finish::Finish(Vector2D position)
	{
		_position = GridGraphicTranslator().FromTo(position);
		_animation = new Animation("../tiles/toad.bmp", Size(32, 32), 4, 150);
	}
	void Finish::Update(double elapsed) {
		_animation->OnUpdate(elapsed);
	}
	void Finish::Paint(Graphics* graphics) {
		_animation->Render(graphics, _position);
	}

	Vector2D Finish::GetPosition() {
		return _position;
	}

	Finish::~Finish(void)
	{
		delete _animation;
	}
}