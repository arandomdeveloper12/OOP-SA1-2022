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
	// If the vector is not empty, do the following code
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
	// If the vector is not empty, do the following code
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
	// If the vector is not empty, do the following code
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
	// If the vector is not empty, do the following code
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
	// If the vector is not empty, do the following code
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

// Commit details below
// ----------------------------------------------------------

/* 
Commit d504b1e448d488582960b0f3ea4e899a65cca512
Author: Callum Dyson <313906@student.lincolncollege.ac.uk>
Date : 14 December 2022 10 : 57
Parent : 880fa797
Creating and implementing the method signatures and implementing them

Commit 9b139f7992f00577191a52671a943942c3d435b8
Author : Callum Dyson <313906@student.lincolncollege.ac.uk>
Authored Date : 28 December 2022 19 : 04
Committer : Callum Dyson <313906@student.lincolncollege.ac.uk>
Commit Date : 28 December 2022 19 : 39
Parent : d504b1e4
Creating and implementing both classes(long doubleand int) for the sum

Commit f9759d19c7c70a6d4236f685faac62356ba4d875
Author : Callum Dyson <313906@student.lincolncollege.ac.uk>
Date : 28 December 2022 20 : 22
Parents : 9b139f79, 4224cc94
Sum and mean branches has been merged into the 3rd branch

Commit 3a571ba8e83a206b9a9c980f550865da8a5787e0
Author: Callum Dyson <313906@student.lincolncollege.ac.uk>
Date: 28 December 2022 20:27
Parent: f9759d19
Fixed merge issue with other branches so duplicate code has been removed

Commit 6b120331956b1b2113bffed376c6ae97245de0c6
Author: Callum Dyson <313906@student.lincolncollege.ac.uk>
Date: 29 December 2022 18:42
Parents: 3a571ba8, a71ac36d
Fixed merge problem between the 3rd branch and population branch

*/