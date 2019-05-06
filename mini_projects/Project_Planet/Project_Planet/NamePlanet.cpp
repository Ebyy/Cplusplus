#include <iostream>
#include <cstring>
#include "NamedPlanet.h"
#include "Planet.h"

namespace vac {
	NamedPlanet::NamedPlanet(double kg, int power, const char* name) : Planet(kg, power) {
		if (name != nullptr) {
			planetName = new char[strlen(name) + 1];
			strncpy(planetName, name, strlen(name));
			planetName[strlen(name)] = '\0';
		}
		else
			planetName = nullptr;
	}

	const char* NamedPlanet::name()const {
		return planetName;
	}

	NamedPlanet::~NamedPlanet() {
		delete[]planetName;
	}
	ostream& operator<<(ostream& ostr, const NamedPlanet& thePlanet) {
		ostr << "The mass of " << thePlanet.name() << " is ";
		thePlanet.display(ostr);
		return ostr;
	}
}