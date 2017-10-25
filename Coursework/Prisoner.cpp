#include "Prisoner.h"
#include <iostream>


Prisoner::Prisoner(Strategy& strategy, int id):strat(strategy) , idNumber(id)
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

double Prisoner::getVariableValue(Token t) {
	if (t.getType() == INTEGER) {
		//exception handeling when calling stoi on none integer string, this is bad as could handel myself as seen in lexer but example of how could use for mark.
		try {
			return stoi(t.getValue());
		}
		catch (exception e) {
			std::cout << "Exception caught at like 29 of prisoner.cpp, Cant convert to integer.";
		}
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

	return -1;

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

double Prisoner::getTornScore()
{
	return tornyScore;
}

int Prisoner::getId()
{
	return idNumber;
}

ostream & operator<<(ostream & ostr, const Prisoner & prisoner)
{
	ostr << "Prisoner number: " << prisoner.idNumber << " with a score of " << prisoner.tornyScore << ".\n";
	ostr << "Strategy used: \n";
	ostr << prisoner.strat;
	return ostr;
}
