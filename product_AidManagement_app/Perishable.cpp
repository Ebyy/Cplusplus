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

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Perishable.h"
#include "ErrorState.h"
#include "Product.h"
#include "Date.h"

using namespace std;

namespace ama {
	Perishable::Perishable(char tag) : Product(tag) {

	}

	istream& Perishable::read(istream& in, bool interactive){
		Date temp;
		//char comma;
		Product::read(in, interactive);
		if (interactive == true) {
			cout << right << setw(max_length_label) << "Expiry date (YYYY/MM/DD): ";
			in >> temp;
			if(!in.fail()){
				switch (temp.status()) {

				case error_year:
					in.setstate(ios::failbit);
					message(" Invalid Year in Date Entry");
					break;
				case error_mon:
					in.setstate(ios::failbit);
					message("Invalid Month in Date Entry");
					break;
				case error_day:
					in.setstate(ios::failbit);
					message("Invalid Day in Date Entry");
					break;
				case no_error:
					expiryDate = temp;
					break;
				}
			}
			else if (in.fail()) {
				in.setstate(ios::failbit);
				message("Invalid Date Entry");

			}
			/*else if(!in.fail() && temp.status() == no_error) {
				expiryDate = temp;
			}*/
		}
		else {
			in.ignore();
			in >> temp;
			//in.ignore();
			expiryDate = temp;
		}
		return in;

	}
	ostream& Perishable::write(ostream& out, int writeMode) const {
		Product::write(out, writeMode);

		if (this != nullptr && isClear()) {
			switch (writeMode) {
			case write_human:
				out << right << setw(max_length_label) << "Expiry Date: " << expiryDate << endl;
				break;
			case write_condensed:
				out << ',' << expiryDate;
				break;
			case write_table:
				out << ' ' << expiryDate << " |";
				break;
			} 
		}
		return out;
	}
}
