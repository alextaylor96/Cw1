#pragma once
#include "Lexer.h"

enum result {BETRAY, SILENCE};

class Interpreter
{
public:
	Interpreter();
	~Interpreter();

	//returns the result of the stratergy 
	result interpretResult(vector<vector<Token>> strat);

};

