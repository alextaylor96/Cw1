#pragma once
#include "Interpreter.h"

class Game
{
public:
	Game();
	~Game();

	//plays a game of 200 iterations between 2 prisoners
	void playGame(Prisoner& prisoner1, Prisoner& prisoner2);

private:
	Interpreter interpreter;
	int iterations = 200;
};

