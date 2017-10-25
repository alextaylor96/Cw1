#pragma once
#include "GangMember.h"

class Gang
{
public:
	Gang(vector<GangMember>& members, int id);
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
	//gets the total score of the gang
	double getTotalScore();

	int getId();

private:
	vector<GangMember>& members;
	int gangId;

};

