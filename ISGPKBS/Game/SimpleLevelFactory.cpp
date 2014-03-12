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
		Level* result = new Level(new Grid(2000,30));
		Grid * g = result->GetGrid();
		
		g->GetTileAt(Vector2D(10, 10))->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(10, 11))->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(10, 12))->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));

		g->TraverseRow(18, this);

		result->_player = new Player(Vector2D(200,100));
		result->_player->SetGrid(g);
		//g->TraverseRow(1, this);
		//g->TraverseRow(2, this);
		return result;
	}
	void SimpleLevelFactory::ReceiveTile(Tile* tile){
		tile->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
	}
}
