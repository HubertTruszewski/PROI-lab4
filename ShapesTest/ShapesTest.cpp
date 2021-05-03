#include "CppUnitTest.h"
#include "../ShapesLib/ShapesLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ShapesTest
{
	TEST_CLASS(ShapesTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Shape* a = new Rectangle(3, 3);
			Shape* b = new Square(3);
			Assert::IsTrue(*a == *b);
		}
	};
}
