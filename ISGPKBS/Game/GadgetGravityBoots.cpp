#include "GadgetGravityBoots.h"

namespace isgp {

	GadgetGravityBoots::GadgetGravityBoots(void) {
		this->SetSize(new Vector2D(16, 16));
	}

	GadgetGravityBoots::~GadgetGravityBoots(void) {
		delete this->GetSize();
	}

	void GadgetGravityBoots::Update(const double tpf) {

	}

	void GadgetGravityBoots::Paint(Graphics* g) {
	}
}
