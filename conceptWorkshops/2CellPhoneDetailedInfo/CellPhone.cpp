
/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: II
Date: 01/27/2019
----------------------------------------------
Workshop: 2 lab
---------------------------------------------- */
// TODO: include the necessary headers
#include<iostream>
#include "CellPhone.h"
using namespace std;
// TODO: the sict namespace
namespace sict {
	// TODO: definition for display(...)
	void display(const CellPhone& cell) {

		cout << "Phone " << cell.m_model << " costs $" << cell.m_price << "!" << endl;
	}

	void display(const CellPhone phones[], int n) {
		float temp = phones[0].m_price;
		for (int i = 0; i < n; i++) {
			if (phones[i].m_price < temp) {
				temp = phones[i].m_price;
			}
		}
		cout << "------------------------------" << endl; 
		cout << "Phones available at the mall:"<< endl;
		cout << "------------------------------" << endl;
		cout << "1. Phone " << phones[0].m_model << " costs $" << phones[0].m_price << "!"<< endl;
		cout << "2. Phone " << phones[1].m_model << " costs $" << phones[1].m_price << "!" << endl;
		cout << "3. Phone " << phones[2].m_model << " costs $" << phones[2].m_price << "!" << endl;
		cout << "------------------------------" << endl;
		cout << "The cheapest phone costs $"<< temp << "."<< endl;
		cout << "------------------------------"<<endl;
	}
}
