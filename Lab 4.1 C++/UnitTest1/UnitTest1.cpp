#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 4.1 C++/Lab 4.1 C++.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			int k = 3;
			Assert::AreEqual(ProcessTXT1("../t"), k);
		}
	};
}
