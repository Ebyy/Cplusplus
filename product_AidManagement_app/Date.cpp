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
#include <iostream>
#include "Date.h"
using namespace std;

namespace ama{

	Date::Date() {
		year = 0;
		month = 0;
		date = 0;
		obj_status = 0;
	}


	int Date::mdays(int year, int mon) const { 
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 }; 
		int month = mon >= 1 && mon <= 12 ? mon : 13; 
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)); 
	}

	void Date::status(int newStatus) {
		this->obj_status = newStatus;
	}

	bool Date::isGood()const {
		bool good;
		if ((this->obj_status == no_error) && (year != 0)) {
			good = true;
		}
		else
			good = false;
		return good;
	}
	bool Date::isValidYear(const int yr)const {
		bool valid;
		if (yr <= max_year && yr >= min_year) {
			valid = true;
		}
		else
			valid = false;
		return valid;
	}
	bool Date::isValidMonth(const int mn)const {
		bool v_month;
		if (mn >= 1 && mn < 13) {
			v_month = true;
		}
		else
			v_month = false;
		return v_month;
	}
	bool Date::isValidDay(const int day)const {
		bool x_day;
		if (day >= 1 && day <= mdays(year, month)) {
			x_day = true;
		}
		else
			x_day = false;
		return x_day;
	}
	Date::Date(int yr, int mn, int day) {
		if (yr <= max_year && yr >= min_year) {
			if(mn>0 && mn <13) {
				if (day>0 && day <= mdays(yr,mn)) {
					this->year = yr;
					this->month = mn;
					this->date = day;
					this->obj_status = no_error;
				}
				else {
					*this = Date();
					this->obj_status = error_day;
				}
			}
			else {
				*this = Date();
				this->obj_status = error_mon;
			}
		}
		else {
			*this = Date();
			this->obj_status = error_year;
		}
	}


	int Date::status() {
		return this->obj_status;
	}
	void Date::clearError() {
		obj_status = no_error;
	}

	Date& Date::operator+=(int days) {
		if (!isValidDay(this->date + days)) {
			this->obj_status = error_invalid_operation;
		}

		if (!isGood() || status() != 0) {
			this->obj_status = error_invalid_operation;
		}
		else
			this->date += days;
		return *this;
	}
	Date& Date::operator++() {
		if (!isGood()) {
			status(error_invalid_operation);
			
		}
		if (!isValidDay(date+1)) {
			status(error_invalid_operation);
			
		}
		else
			++date;
		return *this;
	}
	Date Date::operator++(int) {
		Date temp = *this;
		++(*this);
		return temp;
	}
	Date Date::operator+(int days) {
		Date newDate=*this;
		
		if ((this->date + days) > mdays(year,month)/*!isValidDay(date+days)*/) {
			newDate.obj_status = error_invalid_operation;
		}
		else if (!isGood()) {
			newDate.obj_status = error_invalid_operation;
		}
		else
			newDate.date= this->date+days;
		return newDate;
	}
	bool Date::operator==(const Date& rhs) const {
		bool equal;
		
		if (this->year == rhs.year && month == rhs.month && date == rhs.date) {
			equal = true;
		}
		else
			equal = false;
		return equal;
	}
	bool Date::operator!=(const Date& rhs) const {
		bool diff;
		if(this->year != rhs.year || month != rhs.month || date != rhs.date){
			diff = true;
		}
		else
			diff = false;
		return diff;
	}
	bool Date::operator<(const Date& rhs) const {
		bool lt;
		int this_total = year + month + date;
		int rhs_total = rhs.year + rhs.month + rhs.date;
		if (this_total < rhs_total) {
			lt = true;
		}
		else
			lt = false;
		return lt;
	}
	bool Date::operator>(const Date& rhs) const {
		bool gt;
		int this_total = year + month + date;
		int rhs_total = rhs.year + rhs.month + rhs.date;
		if (this_total > rhs_total) {
			gt = true;
		}
		else
			gt = false;
		return gt;
	}
	bool Date::operator<=(const Date& rhs) const {
		bool lt_eq;
		int this_total = year + month + date;
		int rhs_total = rhs.year + rhs.month + rhs.date;
		if (this_total < rhs_total || (this->year == rhs.year && month == rhs.month && date == rhs.date)) {
			lt_eq = true;
		}
		else
			lt_eq = false;
		return lt_eq;
	}
	bool Date::operator>=(const Date& rhs) const {
		bool gt_eq;
		int this_total = year + month + date;
		int rhs_total = rhs.year + rhs.month + rhs.date;
		if (this_total >= rhs_total || (this->year == rhs.year && month == rhs.month && date == rhs.date)) {
			gt_eq = true;
		}
		else
			gt_eq = false;
		return gt_eq;
	}
	istream& operator>>(istream& istr, Date& x_date) {
		
		x_date.read(istr);
		return istr;
	}

	ostream& operator<<(ostream& ostr,const Date& i_date) {
		
		i_date.write(ostr);
		return ostr;
	}

	istream& Date::read(istream& is) {
		char to_read;
		is.clear();
		is >> year >> to_read >> month >> to_read >> date;
		if (is.fail()) {
			*this = Date();
			status(error_input);
		}
		else if (year < min_year || year > max_year) {
			*this = Date();
			status(error_year);
		}
		else if (month < 1 || month> 12) {
			*this = Date();
			status(error_mon);
		}
		else if (date < 1 || date > mdays(year, month)) {
			*this = Date();
			status(error_day);
		}
		else
			*this = Date(year,month,date);
		return is;

	}
	ostream& Date::write(ostream& os)const{
		os.width(4);
		os.fill('0');
		os << year << '/';
		if (month < 10) {
			os << 0;
		}
		os << month << '/';
		if (date < 10) {
			os << 0;
		}
		os << date;
		os.fill(' ');
		return os;
	}

}
	
