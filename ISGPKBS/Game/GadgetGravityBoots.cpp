#include "GadgetGravityBoots.h"
#include "GravityBootsBehaviour.h"

namespace isgp {
	GadgetGravityBoots::GadgetGravityBoots(Vector2D position, Player* player) {
		this->SetSize(new Vector2D(16, 16));
		this->_position = position;
		this->_player = player;
		this->_pickedUp = false;
	}

	GadgetGravityBoots::~GadgetGravityBoots(void) {
		delete this->GetSize();
	}

	void GadgetGravityBoots::OnCollide() {
		if(_pickedUp)
			return;
		_pickedUp = true;
		_player->AddBehaviour(new GravityBootsBehaviour(_player));
	}


	void GadgetGravityBoots::Update(const double tpf) {
		Gadget::Update(tpf);
	}

	void GadgetGravityBoots::Paint(Graphics* g) {
		if(!_pickedUp)
			g->DrawBitmap(".\\tiles\\gravityBoots.bmp", this->_position);
	}
}
