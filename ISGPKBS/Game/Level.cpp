#include "Camera.h"
#include "CollisionHelper.h"
#include "GridGraphicTranslator.h"
#include "Level.h"
#include "PlayingGameState.h"

namespace isgp{
// default amount of tiles in level
const Size Level::defaultTileAmount = Size(500,30);

// tile size, should equal the width and height of spritesheet tiles
const Size	Level::tileSize = Size(TILE_WIDTH, TILE_HEIGHT);
	Level::Level(){
		Init();
		_grid = new Grid(defaultTileAmount.GetWidth(), defaultTileAmount.GetHeight());
		_timePlayed = 0;
	}

	Level::Level(int width, int height) {
		Init();
		_grid = new Grid(width, height);
		_timePlayed = 0;
	}

	Level::Level(Grid* grid) {
		Init();
		_grid = grid;
	}

	void Level::Init() {
		start = NULL;
		_player = NULL;
		_theme = NULL;
		_timePlayed = 0;
	}

	Level::~Level(void)
	{
		delete _grid;
		delete start;
		delete _player;
		delete _theme;
		for (auto it = entities.begin(); it != entities.end(); ++it) {
			delete (*it);
		}
	}

	double Level::GetPlayTime() {
		return _timePlayed;
	}

	void Level::Update(double elapsed) {
		// Update player
		_timePlayed += elapsed;
		_player->Update(elapsed);
		finish->Update(elapsed);
		// Update enemies.
		for (auto it = entities.begin(); it != entities.end(); ++it) {
			(*it)->Update(elapsed);
		}
	}

	void Level::LoadContent(Graphics* g) {
		_theme->LoadContent(g);
	}

	void Level::Paint(Graphics* g) {
		finish->Paint(g);
		
		// Update entities.

		for (auto it = entities.begin(); it != entities.end(); ++it) {
			(*it)->Paint(g);
		}
		if(PlayingGameState::_debugMode)
	{
		double tileSize = TILE_WIDTH;
		double height = _grid->GetSize()->Y()*tileSize;
		
		double width = _grid->GetSize()->X()*tileSize;
		for(double i = tileSize; i<width;i+=tileSize)
		{
			g->DrawLine(Vector2D(i,0.0),Vector2D(i,height));
		}
		
		for(double i = tileSize; i<height;i+=tileSize)
		{
			g->DrawLine(Vector2D(0.0,i),Vector2D(width,i));
		}


		
	}
		_player->Paint(g);
		string elapsed = TimeFormatter::FormatTime(_timePlayed);
		g->DrawStr(Vector2D(730,10), elapsed);
	}

	bool Level::IsFinished() {
		return CollisionHelper::IsColliding(_player->GetPosition(), *_player->GetSize(), finish->GetPosition(), Size(16, 16));
	}

	Grid* Level::GetGrid() const{
		return _grid;
	}
	int Level::GetStageNumber(){
		return _stagenr;
	}
	void Level::SetStageNumber(int nr){
		_stagenr = nr;
	}
}
