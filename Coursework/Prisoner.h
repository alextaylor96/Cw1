#pragma once
#include "Strategy.h"

class Prisoner
{
public:
	Prisoner(Strategy& strategy);
	~Prisoner();

	void assignStrategy(Strategy& strategy);
	Strategy& getStrategy();

private:
	Strategy strat;
	char lastOutcome = 0 ; 
	int alloutcomes_w = 0;
	int alloutcomes_z = 0;
	int alloutcomes_y = 0;
	int alloutcomes_x = 0;
	int iterations = 0;
	int myScore= 0;
};

