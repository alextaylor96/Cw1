#pragma once
#include "Lexer.h"
#include "Prisoner.h"
#include "Gang.h"

enum result {BETRAY, SILENCE};

class Interpreter
{
public:
	Interpreter();
	~Interpreter();

	//returns the result of the stratergy 
	result interpretResult(Prisoner& prisoner);
	vector<result> interpretResult(Gang& gang);
};

