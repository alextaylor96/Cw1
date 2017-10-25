#pragma once
#include "Lexer.h"
#include "SyntaxChecker.h"
#include "Prisoner.h"
#include "Interpreter.h"
#include "Game.h"
#include "Tournament.h"
#include <iostream>
using namespace std;

int main() {
	
	Game game;
	Interpreter interpreter;

	Strategy s1("H:\\visual studio 2017\\Projects\\Coursework\\strat1.txt");
	Prisoner p1(s1,1);

	Strategy s2("H:\\visual studio 2017\\Projects\\Coursework\\strat2.txt");
	Prisoner p2(s2,2);

	Strategy s3("H:\\visual studio 2017\\Projects\\Coursework\\strat3.txt");
	Prisoner p3(s3,2);

	Strategy s4("H:\\visual studio 2017\\Projects\\Coursework\\strat4.txt");
	Prisoner p4(s4,4);

	Strategy s5("H:\\visual studio 2017\\Projects\\Coursework\\strat5.txt");
	Prisoner p5(s5,5);

	Strategy s6("H:\\visual studio 2017\\Projects\\Coursework\\strat6.txt");
	Prisoner p6(s6,6);

	Strategy s7("H:\\visual studio 2017\\Projects\\Coursework\\strat7.txt");
	Prisoner p7(s7,7);

	Strategy s8("H:\\visual studio 2017\\Projects\\Coursework\\strat8.txt");
	Prisoner p8(s8,8);

	Strategy s9("H:\\visual studio 2017\\Projects\\Coursework\\strat9.txt");
	Prisoner p9(s9,9);

	Strategy s10("H:\\visual studio 2017\\Projects\\Coursework\\strat10.txt");
	Prisoner p10(s10,10);


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


	



	std::cout << "The Prisoners Dilemma.\n";
	cout << "Select which coursework to veiw(1 or 2): \n";
	int selected;
	cin >> selected;
	if (selected == 1) {
		cout << "coursework 1 selected, starting tournament...\n";
		Tournament torn(prisoners);
		torn.playTournament();
		cout << torn;

		cout << "Would you like to see the full leader board? (Y / N) \n";
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			torn.printLeaderBoard();
		}
		else if (choice == 'N' || choice == 'n') {
			cout << "Not displaying full leaderboard. \n";
		}

		
		cout << "Press any key to exit.\n";
		cin >> choice;
	}
	
	
	
	return 0;
}