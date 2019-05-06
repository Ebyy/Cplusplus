/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: U
Date:03/10/2019
----------------------------------------------
Assignment: 1
Milestone:  1
---------------------------------------------- */
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>

namespace ama{
	
		const int min_year = 2019;
		const int max_year = 2028;
		const int no_error = 0;
		const int error_year = 1;
		const int error_mon = 2;
		const int error_day = 3;
		const int error_invalid_operation = 4;
		const int error_input = 5; 
		 
		class Date{
			int year;
			int month;
			int date;
			int obj_status;

			void status(int newStatus);
			int mdays(int year, int month) const;
			bool isValidYear(const int)const;
			bool isValidMonth(const int)const;
			bool isValidDay(const int)const;

		public:
			Date();
			Date(int, int, int);
			int status();
			void clearError();
			bool isGood()const;
			Date& operator+=(int days);
			Date& operator++();
			Date operator++(int);
			Date operator+(int days);
			bool operator==(const Date& rhs) const;
			bool operator!=(const Date& rhs) const;
			bool operator<(const Date& rhs) const;
			bool operator>(const Date& rhs) const;
			bool operator<=(const Date& rhs) const;
			bool operator>=(const Date& rhs) const;

			std::istream& read(std::istream& is);
			std::ostream& write(std::ostream& os)const;
		 };
		//helpers
		std::ostream& operator<<(std::ostream& ostr,const Date&);
		std::istream& operator>>(std::istream& istr, Date&);

}
#endif 
