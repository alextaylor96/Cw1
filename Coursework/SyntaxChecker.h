/*Check the syntax of tokens with respect to the interpreted language*/
#pragma once
#include "Lexer.h"

class SyntaxChecker
{
public:
	SyntaxChecker();
	~SyntaxChecker();

	//check the syntax of the tokens to make sure valid
	bool check(vector<vector<Token>>& toCheck);


};

