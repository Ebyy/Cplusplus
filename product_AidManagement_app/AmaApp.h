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

#ifndef _AMAAPP_H_
#define _AMAAPP_H_
#include "iProduct.h"

using namespace std;

namespace ama {

	class AmaApp {
		char m_filename[256];
		int m_noOfProducts;
		iProduct* m_products[100];

		//member functions
		AmaApp& operator=(const AmaApp& rhs) = delete;
		AmaApp(const AmaApp& other) = delete;
		void pause() const;
		int menu() const;
		void loadProductRecords();
		void saveProductRecords() const;
		void listProducts() const;
		//void deleteProductRecord(iProduct* product)
		//void sort()
		iProduct* find(const char* sku) const;
		void addQty(iProduct* product);
		void addProduct(char tag);

	
	public:
		AmaApp(const char * fileName);
		~AmaApp();
		int run();
	};

}
#endif // !_PERISHABLE_H
