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
		_quil = new Graphics();
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
		_quil->BeginRendering(_background);
		_quil->FillRect(Vector2D(), _background->GetSize(), _background->GetTransparant());
		_level->GetGrid()->TraverseTiles(this);
		_background->GenerateMask();
		_quil->EndRendering();
	}
	void BackgroundArtist::Paint(Graphics* g) {
		g->DrawSprite(_background,Vector2D(), Vector2D(), Size(AbstractWindow::WindowSize));
	}
	void BackgroundArtist::ReceiveTile(Tile* tile) {
#ifdef _DEBUG
		Vector2D position = *tile->GetPosition();
		position.X(position.X() * Level::tileSize.GetWidth());
		position.Y(position.Y() * Level::tileSize.GetHeight());

		_quil->DrawRect(
			position, 
			Vector2D(
				position.X() + Level::tileSize.GetWidth(),
				position.Y() + Level::tileSize.GetHeight()
			)
		);
#endif
		tile->Paint(_quil);
	}

}