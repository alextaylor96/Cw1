#include "Token.h"

Token::Token(Type t, string Val):type(t),value(Val)
{
}

Token::~Token()
{
}

Type Token::getType()
{
	return type;
}

string Token::getValue()
{
	return value;
}

ostream & operator<<(ostream & ostr, const Token & token)
{
	ostr << token.value << " ";
	return ostr;
}
