#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.10/Lab 6.10.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Node* root = NULL;
			bool found = false;
			root = BinarySearchInsert(root, 0, found);
			int n = root->info;
			Assert::AreEqual(n, 0);
		}
	};
}
