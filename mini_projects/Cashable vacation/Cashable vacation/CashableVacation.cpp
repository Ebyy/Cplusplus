#include<iostream>
#include <cstring>
#include <iomanip>
#include "CashableVacation.h"
#include "vacation.h"
using namespace std;

namespace vac {
	CashableVacation::CashableVacation(){
		rate = 0.00;
		vacInCash = 0.00;
	}
	CashableVacation::CashableVacation(int empNum, const char* emp, double convRate) : Vacay(empNum, emp) {
		if (convRate > 0 && convRate >= MIN_WAGE) {
			rate = convRate;
			vacInCash = 0.00;
		}
		else {
			*this = CashableVacation();
		}
	}

	bool CashableVacation::valid() const {
		return rate != 0 ? true : false;
	}
	double CashableVacation::cashable() const {
		return vacInCash;
	}
	double CashableVacation::conversionRate()const {
		return rate;
	}
	bool CashableVacation::operator-=(double amt) {
		bool status = false;
		if (amt > 0 && amt < cashable()) {
			vacInCash = cashable() - amt;
			status = true;
		}
		return status;
	}
	void CashableVacation::makeCashable(double time2convert) {
		if (time2convert > 0 && time2convert < time()) {
			vacInCash = time2convert * conversionRate();
		}
	}
	ostream& operator<<(ostream& os, const CashableVacation& rhs) {
		rhs.display(os);
		
		return os;
	}


	ostream& CashableVacation::display(ostream& cout)const {
		Vacay::write(cout);
		if (valid()) {
			cout << setw(6) << fixed << setprecision(2) << rate;
			cout << setw(9) << right << fixed << setprecision(2) << cashable();
			cout << " " << setw(7) << left << name();
		}
		return cout;
	}
}