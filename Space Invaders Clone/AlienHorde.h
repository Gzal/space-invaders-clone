#pragma once

#include <vector>

#include "constants.h"
#include "Alien.h"

using namespace std;

class AlienHorde
{
public:
	int waitFrames = initWaitFrames;
	vector<Alien> aliens;

public:
	AlienHorde();

public:
	void updateAliens();
private:
	void deleteAliens();
};

