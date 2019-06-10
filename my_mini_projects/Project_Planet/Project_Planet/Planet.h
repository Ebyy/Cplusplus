#ifndef _PLANET_H
#define _PLANET_H
#include <iostream>
using namespace std;
namespace vac {
	class Planet {
		double mantissaMass;
		int superscriptTen;
	public:
		Planet(double, int);
		double mass() const;
		int getpower() const;
		double gravity(double r) const;
		ostream& display(ostream&)const;		
	};
	ostream& operator<<(ostream& os, const Planet& other);
	
}
#endif
