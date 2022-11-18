#include <map>
#include <vector>
#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP-SA1-Solution-2022/grade.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/*
BSc. Classification 61 points equate to 2.1
BSc. Learner Results
{ (A12343:70) (A32323:32) (B3223:65) (F000000:39) (J239849:12) (L13217:95) (Q58940849:77) (V12899:45.9) (Z123131:55) }
BSc. High Performers { (L13217) }
BSc. Low Performers { (J239849) }
*/

namespace My21
{
	TEST_CLASS(My21)
	{

	private:
		Grade grader;


		std::vector<weightedAssessmentGrade> bscModuleAssessmentResults{ {20,0.20},{60, 0.50},{90, 0.30} };
	public:
		
		TEST_METHOD(CalculateFinalGradeBsc)
		{

			std::vector<std::pair<double, std::string>> bscBoundaries
			{ {0, "Fail"} , {35, "Condonable"} , {40, "3rd"} , {50, "2.2"} ,
				{60, "2.1"} , {70, "Lower 1st"} , {80, "Middle 1st"} ,
				{90, "Upper 1st"} };

			std::string correctClassification = "2.1";

			std::vector<double> bscAllModuleMarks{ 61, 71, 51, 67, 60, 65 };

			std::pair<double, std::string> bscCourseGrade = grader.finalGrade(bscAllModuleMarks, bscBoundaries);

			Assert::AreEqual(62.5, bscCourseGrade.first, 0.01, L"The finalGrade method for BSc. module marks calculated the result incorrectly.");
			Assert::AreEqual(correctClassification, bscCourseGrade.second, L"The finalGrade method for BSc. module marks calculated the classification incorrectly.");

			// Empty first vector

			auto zeroMarksFunc = [bscBoundaries] {
				std::vector<double> emptyVector;

				Grade localGrader;
				std::pair<double, std::string> bscCourseGrade = localGrader.finalGrade(emptyVector, bscBoundaries);
			};

			Assert::ExpectException<std::invalid_argument>(zeroMarksFunc, L"Final grade failed to to throw and exception when passed an empty vector, for the first parameter module marks.");

			// Empty second vector

			auto zeroBoundariesFunc = [bscAllModuleMarks] {
				std::vector<std::pair<double, std::string>> emptyVector;

				Grade localGrader;
				std::pair<double, std::string> bscCourseGrade = localGrader.finalGrade(bscAllModuleMarks, emptyVector);
			};

			Assert::ExpectException<std::invalid_argument>(zeroBoundariesFunc, L"Final grade failed to to throw and exception when passed an empty vector, for the second parameter mark boundaries.");

		}


		TEST_METHOD(CalculateUnitScoreBSc)
		{

			double moduleMark = grader.calculateUnitScore(bscModuleAssessmentResults);

			Assert::AreEqual(61, moduleMark, 0.01, L"The calculateUnitScore method for BSc. module marks calculated the result incorrectly.");

			auto func = [] {
				std::vector<weightedAssessmentGrade> emptyVector;

				Grade localGrader;
				double result = localGrader.calculateUnitScore(emptyVector);
			};

			Assert::ExpectException<std::invalid_argument>(func, L"Calculate unit score failed to to throw and exception when passed an empty vector.");
		}
	};
}
