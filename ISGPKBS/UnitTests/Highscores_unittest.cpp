#include "stdafx.h"
#include <CppUnitTest.h>
#include "../Game/Highscores.h"
#include "../Game/Highscore.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace isgp;

namespace UnitTests
{		
	TEST_CLASS(HighscoreTest)
	{
	public:
		
		TEST_METHOD(Topscore)
		{
			Highscores h(1337);
			Assert::IsTrue(h.IsHighscore(10));
			
			h.InsertHighscore(Highscore("Test", 20));

			

			h.InsertHighscore(Highscore("Test", 25));
			h.InsertHighscore(Highscore("Test", 30));
			h.InsertHighscore(Highscore("Test", 15));
			h.InsertHighscore(Highscore("Test", 12));
			Assert::AreEqual(5, (int)h.GetHighscores().size());
			Assert::AreEqual(12.0, h.GetHighscores().front().GetTime());
			Assert::IsTrue(h.IsHighscore(10));
			h.InsertHighscore(Highscore("Test", 35));
			Assert::AreEqual(5, (int)h.GetHighscores().size());
			Assert::AreEqual(30.0, h.GetHighscores().back().GetTime());
			h.InsertHighscore(Highscore("Test", 11));
			Assert::AreEqual(11.0, h.GetHighscores().front().GetTime());
			Assert::AreEqual(25.0, h.GetHighscores().back().GetTime());
		}

		TEST_METHOD(Saving) {
			Highscores h(1337);
			h.InsertHighscore(Highscore("Test", 20));
			h.SaveHighscores();
		}
	};
}