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
#ifndef ERROR_H
#define ERROR_H
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

namespace ama {
	class ErrorState {
		char* errMessage;

		bool noError() const;

	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& other) = delete;
		ErrorState& operator=(const ErrorState& other) = delete;
		virtual ~ErrorState();
		operator bool()const;
		ErrorState& operator=(const char* pText);
		void message(const char* pText);
		const char* message()const;
	};
	std::ostream& operator<<(std::ostream& os, const ErrorState& msg);
}
#endif
