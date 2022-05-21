#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.7/Lab 6.7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Train* first = NULL,
				* last = NULL;

			AddNewElem(first, last, 12, 12, 12, 2);

			Assert::AreEqual(first->track, 2);
		}
	};
}
