#include "Theme3.h"

namespace isgp {
	Theme3::Theme3()
	{
		_tilePath = "../tiles/ground2.bmp";
		_bg1 = "../tiles/bg3.bmp";
		_bg2 = "../tiles/bg3Bottom.bmp";
	}

	Theme3::~Theme3(void)
	{

	}

	void Theme3::LoadContent(Graphics* g) {
		g->LoadBitmapFile(_bg1);
		g->LoadBitmapFile(_bg2);
	}

	void Theme3::SetWidth(double width) {
		_gridWidth = width;
	}

	string Theme3::GetTilePath() {
		return _tilePath;
	}

	void Theme3::Paint(Graphics* g) {
		const Size windowSize(800, 600);

		int imgWidth = 1680;
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
