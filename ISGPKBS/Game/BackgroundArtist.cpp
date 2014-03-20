#include "BackgroundArtist.h"

namespace isgp{
	BackgroundArtist::BackgroundArtist(Camera* cam, Level* level, SpriteCache<int>* cache)
	{

		_background = NULL;
		_quil = NULL;
		_cam = cam;
		_level = level;
		_cache = cache;
	}
	BackgroundArtist::~BackgroundArtist(void)
	{
		// don't delete level because we did not create it
		if(_quil){
			delete _quil;
		}
	}
	void BackgroundArtist::RenderBackground(void){
		// first check if there is somthing in cache
		if(_cache->IsAt(_level->GetStageNumber())){
			_background = (*_cache)[_level->GetStageNumber()];
			// ifso we can stop right here
			return;
		}

		// to bad we have to do rendering, initilize the necisary objects
		if(_background == NULL){
			_background = new Sprite(
				GridGraphicTranslator().FromTo(
					*_level->GetGrid()->GetSize()
				)
			);
		}
		if(_quil == NULL){
			_quil = new SpriteGraphics(_background);
		}

		// do rendering
		_quil->BeginRendering();
		_level->GetGrid()->TraverseTiles(this);
		_quil->EndRendering();
		_background->GenerateMask(); // this call is actualy most work, but it allows transparancy

		// fill the cache, to speed up loading
		(*_cache)[_level->GetStageNumber()] = _background;
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