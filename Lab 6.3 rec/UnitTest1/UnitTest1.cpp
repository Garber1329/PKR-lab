#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.3 rec/Lab 6.3 rec.cpp"

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

			Create(first, last, -10);
			PrintEnum(first, last, first);

			int res = 0;
			count(first, last, first, res);
			Assert::AreEqual(res, 10);
		}
	};
}
