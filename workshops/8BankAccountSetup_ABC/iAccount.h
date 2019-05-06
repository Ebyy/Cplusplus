#ifndef _BASE_ACCT_
#define _BASE_ACCT_

#include <iostream>
using namespace std;

namespace sict {
	class iAccount
	{
	public:
		virtual bool credit(double amount) = 0;
		virtual bool debit(double amount) = 0;
		virtual void monthEnd() = 0;
		virtual void display(ostream& out) const = 0;
		virtual ~iAccount() {};

	};
	iAccount* CreateAccount(const char* type, double balance);
}
#endif