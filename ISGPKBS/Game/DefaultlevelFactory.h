#pragma once
#include "ILevelFactory.h"
#include<string>
#include<cstdlib>
#include <iostream>
#include <fstream>


using namespace std;
namespace isgp{
	class DefaultlevelFactory:
		public ILevelFactory
	{
	public:
		//CFile file;

		
	
		void OutputLevel(ifstream &infile );
		void Error();
		void inputString();

		Level *CreateLevel();
		void get_size();
		
		
	private :
		int width;//인풋스트링에하나하나읽어 인풋[0]을 그면 split()함수를받아들여 
		int height;
		int start_X,start_Y;
		string inputString[100];
	
		

	};


}