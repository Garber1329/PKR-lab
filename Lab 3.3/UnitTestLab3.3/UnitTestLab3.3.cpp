#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 3.3/Lab 3.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab33
{
	TEST_CLASS(UnitTestLab33)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 2;
			Price* k = new Price[N];
			k[0].nameTowar = "a";
			k[0].shop = "a";
			k[0].cost = 1;
			k[0].nameTowar = "b";
			k[0].shop = "b";
			k[0].cost = 2;

			Assert::IsTrue(PrintShop(k, N, "b") == 1);
		}
	};
}
