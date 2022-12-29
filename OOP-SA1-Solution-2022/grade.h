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
// Implementation of the Sum class (long double)
long double Grade::sum(const std::vector<double>& data) {
	if (data.empty()) { throw std::invalid_argument("The vector is empty!"); }
	else {
		long double sum_values = 0;
		for (int sum_counter = 0; sum_counter < data.size(); sum_counter++) {
			sum_values += data[sum_counter];
		}
		return sum_values;
	}
	return 0;
}

// Implementation of the Sum class (int)
long double Grade::sum(const std::vector<int>& data) {
	if (data.empty()) { throw std::invalid_argument("The vector is empty!"); }
	else {
		long double sum_values = 0;
		for (int sum_counter = 0; sum_counter < data.size(); sum_counter++) {
			sum_values += data[sum_counter];
		}
		return sum_values;
	}
	return 0;
}

// Implementation of the mean class (double)
double Grade::mean(const std::vector<double>& data) {
	if (data.empty()) { throw std::invalid_argument("The vector is empty!"); }
	else {
		double mean_values = 0;
		for (int mean_counter = 0; mean_counter < data.size(); mean_counter++) {
			mean_values += data[mean_counter];
		}
		mean_values = mean_values / data.size();
		return mean_values;
	}
	return 0;
}

// Implementation of the mean class (int)
double Grade::mean(const std::vector<int>& data) {
	if (data.empty()) { throw std::invalid_argument("The vector is empty!"); }
	else {
		double mean_values = 0;
		for (int mean_counter = 0; mean_counter < data.size(); mean_counter++) {
			mean_values += data[mean_counter];
		}
		mean_values = mean_values / data.size();
		return mean_values;
	}
	return 0;
}

// Implemetation of the population variance method
double Grade::populationVariance(const std::vector<double>& data, double mean) {
	if (data.empty()) { throw std::invalid_argument("The vector is empty!"); }
	else {
		double population_variance_value = 0;
		double mean_data = Grade::mean(data);
		for (int pv_counter = 0; pv_counter < data.size(); pv_counter++) {
			double pv_temp_value = (data[pv_counter] - mean_data);
			population_variance_value += (pv_temp_value * pv_temp_value);
		}
		double pv_result = population_variance_value / data.size();
		return pv_result;
	}
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