// TODO: add file header comments here
/* -------------------------------------------
NAME:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: II
Date: 02/09/2019
----------------------------------------------
Workshop: 4 lab
---------------------------------------------- */


// TODO: add your headers here
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Traveler.h"
using namespace std;
// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Traveler::Traveler() {
		firstName[0] =  '\0';
		lastName[0] =  '\0';
		destination[0] = '\0';
		year = 0;
		month = 0;
		day = 0;	
	}
	// TODO: implement the constructor with 6 parameters here
	// thorough validates inputs both strings and integers 
	
	Traveler::Traveler(const char* fName, const char* lName, const char* dest, int yr, int mnth, int date) {
		if ((fName != nullptr && fName[0] != '\0') && (lName != nullptr && lName[0] != '\0') && 
			(dest != nullptr && dest[0] != '\0')&&(yr >= 2019 && yr <= 2022) && (mnth>=1 && mnth<=12) &&(date>=1 && date<=31)) {
			int i;
			for(i = 0; i<max_name_size+1; i++){
				firstName[i] = fName[i];
				lastName[i] = lName[i];
				destination[i] = dest[i];}
			year = yr;
			month = mnth;
			day = date;
		}
			else{
				*this = Traveler();
			}
	}
// function to set objects with just string inputs and no date - sets date and validates entry
	Traveler::Traveler(const char* fName, const char * lName, const char* dest){
		if ((fName != nullptr && fName[0] != '\0') && (lName != nullptr && lName[0] != '\0') && 
			(dest != nullptr && dest[0] != '\0')) {
			int i;
			for(i = 0; i<max_name_size+1; i++){
				firstName[i] = fName[i];
				lastName[i] = lName[i];
				destination[i] = dest[i];}
			this->year = 2019;
			this->month = 7;
			this->day = 1;

		}
	}
// TODO: implement isEmpty query here

        bool Traveler::isEmpty() const
	 {
                bool response;
                //check if empty or not and save & return response
                if (firstName[0] == '\0' && lastName[0] == '\0' && destination[0] == '\0' && year == 0 && month == 0 && day == 0)
		{
                response = true;
                }
                else
      			response = false;
                return response;
        }


// TODO: implement name query here
	const char* Traveler::name() const{
		bool empty = isEmpty();
		const char* ptr;
		if (empty != true){
			ptr = firstName;
		}
		else if(empty == true){
			ptr = this->firstName;
		}
		/*if (empty){
			return this->firstName;
		}*/
		return ptr;
	}


// TODO: implement canTravelWith query here
	bool Traveler::canTravelWith(const Traveler& p) const{
		bool match;
	//	compare destination using strcmp and numbers and return bool response
		
		if (strcmp(p.destination, this->destination) == 0 && p.year == this->year && p.month == this->month && p.day == this->day)
		{
			match = true;
		}
		else
			match = false;
		return match;
	}

// TODO: implement display query here
	void Traveler::display() const {
	//	int temp_m = month;
				
		cout << lastName << ", " << firstName << " goes to " << destination << " on " << year << "/";		 
		if (month>=10){ 
			cout<<month;
		}
		else{
			cout.fill('0');
			cout.width(2);
			cout << month << "/";
		}
		if (day>=10){
			cout<< day<<endl;
		}
		else {
			cout.fill('0'); 
			cout.width(2);
			cout << day << endl;
		}
	
	}
}


