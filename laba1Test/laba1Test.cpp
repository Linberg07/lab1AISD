#include "pch.h"
#include "CppUnitTest.h"
#include "../1laba/list.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace laba1Test
{
	TEST_CLASS(laba1Test)
	{
	public:
		
		TEST_METHOD(CreateTest)
		{
			List lst;
			Assert::IsTrue(lst.GetSize() == 0);
		}
		TEST_METHOD(PushBackEmptyTest)
		{
			List lst;
			lst.push_back(1);
			Assert::IsTrue((lst.GetSize() == 1) && (lst.at(0) == 1));
		}
		TEST_METHOD(PushBacknoEmptyTest)
		{
			List lst;
			lst.push_back(1);
			lst.push_back(2);
			Assert::IsTrue((lst.GetSize() == 2) && (lst.at(1) == 2)&&(lst.at(0)==1));
		}
		TEST_METHOD(PushFrontEmpyTest)
		{
			List lst;
			lst.push_front(1);
			Assert::IsTrue((lst.GetSize() == 1)&&(lst.at(0)==1));
		}
		TEST_METHOD(PushFrontnoEmptyTest)
		{
			List lst;
			lst.push_front(1);
			lst.push_front(2);
			Assert::IsTrue((lst.GetSize() == 2) && (lst.at(1) == 1) && (lst.at(0) == 2));
		}
		TEST_METHOD(PopBackEmptyTest)
		{
			List lst;
			try {
				lst.pop_back();
			}
			catch (const char* warning) {
				Assert::AreEqual(warning, "List is Empty!");
			}
			Assert::IsTrue((lst.GetSize() == 0)&&(lst.at(0)==NULL));
		}
		TEST_METHOD(PopBackOneElemTest)
		{
			List lst;
			lst.push_back(1);
			lst.pop_back();
			Assert::IsTrue((lst.GetSize() == 0)&&(lst.at(0)==NULL));
		}
		TEST_METHOD(PopBackTest)
		{
			List lst;
			lst.push_back(1);
			lst.push_back(2);
			lst.pop_back();
			Assert::IsTrue((lst.GetSize() == 1)&&(lst.at(0)==1));
		}
		TEST_METHOD(PopFrontEmptyTest)
		{
			List lst;
			try {
				lst.pop_front();
			}
			catch (const char* warning) {
				Assert::AreEqual(warning, "List is Empty!");
			}
			Assert::IsTrue((lst.GetSize() == 0) && (lst.at(0) == NULL));
		}
		TEST_METHOD(PopFrontOneElemTest)
		{
			List lst;
			lst.push_back(1);
			lst.pop_front();
			Assert::IsTrue((lst.GetSize() == 0) && (lst.at(0) == NULL));
		}
		TEST_METHOD(PopFrontTest)
		{
			List lst;
			lst.push_back(1);
			lst.push_back(2);
			lst.pop_front();
			Assert::IsTrue((lst.GetSize() == 1) && (lst.at(0) == 2));
		}
		TEST_METHOD(InsertEmptySecondIndexTest) {
			List lst;
			try {
				lst.insert(2, 1);
			}
			catch (const char* warning) {
				Assert::AreEqual(warning, "Wrong Index!");
			}
			Assert::IsTrue((lst.GetSize() == 0) && (lst.at(0) == NULL));
		}
		TEST_METHOD(InsertEmptyFirstIndexTest) {
			List lst;
			try {
				lst.insert(2, 0);
			}
			catch (const char* warning) {
				Assert::AreEqual(warning, "List is Empty!");
			}
			Assert::IsTrue((lst.GetSize() == 0) && (lst.at(0) == NULL));
		}
		TEST_METHOD(InsertFirstIndexTest) {
			List lst;
			lst.push_back(1);
			lst.insert(2, 0);
			Assert::IsTrue((lst.GetSize() == 2) && (lst.at(0) == 2));
		}
		TEST_METHOD(InsertLastIndexTest) {
			List lst;
			lst.push_back(1);
			lst.push_back(2);
			lst.insert(3, 1);
			Assert::IsTrue((lst.GetSize() == 3) && (lst.at(1) == 3));
		}
		TEST_METHOD(InsertMiddleIndexTest) {
			List lst;
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.push_back(5);
			lst.insert(10, 2);
			Assert::IsTrue((lst.GetSize() == 6) && (lst.at(2) == 10));
		}
		TEST_METHOD(AtTest) {
			List lst;
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			int index = lst.at(2);
			Assert::IsTrue(index = 3);
		}
		TEST_METHOD(RemoveEmptyFirstIndex) {
			List lst;
			try {
				lst.remove(0);
			}
			catch (const char* warning) {
				Assert::AreEqual(warning, "List is Empty!");
			}
			Assert::IsTrue((lst.GetSize() == 0) && (lst.at(0) == NULL));
		}
		TEST_METHOD(RemoveFirstIndex) {
			List lst;
			lst.push_back(1);
			lst.remove(0);
			Assert::IsTrue((lst.GetSize() == 0) && (lst.at(0) == NULL));
		}
		TEST_METHOD(RemoveunRealIndexinEmptyIndex) {
			List lst;
			try {
				lst.remove(2);
			}
			catch (const char* warning) {
				Assert::AreEqual(warning, "Wrong Index!");
			}
			Assert::IsTrue((lst.GetSize() == 0) && (lst.at(0) == NULL));
		}
		TEST_METHOD(RemoveunRealIndexTest) {
			List lst;
			try {
				lst.push_back(1);
				lst.push_back(2);
				lst.remove(2);
			}
			catch (const char* warning) {
				Assert::AreEqual(warning, "Wrong Index!");
			}
			Assert::IsTrue((lst.GetSize() == 2) && (lst.at(0) == 1) && (lst.at(1) == 2));
		}
		TEST_METHOD(GetSizeEmptyTest) {
			List lst;
			Assert::IsTrue(lst.GetSize() == 0);
		}
		TEST_METHOD(GetSizeTest) {
			List lst;
			lst.push_back(1);
			lst.push_back(2);
			Assert::IsTrue(lst.GetSize() == 2);
		}
		TEST_METHOD(ClearTest) {
			List lst;
			lst.push_back(1);
			lst.push_back(2);
			lst.clear();
			Assert::IsTrue((lst.GetSize() == 0)&&(lst.at(0)==NULL));
		}
		TEST_METHOD(SetunRealIndexTest) {
			List lst;
			try {
				lst.push_back(1);
				lst.push_back(2);
				lst.set(3, 2);
			}
			catch (const char* warning) {
				Assert::AreEqual(warning, "Wrong Index!");
			}
			Assert::IsTrue((lst.GetSize() == 2)&&(lst.at(0)==1)&&(lst.at(1)==2));
		}
		TEST_METHOD(SetEmptyIndexTest) {
			List lst;
			try {
				lst.set(3, 2);
			}
			catch (const char* warning) {
				Assert::AreEqual(warning, "List is Empty!");
			}
			Assert::IsTrue((lst.GetSize() == 0) && (lst.at(0) == NULL));
		}
		TEST_METHOD(SetFirstIndexTest) {
			List lst;
			lst.push_back(1);
			lst.set(0, 3);
			Assert::IsTrue((lst.GetSize() == 1) && (lst.at(0) == 3));
		}
		TEST_METHOD(SetLastIndexTest) {
			List lst;
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.set(2, 5);
			Assert::IsTrue((lst.GetSize() == 3) && (lst.at(0) == 1)&&(lst.at(1)==2)&&(lst.at(2)==5));
		}
		TEST_METHOD(isEmptynoEmptyTest) {
			List lst;
			lst.push_back(1);
			Assert::IsTrue(lst.isEmpty()==false);
		}
		TEST_METHOD(isEmptyTest) {
			List lst;
			Assert::IsTrue(lst.isEmpty() == true);
		}
		TEST_METHOD(PushFrontListTest) {
			List lst;
			List lst1;
			lst.push_back(2);
			lst.push_back(3);
			lst1.push_back(1);
			lst.push_front(lst1);
			Assert::IsTrue((lst.GetSize() == 3) && (lst.at(0) == 1) && (lst.at(1) == 2) && (lst.at(2) == 3));
		}
		TEST_METHOD(PushFrontListSecondEmptyTest) {
			List lst;
			List lst1;
			lst.push_back(2);
			lst.push_back(3);
			lst.push_front(lst1);
			Assert::IsTrue((lst.GetSize() == 2) && (lst.at(0) == 2) && (lst.at(1) == 3));
		}
		TEST_METHOD(PushFrontListFirstEmptyTest) {
			List lst;
			List lst1;
			lst1.push_back(2);
			lst1.push_back(3);
			lst.push_front(lst1);
			Assert::IsTrue((lst.GetSize() == 2) && (lst.at(0) == 2) && (lst.at(1) == 3));
		}
		TEST_METHOD(PushFrontListEmptyTest) {
			List lst;
			List lst1;
			lst.push_front(lst1);
			Assert::IsTrue((lst.GetSize() == 0) && (lst.at(0) == NULL));
		}

	};
}
