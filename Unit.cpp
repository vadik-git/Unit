#include "Unit.h"

string Unit::attack(Unit & unit) const
{
	size_t a = (rand() % 100 + 1);
	if (a >= unit.chancheDoge) {
		if (damag >= unit.live) {
			size_t a = unit.live;
			unit.live = 0;
			return string(typeid(*this).name()).substr(6) +
			string("--") + string(typeid(unit).name()).substr(6) +
			string("--") + std::to_string(a) + string("XP");
	
		}
		else {
			unit.live -= damag;
			return string(typeid(*this).name()).substr(6) + 
				string("->") + string(typeid(unit).name()).substr(6) + string(" -") 
				+ std::to_string(damag) + string("xp");
		}
	}
	return string(typeid(*this).name()).substr(6) + string("->") + string(typeid(unit).name()).substr(6) + string("Lost");
}

void Unit::print() const
{
    cout << string(typeid(*this).name()).substr(6);
	cout << "LIVE = " << live;
	cout << "DAMAGE = " << damag;
	cout << "DOGE = " << chancheDoge;

}

bool Unit::stillAlive() const
{
	return live!=0;
}

vector<string> Team::attack(Team & t) const
{
	vector<string >res;
	bool un_atack;
	for (const Unit*atack : units) {
		if (atack->stillAlive()) {
			un_atack = false;
			for (Unit*def : t.units) {
				if (typeid(*atack).name() == typeid(*def).name() && def->stillAlive() == true) {
					res.push_back(atack->attack(*def));
					un_atack = true;
					break;
				}
			}
			if (!un_atack) {
				for (Unit*def : t.units) {
					if (def->stillAlive() == true) {
						res.push_back(atack->attack(*def));
						break;
					}
				}
			}
		}
	}

	return res;
}
