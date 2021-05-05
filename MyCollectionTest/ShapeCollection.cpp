#include "CppUnitTest.h"
#include "../MyCollection/ShapeCollection.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ShapeCollectionTest
{
	TEST_CLASS(ShapeCollectionTest)
	{
	public:
		TEST_METHOD(MinPerimeter1)
		{
			ShapeCollection collection;
			collection.append(new Rectangle(4, 5));
			collection.append(new Square(4));
			collection.append(new Circle(4));
			Assert::AreEqual(collection.minPerimeter(), 16, 0.1);
		}
		TEST_METHOD(MinPerimeter2)
		{
			ShapeCollection collection;
			collection.append(new Rectangle(2, 5));
			collection.append(new Square(8));
			collection.append(new Circle(5));
			Assert::AreEqual(collection.minPerimeter(), 14, 0.1);
		}
		TEST_METHOD(MaxPerimeter1)
		{
			ShapeCollection collection;
			collection.append(new Rectangle(20, 5));
			collection.append(new Square(10));
			collection.append(new Circle(6));
			Assert::AreEqual(collection.maxPerimeter(), 50, 0.1);
		}
		TEST_METHOD(MaxPerimeter2)
		{
			ShapeCollection collection;
			collection.append(new Rectangle(20, 5));
			collection.append(new Square(10));
			collection.append(new Circle(10));
			Assert::AreEqual(collection.maxPerimeter(), 62.8, 0.1);
		}
		TEST_METHOD(AvgPerimeter1)
		{
			ShapeCollection collection;
			collection.append(new Rectangle(3, 5));
			collection.append(new Square(5));
			collection.append(new Circle(3));
			Assert::AreEqual(collection.avgPerimeter(), 18.28, 0.1);
		}
		TEST_METHOD(AvgPerimeter2)
		{
			ShapeCollection collection;
			collection.append(new Rectangle(6, 2));
			collection.append(new Square(3));
			collection.append(new Circle(1));
			Assert::AreEqual(collection.avgPerimeter(), 11.43, 0.1);
		}
		TEST_METHOD(MinArea1)
		{
			ShapeCollection collection;
			collection.append(new Rectangle(1, 2));
			collection.append(new Square(3));
			collection.append(new Circle(1));
			Assert::AreEqual(collection.minArea(), 2, 0.01);
		}
		TEST_METHOD(MinArea2)
		{
			ShapeCollection collection;
			collection.append(new Rectangle(6, 2));
			collection.append(new Square(3));
			collection.append(new Circle(1));
			Assert::AreEqual(collection.minArea(), 3.14, 0.1);
		}
		TEST_METHOD(MaxArea1)
		{
			ShapeCollection collection;
			collection.append(new Rectangle(6, 8));
			collection.append(new Square(7));
			collection.append(new Circle(3));
			Assert::AreEqual(collection.maxArea(), 49, 0.1);
		}
		TEST_METHOD(MaxArea2)
		{
			ShapeCollection collection;
			collection.append(new Rectangle(9, 8));
			collection.append(new Square(8));
			collection.append(new Circle(4));
			Assert::AreEqual(collection.maxArea(), 72, 0.1);
		}
		TEST_METHOD(AvgArea1)
		{
			ShapeCollection collection;
			collection.append(new Rectangle(6, 8));
			collection.append(new Square(7));
			collection.append(new Circle(3));
			Assert::AreEqual(collection.avgArea(), 41.75, 0.1);
		}
		TEST_METHOD(AvgArea2)
		{
			ShapeCollection collection;
			collection.append(new Rectangle(1, 2));
			collection.append(new Square(2));
			collection.append(new Circle(1));
			Assert::AreEqual(collection.avgArea(), 3.05, 0.1);
		}
	};
}