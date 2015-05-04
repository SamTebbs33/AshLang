#ifndef	TOKENS_H

#include <string>
#include <vector>

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

class Token{
public:
	std::string toString();				
};

class TokenStatement : public Token{

};

class Operator{
public:
	std::string* opStr;
	Operator(std::string* str){
		opStr = str;
	}
};

class TokenIdentifier : public Token{
public:
	std::string* str;
	TokenIdentifier(std::string* s);
};

class TokenQualifiedName : public Token{
public:
	std::vector<std::string*>* paths;
	TokenQualifiedName(TokenIdentifier* str);
};

class TokenNamespace : public Token{
public:
	TokenQualifiedName* name;
	TokenNamespace();
	TokenNamespace(TokenQualifiedName* n);
};


class TokenImport : public Token{
public:
	TokenQualifiedName* name;
	TokenImport(TokenQualifiedName* i);
};

class Imports{
public:
	std::vector<TokenImport*>* imports;
	Imports();
	Imports(TokenImport* i);
};


class TokenModifier : public Token{
public:
	EnumModifier::type mod;
	TokenModifier(std::string str);
};

class Modifiers{
public:
	std::vector<TokenModifier*>* mods;
	Modifiers();
	Modifiers(TokenModifier* m);
};

class TokenType : public Token{
public:
	int arrDims;
	TokenIdentifier* id;
	TokenType(TokenIdentifier* i);
};

class TokenArg : public Token{
public:
	TokenIdentifier* id;
	TokenType* type;
	TokenArg(TokenIdentifier* i, TokenType* t);
};

class Args{
public:
	std::vector<TokenArg*>* args;
	Args();
};

class Types{
public:
	std::vector<TokenType*>* types;
	Types(TokenType* t);
};

class TokenBlock : public Token{
public:
	std::vector<TokenStatement*>* stmts;
	TokenBlock(TokenStatement* t);
	TokenBlock();
};

class TokenDeclaration : public TokenStatement{
public:
	TokenIdentifier* id;
	Modifiers* mods;
	TokenDeclaration(TokenIdentifier* i, Modifiers* m);
};

class TokenTypeDec : public TokenDeclaration{
public:
	Args* args;
	TokenBlock* block;
	TokenTypeDec(Args* a, TokenIdentifier* i, Modifiers* m, TokenBlock* b);
};

class TokenClassDec : public TokenTypeDec{
public:
	Types* supers;
	TokenClassDec(Args* a, TokenIdentifier* i, Modifiers* m, TokenBlock* b, Types* s);
};

class TokenProtocolDec : public TokenTypeDec{
public:
	Types* supers;
	TokenProtocolDec(Args* a, TokenIdentifier* i, Modifiers* m, TokenBlock* b, Types* s);
};

class TokenEnumDec : public TokenTypeDec{
public:
	std::vector<TokenIdentifier*>* instances;
	TokenBlock* block;
	TokenEnumDec(Args* a, TokenIdentifier* i, std::vector<TokenIdentifier*>* v, TokenBlock* b);
};

class TokenFile : public Token{
public:
	TokenNamespace* namespc;
	Imports* imports;
	std::vector<TokenTypeDec*>* typeDecs;
	TokenFile(TokenNamespace* n, Imports* i, std::vector<TokenTypeDec*>* v);
};

class TokenFuncDec : public TokenDeclaration{
public:
	TokenBlock* block;
	Args* args;
	TokenType* type;
	TokenType* throws;
	TokenFuncDec(TokenIdentifier* i, Args* a, TokenType* t, TokenType* t2);
};

class TokenExpression : public Token{

};

class TokenVarDec : public TokenDeclaration{
public:
	EnumVarDecKeyword::type decKeyword;
	TokenVarDec(TokenIdentifier* id, EnumVarDecKeyword::type k);
};

class TokenVarDecExplicit : public TokenVarDec{
public:
	TokenType* type;
	TokenVarDecExplicit(TokenIdentifier* i, EnumVarDecKeyword::type k, TokenType* t);
};

class TokenVarDecExplicitAssign : public TokenVarDecExplicit{
public:
	TokenExpression* expr;
	TokenVarDecExplicitAssign(TokenIdentifier* i, EnumVarDecKeyword::type k, TokenType* t, TokenExpression* e);
};

class TokenVarDecImplicit : public TokenVarDec{
public:
	TokenExpression* expr;
	TokenVarDecImplicit(TokenIdentifier* i, EnumVarDecKeyword::type k, TokenExpression* e);
};

class TokenReturn : public TokenStatement{
public:
	TokenExpression* expr;
	TokenReturn();
	TokenReturn(TokenExpression* e);
};

class TokenExprInfix : public TokenExpression{
public:
	TokenExpression* expr1, *expr2;
	Operator* op;
	TokenExprInfix(TokenExpression* e1, Operator* o, TokenExpression* e2);
};

class TokenExprPrefix : public TokenExpression{
public:
	TokenExpression* expr;
	Operator* op;
	TokenExprPrefix(Operator* o, TokenExpression* expr);
};

class TokenExprPostfix : public TokenExpression{
public:
	TokenExpression* expr;
	Operator* op;
	TokenExprPostfix(TokenExpression* e, Operator* o);
};

class TokenExprInt : public TokenExpression{
public:
	int val;
	TokenExprInt(int v);
};

class TokenExprStr : public TokenExpression{
public:
	std::string* str;
	TokenExprStr(std::string* s);
};

class TokenExprChar : public TokenExpression{
public:
	char ch;
	TokenExprChar(char c);
};

class TokenExprBool : public TokenExpression{
public:
	bool val;
	TokenExprBool(bool b);
};

class TokenExprFloat : public TokenExpression{
public:
	float val;
	TokenExprFloat(float v);
};

class TokenExprFloat64 : public TokenExpression{
public:
	double val;
	TokenExprFloat64(double v);
};

class TokenExprLong : public TokenExpression{
public:
	long val;
	TokenExprLong(long v);
};

class TokenExprTernary : public TokenExpression{
public:
	TokenExpression* exprBool, *expr1, *expr2;
	TokenExprTernary(TokenExpression* eBool, TokenExpression* e1, TokenExpression* e2);
};

class TokenPrefix : public TokenExpression{

};

class TokenVariable : public TokenPrefix{
public:
	TokenPrefix* prefix;
	TokenIdentifier* id;
	std::vector<TokenExpression*>* arrExprs;
	TokenVariable(TokenIdentifier* i);
};

class TokenVarAssign : public TokenStatement{
public:
	TokenVariable* var;
	Operator* op;
	TokenExpression* expr;
	TokenVarAssign(TokenVariable* v, Operator* o, TokenExpression* e);
};

class TokenFuncCall : public TokenStatement, public TokenPrefix{
public:
	TokenPrefix* prefix;
	TokenIdentifier* id;
	std::vector<TokenExpression*>* args;
	TokenFuncCall(TokenIdentifier* i, std::vector<TokenExpression*>* e);
};

#endif
