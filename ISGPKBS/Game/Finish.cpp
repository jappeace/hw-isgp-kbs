#include "Finish.h"

namespace isgp {

	Finish::Finish(Vector2D position, Player* player)
	{
		_player = player;
		_animationOffset = Vector2D();
		_position = GridGraphicTranslator().FromTo(position);
		_animation = new Animation("../tiles/toad.bmp", Size(32, 32), 4, 150);
	}
	void Finish::Update(double elapsed) {
		_animation->OnUpdate(elapsed);
		if(_position.X() > _player->GetPosition().X() && !_lastWasLeft) {
			_lastWasLeft = true;
			_animationOffset = Vector2D();
		} else if(_position.X() < _player->GetPosition().X() && _lastWasLeft) {
			_lastWasLeft = false;
			_animationOffset = Vector2D(160, 0);
		}
	}
	void Finish::Paint(Graphics* graphics) {
		_animation->Render(graphics, _position, _animationOffset);
	}

	Vector2D Finish::GetPosition() {
		return _position;
	}

	Finish::~Finish(void)
	{
		delete _animation;
	}
}