#pragma once
#include "Lexer.h"
#include "SyntaxChecker.h"
#include "Prisoner.h"
#include "Interpreter.h"
/*
interpreter on vector of vectors
*/

using namespace std;

int main() {
	
	Interpreter interpreter;

	Strategy s1("H:\\visual studio 2017\\Projects\\Coursework\\strat1.txt");
	Prisoner dave(s1);

	Strategy s2("H:\\visual studio 2017\\Projects\\Coursework\\strat2.txt");
	Prisoner john(s2);

	result r = interpreter.interpretResult(dave);
	result r2 = interpreter.interpretResult(john);
	
	
	return 0;
}