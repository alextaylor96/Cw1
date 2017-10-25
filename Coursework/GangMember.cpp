#include "GangMember.h"



GangMember::GangMember(Strategy& strategy, int id) : Prisoner( strategy,  id)
{
}


GangMember::~GangMember()
{
}

int GangMember::getVariableValue(Token t)
{
		if (t.getType() == INTEGER) {
			return stoi(t.getValue());
		}

		string value = t.getValue();
		if (value == "LASTOUTCOME") {
			if (lastOutcome == 'W') {
				return 0;
			}
			if (lastOutcome == 'X') {
				return 1;
			}
			if (lastOutcome == 'Y') {
				return 2;
			}
			if (lastOutcome == 'Z') {
				return 3;
			}
			if (lastOutcome == 'A') {
				return 4;
			}
			if (lastOutcome == 'B') {
				return 5;
			}
			if (lastOutcome == 'C') {
				return 6;
			}
			else {
				return -1;
			}
		}
		if (value == "ALLOUTCOMES_W") {
			return alloutcomes_w;
		}
		if (value == "ALLOUTCOMES_X") {
			return alloutcomes_x;
		}
		if (value == "ALLOUTCOMES_Y") {
			return alloutcomes_y;
		}
		if (value == "ALLOUTCOMES_Z") {
			return alloutcomes_z;
		}
		if (value == "ITERATIONS") {
			return iterations;
		}
		if (value == "MYSCORE") {
			return myScore;
		}

	
}
