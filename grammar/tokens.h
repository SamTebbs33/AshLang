#ifndef	TOKENS_H

#include <string>
#include <vector>


class Token{
public:
	std::string toString();				
};

class TokenStatement : Token{

};

class Operator{
public:
	std::string* opStr;
	Operator(std::string* str){
		opStr = str;
	}
};

class TokenIdentifier : Token{
public:
	std::string* str;
	TokenIdentifier(std::string* s);
};

class TokenQualifiedName : Token{
public:
	std::vector<std::string*>* paths;
	TokenQualifiedName(std::string* str);
};

class TokenNamespace : Token{
public:
	TokenQualifiedName* name;
	TokenNamespace();
	TokenNamespace(TokenQualifiedName* n);
};


class TokenImport : Token{
public:
	TokenQualifiedName* name;
	TokenImport(TokenImport* i);
};

class Imports{
public:
	std::vector<TokenImport*>* imports;
	Imports();
	Imports(TokenImport* i);
};


class TokenModifier : Token{

};

class Modifiers{
public:
	std::vector<TokenModifier*>* mods;
	Modifiers();
};

class TokenType : Token{
public:
	int arrDims;
	TokenIdentifier* id;
	TokenType(TokenIdentifier* i);
};

class TokenArg : Token{
public:
	TokenIdentifier* id;
	TokenType* type;
};

class Args{
public:
	std::vector<TokenArg*>* args;
};

class TokenDeclaration : TokenStatement{
public:
	TokenIdentifier* id;
	Modifiers* mods;
	TokenDeclaration(TokenIdentifier* i, Modifiers* m);
};

class TokenTypeDec : TokenDeclaration{
public:
	Args* args;
	TokenTypeDec(Args* a, TokenIdentifier* i, Modifiers* m);
};

class TokenFile : Token{
public:
	TokenNamespace* namespc;
	Imports* imports;
	std::vector<TokenTypeDec*>* typeDecs;
	TokenFile(TokenNamespace* n, Imports* i, std::vector<TokenTypeDec*>* v);
};

class TokenFuncDec : TokenDeclaration{
public:
	Args* args;
	TokenType* type;
	TokenType* throws;
	TokenFuncDec(TokenIdentifier* i, Args* a, TokenType* t, TokenType* t2);
};

class Types{
public:
	std::vector<TokenType*>* types;
	Types(TokenType* t);
};

class TokenBlock : Token{
public:
	std::vector<TokenStatement*>* stmts;
	TokenBlock(TokenStatement* t);
};

class TokenVarDec : TokenDeclaration{
public:
	TokenVarDec(TokenIdentifier* id, Modifiers* m);
};

class TokenExpression : Token{

};

#endif
