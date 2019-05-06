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
#ifndef _PROD_H
#define _PROD_H
#include "iProduct.h"
#include "ErrorState.h"

using namespace std;

namespace ama {

	class Product : public iProduct {
		const char p_type;
		char p_sku[max_length_label];
		char p_unit[max_length_label];
		char* p_title;
		int onHandQty;
		int neededQty;
		double untaxedUnitPrice;
		bool isTaxable;
		ErrorState errobj;

	protected:
		void message(const char* pText);
		bool isClear() const;
	public:
		Product(char arg_type = 'N');
		Product(const char* _sku, const char* p_name, const char* unit, double p_price = 0.0, int qty_needed = 0, int qty_onHand = 0, bool cantax = true);
		Product(const Product&);
		~Product();
		Product& operator=(const Product& rhs);
		int operator+=(int cnt);
		bool operator==(const char* sku) const;
		const char* name() const;
		bool operator>(const char* sku) const;
		bool operator>(const iProduct&) const;
		int qtyAvailable()const;
		int qtyNeeded()const;
		double total_cost() const;
		bool isEmpty()const;
		

		istream& read(istream& in, bool interractive);
		ostream& write(ostream& out, int writeMode) const;
	};
}


#endif // !_PROD_H

