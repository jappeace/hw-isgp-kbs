#ifdef _DEBUG
    #define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
    #define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
    #define new DEBUG_NEW
#endif
#include "DefaultlevelFactory.h"
#include "Theme1.h"

namespace isgp{

	bool DefaultlevelFactory::LevelExists(int currentLevel) {
		ifstream f("./levels/level" + StrConverter::IntToString(currentLevel) + ".level");
		if (f.good()) {
			f.close();
			return true;
		} else {
			f.close();
			return false;
		}  
	}

	void DefaultlevelFactory::OutputLevel(int currentLevel)
	{
		ifstream infile("./levels/level" + StrConverter::IntToString(currentLevel) + ".level");

		//infile.open("level.txt");
		
		string word;
		int i=0;

		getline(infile,word);
		while(!infile.eof())
		{
			
			v.push_back(string(word));
			getline(infile,word);
		}
		infile.close();

	}

	
	void DefaultlevelFactory::get_size(Theme* theme)
	{
		GridGraphicTranslator fromto;
		char *result =NULL;
		char *j,*m;
		char ch[30],v_for[30];
		int v_size=v.size();
	
	///////////// information(x,y) of start,finish & size of width,height
		
			//ch = v[0].c_str();
				strcpy_s(ch,30,v[0].c_str());
				result = strtok_s(ch,"=",&j);
				width = atoi(j);
			
				strcpy_s(ch,30,v[1].c_str());
			
				result = strtok_s(ch,"=",&j);
				height = atoi(j);
				level = new Level(width,height);
				level->_theme = theme;
				level->_theme->SetWidth(GridGraphicTranslator().FromTo(Vector2D(width)).X());
				//start
				strcpy_s(ch,30,v[2].c_str());
			
				result = strtok_s(ch,"=",&j);
				start_X=atoi(j);

				strcpy_s(ch,30,v[2].c_str());
				result = strtok_s(ch,",",&j);
				start_Y=atoi(j);
				//finish
				strcpy_s(ch,30,v[3].c_str());
				result = strtok_s(ch,"=",&j);
				finish_X=atoi(j);
				strcpy_s(ch,30,v[3].c_str());
				result = strtok_s(ch,",",&j);
				finish_Y=atoi(j);
			
		
		level->_player = new Player(Vector2D(start_X,start_Y));
		level->finish = new Finish(Vector2D(finish_X, finish_Y), level->_player);
		
	////////////////information (x,y)of ghost,patrol,tile	
		int size = v.size();
		for(int k=4;k<size;k++)
		{
			strcpy_s(v_for,30,v[k].c_str());
			result = strtok_s(v_for,"=",&m);
			
			if(0==strcmp(m,"ghost"))
				ghost.push_back(string(v[k]));
			else if(0==strcmp(m,"tile"))
				tile.push_back(string(v[k]));
			else if(0==strcmp(m,"patrol"))
				patrol.push_back(string(v[k]));
			else if(0==strcmp(m, "jumpplatform"))
				jumpplatform.push_back(string(v[k]));
			else if(0==strcmp(m, "gravityboots")) 
				gravityboots.push_back(string(v[k]));
		}

		int tile_size = tile.size();
		for(int n=0;n< tile_size;n++)
		{
			tile_X= atoi(tile[n].c_str());
			strcpy_s(v_for,30,tile[n].c_str());
			result=strtok_s(v_for,",",&m);
			tile_Y=atoi(m);
			//level->ReceiveTile(new Tile(tile_X,tile_Y));
			level->GetGrid()->GetTileAt(tile_X,tile_Y)->SetData(new WorldBlock(level->_theme->GetTilePath()));

		}
		level->_player->SetGrid(level->GetGrid());

		int ghost_size = ghost.size();
		Entity* ghost2; 
		for(int n=0;n< ghost_size;n++)
		{
			ghost_X= atoi(ghost[n].c_str());
			strcpy_s(v_for,30,ghost[n].c_str());
			result=strtok_s(v_for,",",&m);
			ghost_Y=atoi(m);

			ghost2 = new Ghost(fromto.FromTo(Vector2D(ghost_X,ghost_Y)),level->_player);
			ghost2->SetGrid(level->GetGrid());
			level->entities.push_back(ghost2); 
			
		}

		int patrol_size = patrol.size();
		Entity * patrol2;
		for(int n=0;n< patrol_size;n++)
		{
			patrol_X= atoi(patrol[n].c_str());
			strcpy_s(v_for,30,patrol[n].c_str());
			result=strtok_s(v_for,",",&m);
			patrol_Y=atoi(m);
			//

			patrol2 = new Patrol(fromto.FromTo(Vector2D(patrol_X,patrol_Y)),100,level->_player);
			patrol2->SetGrid(level->GetGrid());
			level->entities.push_back(patrol2); 
			
		}
		Gadget * gadget;
		int gadget_size = gravityboots.size();
		for(int n=0;n< gadget_size;n++)
		{
			patrol_X= atoi(gravityboots[n].c_str());
			strcpy_s(v_for,30,gravityboots[n].c_str());
			result=strtok_s(v_for,",",&m);
			patrol_Y=atoi(m);
			//

			gadget = new GadgetGravityBoots(fromto.FromTo(Vector2D(patrol_X,patrol_Y)),level->_player);
			gadget->SetGrid(level->GetGrid());
			level->entities.push_back(gadget); 
			
		}

		gadget_size = jumpplatform.size();
		
		for(int n=0;n< gadget_size;n++)
		{
			patrol_X= atoi(jumpplatform[n].c_str());
			strcpy_s(v_for,30,jumpplatform[n].c_str());
			result=strtok_s(v_for,",",&m);
			patrol_Y=atoi(m);
			//

			gadget = new GadgetJumpPlatform(fromto.FromTo(Vector2D(patrol_X,patrol_Y)),level->_player);
			gadget->SetGrid(level->GetGrid());
			level->entities.push_back(gadget); 
			
		}
	//tile, ghost, patrol 있음. 캄 vector 에 ghost가 몇번째에나오는지 확인하고. 그전까지 나온 거를 다 좌표로저장하기 위에처럼
		//마찬가지로 patrol 나오기전까지 ghost 나온거를 다 좌표로 저장해서 무슨 2d 거기로넘겨야됨.

}

	Level *DefaultlevelFactory::CreateLevel(int currentLevel, Theme* theme)
	{
		OutputLevel(currentLevel);
		get_size(theme);

		return level;
	}
	void DefaultlevelFactory::Error()
	{
		//MessageBox(0,"Error","Warning",MB_OK);
		exit(1);

	}
}