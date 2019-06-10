/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: I
Date:03/28/2019
----------------------------------------------
Workshop: 9
---------------------------------------------- */
#include <iostream>
#include <cstring>
#include "Data.h"

using namespace std;

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	
	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		int pop_ = population[n - 1] - population[0];
		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is ";
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << static_cast<double>(pop_) / 1000000 << " million" << endl;
		cout.unsetf(ios::fixed);


		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005

		auto violentCrime1 = violentCrime[0];
		auto violentCrime2 = violentCrime[n - 1];
		const char *mode;
		if (violentCrime1 < violentCrime2) {
			mode = "up";
		}
		else
			mode = "down";
		cout << "Violent Crime trend is " << mode << endl;

		// Q3 print the GTA number accurate to 0 decimal places

		double lossRecorded = 0;
		lossRecorded = average(grandTheftAuto, n);
		cout << "There are ";
		cout.precision(2);
		cout << fixed << lossRecorded / 1000000 << " million Grand Theft Auto incidents on average a year" << endl;

		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;

	}
}