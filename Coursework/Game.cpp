#include "Game.h"



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

	}

}
