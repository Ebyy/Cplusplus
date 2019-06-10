/* -------------------------------------------
Name:Eberechi Ogunedo
Student number: 117277160
Email: eokengwu@myseneca.ca
Section: II
Date: 03/05/2019
----------------------------------------------
Workshop: 6 lab
---------------------------------------------- */
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H
namespace sict {
	const int max_name_size = 16;

	class Contact {
		char name[max_name_size];
		long long * numPtr;
		int numOfNums;

		//int CountryCodeGetter(long long);
		//int AreaCodeGetter(long long);
		//int PhoneNumberGetter(long long);
	public:
		Contact();
		Contact(const char*, const long long *, int);
		~Contact();
		bool isEmpty() const;
		void display() const;

		Contact(const Contact& );
		Contact& operator=(const Contact&);
		Contact& operator+=(long long);
		//int checkNum(int);
		bool valid(const long long) const;
	};
}
#endif
