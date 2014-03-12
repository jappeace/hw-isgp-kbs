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
		Level* result = new Level(new Grid(30,10));
		Grid * g = result->GetGrid();

		g->TraverseRow(9, this);
		g->TraverseCollumn(0, this);
		g->TraverseCollumn(29, this);

		result->_player = new Player(Vector2D(100,70));
		result->_player->SetGrid(g);
		result->_enemy = new Ghost(Vector2D(100,221), result->_player);
		result->_enemy2 = new Patrol(Vector2D(100,221), 200, result->_player);
		//g->TraverseRow(1, this);
		//g->TraverseRow(2, this);
		return result;
	}
	void SimpleLevelFactory::ReceiveTile(Tile* tile){
		tile->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
	}
}
