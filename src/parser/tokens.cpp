#include <parser/tokens.h>
#include <loader/context.h>
#include <loader/member.h>
#include <util/util.h>

EnumModifier::type Tokens::getMod(std::string s){
	if(s == "public") return EnumModifier::PUBLIC;
	else if(s == "private") return EnumModifier::PRIVATE;
	else if(s == "protected") return EnumModifier::PROTECTED;
	else if(s == "final") return EnumModifier::FINAL;
	else if(s == "required") return EnumModifier::REQUIRED;
	else if(s == "native") return EnumModifier::NATIVE;
	else if(s == "override") return EnumModifier::OVERRIDE;
	else if(s == "standard") return EnumModifier::STANDARD;
	else if(s == "static") return EnumModifier::STATIC;
	return EnumModifier::INVALID;
}

Token::Token(){}

TokenFile::TokenFile(TokenNamespace n, Imports i, std::vector<TokenTypeDec*> v) : namespc(n), imports(i), typeDecs(v){}

TokenFile::TokenFile(){}

TokenStatement::TokenStatement() : TokenAnalysable(){}

TokenIdentifier::TokenIdentifier(std::string* str) : str(str){}

TokenIdentifier::TokenIdentifier(){}

TokenQualifiedName::TokenQualifiedName(TokenIdentifier id){
	paths.push_back(*id.str);
}

TokenQualifiedName::TokenQualifiedName(){}

TokenNamespace::TokenNamespace(){}

TokenNamespace::TokenNamespace(TokenQualifiedName name) : name(name){}

TokenImport::TokenImport(TokenQualifiedName name) : name(name){}

TokenReturn::TokenReturn(TokenExpression e) : expr(e){}

TokenReturn::TokenReturn() {}

Imports::Imports(){}

Imports::Imports(TokenImport i){
	imports.push_back(i);
}

TokenType::TokenType(TokenIdentifier i) : id(i){}

TokenType::TokenType(){}

TokenArg::TokenArg(TokenIdentifier i, TokenType t) : id(i), type(t){}

Args::Args(){}

TokenDeclaration::TokenDeclaration(TokenIdentifier i, ModifiersInt m) : id(i), mods(m){}

TokenDeclaration::TokenDeclaration(TokenIdentifier i) : id(i){}

TokenDeclaration::TokenDeclaration() : id(TokenIdentifier()){}

TokenTypeDec::TokenTypeDec(Args a, TokenIdentifier i, ModifiersInt m, TokenBlock b) : TokenDeclaration(i, m), args(a){}

TokenTypeDec::TokenTypeDec(Args a, TokenIdentifier i, TokenBlock b) : TokenDeclaration(i), args(a){}

TokenClassDec::TokenClassDec(Args a, TokenIdentifier i, ModifiersInt m, TokenBlock b, Types s) : TokenTypeDec(a, i, m, b), supers(s){}

TokenProtocolDec::TokenProtocolDec(Args a, TokenIdentifier i, ModifiersInt m, TokenBlock b, Types  s) : TokenTypeDec(a, i, m, b), supers(s){}

TokenEnumDec::TokenEnumDec(Args a, TokenIdentifier i, std::vector<TokenIdentifier> v, TokenBlock b) : TokenTypeDec(a, i, b), instances(v){}

TokenFuncDec::TokenFuncDec(ModifiersInt m, TokenIdentifier i, Args a, TokenType t, TokenType t2) : TokenDeclaration(i, m), args(a), type(t), throws(t2){}

TokenFuncDec::TokenFuncDec() : TokenDeclaration(), type(TokenType()), throws(TokenType()){}

Types::Types(TokenType t){
	types.push_back(t);
}

TokenBlock::TokenBlock() : TokenAnalysable(){}

TokenBlock::TokenBlock(TokenStatement* s) : TokenBlock(){
	stmts.push_back(s);
}

TokenVarDec::TokenVarDec(ModifiersInt m, TokenIdentifier i, EnumVarDecKeyword::type k) : TokenDeclaration(i, m), decKeyword(k){}

TokenVarDecExplicit::TokenVarDecExplicit(TokenIdentifier i, EnumVarDecKeyword::type k, TokenType t) : TokenVarDec(mods, i, k), type(t){}

TokenVarDecExplicitAssign::TokenVarDecExplicitAssign(TokenIdentifier i, EnumVarDecKeyword::type k, TokenType t, TokenExpression e) : TokenVarDecExplicit(i, k, t), expr(e){}

TokenVarDecImplicit::TokenVarDecImplicit(TokenIdentifier i, EnumVarDecKeyword::type k, TokenExpression e, ModifiersInt m) : TokenVarDec(m, i, k), expr(e){}

TokenExprInfix::TokenExprInfix(TokenExpression e1, Operator o, TokenExpression e2) : expr1(e1), op(o), expr2(e2){}

TokenExprPrefix::TokenExprPrefix(Operator o, TokenExpression e) : op(o), expr(e){}

TokenExprPostfix::TokenExprPostfix(TokenExpression e, Operator o) : expr(e), op(o){}

TokenExprInt::TokenExprInt(int v) : val(v){}

TokenExprStr::TokenExprStr(std::string* s) : str(s){}

TokenExprChar::TokenExprChar(char c) : ch(c){}

TokenExprBool::TokenExprBool(bool v) : val(v){}

TokenExprFloat::TokenExprFloat(float v) : val(v){}

TokenExprFloat64::TokenExprFloat64(double v) : val(v){}

TokenExprLong::TokenExprLong(long v) : val(v){}

TokenExprTernary::TokenExprTernary(TokenExpression eB, TokenExpression e1, TokenExpression e2) : exprBool(eB), expr1(e1), expr2(e2){}

TokenVariable::TokenVariable(TokenIdentifier i) : id(i){}

TokenVarAssign::TokenVarAssign(TokenVariable v, Operator* o, TokenExpression e) : var(v), op(o), expr(e){}

TokenFuncCall::TokenFuncCall(TokenIdentifier i, std::vector<TokenExpression> e) : id(i), args(e){}
