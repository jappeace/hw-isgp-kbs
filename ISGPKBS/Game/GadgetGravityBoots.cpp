#include "GadgetGravityBoots.h"
#include "GravityBootsBehaviour.h"

namespace isgp {
	GadgetGravityBoots::GadgetGravityBoots(Vector2D position, Player* player) {
		this->SetSize(new Vector2D(16, 16));
		this->_position = position;
		this->_player = player;
		this->_pickedUp = false;
		this->_finished = false;
		this->_pickedUpTime = 0.0;
		this->_activationTime = 5000;
		this->_gravityBootsBehaviour = new GravityBootsBehaviour(_player);
		this->_bounceHeight = 0.75;
		this->_spawnPos = _position.Y();
		this->_vel = 0;
		this->_up = true;
	}

	GadgetGravityBoots::~GadgetGravityBoots(void) {
		delete this->GetSize();
	}

	void GadgetGravityBoots::OnCollide() {
		if(_pickedUp)
			return;
		_player->Set_has_gravity_boots(true);
		_pickedUp = true;
		_player->AddBehaviour(_gravityBootsBehaviour);
	}


	void GadgetGravityBoots::Update(const double tpf) {
		Gadget::Update(tpf);
		if (!_finished && _pickedUp) {
			_pickedUpTime += tpf;
			if(_pickedUpTime > _activationTime) {
				_finished = true;
				_player->Set_has_gravity_boots(false);
				_player->RemoveBehaviour(_gravityBootsBehaviour);
			}
		} else if (!_pickedUp) {
			if (_position.Y() > _spawnPos + _bounceHeight) {
				_up = true;
			} else if (_position.Y() < _spawnPos - _bounceHeight) {
				_up = false;
			}
			
			if (_up && _vel > -_bounceHeight) {
				_vel -= (tpf / 200);
			} else if (_vel < _bounceHeight) {
				_vel += (tpf / 200);
			}

			_position.Y(_position.Y() + _vel);
		}
	}

	void GadgetGravityBoots::Paint(Graphics* g) {
		if(!_pickedUp)
			g->DrawBitmap("../tiles/gravityBoots.bmp", this->_position);
	}
}
