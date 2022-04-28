#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 5.3 A/Lab 5.3 A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char f[6] = "f.dat";
			int t = binSearch(f, "dv", 2, 2);
			Assert::AreEqual(t, 2);
		}
	};
}
