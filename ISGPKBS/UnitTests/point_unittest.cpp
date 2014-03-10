#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Game/Vector2D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(Vector2DTest)
	{
	public:
		
		TEST_METHOD(Getter)
		{
			isgp::Vector2D p(5, 7);
			Assert::AreEqual(5.0, p.X());
			Assert::AreEqual(7.0, p.Y());
		}

		TEST_METHOD(Setter) {
			isgp::Vector2D p(5, 7);
			p.X(p.X() + 1);
			p.Y(p.Y() - 2);
			Assert::AreEqual(6.0, p.X());
			Assert::AreEqual(5.0, p.Y());
		}
		TEST_METHOD(AddOverload) {
			isgp::Vector2D p(5, 7);
			p -= isgp::Vector2D(1, -2);
			Assert::AreEqual(6.0, p.X());
			Assert::AreEqual(5.0, p.Y());
		}
	};
}