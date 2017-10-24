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
		return lastOutcome;
	}
	if (value == "ALLOUTCOMES_X") {
		return lastOutcome;
	}
	if (value == "ALLOUTCOMES_Y") {
		return lastOutcome;
	}
	if (value == "ALLOUTCOMES_Z") {
		return lastOutcome;
	}
	if (value == "ITERATIONS") {
		return lastOutcome;
	}
	if (value == "MYSCORE") {
		return lastOutcome;
	}

}