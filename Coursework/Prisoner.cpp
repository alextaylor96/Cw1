#include "Prisoner.h"



Prisoner::Prisoner(Strategy& strategy):strat(strategy)
{
	
}


Prisoner::~Prisoner()
{
}

void Prisoner::assignStrategy(Strategy& strategy)
{
	strat = strategy;
}

Strategy& Prisoner::getStrategy()
{
	return strat;
}

int Prisoner::getVariableValue(Token t) {
	if (t.getType() == INTEGER) {
		return stoi(t.getValue());
	}

	string value = t.getValue();
	if (value == "LASTOUTCOME") {
		if (lastOutcome == 'W') {
			return 0;
		}
		if (lastOutcome == 'X') {
			return 1;
		}
		if (lastOutcome == 'Y') {
			return 2;
		}
		if (lastOutcome == 'Z') {
			return 3;
		}
		else {
			return -1;
		}
	}
	if (value == "ALLOUTCOMES_W") {
		return alloutcomes_w;
	}
	if (value == "ALLOUTCOMES_X") {
		return alloutcomes_x;
	}
	if (value == "ALLOUTCOMES_Y") {
		return alloutcomes_y;
	}
	if (value == "ALLOUTCOMES_Z") {
		return alloutcomes_z;
	}
	if (value == "ITERATIONS") {
		return iterations;
	}
	if (value == "MYSCORE") {
		return myScore;
	}

}

void Prisoner::reset()
{
	tornyScore += myScore;
	lastOutcome = 0;
	alloutcomes_w = 0;
	alloutcomes_z = 0;
	alloutcomes_y = 0;
	alloutcomes_x = 0;
	iterations = 0;
	myScore = 0;
}

int Prisoner::getTornScore()
{
	return tornyScore;
}
