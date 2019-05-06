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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Product.h"
#include "ErrorState.h"
#include "Utilities.h"

using namespace std;

namespace ama {
	Product::Product(char type) : p_type(type) {
		p_sku[0] = '\0';
		p_unit[0] = '\0';
		p_title = nullptr;
		onHandQty = 0;
		neededQty = 0;
		untaxedUnitPrice = 0.0;
		isTaxable = false;
		
	}
	Product::Product(const char* _sku, const char* name, const char* unit, double price, int qty_needed, int qty_onHand, bool canTax) : p_type('N') {
		if (name != nullptr) {

			p_title = new char[strlen(name) + 1];
			strncpy(p_title, name, strlen(name)+1);
			p_title[strlen(name)] = '\0';
			strncpy(p_sku, _sku, max_length_sku);
			p_sku[max_length_sku] = '\0';
			strncpy(p_unit, unit, max_length_unit);
			p_unit[max_length_unit] = '\0';
			untaxedUnitPrice = price;
			onHandQty = qty_onHand;
			neededQty = qty_needed;
			isTaxable = canTax;
		}
		else
		{
			*this = Product();
		}

	}

	Product::~Product() {
		if (p_title != nullptr) {

			delete[] p_title;
			p_title = nullptr;
		}
	}
	const char* Product::name() const {
		return p_title;
	}

	Product::Product(const Product& rhs) : p_type('N') {
		p_title = nullptr;
		*this = rhs;
	}

	Product& Product::operator=( const Product& rhs) {
		if (this != &rhs) {
			//p_type = rhs.p_type;
			strncpy(p_sku, rhs.p_sku, max_length_sku);
			p_sku[max_length_sku] = '\0';
			strncpy(p_unit, rhs.p_unit, max_length_unit);
			p_unit[max_length_unit] = '\0';
			untaxedUnitPrice = rhs.untaxedUnitPrice;
			onHandQty = rhs.onHandQty;
			neededQty = rhs.neededQty;
			isTaxable = rhs.isTaxable;
			delete[] p_title;
			if (rhs.p_title != nullptr) {
				p_title = new char[strlen(rhs.p_title) + 1];
				strncpy(p_title, rhs.p_title, strlen(rhs.p_title));
				p_title[strlen(rhs.p_title)] = '\0';
			}
			else
				p_title = nullptr;
		}
		return *this;
	}

	int Product::operator+=(int qty) {
		return qty > 0 ? onHandQty += qty : onHandQty;
	}
	bool Product::operator==(const char* sku) const {
		bool eqSku;
		if (strcmp(p_sku, sku) == 0) {
			eqSku = true;
		}
		else
			eqSku = false;
		return eqSku;
	}
	bool Product::operator>(const char* sku) const {
		return (strcmp(p_sku, sku) >0) ? true : false;
	}
	bool Product::operator>(const iProduct& rhs) const {
		bool bigName;
		if (strcmp(p_title, rhs.name()) > 0) {
			bigName = true;
		}
		else
			bigName = false;
		return bigName;
	}
	int Product::qtyAvailable()const {
		return onHandQty;
	}
	int Product::qtyNeeded()const {
		return neededQty;
	}
	double Product::total_cost() const {
		double total = 0;
		if (isTaxable) {
			total = onHandQty * (untaxedUnitPrice *(1 + tax_rate));
		}
		else
			total = onHandQty * untaxedUnitPrice;

		return total;
	}
	
