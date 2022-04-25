#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 4.3/Lab 4.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			bool k = searchForNameStore("../t.txt", "ui");
			Assert::AreEqual(k,true);
		}
	};
}
