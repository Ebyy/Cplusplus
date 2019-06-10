#include <iostream>
#include "CashableVacation.h"
using namespace std;
using namespace vac;

 int main() {

     CashableVacation jim(345, "Jim", 8.50), jane(370, "Jane", 6.00), steph(382, "Steph", 10.50), ghost;

     cout << "Number Accumulated  Rate Cashable Name" << endl;

     // should show that Jim starts with nothing
     cout << jim << endl;

     // Jim accumulates 6.5 hours of vacation time
     jim += 18.5;
     cout << jim << endl;

	 // Jane accumulates 8.5 hours of vacation time
	 jane += 8.5;
	 cout << jane << endl;

	 // Jane accumulates 8.5 hours of vacation time
	 steph += 38.5;
	 cout << steph << endl;

     // Jim accumulates 4.5 more hours of vacation time
     jim -= 1.5;
     cout << jim << endl;

	 // Jane accumulates 8.5 hours of vacation time
	 steph -= 8.5;
	 cout << steph << endl;

	 // Jane accumulates 3.5 hours of vacation time
	 jane += 3.5;
	 cout << jane << endl;

     // The company makes 10 hours of Jim's vacation time cashable 
     jim.makeCashable(10);
     cout << jim << endl;

	 // The company makes 6 hours of Jane's vacation time cashable 
	 jane.makeCashable(6);
	 cout << jane << endl;

	 // The company makes 10 hours of Jim's vacation time cashable 
	 steph.makeCashable(15);
	 cout << steph << endl;

     // Jim withdraws $40
     jim -= 40.0;
     cout << jim << endl;

	 // Steph withdraws $55
	 steph -= 35.00;
	 cout << steph << endl;
	 
     // data for ghost employee
     cout << endl << ghost << endl;

     return 0;
 }