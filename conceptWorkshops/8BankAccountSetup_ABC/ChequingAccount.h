/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: I
Date:03/21/2019
----------------------------------------------
Workshop: 8
---------------------------------------------- */
#ifndef _CHEQUE_H
#define _CHEQUE_H
#include "Account.h"

using namespace std;

namespace sict {
	class ChequingAccount : public  Account{
		double cTransFee;
		double cMonthlyFee;
	public:
		ChequingAccount(double balance, double transFee, double monthlyFee);
		bool credit(double amount);
		bool debit(double amount);
		void monthEnd();
		void display(ostream& out) const;
	};
}
#endif
