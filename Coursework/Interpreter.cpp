#include "Interpreter.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <thread>
#include <mutex>

Interpreter::Interpreter()
{
}


Interpreter::~Interpreter()
{
}

//computes result of an equation suplyed as a vector of tokens
double compute(vector<Token>& toCompute, Prisoner& prisoner) {
	if (toCompute.at(0).getType() == CHARVARIABLE) {
		if(toCompute.at(0).getValue() == "W") {
			return 0;
		}
		if (toCompute.at(0).getValue() == "X") {
			return 1;
		}
		if (toCompute.at(0).getValue() == "Y") {
			return 2;
		}
		if (toCompute.at(0).getValue() == "Z") {
			return 3;
		}
		if (toCompute.at(0).getValue() == "A") {
			return 4;
		}
		if (toCompute.at(0).getValue() == "B") {
			return 5;
		}
		if (toCompute.at(0).getValue() == "C") {
			return 6;
		}
	}



	double totalValue = 0;
	bool prevOpAdd = true;
	
	for (int i = 0; i < (int)toCompute.size(); ++i) {
		if (toCompute.at(i).getValue() == "+") {
			prevOpAdd = true;
		}
		else if (toCompute.at(i).getValue() == "-") {
			prevOpAdd = false;
		}
		else if (prevOpAdd) {
			totalValue += prisoner.getVariableValue(toCompute.at(i));
		}
		else{
			totalValue -= prisoner.getVariableValue(toCompute.at(i));
		}
	}

	return totalValue;
}

//solves comparison operators
bool solveComparison(vector<Token> left, vector<Token> right, Token operation, Prisoner& prisoner) {
	
	double leftVal = compute(left,prisoner);
	double rightVal = compute(right, prisoner);

	if ((operation.getValue() == "=") && (leftVal == rightVal)) {
		return true;
	}
	if ((operation.getValue() == "<") && (leftVal < rightVal)){
		return true;
	}
	if ((operation.getValue() == ">") && (leftVal > rightVal)) {
		return true;
	}
	else {
		return false;
	}
}


//find the line that starts with the given line number
int findLine(string lineNumber, vector<vector<Token>>& lines) {
	int i = 0;
	while(i < (int)lines.size()) {
		if (lines.at(i).at(0).getValue() == lineNumber) {
			return i;
		}
		else {
			++i;
		}
	}
	return i;
}

result Interpreter::interpretResult(Prisoner& prisoner)
{
	int lineNumber = 0;
	while(lineNumber < (int)prisoner.getStrategy().getTokens().size()) {
		if (prisoner.getStrategy().getTokens().at(lineNumber).at(1).getValue() == "BETRAY") {
			return	BETRAY;	
		}
		if (prisoner.getStrategy().getTokens().at(lineNumber).at(1).getValue() == "SILENCE") {
			return	SILENCE;
		}
		if (prisoner.getStrategy().getTokens().at(lineNumber).at(1).getValue() == "RANDOM") {
			srand((int)time(NULL));
			int rdm = rand() % 2;
			if (rdm = 1) {
				return	SILENCE;
			}
			else {
				return BETRAY;
			}
		}
		
		if (prisoner.getStrategy().getTokens().at(lineNumber).at(1).getValue() == "IF") {
			//lambda function to find the iterator whihc points to an operator
			std::vector<Token>::iterator opIt = std::find_if(prisoner.getStrategy().getTokens().at(lineNumber).begin() ,
				prisoner.getStrategy().getTokens().at(lineNumber).end(),
				[](Token& t) {
					if (t.getValue() == "=" || t.getValue() == "<" || t.getValue() == ">") {
						return true;
					}
					else {
						return false;
					}
				});

			std::vector<Token>::iterator gotoIT = std::find_if(prisoner.getStrategy().getTokens().at(lineNumber).begin(),
				prisoner.getStrategy().getTokens().at(lineNumber).end(),
				[](Token& t) {
				if (t.getValue() == "GOTO") {
					return true;
				}
				else {
					return false;
				}
			});

			vector<Token> left(prisoner.getStrategy().getTokens().at(lineNumber).begin()+2, opIt);
			vector<Token> right(opIt + 1,gotoIT);
			Token op = *opIt;
			
			if (solveComparison(left, right, op, prisoner)) {
				Token goTo = *(gotoIT + 1);
				
				lineNumber = findLine(goTo.getValue(), prisoner.getStrategy().getTokens());
			}
			else {
				++lineNumber;
			}
			
		}

	}

	return BETRAY;

}


mutex mtx;

void pushTo(vector<result>* results, Prisoner* member) {
	Interpreter inter;
	mtx.lock();
	results->push_back(inter.interpretResult(*member));
	mtx.unlock();
}

vector<result> Interpreter::interpretResult(Gang & gang)
{
	vector<result> results;
	vector<thread> threads;
	for (int i = 0; i < (int)gang.getMembers().size(); ++i) {
		threads.push_back(std::thread(&pushTo, &results, &gang.getMembers().at(i)));
	}
	for (int i = 0; i < threads.size();++i) {
		threads.at(i).join();
	}
	return results;
}
