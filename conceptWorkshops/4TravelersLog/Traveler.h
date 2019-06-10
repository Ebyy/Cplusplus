// TODO: add file header comments here

/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: II
Date: 02/09/2019
----------------------------------------------
Workshop: 4 lab
---------------------------------------------- */
// TODO: add header file guard here
#ifndef SICT_TRAVELER_H
#define SICT_TRAVELER_H
// TODO: declare your namespace here
namespace sict {
// TODO: define the constants here
	const int max_destination_size = 32;
	const int max_name_size = 16;
// TODO: define the Traveler class here
	class Traveler {
		char firstName[17];
		char lastName[17];
		char destination[33];
		int year;
		int month;
		int day;
	public:
		Traveler();
		Traveler(const char*, const char*, const char*);
		Traveler(const char*, const char*,const char *, int, int, int);
		bool isEmpty()const;
		const char* name() const;
		bool canTravelWith(const Traveler&) const;
		void display()const;
	};
}

#endif
