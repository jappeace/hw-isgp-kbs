#include "gravitybehaviour.h"
#include "CollisionDetection.h"
namespace isgp {
	static const double GRAVITATIONAL_PULL = (double) 2000;

	GravityBehaviour::GravityBehaviour(Player* player) {
		this->_player = player;
	}

	GravityBehaviour::~GravityBehaviour(void) {
	}

	double GravityBehaviour::CalculateGravity(const double ms) {
		const double TIME_MULTIPLIER = ms / (double) 1000;

		// The calculation needs to keep in mind that the applied gravity will get removed by 1 unit per second.
		double gravity = TIME_MULTIPLIER * GRAVITATIONAL_PULL; // The amount of velocity which should be applied at this update
		return gravity;
	}

	void GravityBehaviour::Update(const double ms) {
		if (_player->GetCollision() & Down) {
			// The character is on a platform so we don't apply gravity to that.
			OutputDebugString("Down\n");
			return;
		}

		// Calculate downward motion
		

		// Apply downward motion onto character
		_player->AddToVelocityY(CalculateGravity(ms));
	}
}
