#pragma once
#include "Lexer.h"
/*
Tokenize file to lexer
syntax checker on vector of vectors of file tokens
interpreter on vector of vectors

*/

using namespace std;

int main() {
	
	
	Lexer lexer;
	lexer.tokenize("a 241 quick 234 test of IF the tokenizer  31works + IF BETRAY ");

	
	return 0;
}