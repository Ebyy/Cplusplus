/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: I
Date:03/16/2019
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "ErrorState.h"

using namespace std;

namespace ama {

	ErrorState::ErrorState(const char* errorMessage) {
		//check if str is not empty and set ' if it is set to null
		if (errorMessage != nullptr && errorMessage[0] != '\0') {
			errMessage = new char[strlen(errorMessage) + 1];
			strncpy(errMessage, errorMessage, strlen(errorMessage));
			errMessage[strlen(errorMessage)] = '\0';
		}
		else if (errorMessage == nullptr || errorMessage[0] == '\0') {
			errMessage = nullptr;
		}
		else
			errMessage = nullptr;
		
	}
	ErrorState::~ErrorState() {
		delete[] errMessage;
		errMessage = nullptr;

	}
	ErrorState::operator bool() const {
		return errMessage != nullptr && strlen(errMessage) != 0? true : false;
	}
	
	ErrorState& ErrorState::operator=(const char* pText) {
		if (errMessage != pText) {
			//call message function to set values
			message(pText);
		}
		
		return *this;
	}
	void ErrorState::message(const char* pText) {
		if (pText != nullptr && strlen(pText) != 0) {
			char * temp = new char[strlen(pText) + 1];
			strcpy(temp, pText);
			delete[] this->errMessage;
			this->errMessage = temp;
		}
		else if(pText == nullptr || strlen(pText) == 0)
			this->errMessage = nullptr;
	}
	const char* ErrorState::message()const {
		return errMessage;
	}

	ostream& operator<<(ostream& os, const ErrorState& msg) {
		if (msg.operator bool()) {
			os << msg.message();
		}
		return os;
	}

}
