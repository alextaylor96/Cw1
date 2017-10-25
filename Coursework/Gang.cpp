#include "Gang.h"



Gang::Gang(vector<GangMember>& members): members(members)
{
}


Gang::~Gang()
{
}

vector<GangMember>& Gang::getMembers()
{
	return members;
}

void Gang::updateLastOutcome(char loc)
{
	for (int i = 0; i < members.size(); ++i) {
		members.at(i).lastOutcome = loc;
	}
}

void Gang::updateIterations()
{
	for (int i = 0; i < members.size(); ++i) {
		++members.at(i).iterations;
	}
}

void Gang::updateScore(int toAdd)
{
	for (int i = 0; i < members.size(); ++i) {
		members.at(i).tornyScore += toAdd;
	}
}

void Gang::reset() {
	for (int i = 0; i < members.size(); ++i) {
		members.at(i).reset();
	}
}