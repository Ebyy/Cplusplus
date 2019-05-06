/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: I
Date:03/21/2019
----------------------------------------------
Workshop: 8
---------------------------------------------- */
#include <iostream>
#include <cstring>
#include <iomanip>
#include "ChequingAccount.h"
using namespace std;

namespace sict {
	ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee) : Account(balance) {
		transFee > 0 ? cTransFee = transFee : cTransFee = 0.0; // set TransactionFee
	
		monthlyFee > 0 ? cMonthlyFee = monthlyFee : cMonthlyFee = 0.0; //set MonthlyFee
	}
	bool ChequingAccount::credit(double credAmount) {
		bool credited;
		if (Account::credit(credAmount) == true) {
			Account::debit(cTransFee) == true ? credited = true : credited = false;
		}
		else
			credited = false;
		return credited;
	}
	bool ChequingAccount::debit(double debAmount) {
		bool debited;
		if (Account::debit(debAmount) == true) {
			Account::debit(cTransFee) == true ? debited = true : debited = false;
			
		}
		else
			debited = false;
		return debited;
	}
	void ChequingAccount::monthEnd() {
		Account::debit(cMonthlyFee);
	}
	void ChequingAccount::display(ostream& out) const {
		out << "Account type: Chequing\n";
		out << "Balance: $";
		out << fixed;
		out << setprecision(2);
		out << balance() << "\nPer Transaction Fee: ";
		out << cTransFee;
		out << "\nMonthly Fee: ";
		out << cMonthlyFee << endl;
	}
}
