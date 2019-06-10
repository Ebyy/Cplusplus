/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: I
Date:03/26/2019
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */
#ifndef _XTRA_TOOLS_H
#define _XTRA_TOOLS_H
#include <iostream>
#include "iProduct.h"
using namespace std;

namespace ama {
	double& operator+=(double& total, const iProduct& prod);
	ostream& operator<<(ostream& out, const iProduct& prod);
	istream& operator>>(istream& in, iProduct& prod);

	iProduct* createInstance(char tag);
}
#endif // !_XTRA_TOOLS_H
