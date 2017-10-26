#include "Gang.h"



Gang::Gang(vector<GangMember>& members, int id): members(members), gangId(id)
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
			++members.at(i).alloutcomes_z;
		}
	}
	if (loc == 'A') {
		for (int i = 0; i <(int)members.size(); ++i) {
			members.at(i).lastOutcome = loc;
			++members.at(i).alloutcomes_a;
		}
	}
	if (loc == 'B') {
		for (int i = 0; i < (int)members.size(); ++i) {
			members.at(i).lastOutcome = loc;
			++members.at(i).alloutcomes_b;
		}
	}

	if (loc == 'C') {
		for (int i = 0; i < (int)members.size(); ++i) {
			members.at(i).lastOutcome = loc;
			++members.at(i).alloutcomes_c;
		}
	}




}

void Gang::updateIterations()
{
	for (int i = 0; i <(int)members.size(); ++i) {
		++members.at(i).iterations;
	}
}

void Gang::updateScore(double toAdd)
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

double Gang::getTotalScore() const
{
	double score = 0;
	for (int i = 0; i < (int)members.size(); ++i) {
		score += members.at(i).tornyScore;
	}
	return score;
}

int Gang::getId()
{
	return gangId;
}
