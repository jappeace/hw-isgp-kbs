#include "Theme4.h"

namespace isgp {
	Theme4::Theme4()
	{
		_tilePath = "../tiles/ground5.bmp";
		_bg1 = "../tiles/cbg1.bmp";
		_bg2 = "../tiles/cbg2.bmp";
		_bg3 = "../tiles/cbg3.bmp";
		_bg4 = "../tiles/cbg4.bmp";
	}

	Theme4::~Theme4(void)
	{

	}

	void Theme4::LoadContent(Graphics* g) {
		g->LoadBitmapFile(_bg1);
		g->LoadBitmapFile(_bg2);
	}

	void Theme4::SetWidth(double width) {
		_gridWidth = width;
	}

	string Theme4::GetTilePath() {
		return _tilePath;
	}

	void Theme4::Paint(Graphics* g) {
		const Size windowSize(800, 600);

		int imgWidth = 1055;
		int imgHeight1 = 791;
		int imgHeight2 = 791;
		
		double width1 = (_gridWidth * 0.2) + AbstractWindow::WindowSize.GetWidth();
		double width2 = (_gridWidth * 0.4) + AbstractWindow::WindowSize.GetWidth();
		double width3 = (_gridWidth * 0.6) + AbstractWindow::WindowSize.GetWidth();
		double width4 = (_gridWidth * 0.8) + AbstractWindow::WindowSize.GetWidth();

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
				Vector2D(((x - fix.X()) * 0.8) + i,
				(y - fix.Y()) * 0.4),
				Size(imgWidth, imgHeight1));
		}
		
		//Draw ground
		for (int i = 0; i < width1; i += imgWidth) {
			g->DrawBitmap(_bg2,
				Vector2D(((x - fix.X()) * 0.6) + i,
				(y - fix.Y() + 500) * 0.3),
				Size(imgWidth, imgHeight1));
		}
		
		//Draw ground
		for (int i = 0; i < width1; i += imgWidth) {
			g->DrawBitmap(_bg3,
				Vector2D(((x - fix.X()) * 0.4) + i,
				(y - fix.Y() + 500) * 0.2),
				Size(imgWidth, imgHeight1));
		}
		
		//Draw ground
		for (int i = 0; i < width1; i += imgWidth) {
			g->DrawBitmap(_bg4,
				Vector2D(((x - fix.X()) * 0.2) + i,
				(y - fix.Y() + 500) * 0.1),
				Size(imgWidth, imgHeight1));
		}
	}
}
