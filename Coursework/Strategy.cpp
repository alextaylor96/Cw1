#include "Strategy.h"
#include <iostream>


Strategy::Strategy(std::string filePath)
{
	Lexer lexer;
	SyntaxChecker checker;
	vector<vector<Token>> tokens = lexer.tokenizeFile(filePath);
	if (checker.check(tokens)) {
		strat = tokens;
	}
	else {
	//ask about adding exception here 
		cout << "error is creating strategy. \n";
	}
}


Strategy::~Strategy()
{
}

vector<vector<Token>>& Strategy::getTokens()
{
	return strat;
}
