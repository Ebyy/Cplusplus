/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: II
Date: 01/27/2019
----------------------------------------------
Workshop: 2 lab
---------------------------------------------- */
// TODO: header safeguards
#ifndef CellPhone_h
#define CellPhone_h

// TODO: sict namespace
namespace sict {
	// TODO: define the structure CellPhone in the sict namespace
	struct CellPhone {
		char m_model[32];
		float m_price;
	};

	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(const CellPhone&);

	void display(const CellPhone[], int);
}
#endif // !1
#pragma once
