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
	lexer.tokenizeLine("a 241 quick 234 test of IF the tokenizer  31works + IF BETRAY ");

	SyntaxChecker checker;
	checker.testCheck();
	
	return 0;
}