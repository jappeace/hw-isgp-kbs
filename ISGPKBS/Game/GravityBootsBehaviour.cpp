#include "GravityBootsBehaviour.h"
#include "CollisionDetection.h"
namespace isgp {
	static const double GRAVITATIONAL_PULL = (double) 2000;

	GravityBootsBehaviour::GravityBootsBehaviour(Entity* entity) {
		this->_entity = entity;
	}

	GravityBootsBehaviour::~GravityBootsBehaviour(void) {
	}

	double GravityBootsBehaviour::CalculateGravity(const double ms) {
		const double TIME_MULTIPLIER = ms / (double) 2000;

		// The calculation needs to keep in mind that the applied gravity will get removed by 1 unit per second.
		double gravity = TIME_MULTIPLIER * GRAVITATIONAL_PULL; // The amount of velocity which should be applied at this update
		return gravity;
	}

	void GravityBootsBehaviour::Update(const double ms) {
		if (_entity->GetCollision() & Down) {
			// The character is on a platform so we don't apply gravity to that.
			return;
		}

		// Calculate downward motion
		

		// Apply downward motion onto character
		_entity->AddToVelocityY(-CalculateGravity(ms));
	}
}
