#include "Tournament.h"



Tournament::Tournament()
{
}


Tournament::~Tournament()
{
}

Prisoner Tournament::playTournament(vector<Prisoner>& prisoners)
{
	Game game;

	for (int i = 0; i < prisoners.size(); ++i) {
		for (int j = i + 1 ; j < prisoners.size(); ++j) {
			game.playGame(prisoners.at(i), prisoners.at(j));
		}
	}
	int bestIndex;
	int bestScore = 10000;
	for (int i = 0; i < prisoners.size(); ++i) {
		if (prisoners.at(i).getTornScore() < bestScore) {
			bestIndex = i;
			bestScore = prisoners.at(i).getTornScore();
		}
	}
	
	return prisoners.at(bestIndex);
}
