#pragma once
#include "gadget.h"

namespace isgp {
	class GadgetJumpPlatform : public Gadget {

	public:
		GadgetJumpPlatform(Vector2D position, Player* player);
		~GadgetJumpPlatform(void);

		void Update(const double tpf) override;
		void OnCollide() override;
		void Paint(Graphics* g) override;

	private:
		Animation* _animation;
		int _ms_till_next_launch;
	};
}

