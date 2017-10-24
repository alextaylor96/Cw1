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

bool solveComparison(vector<Token> left, vector<Token> right, Token operation) {
	if (operation.getValue() == "=") {
		


	}
	if (operation.getValue() == "<"){


	}
	if (operation.getValue() == ">") {




	}

	return true;
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
	for (int i = 0; i < (int)prisoner.getStrategy().getTokens().size(); ++i) {
		if (prisoner.getStrategy().getTokens().at(i).at(1).getValue() == "BETRAY") {
			return	BETRAY;	
		}
		if (prisoner.getStrategy().getTokens().at(i).at(1).getValue() == "SILENCE") {
			return	SILENCE;
		}
		if (prisoner.getStrategy().getTokens().at(i).at(1).getValue() == "RANDOM") {
			srand((int)time(NULL));
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
			
			solveComparison(left, right, op);
			
		}

	}

	return BETRAY;
}
