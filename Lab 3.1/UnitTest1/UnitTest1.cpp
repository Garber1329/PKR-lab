#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 3.1/Lab 3.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 1;
			Student* k = new Student[N];
			string name = "a";
			k->prizv = "a";
			k->kurs = (Kurs)1;
			k->spec = (Spec)1;
			k->physics = 5;
			k->maths = 5;
			k->numMethods = 5;

			string actual = highestAverageScore(k, N);
			Assert::AreEqual(name, actual);
			Assert::IsTrue(percentageStudentsStudyExcellently(k, N) >=  0.0);
		}

	};
}
