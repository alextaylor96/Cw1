#include "Lexer.h"
#include <sstream>
#include <iterator>

Lexer::Lexer()
{
}


Lexer::~Lexer()
{
}

vector<Token> Lexer::tokenize(string input)
{
	vector<string> inputWords;
	istringstream ss(input);
	copy(istream_iterator<string>(ss),
		istream_iterator<string>(),
		back_inserter(inputWords));

	vector<Token> tokens;
	for (int i = 0; i < inputWords.size(); ++i) {
	//keywords
		if (inputWords[i] == "IF") {
			Token newToken(KEYWORD, "IF");
			tokens.push_back(newToken);
		}
		else if (inputWords[i] == "GOTO") {
			Token newToken(KEYWORD, "GOTO");
			tokens.push_back(newToken);
		}
		else if (inputWords[i] == "BETRAY") {
			Token newToken(KEYWORD, "BETRAY");
			tokens.push_back(newToken);
		}
		else if (inputWords[i] == "SILENCE") {
			Token newToken(KEYWORD, "SILENCE");
			tokens.push_back(newToken);
		}
		else if (inputWords[i] == "RANDOM") {
			Token newToken(KEYWORD, "RANDOM");
			tokens.push_back(newToken);
		}
	//operators
		else if (inputWords[i] == "+") {
			Token newToken(OPERATOR, "+");
			tokens.push_back(newToken);
		}

		else if (inputWords[i] == "=") {
			Token newToken(OPERATOR, "=");
			tokens.push_back(newToken);
		}
		else if (inputWords[i] == "-") {
			Token newToken(OPERATOR, "-");
			tokens.push_back(newToken);
		}
		else if (inputWords[i] == ">") {
			Token newToken(OPERATOR, ">");
			tokens.push_back(newToken);
		}
		else if (inputWords[i] == "<") {
			Token newToken(OPERATOR, "<");
			tokens.push_back(newToken);
		}
	//variables
		else if (inputWords[i] == "LASTOUTCOME") {
			Token newToken(VARIABLE, "LASTOUTCOME");
			tokens.push_back(newToken);
		}
		else if (inputWords[i] == "ALLOUTCOMES_W") {
			Token newToken(VARIABLE, "ALLOUTCOMES_W");
			tokens.push_back(newToken);
		}
		else if (inputWords[i] == "ALLOUTCOMES_X") {
			Token newToken(VARIABLE, "ALLOUTCOMES_X");
			tokens.push_back(newToken);
		}
		else if (inputWords[i] == "ALLOUTCOMES_Y") {
			Token newToken(VARIABLE, "ALLOUTCOMES_Y");
			tokens.push_back(newToken);
		}
		else if (inputWords[i] == "ALLOUTCOMES_Z") {
			Token newToken(VARIABLE, "ALLOUTCOMES_Z");
			tokens.push_back(newToken);
		}
		else if (inputWords[i] == "ITERATIONS") {
			Token newToken(VARIABLE, "ITERATIONS");
			tokens.push_back(newToken);
		}
		else if (inputWords[i] == "MYSCORE") {
			Token newToken(VARIABLE, "MYSCORE");
			tokens.push_back(newToken);
		}
		else{
			try {
				stoi(inputWords[i]);
				Token newToken(INTEGER, inputWords[i]);
				tokens.push_back(newToken);
			}
			catch (exception e) {

			}
		}
	}


	return tokens;
}
