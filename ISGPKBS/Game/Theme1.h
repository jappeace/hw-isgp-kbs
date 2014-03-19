#pragma once

#include "Theme.h"
#include "Camera.h"

namespace isgp {
	class Theme1 : public Theme
	{
	public:
		Theme1();
		~Theme1(void);
		void LoadContent(Graphics*) override;
		void SetWidth(double) override;
		void Paint(Graphics*) override;
		string GetTilePath() override;
	};
}

