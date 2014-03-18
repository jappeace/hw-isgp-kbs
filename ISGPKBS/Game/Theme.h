#pragma once

#include "Level.h"

namespace isgp {
	class Theme {
	protected:
		double _gridWidth;
		string _tilePath;
		string _bg1;
		string _bg2;
		string _bg3;
		string _bg4;
	public:
		virtual void LoadContent(Graphics*, double) = 0;
		virtual void Paint(Graphics*) = 0;
		virtual string GetTilePath() = 0;
	};
}
