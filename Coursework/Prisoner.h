#pragma once
#include "Strategy.h"

class Prisoner
{
public:
	Prisoner(Strategy& strategy, int id);
	~Prisoner();

	void assignStrategy(Strategy& strategy);
	Strategy& getStrategy();

	int getVariableValue(Token t);
	//resets the prisoner for use at the start of each game
	void reset();

	int getTornScore();

	int getId();

	//operator used for sorting
	bool operator< (const Prisoner &other) const {
		return tornyScore < other.tornyScore;
	}

	friend ostream& operator<<(ostream& ostr, const Prisoner& prisoner);

	friend class Game;
	

protected:
	Strategy strat;
	char lastOutcome = 0 ; 
	int alloutcomes_w = 0;
	int alloutcomes_z = 0;
	int alloutcomes_y = 0;
	int alloutcomes_x = 0;
	int iterations = 0;
	//score represents the total time recived in sentancing so far(lower score is better)
	int myScore= 0;
	
	int idNumber;
	int tornyScore = 0;;
};

