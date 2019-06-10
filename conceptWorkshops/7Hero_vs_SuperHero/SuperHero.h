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
#ifndef SICT_S_HERO_H
#define SICT_S_HERO_H
#include "Hero.h"

namespace sict {

	//derived class
	class SuperHero : public Hero {
		int attackBonus;
		int defendStrength;
	public:
		SuperHero();
		SuperHero(const char *, int, int, int, int);
		int attackStrength()const;
		int defend() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif

