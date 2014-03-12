#include "DefaultlevelFactory.h"



namespace isgp{

	void DefaultlevelFactory::OutputLevel(ifstream &infile)
	{
		infile.open("level.txt");
		
		string word;
		int i=0;
		while(!infile.eof())
		{
			infile>>word;
			v.push_back(string(word));
		}
		infile.close();

	}

	
	void DefaultlevelFactory::get_size()
	{
		char *result =NULL;
		char *j;
		char ch[30];
		
	
		for(int i=0; i<5;i++)
	{
		strcpy_s(ch,30,v[i].c_str());
		if(i==0)
		{
			result = strtok_s(ch,"=",&j);
			width = atoi(j);
			cout << "width : "<< width <<endl;
			
		}
		else if(i==1)
		{
			result = strtok_s(ch,"=",&j);
			height = atoi(j);
			cout << "height : "<< height <<endl;
			
		}
		else if(i==2)
		{
			result = strtok_s(ch,"=",&j);
	
			start_X=atoi(j);
			cout <<"Start x : " << start_X <<endl;

			strcpy_s(ch,30,v[2].c_str());
			result = strtok_s(ch,",",&j);
			start_Y=atoi(j);
			cout <<"Start y : " <<start_Y <<endl;
		}
		else if(i==3)
		{
			result = strtok_s(ch,"=",&j);
	
			finish_X=atoi(j);
			cout <<"Finish x : " << finish_X <<endl;

			strcpy_s(ch,30,v[3].c_str());
			result = strtok_s(ch,",",&j);
			finish_Y=atoi(j);
			cout <<"Finish y : " <<finish_Y <<endl;
		}
		else
			break;

	}
	

	}


	void DefaultlevelFactory::Error()
	{
		//MessageBox(0,"Error","Warning",MB_OK);
		exit(1);

	}
}