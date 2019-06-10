/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: II
Date: 02/14/2019
----------------------------------------------
Workshop: 4 home
---------------------------------------------- */
// TODO: insert header files
#include <iostream>
#include "Fraction.h"
using namespace std;

// TODO: continue the namespace
namespace sict{
	// TODO: implement the default constructor
	Fraction::Fraction() {
		//define empty state
		numerator = 0;
		denominator = 1;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction (int a_numerator, int b_denominator) {
		//validate and set valid values accordingly
		if (a_numerator >= 0 && b_denominator > 0) {
			numerator = a_numerator;
			denominator = b_denominator;
			//reduce values with function call
			reduce();
		}
		else
			*this=Fraction();
	}
	// TODO: implement the max query and return the greater part of the fraction
	int Fraction::max() const {
		int greater;
		if (numerator > denominator) {
			greater = numerator;
		}
		else
			greater = denominator;
		return greater;
	}
    // TODO: implement the min query and return the lesser part of the fraction
	int Fraction::min() const {
		int lesser;
		if (numerator < denominator) {
			lesser = numerator;
		}
		else
			lesser = denominator;
		return lesser;
	}
	// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
	void Fraction::reduce() {
		int divInt = gcd();	//initialise variable with result from gcd function call
		//reduce the fraction
		numerator /= divInt;
		denominator /= divInt;
	}
    // TODO: implement the display query
	void Fraction::display() const {
		bool valid = this->isEmpty();	//check if value is empty
		//validate value and print appropriate statement
		if (valid != true && denominator != 1) {
			cout << numerator << "/" << denominator;
		}
		else if (valid != true && denominator == 1) {
			cout << numerator;
		}
		else
			cout << "no fraction stored";
	}
    // TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		bool empty;
		if (numerator == 0 && denominator == 1) {
			empty = true;
		}
		else
			empty = false;
		return empty;
	}
    // TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction temp;
		if (this->isEmpty() != true && rhs.isEmpty() != true) {
			temp.numerator = ((numerator * rhs.denominator) + (rhs.numerator * denominator));
			temp.denominator =  (denominator * rhs.denominator);
		}
		else
			temp = Fraction();
		return temp;
	}
	// overloaded * operator defined	
	Fraction Fraction::operator*(const Fraction& rhs) const{
		Fraction temp;
		if (this->isEmpty() != true && rhs.isEmpty() != true) {
			temp.numerator = (numerator * rhs.numerator);
			temp.denominator =  (denominator * rhs.denominator);
		}
		else
			temp = Fraction();
		return temp;
	}
	//overloaded == operator defined
	bool Fraction::operator==(const Fraction& rhs) const{
		bool temp = false;//flag
		//check that values are valid then compare the 2 fraction values
		if (this->isEmpty() != true && rhs.isEmpty() != true){
			if ((numerator == rhs.numerator) && (denominator == rhs.denominator)){
				temp = true;
			}
		}
		return temp;
	}
	// overloaded != operator defined
	bool Fraction::operator!=(const Fraction& rhs) const {
		bool temp=false; //flag
		//validate values then compare them for equality
		if (this->isEmpty() != true && rhs.isEmpty() != true){
			if ((numerator != rhs.numerator) && (denominator != rhs.denominator)){
				temp = true;
			}
		}
		return temp;
		
	}
	//overloaded += operator defined	
	Fraction Fraction::operator+=(const Fraction& rhs) {
		//validate values then return appropriate values 
		if (this->isEmpty() != true && rhs.isEmpty() != true) {
			numerator = ((numerator * rhs.denominator) + (rhs.numerator * denominator));
			denominator =  (denominator * rhs.denominator);
		}
		else
			*this = Fraction();
		return *this;
	}	
}
