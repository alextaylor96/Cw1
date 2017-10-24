#pragma once
#include "Game.h"
class Tournament
{
public:
	Tournament(vector<Prisoner>& prisoners);
	~Tournament();

	Prisoner playTournament();

	void printLeaderBoard();

	friend ostream& operator<<(ostream& ostr, const Tournament& torn);

private:
	vector<Prisoner>& contestants;
	Prisoner* winner = nullptr;
};

