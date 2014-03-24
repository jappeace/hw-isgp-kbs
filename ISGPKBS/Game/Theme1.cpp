#include "Theme1.h"

namespace isgp {
	Theme1::Theme1()
	{
		_tilePath = "../tiles/ground4.bmp";
		_bg1 = "../tiles/mountain.bmp";
		_bg2 = "../tiles/ground.bmp";
		_loadFilePath = "../tiles/theme1.bmp";
	}

	Theme1::~Theme1(void)
	{
		
	}

	void Theme1::LoadContent(Graphics* g) {
		g->LoadBitmapFile(_tilePath);
		g->LoadBitmapFile(_bg1);
		g->LoadBitmapFile(_bg2);
	}

	void Theme1::SetWidth(double width) {
		_gridWidth = width;
	}

	string Theme1::GetTilePath() {
		return _tilePath;
	}

	void Theme1::Paint(Graphics* g) {
		const Size windowSize(800, 600);

		int imgWidth = 1920;
		int imgHeight1 = 791;
		int imgHeight2 = 321;

		double width1 = (_gridWidth * 1.5) + windowSize.GetWidth();
		double width2 = (_gridWidth * 1.75) + windowSize.GetWidth();

		Vector2D fix = ((windowSize - Player::InitSize) * Vector2D(1.0,1.35)) / Vector2D(2);

		//Draw sky
		Camera* cam = (Camera*)g->GetTranslator();
		double x, y;
		if (cam) {
			x = cam->GetPosition().X();
			y = cam->GetPosition().Y();
		} else {
			x = 0;
			y = 0;
		}
		for (int i = 0; i < width1; i += imgWidth) {
			g->DrawBitmap(_bg1,
				Vector2D(((x - fix.X()) * 0.5) + i,
				(y - fix.Y()) * 0.5),
				Size(imgWidth, imgHeight1));
		}

		//Draw ground
		for (int i = 0; i < width2; i += imgWidth) {
			g->DrawBitmap(_bg2,
				Vector2D(((x - fix.X()) * 0.25) + i,
				(y + 2000) * 0.25),
				Size(imgWidth, imgHeight2));
		}
	}
}
