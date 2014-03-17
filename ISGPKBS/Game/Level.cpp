#include "Level.h"
#include "GridGraphicTranslator.h"
#include "Camera.h"
namespace isgp{
// default amount of tiles in level
const Size Level::defaultTileAmount = Size(500,30);

// tile size, should equal the width and height of spritesheet tiles
const Size	Level::tileSize = Size(TILE_WIDTH, TILE_HEIGHT);
	Level::Level(){
		_grid = new Grid(defaultTileAmount.GetWidth(), defaultTileAmount.GetHeight());
	}
	Level::Level(int width, int height) {
		_grid = new Grid(width, height);
	}
	Level::Level(Grid* grid) {
		_grid = grid;
	}

	Level::~Level(void)
	{
		if(_grid){
			delete _grid;
		}
	}

	void Level::Update(double elapsed) {
		// Update player
		_player->Update(elapsed);

		// Update gadgets
		for (auto it = gadgets.begin(); it != gadgets.end(); ++it) {
			(*it)->Update(elapsed);
		}
		// Update enemies.
		for (auto it = enemies.begin(); it != enemies.end(); ++it) {
			(*it)->Update(elapsed);
		}
	}

	void Level::Paint(Graphics* g) {
		Size windowSize(800, 600);
		double width1 = (GridGraphicTranslator().FromTo(*GetGrid()->GetSize()).X() * 0.5) + windowSize.GetWidth();
		double width2 = (GridGraphicTranslator().FromTo(*GetGrid()->GetSize()).X() * 0.75) + windowSize.GetWidth();

		Vector2D fix = ((windowSize - Player::InitSize) * Vector2D(1.0,1.35)) / Vector2D(2);

		//Draw sky
		Camera* cam = (Camera*)g->_cam;
		for (int i = 0; i < width1; i += 1920) {
			g->DrawBitmap("../tiles/mountain.bmp",
				Vector2D(((cam->GetPosition().X() - fix.X()) * 0.5) + i,
				(cam->GetPosition().Y() - fix.Y()) * 0.5),
				Size(1920, 791));
		}

		//Draw ground
		for (int i = 0; i < width2; i += 1920) {
			g->DrawBitmap("../tiles/ground.bmp",
				Vector2D(((cam->GetPosition().X() - fix.X()) * 0.25) + i,
				(cam->GetPosition().Y() + 2000) * 0.25),
				Size(1920, 321));
		}

		_graphics = g;
		_grid->TraverseTiles(this);
		_player->Paint(g);
		// Update gadgets
		for (auto it = gadgets.begin(); it != gadgets.end(); ++it) {
			(*it)->Paint(g);
		}
		// Update enemies.
		for (auto it = enemies.begin(); it != enemies.end(); ++it) {
			(*it)->Paint(g);
		}
	}
	void Level::ReceiveTile(Tile* tile) {
#ifdef _DEBUG
		Vector2D position = *tile->GetPosition();
		position.X(position.X() * Level::tileSize.GetWidth());
		position.Y(position.Y() * Level::tileSize.GetHeight());

		_graphics->DrawRect(
			position, 
			Vector2D(
				position.X() + Level::tileSize.GetWidth(),
				position.Y() + Level::tileSize.GetHeight()
			)
		);
#endif
		tile->Paint(_graphics);
	}
	Grid* Level::GetGrid() const{
		return _grid;
	}
}
