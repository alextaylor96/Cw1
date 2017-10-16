/*Class used to store tokens created by the lexer and used in the interpretation on the prisoner strategy interpretation language, each token has a type
 and a value*/

#pragma once
#include <string>

using namespace std;
//the type of the token
enum Type {KEYWORD,OPERATOR,INTEGER,VARIABLE};

class Token
{
public:
	Token(Type type,string Value);
	~Token();

private:
	
	Type type;
	string value;
};

