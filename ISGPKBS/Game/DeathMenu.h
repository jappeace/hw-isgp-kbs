#pragma once

#include "ListMenu.h"
#include <vector>

namespace isgp {
	class DeathMenu : public ListMenu {
	public:
		~DeathMenu();
		void PaintDecoration(Graphics* g);
	};
}
