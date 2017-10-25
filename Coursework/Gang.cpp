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
	if (loc == 'W') {
		for (int i = 0; i <(int)members.size(); ++i) {
			members.at(i).lastOutcome = loc;
			++members.at(i).alloutcomes_w;
		}
	}
	if (loc == 'X') {
		for (int i = 0; i <(int)members.size(); ++i) {
			members.at(i).lastOutcome = loc;
			++members.at(i).alloutcomes_x;
		}
	}
	if (loc == 'Y') {
		for (int i = 0; i < (int)members.size(); ++i) {
			members.at(i).lastOutcome = loc;
			++members.at(i).alloutcomes_y;
		}
	}

	if (loc == 'Z') {
		for (int i = 0; i < (int)members.size(); ++i) {
			members.at(i).lastOutcome = loc;
			++members.at(i).alloutcomes_x;
		}
	}



}

void Gang::updateIterations()
{
	for (int i = 0; i <(int)members.size(); ++i) {
		++members.at(i).iterations;
	}
}

void Gang::updateScore(int toAdd)
{
	for (int i = 0; i <(int)members.size(); ++i) {
		members.at(i).tornyScore += toAdd;
	}
}

void Gang::reset() {
	for (int i = 0; i < (int)members.size(); ++i) {
		members.at(i).reset();
	}
}