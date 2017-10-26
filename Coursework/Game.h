#pragma once
#include "Interpreter.h"

class Game
{
public:
	Game();
	~Game();

	//plays a game of 200 iterations between 2 prisoners
	void playGame(Prisoner& prisoner1, Prisoner& prisoner2);

	void playSpyGame(Gang & gang1, Gang & gang2, int spyFrequency);

	//plays a game of 200 iterations between 2 Gangs
	void playGame(Gang& gang1, Gang& gang2);

private:
	Interpreter interpreter;
	int iterations = 200;
};

