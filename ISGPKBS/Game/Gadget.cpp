#include "Gadget.h"

namespace isgp {
	void Entity::AddToVelocityY(double d) {

	}

	void Gadget::Update(const double ms) {
		double collisionRange = sqrt(pow(_position.X() - _player->GetPosition().X(), 2) + pow(_position.Y() - _player->GetPosition().Y(), 2));

		if (collisionRange < 26) {
			OnCollide();
		}
	}
}