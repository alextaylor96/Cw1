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

