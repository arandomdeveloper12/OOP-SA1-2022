#include <map>
#include <vector>
#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP-SA1-Solution-2022/grade.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My22
{
	TEST_CLASS(My22)
	{
	private:
		Grade grader;

		std::vector<double> btecVectData{ 70, 32, 104, 39, 12, 135, 77, 45.9, 55 };

		std::map<std::string, double> bscLearnerGrades{
		  {"A12343", 70}, {"A32323", 32 }, {"B3223", 65}, {"Z123131", 55}, {"V12899", 45.9},
		  {"Q58940849", 77}, {"J239849", 12}, {"L13217", 95 }, {"F000000", 39 }
		};

		std::map<std::string, double> btecLearnerGrades{
			{"A12343", 70}, {"A32323", 32 }, {"B3223", 104}, {"Z123131", 55}, {"V12899", 45.9},
			{"Q58940849", 77}, {"J239849", 12}, {"L13217", 135 }, {"F000000", 39 }
		};

	public:
		TEST_METHOD(StandardDeviation)
		{
			double sdResult = grader.standardDeviation(btecVectData, grader.mean(btecVectData));
			Assert::AreEqual(35.906, sdResult, 0.001, L"The standard deviation method did not calculate the result correctly.");
		}

		TEST_METHOD(HighPerformingLearners)
		{
			// BTEC High Performers { (B3223) (L13217) }			
			std::vector<std::string> btecHighPerforming = grader.highPerformingLearners(btecLearnerGrades);
			std::string learnerIds = "";
			std::string expectedLearnerIds = "B3223L13217";
			for (auto currentLearnerId : btecHighPerforming) {
				learnerIds = learnerIds.append(currentLearnerId);
			}
			Assert::AreEqual(expectedLearnerIds, learnerIds, L"High performing learners reported do not match the test data.");

		}

		TEST_METHOD(LowPerformingLearners)
		{
			// BTEC Low Performers{ (J239849) }
			std::vector<std::string> btecLowPerforming = grader.lowPerformingLearners(btecLearnerGrades);
			std::string learnerIds = "";
			std::string expectedLearnerIds = "J239849";
			for (auto currentLearnerId : btecLowPerforming) {
				learnerIds = learnerIds.append(currentLearnerId);
			}

			Assert::AreEqual(expectedLearnerIds, learnerIds, L"Low performing learners reported do not match the test data.");

		}

		TEST_METHOD(ExceptionSum)
		{
			auto func = [] {
				std::vector<double> emptyVector;

				Grade localGrader;
				long double result = localGrader.sum(emptyVector);
			};

			Assert::ExpectException<std::invalid_argument>(func, L"Sum failed to to throw and exception when passed an empty vector.");
		}

		TEST_METHOD(ExceptionMean)
		{
			auto func = [] {
				std::vector<double> emptyVector;

				Grade localGrader;
				double result = localGrader.mean(emptyVector);
			};

			Assert::ExpectException<std::invalid_argument>(func, L"Mean failed to to throw and exception when passed an empty vector.");
		}

		TEST_METHOD(ExceptionPopulationVariance)
		{
			auto func = [] {
				std::vector<double> emptyVector;

				Grade localGrader;
				double result = localGrader.populationVariance(emptyVector,0);
			};

			Assert::ExpectException<std::invalid_argument>(func, L"Population Variance failed to to throw and exception when passed an empty vector.");
		}

		TEST_METHOD(ExceptionStandardDeviation)
		{
			auto func = [] {
				std::vector<double> emptyVector;

				Grade localGrader;
				double result = localGrader.standardDeviation(emptyVector, 0);
			};

			Assert::ExpectException<std::invalid_argument>(func, L"Standard Deviation failed to to throw and exception when passed an empty vector.");
		}
	};
}
