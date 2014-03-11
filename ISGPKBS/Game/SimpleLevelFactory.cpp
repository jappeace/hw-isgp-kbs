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
		Level* result = new Level(new Grid(50,50));
		Grid * g = result->GetGrid();
		
		g->GetTileAt(Vector2D(10, 10))->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(10, 11))->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(10, 12))->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));

		g->TraverseRow(18, this);

		result->_player = new Player(Vector2D(200,100));
		result->_player->SetGrid(g);
		result->_enemy = new Ghost(Vector2D(100,221), result->_player);
		result->_enemy2 = new Patrol(Vector2D(200,221), 200, result->_player);
		result->_enemy2->SetGrid(g);
		//g->TraverseRow(1, this);
		//g->TraverseRow(2, this);
		return result;
	}
	void SimpleLevelFactory::ReceiveTile(Tile* tile){
		tile->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
	}
}
