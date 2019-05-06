#include <iostream>
#include <iomanip>
#include <cstring>
#include "vacation.h"
using namespace std;

namespace vac {
	Vacay::Vacay() {
		empName = nullptr;
		empID = 0;
		vacayTime = 0.00;
	}
	Vacay::Vacay(int id, const char * nm) {
		if (nm != nullptr) {
			empName = new char[strlen(nm) + 1];
			strncpy(empName, nm, strlen(nm));
			empName[strlen(nm)] = '\0';
			empID = id;
			vacayTime = 0.00;
		}
		else
			*this = Vacay();
	}

	Vacay::~Vacay() {
		delete [] empName;
		empName = nullptr;
	}

	bool Vacay::operator+=(double extraTime) {
		bool done = false;
		if (extraTime > 0 && valid()) {
			vacayTime = time() + extraTime;
			done = true;
		}
		return done;
	}
	bool Vacay::operator-=(double takenTime) {
		bool done = false;
		if (takenTime > 0 && takenTime < time() && this->valid()) {
			vacayTime = time() - takenTime;
			done = true;
		}
		return done;
	}

	char* Vacay::name()const {
		return valid() ? empName : nullptr;
	}
	bool Vacay::valid() const {
		return empID != 0 && empName != nullptr ? true : false;
	}
	int Vacay::number() const {
		return empID;
	}
	double Vacay::time() const {
		return vacayTime;
	}

	ostream& operator<<(ostream& output, const Vacay& obj) {
		obj.write(output);
		return output;
	}

	ostream& Vacay::write(ostream& cout)const {
		//cout << "Number Accumulated Name" << endl;
		if (valid()) {
			cout << setw(6) << setfill('0') << right << empID;
			cout << setw(12) << setfill(' ') << fixed << setprecision(2) << time();
			//cout << " " << setw(7) << left << empName;
		}
		else {
			cout << "no data available";
		}
		return cout;
	}
}
