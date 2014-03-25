#pragma once

#include <utility>

namespace isgp {

	class SaveGame
	{
	public:
		// Reads the current level number
		static std::pair<int, int> ReadCurrentLevel();
		// Writes the current level number
		static void WriteCurrentLevel(int currentLevel, int lives);
	};
}
