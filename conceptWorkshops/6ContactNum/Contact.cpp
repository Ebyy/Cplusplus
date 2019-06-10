/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: II
Date: 03/05/2019
----------------------------------------------
Workshop: 6 lab
---------------------------------------------- */
#include <iostream>
#include <cstring>
#include <string>
#include "Contact.h"
using namespace std;

namespace sict {
	Contact::Contact(){
		name[0] = '\0';
		numPtr = nullptr;
		numOfNums = 0;
	}


	bool Contact::valid(const long long numToCheck) const{
		bool check;
		// 11 or 12 digit check
		if (numToCheck >= 10000000000 && numToCheck <= 999999999999){
			int firstNum = numToCheck/10000000000;
			int secondNum = (numToCheck%10000000000)/10000000;
			int thirdNum = numToCheck % 10000000;
			//int end_pnum = thirdNum % 10000;
			string str1 = to_string(firstNum);
			string str2 = to_string(secondNum);
			string str3 = to_string(thirdNum);
			//check that specified elements dont start with zero
			if(str1[0] != '0' && str2[0] != '0' && str3[0] != '\0' && firstNum > 0 && firstNum <= 99 && secondNum >= 100 && secondNum <= 999 && thirdNum >= 1000000 && thirdNum <= 9999999){	
				check = true;
			}
			else
				check = false;
		}
		else
			check = false;
		return check; 
		
	}

	Contact::Contact(const char * contactName, const long long * p_num, int num){
		int validNums = 0;
		if (contactName != nullptr){

			//set validated name of contact
			strncpy(name, contactName, max_name_size-1);
			name[max_name_size - 1] = '\0';
		}
		else{
			*this = Contact();
		}
			//set valid phone numbers
			// how many valid numbers in the array
		for (int i = 0; i < num; i++) {
	       		if (valid(p_num[i]) == true){
	       			validNums++;
	     	  	}	
	     	}
	       //allocate memory to accomodate just the valid numbers
	       	numPtr = new long long[validNums];
	       	int diffCounter = 0;
	       	for (int i = 0; i < num; i++) {
	       		if (valid(p_num[i]) == true){
	       			numPtr[diffCounter] = p_num[i];
	   	    		diffCounter++;
	       		}	
	       	}
	    	numOfNums = validNums;
		
	}


	Contact::~Contact(){
		if (numPtr != nullptr){
			delete [] numPtr;
		}
	}
	bool Contact::isEmpty() const{
		bool response;
		if (name[0] == '\0' && numPtr == nullptr && numOfNums == 0) {
			response = true;
		}
		else
			response = false;
		return response;
	}


	void Contact::display() const{
		if(!isEmpty()){
			cout << name << endl;
			for(int i = 0; i < numOfNums; i++){
				int cCode = numPtr[i]/10000000000;
				int aCode = (numPtr[i] % 10000000000) / 10000000;
				int pNum = numPtr[i] % 10000000;
				int first_pNum = pNum/10000;
				int second_pNum = pNum % 10000;
				
				if(cCode > 0 && cCode <= 99 && aCode >= 100 && aCode <= 999 && first_pNum >= 100 && first_pNum <= 999 && second_pNum >= 1000 && second_pNum <= 9999){	
					cout << "(+" << cCode << ") " << aCode << " " << first_pNum << "-" << second_pNum << endl;
				}
				else
					cout << "Empty contact!"<<endl;//umptr[i] = nullptr;
			}
		}
		else
			cout<< "Empty contact"<<endl;
	}

	Contact& Contact::operator+=(long long newPhone) {
		
		if (valid(newPhone) == true) {
			numOfNums = numOfNums+1;
			//allocate new memory to accommodate additional number to be added
			long long* tempPtr = new long long[numOfNums];
			//copy existing numbers in the array into new location
			for (int i = 0; i < numOfNums-1; i++) {
				tempPtr[i] = this->numPtr[i];
			}
			tempPtr[numOfNums-1] = newPhone; // new number copied in????????
			//deallocate previously allocated memory and replace with new created one that has the new number added on
			delete[] numPtr;
			numPtr = tempPtr;
		}
		
		return *this;
	}

	Contact::Contact(const Contact& contactToCopy) {
		
		numPtr = nullptr;
		//call assignment operator.
		*this = contactToCopy ;
	}

	Contact& Contact::operator=(const Contact& newContact) {
		//check for self assignment
		if (this != &newContact) {
			
			strcpy(name, newContact.name);
			//name[max_name_size] = '\0';
			numOfNums = newContact.numOfNums;
			
			if (newContact.numPtr != nullptr) {
				numPtr = new long long[numOfNums];
				for (int x = 0; x < numOfNums; x++) {
					numPtr[x] = newContact.numPtr[x];
				}
				
			}
			else
			{
				numPtr = nullptr;
			}
			
		}
		
		return *this;
	}
	
	/*
	int Contact::AreaCodeGetter(const long long numToCheck) {
		int p_num = numToCheck;
		int aCode = (p_num % 10000000000) / 10000000;
		return aCode;
	}
	int Contact::CountryCodeGetter(long long p_num) {
		int cCode = p_num / 10000000000;
		return cCode;
	}
	int Contact::PhoneNumberGetter(long long p_num) {
		int last7_num = p_num % 10000000;
		return last7_num;
	}
	int Contact::checkNum(const int numToCheck){
		int counter = 0;
		int i = numToCheck;
		while (i > 0){
			i /= 10;
			counter++;
		}
		return counter;
	}	*/
}
