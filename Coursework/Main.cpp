#pragma once
#include "Lexer.h"

using namespace std;

int main() {
	
	
	Lexer lexer;
	lexer.tokenize("a quick 234 test of IF the tokenizer works + IF BETRAY ");

	
	return 0;
}