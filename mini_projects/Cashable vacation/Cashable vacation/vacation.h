#ifndef _VAC_H_
#define _VAC_H_

#include <iostream>
using namespace std;

namespace vac {
	class Vacay {
		int empID;
		double vacayTime;
		char* empName;

	public:
		Vacay();	//sets empty state
		Vacay(int id, const char * nm);		//sets values
		virtual ~Vacay();
		bool operator+=(double extraTime);	//add vacay time to employee
		bool operator-=(double leftTime);		//removes takes vacay from employee
		bool valid() const;		//checks if obj not in empty state
		int number() const;		//retruns employee number
		double time() const;	//returns return time accumulated if obj is valid
		char* name()const;		//returns address of empName if obj is valid
		ostream& write(ostream& out)const;		//display
	};

	//helper
	ostream& operator<<(ostream& o, const Vacay& obj);

}

#endif
