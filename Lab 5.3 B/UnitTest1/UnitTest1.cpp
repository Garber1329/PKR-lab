#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 5.3 B/Lab 5.3 B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char f[6] = "f.dat";
			int t = binSearch(f, "katsap", 1, 2);
			Assert::AreEqual(t, 3);
		}
	};
}
