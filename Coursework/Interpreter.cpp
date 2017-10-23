#include "Interpreter.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


Interpreter::Interpreter()
{
}


Interpreter::~Interpreter()
{
}

result Interpreter::interpretResult(Prisoner& prisoner)
{
	for (int i = 0; i < prisoner.getStrategy().getTokens().size(); ++i) {
		if (prisoner.getStrategy().getTokens().at(i).at(1).getValue() == "BETRAY") {
			return	BETRAY;	
		}
		if (prisoner.getStrategy().getTokens().at(i).at(1).getValue() == "SILENCE") {
			return	SILENCE;
		}
		if (prisoner.getStrategy().getTokens().at(i).at(1).getValue() == "RANDOM") {
			srand(time(NULL));
			int rdm = rand() % 2;
			if (rdm = 1) {
				return	SILENCE;
			}
			else {
				return BETRAY;
			}
		}
		
		if (prisoner.getStrategy().getTokens().at(i).at(1).getValue() == "IF") {




		}

	}

	return BETRAY;
}
