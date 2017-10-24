#pragma once
#include "Lexer.h"
#include "SyntaxChecker.h"
#include "Prisoner.h"
#include "Interpreter.h"
#include "Game.h"
#include "Tournament.h"

using namespace std;

int main() {
	
	Game game;
	Interpreter interpreter;
	Tournament torn;

	Strategy s1("H:\\visual studio 2017\\Projects\\Coursework\\strat1.txt");
	Prisoner p1(s1);

	Strategy s2("H:\\visual studio 2017\\Projects\\Coursework\\strat2.txt");
	Prisoner p2(s2);

	Strategy s3("H:\\visual studio 2017\\Projects\\Coursework\\strat3.txt");
	Prisoner p3(s3);

	Strategy s4("H:\\visual studio 2017\\Projects\\Coursework\\strat4.txt");
	Prisoner p4(s4);

	vector<Prisoner> prisoners;
	prisoners.push_back(p1);
	prisoners.push_back(p2);
	prisoners.push_back(p3);
	prisoners.push_back(p4);

	
	torn.playTournament(prisoners);

	return 0;
}