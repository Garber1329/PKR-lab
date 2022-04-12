﻿#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 3.2A/Lab 3.2A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1Lab32A
{
	TEST_CLASS(UnitTest1Lab32A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 2;
			Student* k = new Student[N];
			k[0].prizv = "a";
			k[0].kurs = (Kurs)1;
			k[0].spec = (Spec)1;
			k[0].physics = 5;
			k[0].maths = 5;
			k[0].informat = 5;
			k[1].prizv = "b";
			k[1].kurs = (Kurs)2;
			k[1].spec = (Spec)2;
			k[1].physics = 5;
			k[1].maths = 5;
			k[1].informat = 5;

			Assert::IsTrue(BinSearch(k, N, "b", (Kurs)2, (Spec)2) == 1);
		}
	};
}
