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
		Level* result = new Level();
		Vector2D position = Vector2D(5,5);
		Grid * g = result->GetGrid();
		result->_player = new Player(Point(4,4));
		result->_player->SetGrid(g);
		g->GetTileAt(Point(10, 10))->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
		g->GetTileAt(Point(10, 11))->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
		g->GetTileAt(Point(10, 12))->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
		g->TraverseRow(15, this);
		g->TraverseRow(16, this);
		g->TraverseRow(17, this);
		g->TraverseRow(18, this);
		g->TraverseRow(1, this);
		g->TraverseRow(2, this);
		return result;
	}
	void SimpleLevelFactory::ReceiveTile(Tile* tile){
		tile->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
	}
}
