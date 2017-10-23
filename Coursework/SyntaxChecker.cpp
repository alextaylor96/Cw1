#include "SyntaxChecker.h"
#include <iostream>
#include <algorithm>

SyntaxChecker::SyntaxChecker()
{
}


SyntaxChecker::~SyntaxChecker()
{
}

bool isComparer(Token& t) {
	if (t.getValue() == "=" || t.getValue() == "<" || t.getValue() == ">") {
		return true;
	}
	else {
		return false;
	}
}

bool isKeyword(Token& t) {
	if (t.getType() == KEYWORD && t.getValue() != "IF") {
		return true;
	}
	else {
		return false;
	}
}

bool SyntaxChecker::check(vector<vector<Token>>& toCheck)
{
	for (int i = 0; i < toCheck.size(); ++i) {
		for (int tokenPos = 0; tokenPos < toCheck.at(i).size(); ++tokenPos) {


			//if the line is an if statement verify it
			if (toCheck.at(i).at(tokenPos).getValue() == "IF") {

				if (std::count_if(toCheck.at(i).begin(), toCheck.at(i).end(), isComparer) != 1) {
					cout << "incorrect number of '= , < , >' in comparison. \n";
					return false;
				}

				std::vector<Token>::iterator endIt = std::find_if(toCheck.at(i).begin() + 1, toCheck.at(i).end(), isKeyword);
				
				vector<Token> expresion(toCheck.at(i).begin() + tokenPos + 1 , endIt);

				for (int k = 0; k + 2 < expresion.size(); k+=2) {

					if (expresion.at(k).getType() != VARIABLE && expresion.at(k).getType() != INTEGER) {
						cout << "If not followed by a varriable. \n";
						return false;
					}
					if (expresion.at(k + 1).getType() != OPERATOR) {
						cout << "Varriable not followed by an operator. \n";
						return false;
					}

					if (expresion.at(k + 2).getType() != VARIABLE && expresion.at(k + 2).getType() != INTEGER) {
						cout << "Operator not followed by a varriable. \n";
						return false;
					}

				}

			

				
			}
				





		}
	}
}

bool SyntaxChecker::testCheck()
{
	Lexer lexer;
	vector<vector<Token>> testVec;
	testVec.push_back(lexer.tokenizeLine("10 IF ALLOUTCOMES_W < ALLOUTCOMES_Z + 30 GOTO 30"));
	SyntaxChecker checker;
	bool result = checker.check(testVec);
	if (result) {
		cout << "check passed";
	}
	else {
		cout << "check failed";
	}
	

	return false;
}