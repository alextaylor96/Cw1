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

	Strategy s("H:\\visual studio 2017\\Projects\\Coursework\\strat1.txt");
	Prisoner dave(s);

	result r = interpreter.interpretResult(dave);

	SyntaxChecker checker;
	checker.testCheck();
	
	return 0;
}