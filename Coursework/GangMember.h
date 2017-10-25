#pragma once
#include "Prisoner.h"
class GangMember :	public Prisoner
{
public:
	GangMember(Strategy& strategy, int id);
	~GangMember();

	int getVariableValue(Token t);

	friend class Gang;

private:
	int alloutcomes_a;
	int alloutcomes_b;
	int alloutcomes_c;
};

