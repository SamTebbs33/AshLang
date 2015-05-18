#ifndef	TOKENS_H
#define TOKENS_H

using ModifiersInt = unsigned short;

#define SAVE_LINE(a) Token::setLine(a.line);

#include <string>
#include <deque>
#include <vector>
#include <semantics/semantics.hpp>
#include <util/enums.hpp>

extern const char* typeStrs[];

namespace Tokens{
	EnumModifier::type getMod(std::string s);
}

/**
 * A member of the AST. Produced by the parser.
 */
struct Token{
	unsigned int line;
	Token();
	virtual void gen() = 0;
};

/**
 * A token that should be parsed before all other tokens.
 * i.e, type and function declarations use this to be parsed
 * before any statements that require the function/type.
 * @type {Token}
 */
struct TokenPreParseable : Token{
	TokenPreParseable();
	virtual void preParse() = 0;
};

/**
 * A token that should be analysed during the semantic analysis
 * stage. It should also set up any data needed before code
 * generation.
 * @type {Token}
 */
struct TokenAnalysable : Token{
	TokenAnalysable();
	virtual void analyse() = 0;
};

/**
 * A token that can be executed.
 * @type {TokenAnalysable}
 */
struct TokenStatement : public TokenAnalysable, public TokenPreParseable{
	TokenStatement();
	virtual void preParse();
	virtual void analyse();
	virtual void gen();
};

struct Operator{

	std::string* opStr;
	Operator(std::string* str){
		opStr = str;
	}
};

struct TokenIdentifier : public Token{

	std::string str;
	TokenIdentifier(std::string s);
	TokenIdentifier();
	bool operator==(TokenIdentifier n);
	bool operator==(std::string str);
	void gen();
};

struct TokenQualifiedName : public Token{

	std::vector<std::string> paths;
	TokenQualifiedName(TokenIdentifier id);
	TokenQualifiedName();
	void gen();
};

struct TokenNamespace : public TokenPreParseable{

	TokenQualifiedName name;
	TokenNamespace();
	TokenNamespace(TokenQualifiedName n);
	void preParse();
	void gen();
};

struct TokenImport : public TokenPreParseable{

	TokenQualifiedName name;
	TokenImport(TokenQualifiedName i);
	void preParse();
	void gen();
};

struct Imports{

	std::vector<TokenImport> imports;
	Imports();
	Imports(TokenImport i);
};

struct TokenType : public TokenAnalysable{
	bool errored;
	int arrDims = 0;
	TokenIdentifier id;
	TokenType(TokenIdentifier i);
	TokenType();
	virtual void analyse();
	bool operator==(TokenType n);
	bool operator==(std::string str);
	bool operator!=(const char* str);
	void gen();
};

struct TokenArg : public TokenAnalysable{
	bool errored = false;
	TokenIdentifier id;
	TokenType type;
	TokenArg(TokenIdentifier i, TokenType t);
	virtual void analyse();
	bool operator==(TokenArg n);
	bool operator!=(TokenArg n);
	void gen();
};

struct Args{

	std::vector<TokenArg> args;
	Args();
	bool operator==(Args n);
	bool isEmpty();
	void gen();
};

struct Types{
	std::vector<TokenType> types;
	Types(TokenType t);
	Types();
};

struct TokenBlock : public TokenAnalysable{
	std::vector<TokenStatement*> stmts;
	TokenBlock();
	TokenBlock(TokenStatement* s);
	virtual void analyse();
	void gen();
};

struct TokenExpression : public TokenAnalysable{
	virtual void analyse();
	bool errored = false;
    virtual TypeI getExprType();
	void gen();
};

struct TokenDeclaration : public TokenAnalysable, public TokenPreParseable, public TokenStatement{

	TokenIdentifier id;
	ModifiersInt mods;
	TokenDeclaration(TokenIdentifier i, ModifiersInt m);
	TokenDeclaration(TokenIdentifier i);
	TokenDeclaration();
	virtual void preParse();
	virtual void analyse();
	void gen();
};

struct TokenVarDec : public TokenDeclaration, public TokenStatement{

	EnumVarDecKeyword::type decKeyword;
	bool errored = false;
	TokenVarDec(ModifiersInt m, TokenIdentifier id, EnumVarDecKeyword::type k);
	virtual void preParse();
	virtual void analyse();
	void gen();
};

struct TokenVarDecExplicit : public TokenVarDec{

	TokenType type;
	TokenVarDecExplicit(TokenIdentifier i, EnumVarDecKeyword::type k, TokenType t);
	virtual void analyse();
	void gen();
};

struct TokenVarDecExplicitAssign : public TokenVarDecExplicit{

	TokenExpression* expr;
	TokenVarDecExplicitAssign(TokenIdentifier i, EnumVarDecKeyword::type k, TokenType t, TokenExpression* e);
	virtual void analyse();
	void gen();
};

struct TokenVarDecImplicit : public TokenVarDec{

	TokenExpression* expr;
	TokenVarDecImplicit(TokenIdentifier i, EnumVarDecKeyword::type k, TokenExpression* e, ModifiersInt  m);
	virtual void analyse();
	void gen();
};

struct TokenFuncDec : public TokenDeclaration{
	bool errored = false;
	TokenBlock block;
	Args args;
	TokenType type;
	TokenType throws;
	TokenFuncDec(ModifiersInt m, TokenIdentifier i, Args a, TokenType t, TokenType t2);
	TokenFuncDec();
	void preParse();
	virtual void analyse();
	void gen();
};

