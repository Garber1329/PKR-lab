#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 5.2/Lab 5.2 B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char f[6] = "f.dat";
			double n = 25,
				c = percentageStudentsStudyExcellently(f);

			Assert::AreEqual(c, n);
		}
	};
}
