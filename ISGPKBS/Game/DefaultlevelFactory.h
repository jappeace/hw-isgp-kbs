#pragma once
#include "ILevelFactory.h"
#include<string>
#include<cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "WorldBlock.h"
using namespace std;
namespace isgp{
	class DefaultlevelFactory:
		public ILevelFactory
	{
	public:
		void OutputLevel();
		void Error();
		void inputString();
		Level *CreateLevel() override;
		void get_size();
		int width;
		int height;
		int start_X,start_Y,finish_X,finish_Y;
		vector<string> v,ghost,patrol,tile, jumpplatform, gravityboots;
		int tile_X,tile_Y,ghost_X,ghost_Y,patrol_X,patrol_Y;


	private :
		Level *level;
		

	};


}