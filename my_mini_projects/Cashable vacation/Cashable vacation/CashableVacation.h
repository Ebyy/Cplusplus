#ifndef _TOCASH_
#define _TOCASH_
#include "vacation.h"

namespace vac {
	const double MIN_WAGE = 7.50;
	class CashableVacation:public Vacay {
		double rate;
		double vacInCash;
	public:
		CashableVacation();		//empty state
		CashableVacation(int , const char* , double );		//creates instance of the object
		bool valid() const;			//checks if not empty
		double cashable() const;	//returns cashable amt if any
		double conversionRate()const;	//returns rate
		bool operator-=(double amt);		//modifies amount if employee redeems from vacInCash
		void makeCashable(double time2convert);		//converts certain amt of hrs to cash
		ostream& display(ostream& cout)const;
	};
	//helper
	ostream& operator<<(ostream& os, const CashableVacation& obj);
}

#endif
