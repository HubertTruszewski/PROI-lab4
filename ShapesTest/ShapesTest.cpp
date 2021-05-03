#include "CppUnitTest.h"
#include "../ShapesLib/ShapesLib.h"
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ShapesTest
{
	TEST_CLASS(ShapesTest)
	{
	public:
		
		TEST_METHOD(RectangleConstructor)
		{
			Shape* rectangle = new Rectangle(2, 3);
			Assert::AreEqual(rectangle->getPerimeter(), 10, 0.1);
			delete rectangle;
		}
		TEST_METHOD(RectangleConstructorNegativeDismension)
		{
			auto func = [] { Rectangle(-2, 3); };
			auto func2 = [] { Rectangle(2, -3); };
			auto func3 = [] { Rectangle(-2, -3); };
			Assert::ExpectException<std::out_of_range>(func);
			Assert::ExpectException<std::out_of_range>(func2);
			Assert::ExpectException<std::out_of_range>(func3);
		}
		TEST_METHOD(RectangleConstructorZeroAsDismesion)
		{
			auto func = [] { Rectangle(2, 0); };
			auto func2 = [] { Rectangle(0, 2); };
			auto func3 = [] { Rectangle(0, 0); };
			Assert::ExpectException<std::out_of_range>(func);
			Assert::ExpectException<std::out_of_range>(func2);
			Assert::ExpectException<std::out_of_range>(func3);
		}
		TEST_METHOD(CircleConstructor)
		{
			Shape* circle = new Circle(1);
			Assert::AreEqual(circle->getArea(), 3.14, 0.01);
			delete circle;
		}
		TEST_METHOD(CircleConstructorNegativeDismension)
		{
			auto func = [] { Circle(-3); };
			Assert::ExpectException<std::out_of_range>(func);
		}
		TEST_METHOD(CircleConstructorZeroDismension)
		{
			auto func = [] { Circle(0); };
			Assert::ExpectException<std::out_of_range>(func);
		}
		TEST_METHOD(SquareConstructor)
		{
			Shape* square = new Square(4);
			Assert::AreEqual(square->getPerimeter(), 16, 0.0001);
			delete square;
		}
		TEST_METHOD(SquareConstructorNegativeDismension)
		{
			auto func = [] { Square(-2); };
			Assert::ExpectException<std::out_of_range>(func);
		}
		TEST_METHOD(SquareConstructorZeroDismension)
		{
			auto func = [] { Square(0); };
			Assert::ExpectException<std::out_of_range>(func);
		}
		TEST_METHOD(RectanglePerimeter1)
		{
			Shape* rectangle = new Rectangle(2, 6);
			Assert::AreEqual(rectangle->getPerimeter(), 16, 0.01);
			delete rectangle;
		}
		TEST_METHOD(RectanglePerimeter2)
		{
			Shape* rectangle = new Rectangle(15, 0.5);
			Assert::AreEqual(rectangle->getPerimeter(), 31, 0.01);
			delete rectangle;
		}
		TEST_METHOD(RectangleArea1)
		{
			Shape* rectangle = new Rectangle(2, 3);
			Assert::AreEqual(rectangle->getArea(), 6, 0.1);
			delete rectangle;
		}
		TEST_METHOD(RectangleArea2)
		{
			Shape* rectangle = new Rectangle(2.5, 0.1);
			Assert::AreEqual(rectangle->getArea(), 0.25, 0.001);
			delete rectangle;
		}
		TEST_METHOD(CirclePerimeter1)
		{
			Shape* circle = new Circle(2);
			Assert::AreEqual(circle->getPerimeter(), 12.56, 0.01);
			delete circle;
		}
		TEST_METHOD(CirclePerimeter2)
		{
			Shape* circle = new Circle(0.1);
			Assert::AreEqual(circle->getPerimeter(), 0.628, 0.001);
			delete circle;
		}
		TEST_METHOD(CircleArea1)
		{
			Shape* circle = new Circle(2);
			Assert::AreEqual(circle->getArea(), 12.56, 0.01);
			delete circle;
		}
		TEST_METHOD(CircleArea2)
		{
			Shape* circle = new Circle(0.5);
			Assert::AreEqual(circle->getArea(), 0.785, 0.01);
			delete circle;
		}
		TEST_METHOD(SquarePerimeter1)
		{
			Shape* square = new Square(3);
			Assert::AreEqual(square->getPerimeter(), 12, 0.0001);
			delete square;
		}
		TEST_METHOD(SquarePerimeter2)
		{
			Shape* square = new Square(0.5);
			Assert::AreEqual(square->getPerimeter(), 2, 0.0001);
			delete square;
		}
		TEST_METHOD(SquareArea1)
		{
			Shape* square = new Square(7);
			Assert::AreEqual(square->getArea(), 49, 0.0001);
			delete square;
		}
		TEST_METHOD(SquareArea2)
		{
			Shape* square = new Square(0.8);
			Assert::AreEqual(square->getArea(), 0.64, 0.001);
			delete square;
		}
		TEST_METHOD(OperatorEqualTwoRectanglesTrue)
		{
			Shape* rectangle1 = new Rectangle(3, 4);
			Shape* rectangle2 = new Rectangle(4, 3);
			Assert::IsTrue(*rectangle1 == *rectangle2);
			delete rectangle1;
			delete rectangle2;
		}
		TEST_METHOD(OperatorEqualTwoRectanglesFalse)
		{
			Shape* rectangle1 = new Rectangle(4, 4);
			Shape* rectangle2 = new Rectangle(4, 3);
			Assert::IsFalse(*rectangle1 == *rectangle2);
			delete rectangle1;
			delete rectangle2;
		}
		TEST_METHOD(OperatorEqualTwoCirclesTrue)
		{
			Shape* circle1 = new Circle(2);
			Shape* circle2 = new Circle(2);
			Assert::IsTrue(*circle1 == *circle2);
			delete circle1;
			delete circle2;
		}
		TEST_METHOD(OperatorEqualTwoCirclesFalse)
		{
			Shape* circle1 = new Circle(2);
			Shape* circle2 = new Circle(3);
			Assert::IsFalse(*circle1 == *circle2);
			delete circle1;
			delete circle2;
		}
		TEST_METHOD(OperatorEqualTwoSquaresTrue)
		{
			Shape* square1 = new Square(4);
			Shape* square2 = new Square(4);
			Assert::IsTrue(*square1 == *square2);
			delete square1;
			delete square2;
		}
		TEST_METHOD(OperatorEqualTwoSquaresFalse)
		{
			Shape* square1 = new Square(4);
			Shape* square2 = new Square(5);
			Assert::IsFalse(*square1 == *square2);
			delete square1;
			delete square2;
		}
		TEST_METHOD(OperatorEqualRectangleCircleTrue)
		{
			Shape* rectangle = new Rectangle(2, 5);
			Shape* circle = new Circle(1.7845765256);
			Assert::IsTrue(*rectangle == *circle);
			delete rectangle;
			delete circle;
		}
		TEST_METHOD(OperatorEqualRectangleCircleFalse)
		{
			Shape* rectangle = new Rectangle(2, 5);
			Shape* circle = new Circle(10);
			Assert::IsFalse(*rectangle == *circle);
			delete rectangle;
			delete circle;
		}
		TEST_METHOD(OperatorEqualRectangleSquareTrue)
		{
			Shape* rectangle = new Rectangle(4, 4);
			Shape* square = new Square(4);
			Assert::IsTrue(*rectangle == *square);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorEqualRectangleSquareFalse)
		{
			Shape* rectangle = new Rectangle(5, 4);
			Shape* square = new Square(4);
			Assert::IsFalse(*rectangle == *square);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorEqualCircleSquareTrue)
		{
			Shape* circle = new Circle(2);
			Shape* square = new Square(3.544);
			Assert::IsTrue(*circle == *square);
			delete circle;
			delete square;
		}
		TEST_METHOD(OperatorEqualCircleSquareFalse)
		{
			Shape* circle = new Circle(2);
			Shape* square = new Square(3);
			Assert::IsFalse(*circle == *square);
			delete circle;
			delete square;
		}
		TEST_METHOD(OperatorNotEqualTwoRectanglesTrue)
		{
			Shape* rectangle1 = new Rectangle(4, 4);
			Shape* rectangle2 = new Rectangle(4, 3);
			Assert::IsTrue(*rectangle1 != *rectangle2);
			delete rectangle1;
			delete rectangle2;
		}
		TEST_METHOD(OperatorNotEqualTwoRectanglesFalse)
		{
			Shape* rectangle1 = new Rectangle(4, 4);
			Shape* rectangle2 = new Rectangle(4, 4);
			Assert::IsFalse(*rectangle1 != *rectangle2);
			delete rectangle1;
			delete rectangle2;
		}
		TEST_METHOD(OperatorNotEqualTwoCirclesTrue)
		{
			Shape* circle1 = new Circle(2);
			Shape* circle2 = new Circle(4);
			Assert::IsTrue(*circle1 != *circle2);
			delete circle1;
			delete circle2;
		}
		TEST_METHOD(OperatorNotEqualTwoCirclesFalse)
		{
			Shape* circle1 = new Circle(5);
			Shape* circle2 = new Circle(5);
			Assert::IsFalse(*circle1 != *circle2);
			delete circle1;
			delete circle2;
		}
		TEST_METHOD(OperatorNotEqualTwoSquaresTrue)
		{
			Shape* square1 = new Square(4);
			Shape* square2 = new Square(6);
			Assert::IsTrue(*square1 != *square2);
			delete square1;
			delete square2;
		}
		TEST_METHOD(OperatorNotEqualTwoSquaresFalse)
		{
			Shape* square1 = new Square(6);
			Shape* square2 = new Square(6);
			Assert::IsFalse(*square1 != *square2);
			delete square1;
			delete square2;
		}

		TEST_METHOD(OperatorNotEqualRectangleCircleTrue)
		{
			Shape* rectangle = new Rectangle(2, 5);
			Shape* circle = new Circle(4);
			Assert::IsTrue(*rectangle != *circle);
			delete rectangle;
			delete circle;
		}
		TEST_METHOD(OperatorNotEqualRectangleCircleFalse)
		{
			Shape* rectangle = new Rectangle(2, 5);
			Shape* circle = new Circle(1.7845765256);
			Assert::IsFalse(*rectangle != *circle);
			delete rectangle;
			delete circle;
		}
		TEST_METHOD(OperatorNotEqualRectangleSquareTrue)
		{
			Shape* rectangle = new Rectangle(4, 4);
			Shape* square = new Square(5);
			Assert::IsTrue(*rectangle != *square);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorNotEqualRectangleSquareFalse)
		{
			Shape* rectangle = new Rectangle(5, 5);
			Shape* square = new Square(5);
			Assert::IsFalse(*rectangle != *square);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorNotEqualCircleSquareTrue)
		{
			Shape* circle = new Circle(2);
			Shape* square = new Square(2);
			Assert::IsTrue(*circle != *square);
			delete circle;
			delete square;
		}
		TEST_METHOD(OperatorNotEqualCircleSquareFalse)
		{
			Shape* circle = new Circle(2);
			Shape* square = new Square(3.544);
			Assert::IsFalse(*circle != *square);
			delete circle;
			delete square;
		}
		TEST_METHOD(OperatorGreaterTwoRectanglesTrue)
		{
			Shape* rectangle1 = new Rectangle(3, 4);
			Shape* rectangle2 = new Rectangle(3, 3);
			Assert::IsTrue(*rectangle1 > *rectangle2);
			delete rectangle1;
			delete rectangle2;
		}
		TEST_METHOD(OperatorGreaterTwoRectanglesFalse)
		{
			Shape* rectangle1 = new Rectangle(3, 4);
			Shape* rectangle2 = new Rectangle(4, 3);
			Assert::IsFalse(*rectangle2 > *rectangle1);
			delete rectangle1;
			delete rectangle2;
		}
		TEST_METHOD(OpertatorGreaterTwoCirclesTrue)
		{
			Shape* circle1 = new Circle(3);
			Shape* circle2 = new Circle(5);
			Assert::IsTrue(*circle2 > *circle1);
			delete circle1;
			delete circle2;
		}
		TEST_METHOD(OpertatorGreaterTwoCirclesFalse)
		{
			Shape* circle1 = new Circle(3);
			Shape* circle2 = new Circle(5);
			Assert::IsFalse(*circle1 > *circle2);
			delete circle1;
			delete circle2;
		}
		TEST_METHOD(OperatorGreaterTwoSquaresTrue)
		{
			Shape* square1 = new Square(3);
			Shape* square2 = new Square(9);
			Assert::IsTrue(*square2 > *square1);
			delete square1;
			delete square2;
		}
		TEST_METHOD(OperatorGreaterTwoSquaresFalse)
		{
			Shape* square1 = new Square(3);
			Shape* square2 = new Square(9);
			Assert::IsFalse(*square1 > *square2);
			delete square1;
			delete square2;
		}
		TEST_METHOD(OperatorGreaterRectangleCircleTrue)
		{
			Shape* rectangle = new Rectangle(4, 5);
			Shape* circle = new Circle(4);
			Assert::IsTrue(*circle > *rectangle);
			delete rectangle;
			delete circle;
		}
		TEST_METHOD(OperatorGreaterRectangleCircleFalse)
		{
			Shape* rectangle = new Rectangle(4, 5);
			Shape* circle = new Circle(4);
			Assert::IsFalse(*rectangle > *circle);
			delete rectangle;
			delete circle;
		}
		TEST_METHOD(OperatorGreaterRectangleSquareTrue)
		{
			Shape* rectangle = new Rectangle(4, 5);
			Shape* square = new Square(5);
			Assert::IsTrue(*square > *rectangle);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorGreaterRectangleSquareFalse)
		{
			Shape* rectangle = new Rectangle(4, 5);
			Shape* square = new Square(5);
			Assert::IsFalse(*rectangle > *square);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorGreaterCircleSquareTrue)
		{
			Shape* circle = new Circle(5);
			Shape* square = new Square(5);
			Assert::IsTrue(*circle > *square);
			delete circle;
			delete square;
		}
		TEST_METHOD(OperatorGreaterCircleSquareFalse)
		{
			Shape* circle = new Circle(5);
			Shape* square = new Square(5);
			Assert::IsFalse(*square > *circle);
			delete circle;
			delete square;
		}
		TEST_METHOD(OperatorLessTwoRectanglesTrue)
		{
			Shape* rectangle1 = new Rectangle(3, 4);
			Shape* rectangle2 = new Rectangle(3, 3);
			Assert::IsTrue(*rectangle2 < *rectangle1);
			delete rectangle1;
			delete rectangle2;
		}
		TEST_METHOD(OperatorLessTwoRectanglesFalse)
		{
			Shape* rectangle1 = new Rectangle(3, 4);
			Shape* rectangle2 = new Rectangle(4, 3);
			Assert::IsFalse(*rectangle2 < *rectangle1);
			delete rectangle1;
			delete rectangle2;
		}
		TEST_METHOD(OpertatorLessTwoCirclesTrue)
		{
			Shape* circle1 = new Circle(3);
			Shape* circle2 = new Circle(5);
			Assert::IsTrue(*circle1 < *circle2);
			delete circle1;
			delete circle2;
		}
		TEST_METHOD(OpertatorLessTwoCirclesFalse)
		{
			Shape* circle1 = new Circle(3);
			Shape* circle2 = new Circle(5);
			Assert::IsFalse(*circle2 < *circle1);
			delete circle1;
			delete circle2;
		}
		TEST_METHOD(OperatorLessTwoSquaresTrue)
		{
			Shape* square1 = new Square(3);
			Shape* square2 = new Square(9);
			Assert::IsTrue(*square1 < *square2);
			delete square1;
			delete square2;
		}
		TEST_METHOD(OperatorLessTwoSquaresFalse)
		{
			Shape* square1 = new Square(3);
			Shape* square2 = new Square(9);
			Assert::IsFalse(*square2 < *square1);
			delete square1;
			delete square2;
		}
		TEST_METHOD(OperatorLessRectangleCircleTrue)
		{
			Shape* rectangle = new Rectangle(4, 5);
			Shape* circle = new Circle(4);
			Assert::IsTrue(*rectangle < *circle);
			delete rectangle;
			delete circle;
		}
		TEST_METHOD(OperatorLessRectangleCircleFalse)
		{
			Shape* rectangle = new Rectangle(4, 5);
			Shape* circle = new Circle(4);
			Assert::IsFalse(*circle < *rectangle);
			delete rectangle;
			delete circle;
		}
		TEST_METHOD(OperatorLessRectangleSquareTrue)
		{
			Shape* rectangle = new Rectangle(4, 5);
			Shape* square = new Square(5);
			Assert::IsTrue(*rectangle < *square);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorLessRectangleSquareFalse)
		{
			Shape* rectangle = new Rectangle(4, 5);
			Shape* square = new Square(5);
			Assert::IsFalse(*square < *rectangle);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorLessCircleSquareTrue)
		{
			Shape* circle = new Circle(5);
			Shape* square = new Square(5);
			Assert::IsTrue(*square < *circle);
			delete circle;
			delete square;
		}
		TEST_METHOD(OperatorLessCircleSquareFalse)
		{
			Shape* circle = new Circle(5);
			Shape* square = new Square(5);
			Assert::IsFalse(*circle < *square);
			delete circle;
			delete square;
		}
		TEST_METHOD(OperatorGreaterEqual1)
		{
			Shape* square = new Square(5);
			Shape* rectangle = new Rectangle(5, 5);
			Assert::IsTrue(*square >= *rectangle);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorGreaterEqual2)
		{
			Shape* square = new Square(7);
			Shape* rectangle = new Rectangle(5, 5);
			Assert::IsTrue(*square >= *rectangle);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorLessEqual1)
		{
			Shape* square = new Square(5);
			Shape* rectangle = new Rectangle(5, 5);
			Assert::IsTrue(*rectangle <= *square);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorLessEqual2)
		{
			Shape* square = new Square(7);
			Shape* rectangle = new Rectangle(5, 5);
			Assert::IsTrue(*rectangle <= *square);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorGreaterEqualFalse1)
		{
			Shape* square = new Square(3);
			Shape* rectangle = new Rectangle(5, 5);
			Assert::IsFalse(*square >= *rectangle);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorGreaterEqualFalse2)
		{
			Shape* square = new Square(7);
			Shape* rectangle = new Rectangle(10, 10);
			Assert::IsFalse(*square >= *rectangle);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorLessEqualFalse1)
		{
			Shape* square = new Square(2);
			Shape* rectangle = new Rectangle(5, 5);
			Assert::IsFalse(*rectangle <= *square);
			delete square;
			delete rectangle;
		}
		TEST_METHOD(OperatorLessEqualFalse2)
		{
			Shape* square = new Square(2);
			Shape* rectangle = new Rectangle(5, 5);
			Assert::IsFalse(*rectangle <= *square);
			delete square;
			delete rectangle;
		}
	};
}
