#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::playGame(Prisoner& prisoner1, Prisoner& prisoner2)
{
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
