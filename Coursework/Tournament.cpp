#include "Tournament.h"
#include <algorithm>
#include <iostream>

Tournament::Tournament(vector<Prisoner>& prisoners) : contestants(prisoners)
{
	
}


Tournament::~Tournament()
{
}

Prisoner Tournament::playTournament()
{
	Game game;
	
	for (int i = 0; i < contestants.size(); ++i) {
		for (int j = i + 1 ; j < contestants.size(); ++j) {
			game.playGame(contestants.at(i), contestants.at(j));
		}
	}
	int bestIndex;
	int bestScore = 10000;
	for (int i = 0; i < contestants.size(); ++i) {
		if (contestants.at(i).getTornScore() < bestScore) {
			bestIndex = i;
			bestScore = contestants.at(i).getTornScore();
		}
	}
	winner = &contestants.at(bestIndex);
	return contestants.at(bestIndex);
}

void Tournament::printLeaderBoard()
{
	vector<Prisoner> temp;
	int currentBestIndex;
	int currentBestScore = 10000;
	for (int i = 0; i < contestants.size(); ++i) {
		temp.push_back(contestants.at(i));
	}

	sort(temp.begin(), temp.end());

	for (int i = 0; i < temp.size(); ++i) {
		std::cout <<"In position " << i + 1 << " is prisoner number " << temp.at(i).getId() << " with a score of " << temp.at(i).getTornScore() << "\n";
	}
}


ostream & operator<<(ostream & ostr, const Tournament& torn)
{
	ostr << "The winner of the tournament was the prisoner number: " << torn.winner->getId() << " with a score of " << torn.winner->getTornScore() << ".\n";
	return ostr;
}

