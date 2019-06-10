/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: II
Date: 02/03/2019
----------------------------------------------
Workshop: 3 lab
---------------------------------------------- */
// TODO: header safeguards
#ifndef SICT_BOOK_H
#define SICT_BOOK_H

namespace sict{
const int max_title_size = 32;

const int max_name_size = 16;

const long long min_isbn_value = 1000000000000;

const long long max_isbn_value = 9999999999999;

class Book {
	char lname_author[max_name_size + 1];
	char fname_author[max_name_size + 1];
	char book_title[max_title_size + 1];
	long long isbn;
	int pub_year;
	double book_price;
public:
	void set(const char*, const char*, const char*, long long);
	void set(int, double);
	bool isEmpty() const;
	void display(bool=false) const;
};
}
#endif

