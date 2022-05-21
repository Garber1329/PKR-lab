#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.5/Lab 6.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* top = NULL;

			readTXT(top);

			Assert::AreEqual(count(top),4);
		}
	};
}
