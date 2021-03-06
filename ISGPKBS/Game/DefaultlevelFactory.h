#pragma once
#include "ILevelFactory.h"
#include<string>
#include<cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "WorldBlock.h"
#include "GadgetGravityBoots.h"
#include "GadgetJumpPlatform.h"
using namespace std;
namespace isgp{
	class DefaultlevelFactory:
		public ILevelFactory
	{
	public:
		void OutputLevel(int currentLevel);
		void Error();
		void inputString();
		Level* CreateLevel(int level, Theme*) override;
		bool LevelExists(int level) override;
		void get_size(Theme*);
		int width;
		int height;
		int start_X,start_Y,finish_X,finish_Y;
		vector<string> v,ghost,patrol,tile, jumpplatform, gravityboots;
		int tile_X,tile_Y,ghost_X,ghost_Y,patrol_X,patrol_Y;

	private :
		Level *level;
	};


}