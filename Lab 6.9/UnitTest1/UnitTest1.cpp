#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.9/Lab 6.9.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Node* root = NULL;
			int i = Count(root);
			Assert::AreEqual(i, 0);
		}
	};
}
