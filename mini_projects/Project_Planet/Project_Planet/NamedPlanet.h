#ifndef _NAMEDPLANET_
#define _NAMEDPLANET_
#include <iostream>
#include "Planet.h"
using namespace std;
namespace vac {
	class NamedPlanet : public Planet {
		char * planetName;
	public:
		NamedPlanet(double x, int y, const char* nm);
		~NamedPlanet();
		const char* name() const;

	};
	ostream& operator<<(ostream&, const NamedPlanet&);
}
#endif