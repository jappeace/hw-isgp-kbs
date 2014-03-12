#include "SimpleLevelFactory.h"
#include "WorldBlock.h"
namespace isgp{

	SimpleLevelFactory::SimpleLevelFactory(void)
	{
	}


	SimpleLevelFactory::~SimpleLevelFactory(void)
	{
	}

	Level* SimpleLevelFactory::CreateLevel(){
		Level* result = new Level(new Grid(200,50));
		Grid * g = result->GetGrid();
		
		g->GetTileAt(Vector2D(10, 10))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(10, 11))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(10, 12))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		
		g->GetTileAt(Vector2D(17, 1))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(17, 2))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		
		g->GetTileAt(Vector2D(17, 31))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(17, 32))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));

		g->TraverseRow(18, this);

		result->_player = new Player(Vector2D(500,256));
		result->_player->SetGrid(g);
		result->_enemy = new Ghost(Vector2D(2000,256), result->_player);
		result->_enemy2 = new Patrol(Vector2D(200,256), 200, result->_player);
		result->_enemy2->SetGrid(g);
		//g->TraverseRow(1, this);
		//g->TraverseRow(2, this);
		return result;
	}
	void SimpleLevelFactory::ReceiveTile(Tile* tile){
		tile->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
	}
}
