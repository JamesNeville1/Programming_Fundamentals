#pragma once
#include"utility.h"

class enemy {
public:
	string name = "";
	vector<damageType> weakness;
	virtual void attack(playerTemp& player) = 0;
};
class goblin : public enemy {
public:
	goblin() {
		name = "Goblin";
		weakness = {
			slashing
		};
	}
	void attack(playerTemp& player) override {
		player.takeDamage(10);
	}
};
class zombie : public enemy {
public:
	zombie() {
		name = "Zombie";
		weakness = {
			fire
		};
	}
	void attack(playerTemp& player) override {
		player.takeDamage(20);
	}
};