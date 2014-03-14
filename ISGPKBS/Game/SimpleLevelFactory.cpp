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
		Level* result = new Level(new Grid(250,40));
		Grid * g = result->GetGrid();
		
		//g->GetTileAt(Vector2D(10, 10))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		//g->GetTileAt(Vector2D(10, 11))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		//g->GetTileAt(Vector2D(10, 12))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		
		g->GetTileAt(Vector2D(1, 37))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(2, 37))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(1, 36))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(2, 36))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(1, 35))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(2, 35))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(1, 34))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(2, 34))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(1, 33))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(2, 33))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(1, 32))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(2, 32))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(1, 31))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(2, 31))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(1, 30))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(2, 30))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(1, 29))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(2, 29))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(1, 28))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(2, 28))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(1, 27))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(2, 27))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		
		g->GetTileAt(Vector2D(41, 37))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(42, 37))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		
		g->GetTileAt(Vector2D(55, 33))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(56, 33))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(57, 33))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(58, 33))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(59, 33))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(60, 33))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(61, 33))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(62, 33))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
		g->GetTileAt(Vector2D(63, 33))->SetData(new WorldBlock(".\\tiles\\smile.bmp"));

		g->TraverseRow(38, this);

		result->_player = new Player(Vector2D(500,32));
		result->_player->SetGrid(g);
		result->_enemy = new Ghost(Vector2D(2000,256), result->_player);
		result->_enemy2 = new Patrol(Vector2D(200,256), 200, result->_player);
		result->_enemy2->SetGrid(g);
		result->_gadget = new GadgetJumpPlatform(Vector2D(200,592), result->_player);
		result->_gadget->SetGrid(g);
		//g->TraverseRow(1, this);
		//g->TraverseRow(2, this);
		return result;
	}
	void SimpleLevelFactory::ReceiveTile(Tile* tile){
		tile->SetData(new WorldBlock(".\\tiles\\smile.bmp"));
	}
}
