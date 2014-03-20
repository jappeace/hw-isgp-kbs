#pragma once

namespace isgp {

	class SaveGame
	{
	public:
		SaveGame();
		~SaveGame();

		// Reads the current level number
		int ReadCurrentLevel();
		// Writes the current level number
		void WriteCurrentLevel(int currentLevel);
	};
}
