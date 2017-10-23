#include "SyntaxChecker.h"



SyntaxChecker::SyntaxChecker()
{
}


SyntaxChecker::~SyntaxChecker()
{
}

bool SyntaxChecker::check(vector<vector<Token>>& toCheck)
{
	for (int i = 0; i < toCheck.size(); ++i) {
		for (int j = 0; j < toCheck.at(i).size(); ++j) {
			if (toCheck.at(i).at(j))
				return false;
		}
	}
}
