#include "Game.h"
#include <time.h>
#include <iostream>
#include <algorithm>


Game::Game()
{
}


Game::~Game()
{
}

void Game::playGame(Prisoner& prisoner1, Prisoner& prisoner2)
{
	prisoner1.reset();
	prisoner2.reset();
	for (int i = 0; i < iterations; ++i) {
		result p1result = interpreter.interpretResult(prisoner1);
		result p2result = interpreter.interpretResult(prisoner2);

		++prisoner1.iterations;
		++prisoner2.iterations;

		if (p1result == BETRAY && p2result == BETRAY) {
			prisoner1.lastOutcome = 'Z';
			prisoner2.lastOutcome = 'Z';
			++prisoner1.alloutcomes_z;
			++prisoner2.alloutcomes_z;
			prisoner1.myScore += 4;
			prisoner2.myScore += 4;
		}

		if (p1result == SILENCE && p2result == SILENCE) {
			prisoner1.lastOutcome = 'W';
			prisoner2.lastOutcome = 'W';
			++prisoner1.alloutcomes_w;
			++prisoner2.alloutcomes_w;
			prisoner1.myScore += 2;
			prisoner2.myScore += 2;
		}

		if (p1result == BETRAY && p2result == SILENCE) {
			prisoner1.lastOutcome = 'Y';
			prisoner2.lastOutcome = 'X';
			++prisoner1.alloutcomes_y;
			++prisoner2.alloutcomes_x;
			prisoner1.myScore += 0;
			prisoner2.myScore += 5;
		}


		if (p1result == SILENCE && p2result == BETRAY) {
			prisoner1.lastOutcome = 'X';
			prisoner2.lastOutcome = 'Y';
			++prisoner1.alloutcomes_x;
			++prisoner2.alloutcomes_y;
			prisoner1.myScore += 5;
			prisoner2.myScore += 0;
		}
	}

}


bool checkTotalAgreement(vector<result> & results) {
	result desicion = results.at(0);
	for (int i = 1; i < (int)results.size(); ++i) {
		if (results.at(i) != desicion) {
			return false;
		}
	}
	return true;
}

int countBetrays(vector<result>& results) {
	int numBetrays = 0;
	for (int i = 0; i < (int)results.size(); ++i) {
		if (results.at(i) == BETRAY) {
			++numBetrays;
		}
	}
	return numBetrays;
}

//see if the spy was found
bool checkFound(bool leaderswitched) {
	srand((int)time(NULL));
	int num = rand() % 100 + 1;

	if (leaderswitched) {
		if (num <= 37.5) {//37.5% chance of picking prisoner when switching
			return true;
		}
		else{
			return false;
		}
	}
	else {
		if (num <= 25) {//25% chance of picking prisoner when not switching
			return true;
		}
		else {
			return false;
		}
	}
}

//makes the 1st member of the gang be the spy and switch to be the minority
void spyEffect(vector<result>& result) {
	int betrayCount = 0;
	for (int i = 1; i < result.size(); ++i) {
		if (result.at(i) == BETRAY) {
			++betrayCount;
		}
	}
	if (betrayCount > 2) {
		result.at(0) = SILENCE;
	}
	if (betrayCount < 2) {
		result.at(0) = BETRAY;
	}
}

