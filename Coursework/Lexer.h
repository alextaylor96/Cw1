/*The lexer class used to split the incoming text into a series of tokens*/
#pragma once

#include "Token.h"
#include <vector>

class Lexer
{
public:
	Lexer();
	~Lexer();

	 //tokenise file
	 vector<vector<Token>> tokenizeFile(string filePath);

private:

};

