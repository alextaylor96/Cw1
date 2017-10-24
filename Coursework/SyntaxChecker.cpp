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

bool isLastOutcomeCheck(Token& t) {
	if (t.getValue() == "LASTOUTCOME") {
		return true;
	}
	else {
		return false;
	}
}


bool SyntaxChecker::check(vector<vector<Token>>& toCheck)
{
	for (int i = 0; i < toCheck.size(); ++i) {
		//check line starts with number
		if (toCheck.at(i).at(0).getType() != LINENUMBER) {
			cout << "Line doesnt start with number. \n";
			return false;
		}
		
		//if line is telling to betray/silence/random make sure nothing else on line
		if (toCheck.at(i).at(1).getValue() == "BETRAY" ||
			toCheck.at(i).at(1).getValue() == "SILENCE" ||
			toCheck.at(i).at(1).getValue() == "RANDOM") {
			if (toCheck.at(i).size() > 2) {
				cout << "Line must not contain anything except return value. \n";
				return false;
			}


		}


		for (int tokenPos = 1; tokenPos < toCheck.at(i).size(); ++tokenPos) {
			//if the line is an if statement verify it
			if (toCheck.at(i).at(tokenPos).getValue() == "IF") {

				if (std::count_if(toCheck.at(i).begin(), toCheck.at(i).end(), isComparer) != 1) {
					cout << "incorrect number of '= , < , >' in comparison. \n";
					return false;
				}

				if (std::count_if(toCheck.at(i).begin(), toCheck.at(i).end(), isLastOutcomeCheck) > 0) {
					
					std::vector<Token>::iterator loIt = std::find_if(toCheck.at(i).begin() + 1, toCheck.at(i).end(), isLastOutcomeCheck);

					if ((loIt + 1)->getValue() == "=") {
						if ((loIt + 2)->getType() != CHARVARIABLE) {
							cout << "comparing last outcome with none comparable variable \n";
							return false;
						}
					}
					else if ((loIt - 1)->getValue() == "=") {
						if ((loIt - 2)->getType() != CHARVARIABLE) {
							cout << "comparing last outcome with none comparable variable \n";
							return false;
						}
					}
					else {
						cout << "not comparing lastoutcome with anything \n";
						return false;
					}
				}

				std::vector<Token>::iterator endIt = std::find_if(toCheck.at(i).begin() + 1, toCheck.at(i).end(), isKeyword);

				vector<Token> expresion(toCheck.at(i).begin() + tokenPos + 1, endIt);

				for (int k = 0; k + 2 < expresion.size(); k += 2) {

					if (expresion.at(k).getType() != VARIABLE && expresion.at(k).getType() != INTEGER && expresion.at(k).getType() != CHARVARIABLE) {
						cout << "If not followed by a varriable. \n";
						return false;
					}
					if (expresion.at(k + 1).getType() != OPERATOR) {
						cout << "Varriable not followed by an operator. \n";
						return false;
					}

					if (expresion.at(k + 2).getType() != VARIABLE && expresion.at(k + 2).getType() != INTEGER && expresion.at(k + 2).getType() != CHARVARIABLE) {
						cout << "Operator not followed by a varriable. \n";
						return false;
					}

				}

				if ((endIt + 1)->getType() != INTEGER) {
					return false;
				}
				

			}



		}
	}
}
//
//bool SyntaxChecker::testCheck()
//{
//	Lexer lexer;
//	vector<vector<Token>> testVec;
//	
//	testVec = lexer.tokenizeFile("H:\\visual studio 2017\\Projects\\Coursework\\strat1\.txt");
//	SyntaxChecker checker;
//	bool result = checker.check(testVec);
//	if (result) {
//		cout << "check passed";
//	}
//	else {
//		cout << "check failed";
//	}
//	
//
//	return false;
//}