struct ClassBlock : public TokenPreParseable, public TokenAnalysable{
	std::vector<TokenFuncDec*> funcDecs;
	std::vector<TokenVarDec*> varDecs;
	ClassBlock(TokenFuncDec* funcDec);
	ClassBlock(TokenVarDec* varDec);
	ClassBlock();
	void preParse();
	void analyse();
	void gen();
};

struct TokenTypeDec : public TokenDeclaration{
	bool errored = false;
	Args args;
	TokenTypeDec(Args a, TokenIdentifier i, ModifiersInt m);
	TokenTypeDec(Args a, TokenIdentifier i);
	virtual void preParse();
	virtual void analyse();
	virtual EnumType::type getType();
	void gen();
};

struct TokenClassDec : public TokenTypeDec{
	ClassBlock block;
	Types supers;
	TokenClassDec(Args a, TokenIdentifier i, ModifiersInt m, Types s, ClassBlock b);
	void preParse();
	virtual void analyse();
	virtual EnumType::type getType();
	void gen();
};

struct TokenProtocolDec : public TokenTypeDec{
	ClassBlock block;
	Types supers;
	TokenProtocolDec(Args a, TokenIdentifier i, ModifiersInt m, Types s, ClassBlock b);
	void preParse();
	virtual void analyse();
	virtual EnumType::type getType();
	void gen();
};

struct TokenEnumDec : public TokenTypeDec{

	std::vector<TokenIdentifier> instances;
	TokenEnumDec(Args a, TokenIdentifier i, std::vector<TokenIdentifier> v);
	void preParse();
	virtual void analyse();
	virtual EnumType::type getType();
	void gen();
};

struct TokenFile : public TokenPreParseable, public TokenAnalysable{

	TokenNamespace namespc;
	Imports imports;
	// Using pointers to prevent vector slicing
	std::vector<TokenTypeDec*> typeDecs;
	TokenFile(TokenNamespace n, Imports i, std::vector<TokenTypeDec*> v);
	TokenFile();
	void preParse();
	virtual void analyse();
	void gen();
};

struct TokenReturn : public TokenStatement, public TokenAnalysable{
	bool errored = false;
	TokenExpression* expr;
	TokenReturn();
	TokenReturn(TokenExpression* e);
	virtual void analyse();
	void gen();
};

struct TokenExprInfix : public TokenExpression{
    bool errored = false;
	TokenExpression* expr1, *expr2;
	Operator op;
	TokenExprInfix(TokenExpression* e1, Operator o, TokenExpression* e2);
	virtual void analyse();
    virtual TypeI getExprType();
	void gen();
};

struct TokenExprPrefix : public TokenExpression{

	TokenExpression* expr;
	Operator op;
	TokenExprPrefix(Operator o, TokenExpression* expr);
	virtual void analyse();
    virtual TypeI getExprType();
	void gen();
};

struct TokenExprPostfix : public TokenExpression{

	TokenExpression* expr;
	Operator op;
	TokenExprPostfix(TokenExpression* e, Operator o);
	virtual void analyse();
    virtual TypeI getExprType();
	void gen();
};

struct TokenExprInt : public TokenExpression{

	int val;
	TokenExprInt(int v);
    virtual TypeI getExprType();
	void gen();
};

struct TokenExprStr : public TokenExpression{

	std::string* str;
	TokenExprStr(std::string* s);
    virtual TypeI getExprType();
	void gen();
};

struct TokenExprChar : public TokenExpression{

	char ch;
	TokenExprChar(char c);
    virtual TypeI getExprType();
	void gen();
};

struct TokenExprBool : public TokenExpression{

	bool val;
	TokenExprBool(bool b);
    virtual TypeI getExprType();
	void gen();
};

struct TokenExprFloat : public TokenExpression{

	float val;
	TokenExprFloat(float v);
    virtual TypeI getExprType();
	void gen();
};

struct TokenExprFloat64 : public TokenExpression{

	double val;
	TokenExprFloat64(double v);
    virtual TypeI getExprType();
	void gen();
};

struct TokenExprLong : public TokenExpression{

	long val;
	TokenExprLong(long v);
    virtual TypeI getExprType();
	void gen();
};

struct TokenExprTernary : public TokenExpression{

	TokenExpression* exprBool, *expr1, *expr2;
	TokenExprTernary(TokenExpression* eBool, TokenExpression* e1, TokenExpression* e2);
	virtual void analyse();
    virtual TypeI getExprType();
	void gen();
};

struct TokenPrefix : public TokenExpression{

};

struct TokenVariable : public TokenPrefix{

	TokenPrefix* prefix;
	TokenIdentifier id;
	std::vector<TokenExpression*> arrExprs;
	TokenVariable(TokenIdentifier i);
	virtual void analyse();
    virtual TypeI getExprType();
	void gen();
};

struct TokenVarAssign : public TokenStatement{

	TokenVariable var;
	Operator* op;
	TokenExpression* expr;
	TokenVarAssign(TokenVariable v, Operator* o, TokenExpression* e);
	virtual void analyse();
	void gen();
};

struct TokenFuncCall : public TokenStatement, public TokenPrefix{

	TokenPrefix* prefix;
	TokenIdentifier id;
	std::vector<TokenExpression*> args;
	TokenFuncCall(TokenIdentifier i, std::vector<TokenExpression*> e);
	virtual void analyse();
	void gen();
};

#endif
