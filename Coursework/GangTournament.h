#pragma once
#include "Gang.h"

class GangTournament
{
public:
	GangTournament(vector<Gang>& gangs);
	~GangTournament();

	Gang playTournament();

	void printLeaderBoard();

	friend ostream& operator<<(ostream& ostr, const GangTournament& torn);

private:
	vector<Gang>& contestants;
	Gang* winner = nullptr;
};