	bool Product::isEmpty()const {
		bool emp = false;
		if(p_title == nullptr) {

		emp = true;
		}
		
		return emp;
	}
	bool Product::isClear()const {
		bool res = errobj.operator bool();
		return res  == false ? true : false;
	}
	void Product::message(const char* pText) {
		errobj = pText;
	}
	istream& Product::read(istream& in, bool interractive) {
		Product tmp;
		tmp.p_title = new char[max_length_name + 1];

		if (interractive == false) {
			char comma;
			//in.clear();
			in.getline(tmp.p_sku, max_length_sku, ',');
			in.getline(tmp.p_title, max_length_name, ',');
			in.getline(tmp.p_unit, max_length_unit, ','); 
			in >> tmp.untaxedUnitPrice >> comma >> tmp.isTaxable >> comma >> tmp.onHandQty >> comma >> tmp.neededQty; //>> comma;
			
			*this = Product(tmp.p_sku, tmp.p_title, tmp.p_unit, tmp.untaxedUnitPrice, tmp.neededQty, tmp.onHandQty, tmp.isTaxable);

			return in;
		}
		if (interractive == true) {
			Product tmp;
			char tax;
			tmp.p_title = new char[max_length_name + 1];

			cout << right<< setw(max_length_label) << "Sku: ";
			in >> tmp.p_sku;
			cout << right << setw(max_length_label) << "Name (no spaces): ";
			in >> tmp.p_title;
			cout << right << setw(max_length_label)<<"Unit: ";
			in >> tmp.p_unit;
			cout << right << setw(max_length_label) << "Taxed? (y/n): ";
			in >> tax;
			if (tax == 'y' || tax == 'Y' || tax == 'n' || tax == 'N') {
				if (tax == 'y' || tax == 'Y')
				{
					tmp.isTaxable = true;
				}
				else if(tax =='n' || tax =='N'){
					tmp.isTaxable = false;
				}
				cout << right << setw(max_length_label) << "Price: ";
				in >> tmp.untaxedUnitPrice;
				if (!in.fail()) {
					cout << right << setw(max_length_label) << "Quantity on hand: ";
					in >> tmp.onHandQty;

					if (!in.fail()) {
						cout << right << setw(max_length_label) << "Quantity needed: ";
						in >> tmp.neededQty;
						if (in.fail()) {
							in.setstate(ios::failbit);
							errobj.message("Invalid Quantity Needed Entry!");
						}
						else
							*this = Product(tmp.p_sku, tmp.p_title, tmp.p_unit, tmp.untaxedUnitPrice, tmp.neededQty, tmp.onHandQty, tmp.isTaxable);
					}
					else {
						in.setstate(ios::failbit);
						errobj.message("Invalid Quantity Available Entry!");
					}	
				}
				else {
					
					errobj.message("Invalid Price Entry!");
					in.setstate(ios::failbit);
				}
				
			}
			else {
				in.setstate(ios::failbit);
				errobj.message("Only (Y)es or (N)o are acceptable!");
			}
			if (this->isClear()) {
				*this = tmp;
			}
			delete[] tmp.p_title;
			tmp.p_title = nullptr;
			return in;
		}
		
		return in;
		
	}
	ostream& Product::write(ostream& out, int writeMode) const {
		if (!isClear()) {
			out << this->errobj;
		}
		else if (!isEmpty())
		{
			if (writeMode == write_table) {
				out << " " << setw(max_length_sku) << right << p_sku << " | ";
				if (strlen(p_title) > 16) {
					for (int i = 0; i < 13; i++) {
						out << p_title[i];
					}
					out << "..." << " | ";
				}
				else
					out << setw(16) << left << p_title << " | ";

				out << setw(10) << left << p_unit << " | ";
				out << setw(7) << right << fixed << setprecision(2) << untaxedUnitPrice << " | ";
				if (isTaxable) {
					out << setw(3) << right << "yes" << " | ";
				}
				else if(!isTaxable)
					out << setw(3) << right << "no" << " | ";
				out << setw(6) << right << onHandQty << " | ";
				out << setw(6) << right << neededQty << " |";
			}
			else if (writeMode == write_condensed) {
				out << p_type << ',' << p_sku << ',' << p_title << ',' << p_unit << ',' << untaxedUnitPrice << ',' << isTaxable <<
					',' << onHandQty << ',' << neededQty;
			}
			else if (writeMode == write_human) {
				out.setf(ios::right);
				out << right << setw(max_length_label) << "Sku: " << p_sku << endl;
				out << right << setw(max_length_label) << "Name: " << p_title << endl;
				out << right << setw(max_length_label) << fixed << setprecision(2) << "Price: " << untaxedUnitPrice << endl;
				out << right << setw(max_length_label) << fixed << setprecision(2) << "Price after Tax: ";
				if (isTaxable == true) {
					double taxedUnitPrice = 0;
					taxedUnitPrice = untaxedUnitPrice * (1 + tax_rate);
					out << fixed << setprecision(2) << taxedUnitPrice << endl;
				}
				else
					out << fixed << setprecision(2) << untaxedUnitPrice << endl;
				out << right << setw(max_length_label) << "Quantity Available: " << onHandQty << ' ' << p_unit << endl;
				out << right << setw(max_length_label) << "Quantity Needed: " << neededQty << ' ' << p_unit << endl;
			}
		}
		

		return out;
	}

}
