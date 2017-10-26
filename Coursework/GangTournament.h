#pragma once
#include "Gang.h"

class GangTournament
{
public:
	GangTournament(vector<Gang>& gangs);
	~GangTournament();

	Gang playTournament();
	Gang playTournamentWithSpy(int spyFrequency);

	void printLeaderBoard();

	friend ostream& operator<<(ostream& ostr, const GangTournament& torn);

private:
	vector<Gang>& contestants;
	Gang* winner = nullptr;
};


