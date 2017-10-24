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

	Strategy s5("H:\\visual studio 2017\\Projects\\Coursework\\strat5.txt");
	Prisoner p5(s5);

	Strategy s6("H:\\visual studio 2017\\Projects\\Coursework\\strat6.txt");
	Prisoner p6(s6);

	Strategy s7("H:\\visual studio 2017\\Projects\\Coursework\\strat7.txt");
	Prisoner p7(s7);

	Strategy s8("H:\\visual studio 2017\\Projects\\Coursework\\strat8.txt");
	Prisoner p8(s8);

	Strategy s9("H:\\visual studio 2017\\Projects\\Coursework\\strat9.txt");
	Prisoner p9(s9);

	Strategy s10("H:\\visual studio 2017\\Projects\\Coursework\\strat10.txt");
	Prisoner p10(s10);


	vector<Prisoner> prisoners;
	prisoners.push_back(p1);
	prisoners.push_back(p2);
	prisoners.push_back(p3);
	prisoners.push_back(p4);
	prisoners.push_back(p5);
	prisoners.push_back(p6);
	prisoners.push_back(p7);
	prisoners.push_back(p8);
	prisoners.push_back(p9);
	prisoners.push_back(p10);

	
	torn.playTournament(prisoners);
	
	return 0;
}