#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.2 rec/Lab 6.2 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			LinkedList ll;

			for (int i = 1; i <= 5; i++)
				ll.enqueue(ll.first, ll.last, i);
			int n = 0;
			while (ll.first != NULL)
				n += ll.dequeue(ll.first, ll.last);
			Assert::AreEqual(n, 15);
		}
	};
}
