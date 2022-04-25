#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 4.4/Lab 4.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(ProcessTXT1("../t.txt"));
		}
	};
}
