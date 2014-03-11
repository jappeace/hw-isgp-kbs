#include "stdafx.h"
#include <CppUnitTest.h>
#include "../Game/Vector2D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace isgp;

namespace UnitTests
{		
	TEST_CLASS(Vector2DTest)
	{
	public:
		
		TEST_METHOD(Getter)
		{
			Vector2D p(5, 7);
			Assert::AreEqual(5.0, p.X());
			Assert::AreEqual(7.0, p.Y());
		}

		TEST_METHOD(Setter) {
			Vector2D p(5, 7);
			p.X(p.X() + 1);
			p.Y(p.Y() - 2);
			Assert::AreEqual(6.0, p.X());
			Assert::AreEqual(5.0, p.Y());
		}

		TEST_METHOD(AddOverload) {
			Vector2D p(5, 7);
			p += Vector2D(1, -2);
			Assert::AreEqual(6.0, p.X());
			Assert::AreEqual(5.0, p.Y());
		}
		TEST_METHOD(RemoveOverload) {
			Vector2D p(5, 7);
			p -= Vector2D(1, -2);
			Assert::AreEqual(4.0, p.X());
			Assert::AreEqual(9.0, p.Y());
		}
		TEST_METHOD(DivideOverload) {
			Vector2D p(5, 6);
			p /= Vector2D(2, 3);
			Assert::AreEqual(2.5, p.X());
			Assert::AreEqual(2.0, p.Y());
		}
		TEST_METHOD(MulitplyOverload) {
			Vector2D p(5, 6);
			p *= Vector2D(2, 3);
			Assert::AreEqual(10.0, p.X());
			Assert::AreEqual(18.0, p.Y());

			p = p * Vector2D(2, 3);
			Assert::AreEqual(20.0, p.X());
			Assert::AreEqual(54.0, p.Y());

			p *= Vector2D(2);
			Assert::AreEqual(40.0, p.X());
			Assert::AreEqual(108.0, p.Y());

		}
	};
}