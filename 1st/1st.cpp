#include <map>
#include <vector>
#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP-SA1-Solution-2022/grade.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/*
BTEC Classification 60 points equate to Pass
BTEC Learner Results
{ (A12343:70) (A32323:32) (B3223:104) (F000000:39) (J239849:12) (L13217:135) (Q58940849:77) (V12899:45.9) (Z123131:55) }
BTEC High Performers { (B3223) (L13217) }
BTEC Low Performers { (J239849) }
*/

namespace My1st
{
	TEST_CLASS(My1st)
	{
	private:
		Grade grader;


		std::vector<std::pair<int, std::string>> btecUnitBoundaries
		{ {6, "NP"}, { 9, "P" }, { 15, "M" }, { 24, "D" } };




	public:

		TEST_METHOD(CalculateFinalGradeBtec)
		{
			std::vector<std::pair<double, std::string>> btecBoundaries
			{ {0, "Fail"} , {51, "Pass"} , {73, "Merit"} , {104, "Distinction"}, {130, "Distinction*"} };

			std::string correctClassification = "Pass";

			std::vector<int> btecAllModuleMarks{ 15, 9, 9, 9, 9, 9 };

			std::pair<double, std::string> btecCourseGrade = grader.finalGrade(btecAllModuleMarks, btecBoundaries);

			Assert::AreEqual(60, btecCourseGrade.first, 0.01, L"The finalGrade method for BTEC module marks calculated the result incorrectly.");
			Assert::AreEqual(correctClassification, btecCourseGrade.second, L"The finalGrade method for BTEC module marks calculated the classification incorrectly.");

			// Empty first vector

			auto zeroMarksFunc = [btecBoundaries] {
				std::vector<double> emptyVector;

				Grade localGrader;
				std::pair<double, std::string> bscCourseGrade = localGrader.finalGrade(emptyVector, btecBoundaries);
			};

			Assert::ExpectException<std::invalid_argument>(zeroMarksFunc, L"Final grade failed to to throw and exception when passed an empty vector, for the first parameter module marks.");

			// Empty second vector

			auto zeroBoundariesFunc = [btecAllModuleMarks] {
				std::vector<std::pair<double, std::string>> emptyVector;

				Grade localGrader;
				std::pair<double, std::string> bscCourseGrade = localGrader.finalGrade(btecAllModuleMarks, emptyVector);
			};

			Assert::ExpectException<std::invalid_argument>(zeroBoundariesFunc, L"Final grade failed to to throw and exception when passed an empty vector, for the second parameter mark boundaries.");

		}


		TEST_METHOD(CalculateUnitScoreBtec)
		{
			std::vector<std::vector<classifiedAssessmentGrade>> btecUnitAssessmentResults
			{
			{ {6,12}, {12,24}, {24,24} },
			{ {6,12}, {12,24}, {24,24} },
			{ {12,12}, {12,24}, {24,24} },
			{ {6,12}, {12,24}, {24,24} },
			{ {12,12}, {24,24}, {24,24} },
			{ {6,12}, {12,24}, {12,24} }
			};

			std::vector<double> correctModuleMarks{ 6, 6, 12, 6, 24, 6 };

			double unitScore = 0;
			std::string progressMessage;

			// Grade validity checks
			for (std::size_t i = 0; i < correctModuleMarks.size(); i++) {

				unitScore = grader.calculateUnitScore(btecUnitAssessmentResults[i]);

				progressMessage = "Array Element : " + std::to_string(i);
				Logger::WriteMessage(progressMessage.c_str());

				Assert::AreEqual(correctModuleMarks[i], unitScore, 0.01, 
					L"The calculateUnitScore method for BTEC module marks calculated the result incorrectly.");

				Logger::WriteMessage(" Processed Ok\n");
			}

			// Empty vector test
			auto func = [] {
				std::vector<weightedAssessmentGrade> emptyVector;

				Grade localGrader;
				double result = localGrader.calculateUnitScore(emptyVector);
			};

			Assert::ExpectException<std::invalid_argument>(func, L"Calculate unit score failed to to throw and exception when passed an empty vector.");
		}

	};
}
