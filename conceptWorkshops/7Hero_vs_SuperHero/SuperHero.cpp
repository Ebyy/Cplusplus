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
#include <iostream>
#include <cstring>
#include <string>
#include "Hero.h"
#include "SuperHero.h"
using namespace std;

namespace sict {
	SuperHero::SuperHero() : Hero(){
	}

	SuperHero::SuperHero(const char * s_name, int s_health, int s_strength, int bonus, int extraStrength) : Hero(s_name, s_health, s_strength){
		attackBonus = bonus;
		defendStrength = extraStrength;
	}

	int SuperHero::defend()const {
		int def_str = !isAlive() ? 0 : defendStrength;
		return def_str;
	}

	int SuperHero::attackStrength()const {
		int check_strength;
		if (!isAlive()) {
			check_strength = 0;
		}
		else
			check_strength = Hero::attackStrength() + attackBonus;
		return check_strength;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		Hero lhs = first;
		Hero rhs = second;
		Hero betterSuperHero;
		int flag = 1;
		int round_counter = 0;
		//check both superheroes are alive then start fight
		for (int i = 0; i < max_rounds && lhs.isAlive() && rhs.isAlive(); i++) {
			rhs -= first.attackStrength() - second.defend();
			lhs -= second.attackStrength() - first.defend();
			round_counter++;
			if (lhs.isAlive() && rhs.isAlive() && i == max_rounds - 1) {
				betterSuperHero = first;
				cout << "Super Fight! " << first << " vs " << second << " : Winner is " << betterSuperHero << " in " << round_counter << " rounds." << endl;
				i = max_rounds; //flag remains 1
			}
			if (lhs.isAlive() == false) {
				betterSuperHero = second;
				cout << "Super Fight! " << first << " vs " << second << " : Winner is " << betterSuperHero << " in " << round_counter << " rounds." << endl;
				i = max_rounds;
				flag = 2; //flag changes
			}
			if (rhs.isAlive() == false) {
				betterSuperHero = first;
				cout << "Super Fight! " << first << " vs " << second << " : Winner is " << betterSuperHero << " in " << round_counter << " rounds." << endl;
				i = max_rounds;
				//flag remains 1
			}



		}
		return flag == 1 ? first : second;
	}
}
