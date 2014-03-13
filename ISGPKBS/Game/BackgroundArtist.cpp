#include "BackgroundArtist.h"

namespace isgp{
	BackgroundArtist::BackgroundArtist(Graphics* graphics, Camera* cam, Level* level)
	{
		_background = graphics->CreateLinkedGraphics(
			GridGraphicTranslator().FromTo(
				*level->GetGrid()->GetSize()
			)
		);
		_background->SetIsClearingBackbuffer(false);
		_cam = cam;
		_level = level;

	}
	BackgroundArtist::~BackgroundArtist(void)
	{
		// don't delete level because we did not create it
		delete _background;
	}
	void BackgroundArtist::RenderBackground(void){
		_level->GetGrid()->TraverseTiles(this);
	}
	void BackgroundArtist::Paint(Graphics* g) {
		_background->Update(_cam->GetPosition());
	}
	void BackgroundArtist::ReceiveTile(Tile* tile) {
#ifdef _DEBUG
		Vector2D position = *tile->GetPosition();
		position.X(position.X() * Level::tileSize.GetWidth());
		position.Y(position.Y() * Level::tileSize.GetHeight());

		_background->DrawRect(
			position, 
			Vector2D(
				position.X() + Level::tileSize.GetWidth(),
				position.Y() + Level::tileSize.GetHeight()
			)
		);
#endif
		tile->Paint(_background);
	}

}