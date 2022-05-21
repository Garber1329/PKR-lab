#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.6/Lab 6.6.cpp"

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
			Elem* first1 = NULL,
				* last1 = NULL;

			readTXT(first, last, first1, last1);

			Assert::IsTrue(toCompare(first, first1));
		}
	};
}
