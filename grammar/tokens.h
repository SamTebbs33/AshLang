#ifndef	TOKENS_H

#include <string>
#include <vector>

class Token{
public:
	std::string toString();				
};

class Operator{
public:
	std::string* opStr;
	Operator(std::string* str){
		opStr = str;
	}
};

class TokenNamespace : Token{
public:
	std::string qualifiedName;
};

class Imports{

};

class TokenImport : Token{

};

class TokenTypeDec : Token{

};

class TokenFile : Token{
public:
	TokenNamespace* namespc;
	Imports* imports;
	std::vector<TokenTypeDec*> typeDecs;
};

class TokenModifier : Token{

};

class Modifiers{

};

class TokenFuncDec : Token{

};

class TokenArg : Token{

};

class Args{

};

class TokenType : Token{

};

class Types{

};

class TokenBlock : Token{

};

class TokenStatement : Token{

};

class TokenVarDec : Token{

};

class TokenExpression : Token{

};

#endif
