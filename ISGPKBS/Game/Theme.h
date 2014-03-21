#pragma once

#include "Level.h"

namespace isgp {
	class Theme {
	public:
		virtual ~Theme(void) {}
		virtual void LoadContent(Graphics*) = 0;
		virtual void SetWidth(double) = 0;
		virtual void Paint(Graphics*) = 0;
		virtual string GetTilePath() = 0;
		string GetLoadPath() { return _loadFilePath; }
		static Theme* CreateTheme(int nr);
	protected:
		double _gridWidth;
		string _tilePath;
		string _bg1;
		string _bg2;
		string _bg3;
		string _bg4;

		// Image shown when loading a level with this theme.
		string _loadFilePath;
	};
}
