/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: I
Date:04/01/2019
----------------------------------------------
Assignment: 1
Milestone:  5
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "AmaApp.h"
#include "Utilities.h"
#include "Product.h"

using namespace std;

namespace ama {
	AmaApp::AmaApp(const char * fileName) {
		if (fileName != nullptr && fileName != '\0' && strlen(fileName) < 256) {
			strcpy(m_filename, fileName);
			m_filename[strlen(fileName) + 1] = '\0';
			
			for(int i = 0; i < 100; i++) {
				m_products[i] = '\0';
			}			
			m_noOfProducts = 0;
			loadProductRecords();
		}
	}

	AmaApp::~AmaApp(){
		for (int i = 0; i < 100; i++) {
			if (m_products[i] != nullptr) {
				delete m_products[i];
			}
		}
		
	}


	void AmaApp::pause() const {
		cout << "Press Enter to continue..."; 
		cin.ignore(1000,'\n');
		cout << endl;
	}

	int AmaApp::menu() const{
		int selection;
		int min = 0;
		int max = 7;
		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "--------------------------------------" << endl;
		cout << "1- List products" << endl;
		cout << "2- Search product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to product quantity" << endl;
		cout << "6- Delete product" << endl;
		cout << "7- Sort products" << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";
		
		cin >> selection;
		//validate
		!cin.bad() && selection>=min && selection <= max ? selection : selection = -1;
		//clear
		cin.clear();
		cin.ignore(1000, '\n');
		return selection;
	}

	void AmaApp::loadProductRecords() {
		int rIndex = 0;
		char tag;
		iProduct* temp;
		for (int i = 0; i < m_noOfProducts; i++) {
			delete m_products[i];
		}

	
		ifstream f;// file object
		f.open(m_filename, ios::in);//open
		//check if open
		if (f.is_open()) {
			//loop
			while (!f.fail() || !f.eof()) {
			
				//get tag and create instance, validate and assign to a position in pointer arr
				tag = f.get();
				temp = createInstance(tag);
				if (temp != nullptr) {
					m_products[rIndex] = temp;
					//continue reading				
					f.ignore();
					m_products[rIndex]->read(f, false);
					rIndex++;	//increment index
				}

			}
			m_noOfProducts = rIndex;
			
		}
		
		f.close();
	}

	void AmaApp::saveProductRecords()const {
		fstream f;
		f.open(m_filename, ios::out);
		for (int i = 0; i < m_noOfProducts; i++) {
			m_products[i]->write(f, write_condensed);
			f << endl;
		}
		f.close();
	}

	void AmaApp::listProducts()const{
		double total = 0;
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "| Row |" << setw(max_length_sku+1) << right << "SKU" << " | ";
		cout << setw(16) << left << "Product Name" << " | ";
		cout << setw(10) << left << "Unit" << " | ";
		cout << setw(7) << right << "Price" << " | ";
		cout << setw(3) << right << "Tax" << " | ";
		cout << setw(6) << right << "QtyA" << " | ";
		cout << setw(6) << right << "QtyN" << " | ";
		cout << setw(10) << left << "Expiry" << " |" << endl;
		cout << "|-----|---------|------------------|------------|---------|-----|--------|--------|------------|" << endl;

		for (int i = 0; i < m_noOfProducts; i++) {
			cout << '|' << setw(4) << right << i + 1 << " |";
			m_products[i]->write(cout, write_table);
			total += m_products[i]->total_cost();
			cout << endl;
		}
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                      Total cost of support ($): | " << setw(10) << right << total << " |" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl << endl;
	}

	void AmaApp::addQty(iProduct* product) {
		int qty2Add;
		int amountNeeded = product->qtyNeeded() - product->qtyAvailable();
		//int newNeeded;
		cout << endl;
		product->write(cout, write_human);
		cout << endl << endl;
		cout << "Please enter the number of purchased items: ";
		cin >> qty2Add;
		if (cin.fail()) {
			cin.clear();
			cout << "Invalid quantity value!" << endl;	
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else {
			if (qty2Add <= amountNeeded) {
				*product += qty2Add;
			}
			else {
				*product += amountNeeded;
				//newNeeded = product->qtyNeeded() - product->qtyAvailable();
				cout << "Too many items; only " << amountNeeded << " is needed. Please return the extra " << qty2Add - amountNeeded << " items." << endl;
			}
			saveProductRecords(); //save???????????
			cout << endl << "Updated!" << endl;
			cin.ignore(1000, '\n');
		}

	}

	void AmaApp::addProduct(char tag) {
		iProduct* temp = createInstance(tag);
		if (temp != nullptr) {
			
			cin >> *temp;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << endl;
				cout << *temp << endl << endl;
			}
			else {
				m_products[m_noOfProducts] = temp;
				m_noOfProducts++;
				saveProductRecords();
				cout << endl << "Success!" << endl << endl;
			}
		}
	}

	iProduct* AmaApp::find(const char* sku) const {
		iProduct* location = nullptr;
		for (int i = 0; i < m_noOfProducts;i++) {
			if (*m_products[i] == sku) {
				location = m_products[i];
				i = m_noOfProducts;
			}
		}
		return location;
	}

	int AmaApp::run() {
		int option;
		char t_sku[max_length_sku];
		iProduct* prod = nullptr;
		bool keepRunning = true;
		while(keepRunning != false) {
			option = menu();
			switch(option) {
			case 0:
				cout << "Goodbye!";
				cout<<endl;
				keepRunning = false;
				break;

			case 1:
				listProducts();
				//cout << endl;
				pause();
				break;

			case 2:
				
				cout << "Please enter the product SKU: ";
				cin >> t_sku;
				prod = find(t_sku);

				if (prod == nullptr) {
					cout << endl << "No such product!" << endl;
					
				}
				else {
					cout << endl;
					prod->write(cout, write_human);
					cout << endl;
				}
				
				cin.ignore(1000, '\n');
				pause();
				break;

			case 3:
				addProduct('N');
				
				break;

			case 4:
				addProduct('P');
				break;

			case 5:
				cout << "Please enter the product SKU: ";
				cin >> t_sku;
				prod = find(t_sku);
				
				if (prod == nullptr) {
					cout << endl << "No such product!" << endl;
				}
				else {
					addQty(prod);
				}
				cout << endl;
				break;

			case -1:
				cout << "~~~Invalid selection, try again!~~~" << endl;
				pause();
				break;


			//case 6:

			//	break;

			}
		}
		
		return 0;
	}
}
