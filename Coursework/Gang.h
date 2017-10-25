#pragma once
#include "GangMember.h"

class Gang
{
public:
	Gang(vector<GangMember>& members);
	~Gang();

	vector<GangMember>& getMembers();

	void updateLastOutcome(char loc);
	void updateIterations();
	void updateScore(int toAdd);
	void reset();

private:
	vector<GangMember>& members;

};

