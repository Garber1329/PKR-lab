#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.8/Lab 6.8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			StElem* first = NULL,
				* last = NULL;
			AddElem(first, last, "gh", 5, 500);
			AddElem(first, last, "zdg", 3, 0);
			AddElem(first, last, "rdtx", 5, 600);

			int k =	Find(first, 0, 5);

			Assert::AreEqual(k, 2);
		}
	};
}
