#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Game/Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(PointTest)
	{
	public:
		
		TEST_METHOD(Getter)
		{
			isgp::Point p(5, 7);
			Assert::AreEqual(5.0, p.GetX());
			Assert::AreEqual(7.0, p.GetY());
		}

		TEST_METHOD(Setter) {
			isgp::Point p(5, 7);
			p.SetX(p.GetX() + 1);
			p.SetY(p.GetY() - 2);
			Assert::AreEqual(6.0, p.GetX());
			Assert::AreEqual(5.0, p.GetY());
		}
	};
}