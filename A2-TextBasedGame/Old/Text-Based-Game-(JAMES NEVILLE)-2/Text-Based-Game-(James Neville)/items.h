#pragma once
#include "utility"

enum itemType {
	healing,
	rangedWeapon,
	meleeWeapon,
	food
};

struct item {
	string name;
	itemType type;
	int attribute;
	int worth;
};

item items[]{
	{"Potion of Healing", healing, 5, 10},
	{"Standard Bow", rangedWeapon, 5, 20},
	{"Epic Bow", rangedWeapon, 11, 40},
	{"Standard Sword", meleeWeapon, 7, 18},
	{"Epic Sword", meleeWeapon, 15, 35},
	{"Bread", food, 2, 2},
	{"Cake", food, 5, 4}
};