#pragma once
#include <string>
#include "SyntaxChecker.h"

class Strategy
{
public:
	Strategy(std::string filePath);
	~Strategy();

	vector <vector<Token>>& getTokens();

	friend ostream& operator<<(ostream& ostr, const Strategy& strategy);

private:
	vector <vector<Token>> strat;
};

