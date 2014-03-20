#include <fstream>
#include "SaveGame.h"

namespace isgp {

	SaveGame::SaveGame()
	{
	}


	SaveGame::~SaveGame()
	{
	}

	int SaveGame::ReadCurrentLevel() {
		using namespace std;

		ifstream inStream("./levels/autosave.save");
		if (!inStream.good()) {
			// There is no save-game, return that we are at the first level.
			inStream.close();
			return 1;
		}

		// There is a savegame, let's load it
		char* levelNumberString = new char[10];
		inStream.getline(levelNumberString, 10);

		if (inStream.fail()) {
			// Reading failed, restart game
			inStream.close();
			delete levelNumberString;
			return 1;
		}

		inStream.close();

		int levelNumber = atoi(levelNumberString);
		delete levelNumberString;
		return levelNumber;
	}

	void SaveGame::WriteCurrentLevel() {
	}
}
