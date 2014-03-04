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
		Point position = Point(5,5);
		Grid * g = result->GetGrid();
		result->_player = new Player(Point(4,4));
		g->GetTileAt(position)->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
		g->TraverseRow(4, this);
		g->TraverseRow(5, this);
		g->TraverseRow(6, this);
		g->TraverseRow(7, this);
		g->TraverseRow(1, this);
		g->TraverseRow(2, this);
		return result;
	}
	void SimpleLevelFactory::ReceiveTile(Tile* tile){
		tile->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
	}
}