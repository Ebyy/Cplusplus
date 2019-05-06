/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: I
Date:03/28/2019
----------------------------------------------
Assignment: 1
Milestone:  5
---------------------------------------------- */

#ifndef _PERISHABLE_H_
#define _PERISHABLE_H_
#include "Product.h"
#include "Date.h"

using namespace std;

namespace ama {

	class Perishable : public Product {
		Date expiryDate;

	public:
		Perishable(char tag = 'P');
		istream& read(istream&, bool interractive);
		ostream& write(ostream& out, int writeMode) const;
	};

}
#endif // !_PERISHABLE_H

