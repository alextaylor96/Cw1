#include "GangTournament.h"
#include <algorithm>
#include <iostream>
#include "Game.h"

GangTournament::GangTournament(vector<Gang>& gangs) : contestants(gangs)
{

}


GangTournament::~GangTournament()
{
}

Gang GangTournament::playTournament()
{
	Game game;

	for (int i = 0; i < (int)contestants.size(); ++i) {
		for (int j = i + 1; j <(int)contestants.size(); ++j) {
			game.playGame(contestants.at(i), contestants.at(j));
		}
	}
	int bestIndex;
	double bestScore = 10000;
	for (int i = 0; i < (int)contestants.size(); ++i) {
		if (contestants.at(i).getTotalScore() < bestScore) {
			bestIndex = i;
			bestScore = contestants.at(i).getTotalScore();
		}
	}
	winner = &contestants.at(bestIndex);
	return contestants.at(bestIndex);
}

Gang GangTournament::playTournamentWithSpy(int spyFrequency)
{
	Game game;

	for (int i = 0; i < (int)contestants.size(); ++i) {
		for (int j = i + 1; j <(int)contestants.size(); ++j) {
			game.playSpyGame(contestants.at(i), contestants.at(j),spyFrequency);
		}
	}
	int bestIndex;
	double bestScore = 10000;
	for (int i = 0; i < (int)contestants.size(); ++i) {
		if (contestants.at(i).getTotalScore() < bestScore) {
			bestIndex = i;
			bestScore = contestants.at(i).getTotalScore();
		}
	}
	winner = &contestants.at(bestIndex);
	return contestants.at(bestIndex);
}

void GangTournament::printLeaderBoard()
{
	vector<Gang> temp;

	for (int i = 0; i <(int)contestants.size(); ++i) {
		temp.push_back(contestants.at(i));
	}

	sort(temp.begin(), temp.end());

	for (int i = 0; i < (int)temp.size(); ++i) {
		std::cout << "In position " << i + 1 << " is gang number " << temp.at(i).getId() << " with a total score of " << temp.at(i).getTotalScore() ;
		if (temp.at(i).getSwitching()) {
			cout << " this gangs leader switches when trying to find the spy. \n";
		}
		else {
			cout << " this gangs leader doesnt switch when trying to find the spy. \n";
		}
	}
}


ostream & operator<<(ostream & ostr, const GangTournament& torn)
{
	ostr << "The winner of the tournament was the gang number: " << torn.winner->getId() << " with a total score of " << torn.winner->getTotalScore();
	if (torn.winner->getSwitching()) {
		cout << " this gangs leader switches when trying to find the spy. \n";
	}
	else {
		cout << " this gangs leader doesnt switch when trying to find the spy. \n";
	}
	ostr << "It contained members: \n";
	for (int i = 0; i < (int)torn.winner->getMembers().size(); ++i) {
		ostr << torn.winner->getMembers().at(i) << endl;
	}
	
	return ostr;
}

