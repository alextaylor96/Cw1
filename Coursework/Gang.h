#pragma once
#include "GangMember.h"

class Gang
{
public:
	Gang(vector<GangMember>& members, int id, bool switching);
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
	double getTotalScore() const;
	//overloaded op used in sorting
	bool operator< (const Gang &other) const {
		return this->getTotalScore() < other.getTotalScore();
	}
	//returns id of gang
	int getId();

	bool getSwitching();

private:
	vector<GangMember> members;
	int gangId;
	bool switching;
};

