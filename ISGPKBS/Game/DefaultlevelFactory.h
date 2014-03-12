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
		int width;//��ǲ��Ʈ�����ϳ��ϳ��о� ��ǲ[0]�� �׸� split()�Լ����޾Ƶ鿩 
		int height;
		int start_X,start_Y;
		string inputString[100];
	
		

	};


}