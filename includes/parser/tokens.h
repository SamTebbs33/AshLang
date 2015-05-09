#ifndef	TOKENS_H
#define TOKENS_H

#include <string>
#include <vector>
#include <loader/classloader.h>
#include <util/util.h>

struct EnumVarDecKeyword{
	enum type{
		CONST, VAR
	};
};

struct EnumModifier{
	enum type{
		PUBLIC=1, PRIVATE=2, PROTECTED=4, FINAL=8, REQUIRED=16, NATIVE=32, OVERRIDE=64, STANDARD=128, STATIC=256
	};
};

struct Token{

	std::string toString();
	Token();
	virtual void preParse();
};

struct TokenStatement : public Token{

	TokenStatement();
};

struct Operator{

	std::string* opStr;
	Operator(std::string* str){
		opStr = str;
	}
};

struct TokenIdentifier : public Token{

	std::string* str;
	TokenIdentifier(std::string* s);
};

struct TokenQualifiedName : public Token{

	std::vector<std::string*>* paths;
	TokenQualifiedName(TokenIdentifier* str);
};

struct TokenNamespace : public Token{

	TokenQualifiedName* name;
	TokenNamespace();
	TokenNamespace(TokenQualifiedName* n);
	virtual void preParse();
};

struct TokenImport : public Token{

	TokenQualifiedName* name;
	TokenImport(TokenQualifiedName* i);
	virtual void preParse();
};

struct Imports{

	std::vector<TokenImport*>* imports;
	Imports();
	Imports(TokenImport* i);
};


struct TokenModifier : public Token{

	EnumModifier::type mod;
	TokenModifier(std::string str);
};

struct Modifiers{

	std::vector<TokenModifier*>* mods;
	Modifiers();
	Modifiers(TokenModifier* m);
};

struct TokenType : public Token{

	int arrDims;
	TokenIdentifier* id;
	TokenType(TokenIdentifier* i);
};

struct TokenArg : public Token{

	TokenIdentifier* id;
	TokenType* type;
	TokenArg(TokenIdentifier* i, TokenType* t);
};

struct Args{

	std::vector<TokenArg*>* args;
	Args();
};

struct Types{

	std::vector<TokenType*>* types;
	Types(TokenType* t);
};

struct TokenBlock : public Token{

	std::vector<TokenStatement*>* stmts;
	TokenBlock(TokenStatement* t);
	TokenBlock();
	virtual void preParse();
};

struct TokenDeclaration : public TokenStatement{

	TokenIdentifier* id;
	Modifiers* mods;
	TokenDeclaration(TokenIdentifier* i, Modifiers* m);
};

struct TokenTypeDec : public TokenDeclaration{

	Args* args;
	TokenBlock* block;
	TokenTypeDec(Args* a, TokenIdentifier* i, Modifiers* m, TokenBlock* b);
	virtual void preParse();
};

struct TokenClassDec : public TokenTypeDec{

	Types* supers;
	TokenClassDec(Args* a, TokenIdentifier* i, Modifiers* m, TokenBlock* b, Types* s);
};

struct TokenProtocolDec : public TokenTypeDec{

	Types* supers;
	TokenProtocolDec(Args* a, TokenIdentifier* i, Modifiers* m, TokenBlock* b, Types* s);
};

struct TokenEnumDec : public TokenTypeDec{

	std::vector<TokenIdentifier*>* instances;
	TokenBlock* block;
	TokenEnumDec(Args* a, TokenIdentifier* i, std::vector<TokenIdentifier*>* v, TokenBlock* b);
};

struct TokenFile : public Token{

	TokenNamespace* namespc;
	Imports* imports;
	std::vector<TokenTypeDec*>* typeDecs;
	TokenFile(TokenNamespace* n, Imports* i, std::vector<TokenTypeDec*>* v);
	virtual void preParse();
};

struct TokenFuncDec : public TokenDeclaration{

	TokenBlock* block;
	Args* args;
	TokenType* type;
	TokenType* throws;
	TokenFuncDec(TokenIdentifier* i, Args* a, TokenType* t, TokenType* t2);
	virtual void preParse();
};

struct TokenExpression : public Token{

};

struct TokenVarDec : public TokenDeclaration{

	EnumVarDecKeyword::type decKeyword;
	TokenVarDec(TokenIdentifier* id, EnumVarDecKeyword::type k);
};

struct TokenVarDecExplicit : public TokenVarDec{

	TokenType* type;
	TokenVarDecExplicit(TokenIdentifier* i, EnumVarDecKeyword::type k, TokenType* t);
};

struct TokenVarDecExplicitAssign : public TokenVarDecExplicit{

	TokenExpression* expr;
	TokenVarDecExplicitAssign(TokenIdentifier* i, EnumVarDecKeyword::type k, TokenType* t, TokenExpression* e);
};

struct TokenVarDecImplicit : public TokenVarDec{

	TokenExpression* expr;
	TokenVarDecImplicit(TokenIdentifier* i, EnumVarDecKeyword::type k, TokenExpression* e);
};

struct TokenReturn : public TokenStatement{

	TokenExpression* expr;
	TokenReturn();
	TokenReturn(TokenExpression* e);
};

struct TokenExprInfix : public TokenExpression{

	TokenExpression* expr1, *expr2;
	Operator* op;
	TokenExprInfix(TokenExpression* e1, Operator* o, TokenExpression* e2);
};

struct TokenExprPrefix : public TokenExpression{

	TokenExpression* expr;
	Operator* op;
	TokenExprPrefix(Operator* o, TokenExpression* expr);
};

struct TokenExprPostfix : public TokenExpression{

	TokenExpression* expr;
	Operator* op;
	TokenExprPostfix(TokenExpression* e, Operator* o);
};

struct TokenExprInt : public TokenExpression{

	int val;
	TokenExprInt(int v);
};

struct TokenExprStr : public TokenExpression{

	std::string* str;
	TokenExprStr(std::string* s);
};

struct TokenExprChar : public TokenExpression{

	char ch;
	TokenExprChar(char c);
};

struct TokenExprBool : public TokenExpression{

	bool val;
	TokenExprBool(bool b);
};

struct TokenExprFloat : public TokenExpression{

	float val;
	TokenExprFloat(float v);
};

struct TokenExprFloat64 : public TokenExpression{

	double val;
	TokenExprFloat64(double v);
};

struct TokenExprLong : public TokenExpression{

	long val;
	TokenExprLong(long v);
};

struct TokenExprTernary : public TokenExpression{

	TokenExpression* exprBool, *expr1, *expr2;
	TokenExprTernary(TokenExpression* eBool, TokenExpression* e1, TokenExpression* e2);
};

struct TokenPrefix : public TokenExpression{

};

struct TokenVariable : public TokenPrefix{

	TokenPrefix* prefix;
	TokenIdentifier* id;
	std::vector<TokenExpression*>* arrExprs;
	TokenVariable(TokenIdentifier* i);
};

struct TokenVarAssign : public TokenStatement{

	TokenVariable* var;
	Operator* op;
	TokenExpression* expr;
	TokenVarAssign(TokenVariable* v, Operator* o, TokenExpression* e);
};

struct TokenFuncCall : public TokenStatement, public TokenPrefix{

	TokenPrefix* prefix;
	TokenIdentifier* id;
	std::vector<TokenExpression*>* args;
	TokenFuncCall(TokenIdentifier* i, std::vector<TokenExpression*>* e);
};

#endif
