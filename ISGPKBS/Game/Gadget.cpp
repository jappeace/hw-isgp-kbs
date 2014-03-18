#include "Gadget.h"
#include "CollisionHelper.h"

namespace isgp {
	void Entity::AddToVelocityY(double d) {

	}

	void Gadget::Update(const double ms) {
		double x = _player->GetPosition().X();
		double y = _player->GetPosition().Y();
		double w = _player->GetSize()->X();
		double h = _player->GetSize()->Y();
		double x0 = _position.X();
		double y0 = _position.Y();

		if (CollisionHelper::IsColliding(_position, *_size, _player->GetPosition(), *_player->GetSize())) {
			OnCollide();
		}
	}
}