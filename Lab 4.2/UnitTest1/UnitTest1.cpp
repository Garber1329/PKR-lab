#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 4.2/Lab 4.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			string s,
				result = "ab+0.19–1.1";
			RoundingTXT("../t", "../t2");
			ifstream f("t2");
			while (f >> s)
			Assert::AreEqual(s,result);
		}
	};
}
