#include "gravitybehaviour.h"

namespace isgp {

	GravityBehaviour::GravityBehaviour(Player* player) {
		this->_player = player;
	}

	GravityBehaviour::~GravityBehaviour(void) {
	}

	void GravityBehaviour::Update(const double ms) {
		if (_player->_collision) {
			// The character is on a platform so we don't apply gravity to that.
			return;
		}

		// Calculate downward motion
		const double GRAVITATIONAL_PULL = (double) 2.45;
		const double TIME_MULTIPLIER = ms / (double) 1000;

		// The calculation needs to keep in mind that the applied gravity will get removed by 1 unit per second.
		double gravity = TIME_MULTIPLIER * GRAVITATIONAL_PULL; // The amount of velocity which should be applied at this update

		// Apply downward motion onto character
		_player->AddToVelocityY(GRAVITATIONAL_PULL);
	}
}
