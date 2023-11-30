#pragma once
#include "utils.h"
#include <array>

struct raceTemp {
	string displayName = "";
	int stikes = 0;
};

void setRaceData(array<raceTemp, 3>* raceDataRef);

class playerClass {
public:
	string name = "";
	raceTemp* race = NULL;
	int strikes = 0;
	int currentStrikes = 0;

	playerClass(array<raceTemp, 3>* raceDataRef);
	raceTemp* getPlayerRace(array<raceTemp, 3>* raceDataRef);
	void characterDetails();
	bool adjustStrikes(int increaseBy, string currentBachName);
};

