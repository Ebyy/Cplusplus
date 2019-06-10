/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: I
Date:03/21/2019
----------------------------------------------
Workshop: 8
---------------------------------------------- */
#ifndef _IACCOUNT_H
#define _IACCOUNT_H
#include <iostream>
#include "Account.h"
using namespace std;

namespace sict {
	class SavingsAccount : public Account
	{
		double interestRate;
	public:
		SavingsAccount(double balance, double interestRate);
		void monthEnd();
		void display(ostream& out) const;

	};

}

#endif

