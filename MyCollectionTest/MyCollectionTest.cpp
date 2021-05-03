#include "CppUnitTest.h"
#include "../MyCollection/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<List<int>::Iterator>(const List<int>::Iterator& it)
{
	std::wstring result;
	result += ToString(*it);
	return result;
}

namespace MyCollectionTest
{
	TEST_CLASS(MyCollectionTest)
	{
	public:
		TEST_METHOD(ListConstructor)
		{
			List<int> list;
			Assert::AreEqual(list.size(), (size_t)0);
		}

		TEST_METHOD(ListAppend1)
		{
			List<int> list;
			list.append(3);
			Assert::AreEqual(list.size(), (size_t)1);
			Assert::AreEqual(list.getElement(0), 3);
			Assert::IsTrue(list.isIn(3));
		}
		TEST_METHOD(ListAppend2)
		{
			List<int> list;
			list.append(2);
			list.append(3);
			Assert::AreEqual(list.size(), (size_t)2);
			Assert::AreEqual(list.getElement(0), 2);
			Assert::AreEqual(list.getElement(1), 3);
			Assert::IsTrue(list.isIn(3));
			Assert::IsTrue(list.isIn(2));
		}
		TEST_METHOD(ListOperatorAddAssignment)
		{
			List<int> list;
			list.append(2);
			list += 3;
			Assert::AreEqual(list.size(), (size_t)2);
			Assert::AreEqual(list.getElement(0), 2);
			Assert::AreEqual(list.getElement(1), 3);
			Assert::IsTrue(list.isIn(3));
			Assert::IsTrue(list.isIn(2));
		}
		TEST_METHOD(ListRemove)
		{
			List<int> list;
			list.append(4);
			list.append(3);
			list.append(7);
			Assert::AreEqual(list.size(), (size_t)3);
			Assert::IsTrue(list.isIn(4));
			Assert::IsTrue(list.isIn(3));
			Assert::IsTrue(list.isIn(7));
			list.removeFromList(1);
			Assert::AreEqual(list.size(), (size_t)2);
			Assert::IsTrue(list.isIn(4));
			Assert::IsFalse(list.isIn(3));
			Assert::IsTrue(list.isIn(7));
		}
		TEST_METHOD(ListRemoveBadIndex)
		{
			List<int> list;
			list += 3;
			list += 5;
			list += 9;
			auto func = [&] { list.removeFromList(5); };
			Assert::ExpectException<std::invalid_argument>(func);
		}
		TEST_METHOD(ListGetElement)
		{
			List<int> list;
			list.append(4);
			list.append(7);
			list.append(2);
			Assert::AreEqual(list.getElement(0), 4);
			Assert::AreEqual(list.getElement(1), 7);
			Assert::AreEqual(list.getElement(2), 2);
		}
		TEST_METHOD(ListGetElementBadIndex)
		{
			List<int> list;
			list.append(4);
			list.append(7);
			list.append(2);
			auto func = [&] { list.getElement(5); };
			Assert::ExpectException<std::invalid_argument>(func);
		}
		TEST_METHOD(ListSize)
		{
			List<int> list;
			Assert::AreEqual(list.size(), (size_t)0);
			list.append(3);
			Assert::AreEqual(list.size(), (size_t)1);
			list += 32;
			Assert::AreEqual(list.size(), (size_t)2);
			list.removeFromList(0);
			Assert::AreEqual(list.size(), (size_t)1);
		}
		TEST_METHOD(IteratorBegin)
		{
			List<int> list;
			list.append(5);
			list.append(4);
			list.append(9);
			auto it = list.begin();
			Assert::AreEqual(*it, 5);
		}
		TEST_METHOD(IteratorBeginReverse)
		{
			List<int> list;
			list.append(5);
			list.append(4);
			list.append(9);
			auto it = list.rbegin();
			Assert::AreEqual(*it, 9);
		}
		TEST_METHOD(IteratorEnd)
		{
			List<int> list;
			list.append(4);
			list.append(3);
			auto it = list.begin();
			it++;
			it++;
			auto end_it = list.end();
			Assert::IsTrue(it == end_it);
		}
		TEST_METHOD(IteratorEndReverse)
		{
			List<int> list;
			list.append(4);
			list.append(3);
			auto it = list.rbegin();
			it++;
			it++;
			Assert::IsTrue(it == list.rend());
		}
		TEST_METHOD(IteratorIncrementOperator)
		{
			List<int> list;
			list.append(4);
			list.append(3);
			list.append(7);
			auto it = list.begin();
			Assert::AreEqual(*it, 4);
			Assert::AreEqual(*++it, 3);
			Assert::AreEqual(*it++, 3);
			Assert::AreEqual(*it, 7);
		}
		TEST_METHOD(IteratorIncrementOperatorReverse)
		{
			List<int> list;
			list.append(4);
			list.append(3);
			list.append(7);
			list.append(5);
			auto it = list.rbegin();
			Assert::AreEqual(*it, 5);
			Assert::AreEqual(*++it, 7);
			Assert::AreEqual(*it++, 7);
			Assert::AreEqual(*it, 3);
		}
		TEST_METHOD(IteratorDecrementOperator)
		{
			List<int> list;
			list.append(4);
			list.append(3);
			list.append(7);
			list.append(5);
			auto it = list.begin();
			++it;
			++it;
			++it;
			Assert::AreEqual(*it, 5);
			Assert::AreEqual(*--it, 7);
			Assert::AreEqual(*it--, 7);
			Assert::AreEqual(*it, 3);
		}
		TEST_METHOD(IteratorDecrementOperatorReverse)
		{
			List<int> list;
			list.append(4);
			list.append(3);
			list.append(7);
			list.append(5);
			auto it = list.rbegin();
			++it;
			++it;
			++it;
			Assert::AreEqual(*it, 4);
			Assert::AreEqual(*--it, 3);
			Assert::AreEqual(*it--, 3);
			Assert::AreEqual(*it, 7);
		}
		TEST_METHOD(IteratorEqualOperator)
		{
			List<int> list;
			list.append(4);
			list.append(3);
			list.append(7);
			list.append(5);
			auto it = list.begin();
			auto it2 = list.begin();
			auto it3 = list.end();
			Assert::IsTrue(it == it2);
			Assert::IsFalse(it2 == it3);
		}
		TEST_METHOD(IteratorNotEqualOperator)
		{
			List<int> list;
			list.append(4);
			list.append(3);
			list.append(7);
			list.append(5);
			auto it = list.begin();
			auto it2 = list.begin();
			auto it3 = list.end();
			Assert::IsFalse(it != it2);
			Assert::IsTrue(it2 != it3);
		}
		TEST_METHOD(IteratorAsteriskOperator)
		{
			List<int> list;
			list.append(4);
			list.append(3);
			list.append(7);
			list.append(5);
			auto it = list.begin();
			Assert::AreEqual(*it, 4);
			++it;
			Assert::AreEqual(*it, 3);
			++it;
			Assert::AreEqual(*it, 7);
			++it;
			Assert::AreEqual(*it, 5);
		}
		TEST_METHOD(IteratorOutOfRange)
		{
			List<int> list;
			list += 5;
			list += 3;
			auto it = list.begin();
			it++;
			it++;
			auto func = [&] { *it; };
			Assert::ExpectException<std::out_of_range>(func);
		}
	};
}
