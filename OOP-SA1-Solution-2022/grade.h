#pragma once
// Callum Dyson 14/12/2022
// SA01
#include <string>
#include <vector>
#include <map>

struct classifiedAssessmentGrade {
	int grade;
	int maxGrade;
};

struct weightedAssessmentGrade {
	double grade;
	double weighting;
};

// Class specification

class Grade
{
private:

protected:

public:

	// Sample 
	double add(double dataItem1, double dataItem2);
	double subtract(double dataItem1, double dataItem2);


	// 3rd Methods
	// Methods for the sum
	long double sum(const std::vector<double>&);
	long double sum(const std::vector<int>&);
	// Methods for the mean
	double mean(const std::vector<double>&);
	double mean(const std::vector<int>&);
	// Method for the populationVariance
	double populationVariance(const std::vector<double>&, double mean);

	// 2.2 Methods


	// 2.1 Methods


	// 1st Methods


};

// Class Implementation
long double Grade::sum(const std::vector<double>& data) {
	//if (std::vector<double>::empty) throw std::invalid_argument("The vector is empty!");
	return 0;
}

long double Grade::sum(const std::vector<int>& data) {
	//if (std::vector<double>::empty) throw std::invalid_argument("The vector is empty!");
	return 0;
}

double Grade::mean(const std::vector<double>& data) {
	//if (std::vector<double>::empty) throw std::invalid_argument("The vector is empty!");
	return 0;
}

double Grade::mean(const std::vector<int>& data) {
	//if (std::vector<double>::empty) throw std::invalid_argument("The vector is empty!");
	return 0;
}

double Grade::populationVariance(const std::vector<double>& data, double mean) {
	//if (std::vector<double>::empty) throw std::invalid_argument("The vector is empty!");
	return 0;
}

// Sample code passed test
double Grade::add(double dataItem1, double dataItem2) {
	return dataItem1 + dataItem2;
}

// Sample code failed test (error in the code)
double Grade::subtract(double dataItem1, double dataItem2) {
	// Uncomment the line below to fix the failed test
	return dataItem1 - dataItem2;
	// return dataItem1 - dataItem1;
}