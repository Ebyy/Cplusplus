#include <iostream>
#include <iomanip>
#include <cmath>
#include "Planet.h"
using namespace std;

namespace vac {

	Planet::Planet(double mass, int power) {
		if (mass >= 1 && mass < 10) {
			mantissaMass = mass;
			superscriptTen = power;
		}
		else {
			mantissaMass = 0.00;
			superscriptTen = 0;
		}
		
	}
	double Planet::mass() const {
		return mantissaMass;
	}
	double Planet::gravity(double r) const {
		double gravForce;

		gravForce = (6.67e-11 * mass() * pow(10,superscriptTen) * (1.99e30)) / (r*r);
		return gravForce;
	}

	int Planet::getpower()const {
		return superscriptTen;
	}
	ostream& Planet::display(ostream& os)const {
		os << fixed << setprecision(2) << mantissaMass;
		os << " x 10^";
		os << superscriptTen;
		os << "kg";
		
		return os;
	}

	ostream& operator<<(ostream& out, const Planet& other) {

		if (other.mass() != 0) {
			other.display(out);
		}
		else
			out << "Planet doest not exist!";
		return out;
	}

	/*FOR HELPER FUNCTION USE TESTING BASE CLASS WITHOUT display() function
	ostream& operator<<(ostream& os, const Planet& other) {
		if (other.mass() != 0) {
			os << "The mass of the planet is ";
			os << fixed << setprecision(2) << other.mass();
			os << " x 10^";
			os <<other.getpower();
			os << "kg";
		}
		return os;
	}*/
}