#include <iostream>
#include <iomanip>
#include "NamedPlanet.h"
#include "Planet.h"
using namespace std;
using namespace vac;

int main() {
	
	//Planet earth(5.97, 24);
	NamedPlanet earth(5.97, 24, "Earth");

	cout << earth << endl;
	cout << "The force of gravity at the perihelion is ";
	cout << scientific;
	cout << earth.gravity(1.5e11) << "N" << endl;

	return 0;
}