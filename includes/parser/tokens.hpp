#ifndef	TOKENS_H
#define TOKENS_H

using ModifiersInt = unsigned short;

#define SAVE_LINE(a) Token::setLine(a.line);

#include <string>
#include <deque>
#include <vector>
#include <semantics/semantics.hpp>

struct EnumVarDecKeyword{
	enum type{
		CONST, VAR
	};
};

struct EnumModifier{
	enum type{
		PUBLIC=1, PRIVATE=2, PROTECTED=4, FINAL=8, REQUIRED=16, NATIVE=32, OVERRIDE=64, STANDARD=128, STATIC=256, INVALID=512
	};
};

struct EnumType{
    enum type{
        CLASS,
        PROTOCOL,
        ENUM,
		NUM_TYPES
    };
};

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
};

struct TokenQualifiedName : public Token{

	std::vector<std::string> paths;
	TokenQualifiedName(TokenIdentifier id);
	TokenQualifiedName();
};

struct TokenNamespace : public TokenPreParseable{

	TokenQualifiedName name;
	TokenNamespace();
	TokenNamespace(TokenQualifiedName n);
	void preParse();
};

struct TokenImport : public TokenPreParseable{

	TokenQualifiedName name;
	TokenImport(TokenQualifiedName i);
	void preParse();
};

struct Imports{

	std::vector<TokenImport> imports;
	Imports();
	Imports(TokenImport i);
};

struct TokenType : public TokenAnalysable{
	bool errored;
	int arrDims;
	TokenIdentifier id;
	TokenType(TokenIdentifier i);
	TokenType();
	virtual void analyse();
	bool operator==(TokenType n);
	bool operator==(std::string str);
	bool operator!=(const char* str);
};

struct TokenArg : public TokenAnalysable{
	bool errored = false;
	TokenIdentifier id;
	TokenType type;
	TokenArg(TokenIdentifier i, TokenType t);
	virtual void analyse();
	bool operator==(TokenArg n);
	bool operator!=(TokenArg n);
};

struct Args{

	std::vector<TokenArg> args;
	Args();
	bool operator==(Args n);
};

struct Types{
	std::vector<TokenType> types;
	Types(TokenType t);
};

struct TokenBlock : public TokenAnalysable{
	std::vector<TokenStatement*> stmts;
	TokenBlock();
	TokenBlock(TokenStatement* s);
	virtual void analyse();
};

struct TokenExpression : public TokenAnalysable{
	virtual void analyse();
    virtual TypeI getExprType();
};

struct TokenDeclaration : public TokenAnalysable, public TokenPreParseable, public TokenStatement{

	TokenIdentifier id;
	ModifiersInt mods;
	TokenDeclaration(TokenIdentifier i, ModifiersInt m);
	TokenDeclaration(TokenIdentifier i);
	TokenDeclaration();
	virtual void preParse();
	virtual void analyse();
};

struct TokenVarDec : public TokenDeclaration, public TokenStatement{

	EnumVarDecKeyword::type decKeyword;
	bool errored = false;
	TokenVarDec(ModifiersInt m, TokenIdentifier id, EnumVarDecKeyword::type k);
	virtual void preParse();
	virtual void analyse();
};

struct TokenVarDecExplicit : public TokenVarDec{

	TokenType type;
	TokenVarDecExplicit(TokenIdentifier i, EnumVarDecKeyword::type k, TokenType t);
	virtual void analyse();
};

struct TokenVarDecExplicitAssign : public TokenVarDecExplicit{

	TokenExpression expr;
	TokenVarDecExplicitAssign(TokenIdentifier i, EnumVarDecKeyword::type k, TokenType t, TokenExpression e);
	virtual void analyse();
};

struct TokenVarDecImplicit : public TokenVarDec{

	TokenExpression expr;
	TokenVarDecImplicit(TokenIdentifier i, EnumVarDecKeyword::type k, TokenExpression e, ModifiersInt  m);
	virtual void analyse();
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
};

struct ClassBlock : public TokenPreParseable, public TokenAnalysable{
	std::vector<TokenFuncDec*> funcDecs;
	std::vector<TokenVarDec*> varDecs;
	ClassBlock(TokenFuncDec* funcDec);
	ClassBlock(TokenVarDec* varDec);
	ClassBlock();
	void preParse();
	void analyse();
};

