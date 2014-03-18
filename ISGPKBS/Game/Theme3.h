#pragma once

#include "Theme.h"
#include "Camera.h"

namespace isgp {
	class Theme3 : public Theme
	{
	public:
		Theme3();
		~Theme3(void);
		void LoadContent(Graphics*, double) override;
		void Paint(Graphics*) override;
		string GetTilePath() override;
	};
}

