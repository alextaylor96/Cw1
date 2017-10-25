#pragma once
#include "GangMember.h"

class Gang
{
public:
	Gang(vector<GangMember>& members);
	~Gang();

	vector<GangMember>& getMembers();
	//updates the last outcome of every member and incremeent the number of outcomes(for use with wxyz)
	void updateLastOutcome(char loc);
	//update number of iterations of every member
	void updateIterations();
	//update score of every member
	void updateScore(double toAdd);
	//reset every member
	void reset();

private:
	vector<GangMember>& members;

};