struct TokenTypeDec : public TokenDeclaration{
	bool errored = false;
	Args args;
	std::vector<TokenFuncDec> funcDecs;
	std::vector<TokenVarDec> varDecs;
	TokenTypeDec(Args a, TokenIdentifier i, ModifiersInt m);
	TokenTypeDec(Args a, TokenIdentifier i);
	virtual void preParse();
	virtual void analyse();
	virtual EnumType::type getType();
};

struct TokenClassDec : public TokenTypeDec{
	ClassBlock block;
	Types supers;
	TokenClassDec(Args a, TokenIdentifier i, ModifiersInt m, Types s, ClassBlock b);
	void preParse();
	virtual void analyse();
	virtual EnumType::type getType();
};

struct TokenProtocolDec : public TokenTypeDec{
	ClassBlock block;
	Types supers;
	TokenProtocolDec(Args a, TokenIdentifier i, ModifiersInt m, Types s, ClassBlock b);
	void preParse();
	virtual void analyse();
	virtual EnumType::type getType();
};

struct TokenEnumDec : public TokenTypeDec{

	std::vector<TokenIdentifier> instances;
	TokenEnumDec(Args a, TokenIdentifier i, std::vector<TokenIdentifier> v);
	void preParse();
	virtual void analyse();
	virtual EnumType::type getType();
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
};

struct TokenReturn : public TokenStatement, public TokenAnalysable{

	TokenExpression expr;
	TokenReturn();
	TokenReturn(TokenExpression e);
	virtual void analyse();
};

struct TokenExprInfix : public TokenExpression{
    bool errored = false;
	TokenExpression expr1, expr2;
	Operator op;
	TokenExprInfix(TokenExpression e1, Operator o, TokenExpression e2);
	virtual void analyse();
    virtual TypeI getExprType();
};

struct TokenExprPrefix : public TokenExpression{

	TokenExpression expr;
	Operator op;
	TokenExprPrefix(Operator o, TokenExpression expr);
	virtual void analyse();
    virtual TypeI getExprType();
};

struct TokenExprPostfix : public TokenExpression{

	TokenExpression expr;
	Operator op;
	TokenExprPostfix(TokenExpression e, Operator o);
	virtual void analyse();
    virtual TypeI getExprType();
};

struct TokenExprInt : public TokenExpression{

	int val;
	TokenExprInt(int v);
    virtual TypeI getExprType();
};

struct TokenExprStr : public TokenExpression{

	std::string* str;
	TokenExprStr(std::string* s);
    virtual TypeI getExprType();
};

struct TokenExprChar : public TokenExpression{

	char ch;
	TokenExprChar(char c);
    virtual TypeI getExprType();
};

struct TokenExprBool : public TokenExpression{

	bool val;
	TokenExprBool(bool b);
    virtual TypeI getExprType();
};

struct TokenExprFloat : public TokenExpression{

	float val;
	TokenExprFloat(float v);
    virtual TypeI getExprType();
};

struct TokenExprFloat64 : public TokenExpression{

	double val;
	TokenExprFloat64(double v);
    virtual TypeI getExprType();
};

struct TokenExprLong : public TokenExpression{

	long val;
	TokenExprLong(long v);
    virtual TypeI getExprType();
};

struct TokenExprTernary : public TokenExpression{

	TokenExpression exprBool, expr1, expr2;
	TokenExprTernary(TokenExpression eBool, TokenExpression e1, TokenExpression e2);
	virtual void analyse();
    virtual TypeI getExprType();
};

struct TokenPrefix : public TokenExpression{

};

struct TokenVariable : public TokenPrefix{

	TokenPrefix prefix;
	TokenIdentifier id;
	std::vector<TokenExpression> arrExprs;
	TokenVariable(TokenIdentifier i);
	virtual void analyse();
    virtual TypeI getExprType();
};

struct TokenVarAssign : public TokenStatement{

	TokenVariable var;
	Operator* op;
	TokenExpression expr;
	TokenVarAssign(TokenVariable v, Operator* o, TokenExpression e);
	virtual void analyse();
};

struct TokenFuncCall : public TokenStatement, public TokenPrefix{

	TokenPrefix prefix;
	TokenIdentifier id;
	std::vector<TokenExpression> args;
	TokenFuncCall(TokenIdentifier i, std::vector<TokenExpression> e);
	virtual void analyse();
};

#endif
