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

result Interpreter::interpretResult(vector<vector<Token>> strat)
{
	for (int i = 0; i < strat.size(); ++i) {
		if (strat.at(i).at(1).getValue() == "BETRAY") {
			return	BETRAY;	
		}
		if (strat.at(i).at(1).getValue() == "SILENCE") {
			return	SILENCE;
		}
		if (strat.at(i).at(1).getValue() == "RANDOM") {
			srand(time(NULL));
			int rdm = rand() % 2;
			if (rdm = 1) {
				return	SILENCE;
			}
			else {
				return BETRAY;
			}
		}
		
		if (strat.at(i).at(1).getValue() == "IF") {




		}

	}

	return result();
}
