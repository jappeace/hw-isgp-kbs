#pragma once

#include "Theme.h"
#include "Camera.h"

namespace isgp {
	class Theme2 : public Theme
	{
	public:
		Theme2();
		~Theme2(void);
		void LoadContent(Graphics*, double) override;
		void Paint(Graphics*) override;
		string GetTilePath() override;
	};
}

