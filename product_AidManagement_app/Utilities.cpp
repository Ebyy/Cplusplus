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
#include <iostream>
#include "iProduct.h"
#include "Product.h"
#include "Perishable.h"
using namespace std;

namespace ama {
	double& operator+=(double& total, const iProduct& prod){
		 
		return total += prod.total_cost();
	}
	ostream& operator<<(ostream& out, const iProduct& prod) {
		
		prod.write(out, write_human);
		return out;
	}
	istream& operator>>(istream& in, iProduct& prod) {
		prod.read(in,true);
		return in;
	}

	iProduct* createInstance(char tag) {
		iProduct* newProduct = nullptr;
		if (tag == 'N' || tag == 'n') {
			newProduct = new Product();
		}
		else if (tag == 'P' || tag == 'p') {
			newProduct = new Perishable();
		}
		return newProduct;
	}
}