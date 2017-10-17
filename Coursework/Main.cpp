#pragma once
#include "Lexer.h"

using namespace std;

int main() {
	
	
	Lexer lexer;
	lexer.tokenize("a 241 quick 234 test of IF the tokenizer  31works + IF BETRAY ");

	
	return 0;
}