/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: I
Date:03/28/2019
----------------------------------------------
Workshop: 9
---------------------------------------------- */
#ifndef _DATA_H
#define _DATA_H

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;


namespace sict {
	// These number defines the output column width for a single data field



	const int COLUMN_WIDTH    = 15;

	//int min(const int* data, int n);
	// max returns the largest item in data
	template <typename T>
	T max(const T*data, int n) {
		T max = 0; //data[0];
		for (int x = 0; x < n; x++) {
			if (data[x] > max) {
				max = data[x];
			}
		}
		return max;
	}


	// min returns the smallest item in data
	template <typename T>
	T min(const T*data, int n) {
		T min = data[0]; //data[0];

		for (int x = 1; x < n; x++) {
			if (data[x] < min) {
				min = data[x];
			}
		}
		return min;
	}


	// sum returns the sum of n items in data
	template <typename T>
	T sum(const T*data, int n) {
		T total = 0;
		for (int x = 0; x < n; x++) {
			total += data[x];
		}
		return total;
	}

	// average returns the average of n items in data
	template <typename T>
	double average(const T*data, int n) {
		T total = 0;
		double average;
		for (int x = 0; x < n; x++) {
			total += data[x];
		}
		average = static_cast<double>(total) / n;
		return average;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//

	

	template <typename T>
	bool read(istream& input, T* data, int n) {
		bool attempt;
		int flagFail = 0;
		char x;

		//input.ignore();

		for (int i = 0; i < n; i++) {
			input >> x;
			input >> data[i];
			
			if (input.fail()) {
				flagFail = 1;
				//i = n;
			}
		}
		if (flagFail == 1) {
			attempt = false;
		}
		else
			attempt = true;
		return attempt;
	}

	// display inserts n items of data into std::cout
	template<typename T>
	void display(const char* name, const T* data, int n) {
		cout << setw(20) << right << name;
		for (int i = 0; i < n; i++) {
			cout << setw(15) << right << data[i];
		}
		cout << endl;
	}

	template <typename T>
	T readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,...

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');

			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

#endif // !_DATA_H

