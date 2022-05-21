#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.2 iter/Lab 6.2 iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL,
				* last = NULL;

			for (int i = 1; i <= 5; i++)
				enqueue(first, last, i);

			int n = Reverse(&first);
			Assert::AreEqual(n, 15);
		}
	};
}
