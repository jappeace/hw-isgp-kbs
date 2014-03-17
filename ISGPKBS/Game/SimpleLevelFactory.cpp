#include "SimpleLevelFactory.h"
#include "WorldBlock.h"
#include "GadgetGravityBoots.h"
#include "GadgetJumpPlatform.h"
namespace isgp{

	SimpleLevelFactory::SimpleLevelFactory(void)
	{
	}


	SimpleLevelFactory::~SimpleLevelFactory(void)
	{
	}

	Level* SimpleLevelFactory::CreateLevel(){
		Level* result = new Level(new Grid(500,50));
		Grid * g = result->GetGrid();
		
		string tmp = "../tiles/ground4.bmp";

		g->GetTileAt(Vector2D(1, 37))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(2, 37))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(1, 36))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(2, 36))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(1, 35))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(2, 35))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(1, 34))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(2, 34))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(1, 33))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(2, 33))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(1, 32))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(2, 32))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(1, 31))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(2, 31))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(1, 30))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(2, 30))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(1, 29))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(2, 29))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(1, 28))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(2, 28))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(1, 27))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(2, 27))->SetData(new WorldBlock(tmp));
		
		g->GetTileAt(Vector2D(41, 37))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(42, 37))->SetData(new WorldBlock(tmp));
		
		g->GetTileAt(Vector2D(55, 33))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(56, 33))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(57, 33))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(58, 33))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(59, 33))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(60, 33))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(61, 33))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(62, 33))->SetData(new WorldBlock(tmp));
		g->GetTileAt(Vector2D(63, 33))->SetData(new WorldBlock(tmp));

		g->TraverseRow(38, this);

		result->_player = new Player(Vector2D(500,32));
		result->_player->SetGrid(g);
		//g->TraverseRow(1, this);
		//g->TraverseRow(2, this);
		return result;
	}
	void SimpleLevelFactory::ReceiveTile(Tile* tile){
		string tmp = "../tiles/ground4.bmp";
		tile->SetData(new WorldBlock(tmp));
	}
}
