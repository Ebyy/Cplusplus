/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: II
Date: 02/12/2019
----------------------------------------------
Workshop: 4 lab
---------------------------------------------- */
// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// TODO: create namespace
namespace sict{

	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int numerator;
		int denominator;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
		// TODO: declare the * operator overload
		Fraction operator*(const Fraction& rhs) const;
		// TODO: declare the == operator overload
		bool operator==(const Fraction& rhs) const;
		// TODO: declare the != operator overload
		bool operator!=(const Fraction& rhs) const;
		// TODO: declare the += operator overload
		Fraction operator+=(const Fraction& rhs);
	};
}
#endif // !SICT_FRACTION_H
