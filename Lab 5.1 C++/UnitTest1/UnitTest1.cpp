#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 5.1 C++/Lab 5.1 C++.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k = 15;
			Assert::AreEqual(Process("f.dat", "g.dat"), k);
		}
	};
}
