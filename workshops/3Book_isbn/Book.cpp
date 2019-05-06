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
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Book.h"
using namespace std;

namespace sict {

	void Book::set(const char *fname, const char *lname,const char *title, long long isbn_num) {
		//check if number is valid and reset flag
		/*int valid_size = 1;	//flag
		if (isbn_num<min_isbn_value || isbn_num>max_isbn_value) {
			valid_size = 0;
		}*/

		int totalEven = 0;
		int totalOdd = 0;
		int total = 0;
		int highest_ten_multiple;
		int diff = 0;
		int isbnSize = 13;
		int result;
		long long temp_isbn = isbn_num/10;
		int check_digit = isbn_num%10;
		//loop through isbn, determine if position is odd or even and get total accordingly
		for(int i = (isbnSize-1); i > 0; i--)
		{	
			result = temp_isbn%10;

			if ((i%2) != 0)
			{	
				totalOdd += result;
			}
			else
			{
				totalEven += result;
			}	
			temp_isbn /= 10;
		}

		//get sum of numbers at even and odd positions as in the format specified and get the highest multiple of ten for the resulting sum
		total = (totalEven * 3) + totalOdd;
		if ((total%10) != 0)
		{
			highest_ten_multiple = total + (10 - total%10);
		}
		else
		{
			highest_ten_multiple = total;
		}
		//compare difference between total and highest number to check digit to complete validation
		diff = highest_ten_multiple - total;
		
		if(diff == check_digit)
		{
			//set values
			std::strncpy(lname_author, lname, max_name_size+1);
			std::strncpy(fname_author, fname, max_name_size+1);
			std::strncpy(book_title, title, max_title_size+1);
			isbn = isbn_num;
			
		}
		else
		{
			isbn = 0;
		}
			
	}

	bool Book::isEmpty() const {
		bool response;
		//check if empty or not and save response
		if (isbn == 0) {
		response = true;
		}
		else
			response = false;
		return response;

	}

	void Book::display(bool checker) const {
		bool valid = isEmpty();
		//if it is not empty display
		if (valid == false && checker == false)  { 
			cout << "Author: " << lname_author << ", " << fname_author << endl;
			cout << "Title: " << book_title << endl;
			cout << "ISBN-13: " << isbn << endl;
			cout << "Publication Year: " << pub_year << endl;
			cout << "Price: " << book_price << endl;
		}
		if (valid == true && checker == false)
		{
			cout << "The book object is empty!" << endl;
		}
		if (valid == true && checker == true)
		{
			cout.setf(ios::left);
			cout.width(92);
			cout << "|The book object is empty!";
			cout.unsetf(ios::left);
			cout << " |" << endl;
	}
		if (valid == false && checker == true)
		{	
			cout << "|";
			cout.width(max_name_size);
			cout << lname_author;
			cout << "|";
			cout.width(max_name_size);
			cout << fname_author;
			cout<< "|";
			cout.setf(ios::left);
			cout.width(max_title_size);
			cout << book_title;
			cout << "|";
			cout.unsetf(ios::left);
			cout.width(13);
			cout << isbn;
			cout << "|";
			cout.width(4);
			cout << pub_year;
			cout << "|";
			cout.width(6);
			cout.setf(ios::fixed);
			cout.setf(ios::showpoint);
			cout.precision(2);
			cout << book_price;
			cout << "|" << endl;
		}
	}
	void Book::set(int year, double pprice){
		bool empty = isEmpty();
		//if not empty enter values else notify that it is
		if (empty == false){
			pub_year = year;
			book_price = pprice;
		}
	}

}
