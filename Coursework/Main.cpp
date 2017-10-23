#pragma once
#include "Lexer.h"
#include "SyntaxChecker.h"
/*
Tokenize file to lexer
syntax checker on vector of vectors of file tokens
interpreter on vector of vectors
*/

using namespace std;

int main() {
	
	
	Lexer lexer;
	

	lexer.tokenizeFile("H:\\visual studio 2017\\Projects\\Coursework\\strat1\.txt");

	SyntaxChecker checker;
	checker.testCheck();
	
	return 0;
}