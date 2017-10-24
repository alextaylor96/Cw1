#include "Interpreter.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>

Interpreter::Interpreter()
{
}


Interpreter::~Interpreter()
{
}

bool solveComparison(string left, string operation, string right) {
	if (operation == "=") {
		if (left == right) {
			return true;
		}



	}
	if (operation == "<"){


	}
	if (operation == ">") {




	}

}

bool isOp(Token& t) {
	if (t.getValue() == "=" || t.getValue() == "<" || t.getValue() == ">") {
		return true;
	}
	else {
		return false;
	}
}

bool isGOTO(Token& t) {
	if (t.getValue() == "GOTO") {
		return true;
	}
	else {
		return false;
	}
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
			
			std::vector<Token>::iterator opIt = std::find_if(prisoner.getStrategy().getTokens().at(i).begin() ,
				prisoner.getStrategy().getTokens().at(i).end(),
				isOp);

			std::vector<Token>::iterator gotoIT = std::find_if(prisoner.getStrategy().getTokens().at(i).begin(),
				prisoner.getStrategy().getTokens().at(i).end(),
				isGOTO);

			vector<Token> left(prisoner.getStrategy().getTokens().at(i).begin()+2, opIt);
			vector<Token> right(opIt + 1,gotoIT);
			Token op = *opIt;
			
			string s = prisoner.getStrategy().getTokens().at(i).at(2).getValue();
									
			
			
		}

	}

	return BETRAY;
}
