/*The lexer class used to split the incoming text into a series of tokens*/
#pragma once

#include "Token.h"
#include <vector>

class Lexer
{
public:
	Lexer();
	~Lexer();
	//converts a string into a vector of tokens
	 vector<Token> tokenizeLine(string input);
	 //tokenise file
private:

};

