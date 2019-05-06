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
using namespace std;

namespace sict {

	Hero::Hero() {
		name[0] = '\0';
		health = 0;
		strength = 0;
	}

	Hero::Hero(const char * hero_name, int live, int power) {
		if (hero_name != nullptr && live > 0 && power > 0) {
			strncpy(name, hero_name, max_name_size);
			name[max_name_size + 1] = '\0';
			health = live;
			strength = power;
	}
		else
			*this = Hero();
	}
	bool Hero::isAlive() const{
		bool alive;
		if (name != nullptr && health > 0 && strength > 0) {
			alive = true;
		}
		else
			alive = false;
		return alive;
	}

	void Hero::operator-=(int attack) {
		if (attack > 0) {
			this->health -= attack;
			if (health < 0) {
				health = 0;
			}
		}
	}

	int Hero::attackStrength()const {
		return this->strength;
	}


	ostream& operator<<(ostream& os, const Hero& hero) {
		if (hero.isAlive() == false) {
			os << "No hero";
		}
		else
			os << hero.name;
		return os;
		
	}

	const Hero& operator*(const Hero& first, const Hero& second) {
		
		Hero lhs = first;
		Hero rhs = second;
		Hero battleWinner;
		int flag = 1;
		int round_counter = 0;
		for (int i = 0; i < max_rounds && lhs.isAlive() && rhs.isAlive(); i++) {
			rhs -= first.attackStrength();
			lhs -= second.attackStrength();
			round_counter++;
			if (lhs.isAlive() && rhs.isAlive() && i == max_rounds-1) {
				battleWinner = first;
				cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << battleWinner << " in " << round_counter << " rounds." << endl;
				i=max_rounds; //flag remains 1
			}
			if (lhs.isAlive() == false) {
				battleWinner = second;
				cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << battleWinner << " in " << round_counter << " rounds." << endl;
				i= max_rounds;
				flag = 2; //flag changes
			}
			if (rhs.isAlive() == false) {
				battleWinner = first;
				cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << battleWinner << " in " << round_counter << " rounds." << endl;
				i=max_rounds;
				//flag remains 1
			}
			
			
			
		}
		return flag==1?first:second;
	}
}
