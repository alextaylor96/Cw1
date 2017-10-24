#pragma once
#include "Game.h"
class Tournament
{
public:
	Tournament();
	~Tournament();

	Prisoner playTournament(vector<Prisoner>& prisoners);
};

