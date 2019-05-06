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
#ifndef SICT_HERO_H
#define SICT_HERO_H
#include<iostream>
namespace sict {

	const int max_name_size = 40; 
	const int max_rounds = 100;

	class Hero {
		char name[max_name_size + 1];
		int health;
		int strength;
	public:
		Hero();
		Hero(const char*, int, int);
		void operator-=(int);
		bool isAlive() const;
		//const char* getName()const;
		int attackStrength()const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};
	//Helpers
	const Hero& operator*(const Hero& first, const Hero& second);


}

#endif
