#pragma once
#include <vector>
#include "Highscore.h"
#include <cfloat>
#include <algorithm>
namespace isgp {
	class Highscores
	{
	public:
		Highscores(int level);
		Highscores();
		~Highscores(void);
		
		vector<Highscore> GetHighscores();
		void SaveHighscores();
		void LoadHighscores();
		bool IsHighscore(double time);
		void InsertHighscore(Highscore h);

	private:
		vector<Highscore> _highscores;
		int _level;
	};

}