#pragma once

#include "Level.h"

namespace isgp {
	class Theme {
	public:
		virtual ~Theme(void) {}
	protected:
		double _gridWidth;
		string _tilePath;
		string _bg1;
		string _bg2;
		string _bg3;
		string _bg4;
	public:
		virtual void LoadContent(Graphics*) = 0;
		virtual void SetWidth(double) = 0;
		virtual void Paint(Graphics*) = 0;
		virtual string GetTilePath() = 0;
	};
}
