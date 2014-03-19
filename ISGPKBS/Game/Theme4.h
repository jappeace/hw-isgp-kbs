#pragma once

#include "Theme.h"
#include "Camera.h"

namespace isgp {
	class Theme4 : public Theme
	{
	public:
		Theme4();
		~Theme4(void);
		void LoadContent(Graphics*) override;
		void SetWidth(double) override;
		void Paint(Graphics*) override;
		string GetTilePath() override;
	};
}

