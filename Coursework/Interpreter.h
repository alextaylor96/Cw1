#pragma once
#include "Lexer.h"
#include "Prisoner.h"

enum result {BETRAY, SILENCE};

class Interpreter
{
public:
	Interpreter();
	~Interpreter();

	//returns the result of the stratergy 
	result interpretResult(Prisoner& prisoner);

};

