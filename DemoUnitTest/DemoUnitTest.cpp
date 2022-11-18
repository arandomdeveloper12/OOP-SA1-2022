#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP-SA1-Solution-2022/grade.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DemoUnitTest
{
	TEST_CLASS(DemoUnitTest)
	{
	public:
		Grade grader;
		
		TEST_METHOD(AddTest)
		{
			Assert::AreEqual(5 + 9.5, grader.add(5, 9.5), 0.001, L"Add method did not total the two values correctly.");
		}

		TEST_METHOD(SubtractTest)
		{
			Assert::AreEqual(5 - 9.5, grader.subtract(5, 9.5), 0.001, L"Add method did not total the two values correctly.");
		}
	};
}
