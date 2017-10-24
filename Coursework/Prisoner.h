#pragma once
#include "Strategy.h"

class Prisoner
{
public:
	Prisoner(Strategy& strategy);
	~Prisoner();

	void assignStrategy(Strategy& strategy);
	Strategy& getStrategy();

	int getVariableValue(Token t);
	//resets the prisoner for use at the start of each game
	void reset();

	int getTornScore();

	friend class Game;
private:
	Strategy strat;
	char lastOutcome = 0 ; 
	int alloutcomes_w = 0;
	int alloutcomes_z = 0;
	int alloutcomes_y = 0;
	int alloutcomes_x = 0;
	int iterations = 0;
	//score represents the total time recived in sentancing so far(lower score is better)
	int myScore= 0;
	
	int tornyScore = 0;;
};

