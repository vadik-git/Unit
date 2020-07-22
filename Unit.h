#pragma once
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;
class Unit abstract
{
protected:
	size_t live;
	size_t damag;
	size_t chancheDoge;
public:
	Unit(size_t live = 100, size_t damag = 0, size_t chancheDoge = 0)
		:live(live), damag(damag), chancheDoge(chancheDoge) {};
	virtual string attack(Unit& unit)const;
	virtual void print()const;
	bool stillAlive()const;

};

class Swordsman :public Unit {
public:
	Swordsman() {
		Unit::live = 10;
		Unit::damag = 5;
		Unit::chancheDoge = 60;
	};
};

class Archer :public Unit {
public:
	Archer() {
		Unit::live = 15;
		Unit::damag = 6;
		Unit::chancheDoge = 40;
	};
};

class Mage:public Unit {
public:
	Mage() {
		Unit::live = 12;
		Unit::damag = 8;
		Unit::chancheDoge = 30;
	};
};

class Team {
	string name;
	const size_t NumberUnitsTeam = 5;
	vector<Unit*>units;
public:
	Team(const string &name = "Noname") :name(name) {
		for (size_t i = 0; i < 5; i++) {
			switch (rand() % 3 + 1) {
			case 1:
				units.push_back(new Swordsman());
				break;
			case 2:
				units.push_back(new Archer());
				break;
			case 3:
				units.push_back(new Mage());
				break;
			}
		}
	}

	vector<string> attack(Team&t)const;
	bool areAlive() {
		for (Unit* el : units)
		{
			if (el->stillAlive())
			{
				return true;
			}
		}
		return false;
	};
	void print()const {
		cout << "Name : " << name << endl;
		for (const Unit* el : units)
		{
			el->print();
		}
	};

};
class Game {
private:
	Team t1 = Team("White");
	Team t2 = Team("Black");
	vector<string>h1;
	vector<string>h2;
	
public:
	void start() {
		while (t1.areAlive() == t2.areAlive() == true) {
			t1.print();
			t2.print();
			
			for (string&s : h1) {
				cout << s;
			}
			for (string&s : h2) {
				cout << s;
			}

			system("cls");
			h1 = t1.attack(t2);
			h2 = t2.attack(t1);

		}
		t1.print();
		t2.print();
		cout << "Team winner" << (t1.areAlive() ? "White" : "Black");
	}
};


