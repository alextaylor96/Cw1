#pragma once
#include "Lexer.h"
#include "SyntaxChecker.h"
#include "Prisoner.h"
#include "Interpreter.h"
#include "Game.h"
#include "Tournament.h"
#include "GangTournament.h"
#include <iostream>
using namespace std;

//question 2 the morelikely there is for there to be a spy the better it is for the leader to switch, if spys are alot rarer then its better ot not switch

int main() {
	
	Game game;
	Interpreter interpreter;

	Strategy s1("H:\\visual studio 2017\\Projects\\Coursework\\strat1.txt");
	Prisoner p1(s1,1);
	GangMember g1(s1, 1);

	Strategy s2("H:\\visual studio 2017\\Projects\\Coursework\\strat2.txt");
	Prisoner p2(s2,2);
	GangMember g2(s2, 2);

	Strategy s3("H:\\visual studio 2017\\Projects\\Coursework\\strat3.txt");
	Prisoner p3(s3,2);
	GangMember g3(s3, 3);

	Strategy s4("H:\\visual studio 2017\\Projects\\Coursework\\strat4.txt");
	Prisoner p4(s4,4);
	GangMember g4(s4, 4);

	Strategy s5("H:\\visual studio 2017\\Projects\\Coursework\\strat5.txt");
	Prisoner p5(s5,5);
	GangMember g5(s5, 5);

	Strategy s6("H:\\visual studio 2017\\Projects\\Coursework\\strat6.txt");
	Prisoner p6(s6,6);
	GangMember g6(s6, 6);

	Strategy s7("H:\\visual studio 2017\\Projects\\Coursework\\strat7.txt");
	Prisoner p7(s7,7);
	GangMember g7(s7, 7);

	Strategy s8("H:\\visual studio 2017\\Projects\\Coursework\\strat8.txt");
	Prisoner p8(s8,8);
	GangMember g8(s8, 8);

	Strategy s9("H:\\visual studio 2017\\Projects\\Coursework\\strat9.txt");
	Prisoner p9(s9,9);
	GangMember g9(s9, 9);

	Strategy s10("H:\\visual studio 2017\\Projects\\Coursework\\strat11.txt");
	Prisoner p10(s10,10);
	GangMember g10(s10, 10);


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


	vector<GangMember> gang1Members;
	gang1Members.push_back(g1);
	gang1Members.push_back(g2);
	gang1Members.push_back(g3);
	gang1Members.push_back(g4);
	gang1Members.push_back(g5);

	vector<GangMember> gang2Members;
	gang2Members.push_back(g6);
	gang2Members.push_back(g7);
	gang2Members.push_back(g8);
	gang2Members.push_back(g9);
	gang2Members.push_back(g10);

	vector<GangMember> gang3Members;
	gang3Members.push_back(g2);
	gang3Members.push_back(g2);
	gang3Members.push_back(g2);
	gang3Members.push_back(g2);
	gang3Members.push_back(g2);

	vector<GangMember> gang4Members;
	gang4Members.push_back(g10);
	gang4Members.push_back(g2);
	gang4Members.push_back(g2);
	gang4Members.push_back(g9);
	gang4Members.push_back(g10);
	
	
	Gang gang1(gang1Members,1,true);
	Gang gang2(gang2Members,2, true);
	Gang gang3(gang3Members, 3,true);
	Gang gang4(gang4Members, 4, true);
	Gang gang5(gang1Members, 5, false);
	Gang gang6(gang2Members, 6, false);
	Gang gang7(gang3Members, 7, false);
	Gang gang8(gang4Members, 8, false);

	vector<Gang> gangs;
	gangs.push_back(gang1);
	gangs.push_back(gang2);
	gangs.push_back(gang3);
	gangs.push_back(gang4);
	gangs.push_back(gang5);
	gangs.push_back(gang6);
	gangs.push_back(gang7);
	gangs.push_back(gang8);


	vector<Gang> gangs2;
	gangs2.push_back(gang1);
	gangs2.push_back(gang2);
	gangs2.push_back(gang3);
	gangs2.push_back(gang4);

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

		
		cout << "Press 2 to carry on to coursework 2 or any other key to exit.\n";
		cin >> selected;
	}
	if (selected == 2) {
		cout << "coursework 2 selected. \n";
		
		cout << "Would you like a spy to be present? (Y/N) \n";
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			GangTournament gt(gangs);
			cout << "Please enter % of the time for spy to be present in the team: \n";
			int spyPercent;
			cin >> spyPercent;
			gt.playTournamentWithSpy(spyPercent);
			cout << gt;
			cout << "Would you like to see the full leader board? (Y / N) \n";
			cin >> choice;
			if (choice == 'Y' || choice == 'y') {
				gt.printLeaderBoard();
			}
			else if (choice == 'N' || choice == 'n') {
				cout << "Not displaying full leaderboard. \n";
			}

			cout << "Would you like to run a small tornament with 2 gangs at varring spy % (Y / N) \n";
			cin >> choice;
			if (choice == 'Y' || choice == 'y') {
				vector<Gang> gangs2;
				gangs2.push_back(gang2);
				gangs2.push_back(gang6);
				GangTournament gt(gangs2);
				gt.playTournamentWithSpy(0);
				cout << gt;
				gt.playTournamentWithSpy(5);
				cout << gt;
				gt.playTournamentWithSpy(10);
				cout << gt;
				gt.playTournamentWithSpy(15);
				cout << gt;
				gt.playTournamentWithSpy(20);
				cout << gt;
				
			}
			else if (choice == 'N' || choice == 'n') {
				cout << "Not playing small torny. \n";
			}

		}
		else if (choice == 'N' || choice == 'n') {
			GangTournament gt(gangs2);
			cout << "Playing tornament with no spy. \n";
			gt.playTournament();
			cout << gt;

			cout << "Would you like to see the full leader board? (Y / N) \n";
			cin >> choice;
			if (choice == 'Y' || choice == 'y') {
				gt.printLeaderBoard();
			}
			else if (choice == 'N' || choice == 'n') {
				cout << "Not displaying full leaderboard. \n";
			}
		}

		


		cout << "Press any key to exit.\n";
		cin >> selected;
	}
	
	
	
	return 0;
}