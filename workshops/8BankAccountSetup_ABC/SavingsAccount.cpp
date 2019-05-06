/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: I
Date:03/19/2019
----------------------------------------------
Workshop: 8
---------------------------------------------- */
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;

namespace sict {
	SavingsAccount::SavingsAccount(double bal, double int_rate): Account(bal){
		if (int_rate > 0) {
			interestRate = int_rate; //assign
		}
		else
		{
			interestRate = 0.0; //empty state is set
		}
	}
	void SavingsAccount::monthEnd() {
		double newBal = balance();
		double rate = newBal * interestRate;
		credit(rate);
	}
	void SavingsAccount::display(ostream& out)const {
		out << "Account type: Savings\n";
		out << "Balance: $";
		out << fixed;
		out << setprecision(2);
		out << balance() << "\nInterest Rate (%): ";
		out << interestRate*100 << endl;

	}
}
