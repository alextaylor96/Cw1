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

ostream & operator<<(ostream & ostr, const Strategy & strategy)
{
	for (int i = 0; i < strategy.strat.size(); ++i) {
		for (int j = 0; j < strategy.strat.at(i).size(); ++j) {
			ostr << strategy.strat.at(i).at(j);
		}
		cout << endl;
	}
	return ostr;
}
