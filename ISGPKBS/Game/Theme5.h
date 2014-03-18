#pragma once

#include "Theme.h"
#include "Camera.h"

namespace isgp {
	class Theme5 : public Theme
	{
	public:
		Theme5();
		~Theme5(void);
		void LoadContent(Graphics*, double) override;
		void Paint(Graphics*) override;
		string GetTilePath() override;
	};
}

