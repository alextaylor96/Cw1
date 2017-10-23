#pragma once
#include <string>
#include "SyntaxChecker.h"

class Strategy
{
public:
	Strategy(std::string filePath);
	~Strategy();

	vector <vector<Token>> getTokens();

private:
	vector <vector<Token>> strat;
};

