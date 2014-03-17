#include "GadgetJumpPlatform.h"

namespace isgp {

	GadgetJumpPlatform::GadgetJumpPlatform(Vector2D position, Player* player) {
		this->_position = position;
		this->_player = player;
		this->_animation = new Animation("../tiles/jumpPad.bmp", Size(16, 16), 5, 100);
		this->_ms_till_next_launch = 0;
		this->SetSize(new Vector2D(16, 16));
	}

	GadgetJumpPlatform::~GadgetJumpPlatform(void) {
		delete this->GetSize();
		delete this->_animation;
	}

	void GadgetJumpPlatform::Update(const double tpf) {
		Gadget::Update(tpf);
		this->_animation->OnUpdate(tpf);

		if (this->_ms_till_next_launch > 0) {
			this->_ms_till_next_launch -= (int) tpf;
			return;
		}

		this->_animation->Reset();
	}

	void GadgetJumpPlatform::OnCollide() {
		if (!this->_player->IsColliding(Down))
			return;

		this->_ms_till_next_launch = 500;
		this->_player->GetVelocity()->Y(-800);
	}

	void GadgetJumpPlatform::Paint(Graphics* g) {
		this->_animation->Render(g, _position);
	}
}
