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
		//get help here
		if (prisoner.getStrategy().getTokens().at(i).at(1).getValue() == "IF") {
			int left;
			int right;

			if (prisoner.getStrategy().getTokens().at(i).at(2).getType() == INTEGER) {
				left = std::stoi(prisoner.getStrategy().getTokens().at(i).at(2).getValue());
			}

			if (prisoner.getStrategy().getTokens().at(i).at(2).getType() == CHARVARIABLE) {
				left = std::stoi(prisoner.getStrategy().getTokens().at(i).at(2).getValue());
			}

			string s = prisoner.getStrategy().getTokens().at(i).at(2).getValue();
									
			if(s == "")
			
		}

	}

	return BETRAY;
}
