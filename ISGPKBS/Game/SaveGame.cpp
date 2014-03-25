#include <fstream>
#include <ostream>
#include "SaveGame.h"
#include "StrConverter.h"

namespace isgp {

	std::pair<int, int> SaveGame::ReadCurrentLevel() {
		using namespace std;

		std::pair<int, int> saveState;
		saveState.first = 1; // Level
		saveState.second = 10; // Lives

		ifstream inStream("levels/autosave.save");
		if (!inStream.good()) {
			// There is no save-game, return that we are at the first level.
			inStream.close();
			return saveState;
		}

		// There is a savegame, let's load it
		char* levelNumberString = new char[10];
		inStream.getline(levelNumberString, 10);

		if (inStream.fail()) {
			// Reading failed, restart game
			inStream.close();
			delete levelNumberString;
			return saveState;
		}

		int levelNumber = atoi(levelNumberString);
		inStream.getline(levelNumberString, 10);
		int livesRemaining = atoi(levelNumberString);

		saveState.first = levelNumber;
		saveState.second = livesRemaining;

		inStream.close();

		delete levelNumberString;
		return saveState;
	}

	void SaveGame::WriteCurrentLevel(int currentLevel, int lives) {
		using namespace std;
		ofstream outStream("levels/autosave.save", ios::out);
		outStream << StrConverter::IntToString(currentLevel) << endl;
		outStream << StrConverter::IntToString(lives) << endl;
		outStream.close();
	}
}
