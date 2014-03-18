#include "Theme2.h"

namespace isgp {
	Theme2::Theme2()
	{
		_tilePath = "../tiles/ground3.bmp";
		_bg1 = "../tiles/bg2.bmp";
		_bg2 = "../tiles/bg2Bottom.bmp";
	}

	Theme2::~Theme2(void)
	{

	}

	void Theme2::LoadContent(Graphics* g, double width) {
		_gridWidth = width;

		g->LoadBitmapFile(_bg1);
		g->LoadBitmapFile(_bg2);
	}

	string Theme2::GetTilePath() {
		return _tilePath;
	}

	void Theme2::Paint(Graphics* g) {
		const Size windowSize(800, 600);

		int imgWidth = 1920;
		int imgHeight1 = 791;
		int imgHeight2 = 321;

		double width1 = (_gridWidth * 0.5) + windowSize.GetWidth();
		double width2 = (_gridWidth * 0.75) + windowSize.GetWidth();

		Vector2D fix = ((windowSize - Player::InitSize) * Vector2D(1.0,1.35)) / Vector2D(2);

		//Draw sky
		Camera* cam = (Camera*)g->GetTranslator();
		for (int i = 0; i < width1; i += imgWidth) {
			g->DrawBitmap(_bg1,
				Vector2D(((cam->GetPosition().X() - fix.X()) * 0.5) + i,
				(cam->GetPosition().Y() - fix.Y()) * 0.5),
				Size(imgWidth, imgHeight1));
		}

		//Draw ground
		for (int i = 0; i < width2; i += imgWidth) {
			g->DrawBitmap(_bg2,
				Vector2D(((cam->GetPosition().X() - fix.X()) * 0.25) + i,
				(cam->GetPosition().Y() + 2000) * 0.25),
				Size(imgWidth, imgHeight2));
		}
	}
}