//redo if time
void Game::playSpyGame(Gang & gang1, Gang & gang2, int spyFrequency)
{
	gang1.reset();
	gang2.reset();

	for (int i = 0; i < iterations; ++i) {
		vector<result> gang1Results = interpreter.interpretResult(gang1);
		vector<result> gang2Results = interpreter.interpretResult(gang2);

		gang1.updateIterations();
		gang2.updateIterations();

		srand((int)time(NULL));
		int gang1Spy = rand() % 100 + 1;

		bool leader1Switching = gang1.getSwitching();
		bool leader2Switching = gang2.getSwitching();
		bool spy1Exists = false;
		bool spy2Exists = false;
		bool spy1Found = false;
		bool spy2Found = false;
		//if theres a spy in gang 1
		if (gang1Spy <= spyFrequency) {
			spy1Exists = true;
			spy1Found = checkFound(leader1Switching);
			spyEffect(gang1Results);
		}
		int gang2Spy = rand() % 100 + 1;
		if (gang2Spy <= spyFrequency) {
			spy2Exists = true;
			spy2Found = checkFound(leader2Switching);
			spyEffect(gang2Results);
		}
		


		bool gang1Agree = checkTotalAgreement(gang1Results);
		bool gang2Agree = checkTotalAgreement(gang2Results);
		//if spys found
		if (spy1Found && spy2Found) {
			gang1.updateScore(6);
			gang2.updateScore(6);

			gang1.updateLastOutcome('?');
			gang2.updateLastOutcome('?');
		}

		else if (spy1Found && !spy2Found) {
			if (leader1Switching) {
				gang1.updateScore(2);
				gang2.updateScore(5);

				gang1.updateLastOutcome('?');
				gang2.updateLastOutcome('?');
			}
			else {
				gang1.updateScore(0);
				gang2.updateScore(5);

				gang1.updateLastOutcome('?');
				gang2.updateLastOutcome('?');
			}
		}

		else if (spy2Found && !spy1Found) {
			if (leader2Switching) {
				gang1.updateScore(5);
				gang2.updateScore(2);

				gang1.updateLastOutcome('?');
				gang2.updateLastOutcome('?');
			}
			else {
				gang1.updateScore(5);
				gang2.updateScore(0);

				gang1.updateLastOutcome('?');
				gang2.updateLastOutcome('?');
			}
		}
		
		//if spys not found
		else if (gang1Agree && gang2Agree && (gang1Results.at(0) == SILENCE) && (gang2Results.at(0) == SILENCE)) {
			gang1.updateScore(2);
			gang2.updateScore(2);
			
			gang1.updateLastOutcome('W');
			gang2.updateLastOutcome('W');
		}
		else if (gang1Agree && gang2Agree && (gang1Results.at(0) == BETRAY) && (gang2Results.at(0) == BETRAY)) {
			gang1.updateScore(4);
			gang2.updateScore(4);

			gang1.updateLastOutcome('Z');
			gang2.updateLastOutcome('Z');
		}
		else if (gang1Agree && gang2Agree && (gang1Results.at(0) == SILENCE) && (gang2Results.at(0) == BETRAY)) {
			gang1.updateScore(5);
			gang2.updateScore(0);

			gang1.updateLastOutcome('X');
			gang2.updateLastOutcome('Y');
		}
		else if (gang1Agree && gang2Agree && (gang1Results.at(0) == BETRAY) && (gang2Results.at(0) == SILENCE)) {
			gang1.updateScore(0);
			gang2.updateScore(5);

			gang1.updateLastOutcome('Y');
			gang2.updateLastOutcome('X');
		}

		else {
			int g1Betrays = countBetrays(gang1Results);
			int g2Betrays = countBetrays(gang2Results);

			if (g1Betrays == g2Betrays) {
				gang1.updateScore(2);
				gang2.updateScore(2);

				gang1.updateLastOutcome('C');
				gang2.updateLastOutcome('C');
			}

			if (g1Betrays > g2Betrays) {
				gang1.updateScore(2.5);
				gang2.updateScore(3);

				gang1.updateLastOutcome('A');
				gang2.updateLastOutcome('B');
			}

			if (g1Betrays < g2Betrays) {
				gang1.updateScore(3);
				gang2.updateScore(2.5);

				gang1.updateLastOutcome('B');
				gang2.updateLastOutcome('A');
			}


		}

	}

}

void Game::playGame(Gang & gang1, Gang & gang2)
{
	gang1.reset();
	gang2.reset();

	for (int i = 0; i < iterations; ++i) {
		vector<result> gang1Results = interpreter.interpretResult(gang1);
		vector<result> gang2Results = interpreter.interpretResult(gang2);

		gang1.updateIterations();
		gang2.updateIterations();

		bool gang1Agree = checkTotalAgreement(gang1Results);
		bool gang2Agree = checkTotalAgreement(gang2Results);

		if (gang1Agree && gang2Agree && (gang1Results.at(0) == SILENCE) && (gang2Results.at(0) == SILENCE)) {
			gang1.updateScore(2);
			gang2.updateScore(2);

			gang1.updateLastOutcome('W');
			gang2.updateLastOutcome('W');
		}
		else if (gang1Agree && gang2Agree && (gang1Results.at(0) == BETRAY) && (gang2Results.at(0) == BETRAY)) {
			gang1.updateScore(4);
			gang2.updateScore(4);

			gang1.updateLastOutcome('Z');
			gang2.updateLastOutcome('Z');
		}
		else if (gang1Agree && gang2Agree && (gang1Results.at(0) == SILENCE) && (gang2Results.at(0) == BETRAY)) {
			gang1.updateScore(5);
			gang2.updateScore(0);

			gang1.updateLastOutcome('X');
			gang2.updateLastOutcome('Y');
		}
		else if (gang1Agree && gang2Agree && (gang1Results.at(0) == BETRAY) && (gang2Results.at(0) == SILENCE)) {
			gang1.updateScore(0);
			gang2.updateScore(5);

			gang1.updateLastOutcome('Y');
			gang2.updateLastOutcome('X');
		}

		else {
			int g1Betrays = countBetrays(gang1Results);
			int g2Betrays = countBetrays(gang2Results);

			if (g1Betrays == g2Betrays) {
				gang1.updateScore(2);
				gang2.updateScore(2);

				gang1.updateLastOutcome('C');
				gang2.updateLastOutcome('C');
			}

			if (g1Betrays > g2Betrays) {
				gang1.updateScore(2.5);
				gang2.updateScore(3);

				gang1.updateLastOutcome('A');
				gang2.updateLastOutcome('B');
			}

			if (g1Betrays < g2Betrays) {
				gang1.updateScore(3);
				gang2.updateScore(2.5);

				gang1.updateLastOutcome('B');
				gang2.updateLastOutcome('A');
			}


		}

	}

}