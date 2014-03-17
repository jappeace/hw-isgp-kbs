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
		Level* result = new Level(new Grid(500,30));
		Grid * g = result->GetGrid();
		
	//g->GetTileAt(Vector2D(10, 10))->SetData(new WorldBlock("../tiles/smile.bmp"));
	//g->GetTileAt(Vector2D(10, 11))->SetData(new WorldBlock("../tiles/smile.bmp"));
	//g->GetTileAt(Vector2D(10, 12))->SetData(new WorldBlock("../tiles/smile.bmp"));
	
		g->GetTileAt(Vector2D(1, 27))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(2, 27))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(1, 26))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(2, 26))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(1, 25))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(2, 25))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(1, 24))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(2, 24))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(1, 23))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(2, 23))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(1, 22))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(2, 22))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(1, 21))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(2, 21))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(1, 20))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(2, 20))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(1, 19))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(2, 19))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(1, 18))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(2, 18))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(1, 17))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(2, 17))->SetData(new WorldBlock("tiles/smile.bmp"));
		
		g->GetTileAt(Vector2D(41, 27))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(42, 27))->SetData(new WorldBlock("tiles/smile.bmp"));
		
		g->GetTileAt(Vector2D(55, 23))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(56, 23))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(57, 23))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(58, 23))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(59, 23))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(60, 23))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(61, 23))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(62, 23))->SetData(new WorldBlock("tiles/smile.bmp"));
		g->GetTileAt(Vector2D(63, 23))->SetData(new WorldBlock("tiles/smile.bmp"));

		g->TraverseRow(28, this);

		result->_player = new Player(Vector2D(500,22));
		result->_player->SetGrid(g);
		result->_enemy = new Ghost(Vector2D(2000,256), result->_player);
		result->_enemy2 = new Patrol(Vector2D(200,256), 200, result->_player);
		result->_enemy2->SetGrid(g);
		result->_gadget = new GadgetJumpPlatform(Vector2D(200,592), result->_player);
		result->_gadget->SetGrid(g);
		result->_gadget2 = new GadgetGravityBoots(Vector2D(222,576), result->_player);
		result->_gadget2->SetGrid(g);
		//g->TraverseRow(1, this);
		//g->TraverseRow(2, this);
		return result;
	}
	void SimpleLevelFactory::ReceiveTile(Tile* tile){
		tile->SetData(new WorldBlock("tiles/smile.bmp"));
	}
}
