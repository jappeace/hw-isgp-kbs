#include "BackgroundArtist.h"

namespace isgp{
	BackgroundArtist::BackgroundArtist(Camera* cam, Level* level)
	{
		_background = new Sprite(
			GridGraphicTranslator().FromTo(
				*level->GetGrid()->GetSize()
			)
		);
		_cam = cam;
		_level = level;
		_quil = new SpriteGraphics(_background);
	}
	BackgroundArtist::~BackgroundArtist(void)
	{
		// don't delete level because we did not create it
		if(_background){
			delete _background;
		}
		if(_quil){
			delete _quil;
		}
	}
	void BackgroundArtist::RenderBackground(void){
		_quil->BeginRendering();
		_level->GetGrid()->TraverseTiles(this);
		_quil->EndRendering();
		_background->GenerateMask();
	}
	void BackgroundArtist::Paint(Graphics* g) {
		g->DrawSprite(_background,_cam->ToFrom(Vector2D()), _cam->GetPosition() - Vector2D(384,384), Size(AbstractWindow::WindowSize));
	}
	void BackgroundArtist::ReceiveTile(Tile* tile) {
#ifdef _DEBUG
		Vector2D position = *tile->GetPosition() * Level::tileSize;
		_quil->DrawLine(position, position + Vector2D(Level::tileSize.GetWidth(), 0));
		_quil->DrawLine(position, position + Vector2D(0, Level::tileSize.GetHeight()));
#endif
		tile->Paint(_quil);
	}

}