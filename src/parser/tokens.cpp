#include <parser/tokens.hpp>
#include <loader/context.hpp>
#include <loader/member.hpp>
#include <util/util.hpp>
#include <semantics/stdtypes.hpp>
#include <semantics/semantics.hpp>
#include <error/errors.hpp>

const char* typeStrs[EnumType::NUM_TYPES] = {
	"Class",
	"Protocol",
	"Enum"
};

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

TokenPreParseable::TokenPreParseable(){}

TokenAnalysable::TokenAnalysable(){}

TokenFile::TokenFile(TokenNamespace n, Imports i, std::vector<TokenTypeDec*> v) : namespc(n), imports(i), typeDecs(v){}

TokenFile::TokenFile(){}

TokenStatement::TokenStatement(){}

TokenIdentifier::TokenIdentifier(std::string str) : str(str){}

TokenIdentifier::TokenIdentifier(){}

bool TokenIdentifier::operator==(TokenIdentifier id){
	return id.str == str;
}

bool TokenIdentifier::operator==(std::string s){
	return str == s;
}

TokenQualifiedName::TokenQualifiedName(TokenIdentifier id){
	paths.push_back(id.str);
}

TokenQualifiedName::TokenQualifiedName(){}

TokenNamespace::TokenNamespace(){}

TokenNamespace::TokenNamespace(TokenQualifiedName name) : name(name){}

TokenImport::TokenImport(TokenQualifiedName name) : name(name){}

TokenReturn::TokenReturn(TokenExpression* e) : expr(e){}

TokenReturn::TokenReturn(){}

Imports::Imports(){}

Imports::Imports(TokenImport i){
	imports.push_back(i);
}

TokenType::TokenType(TokenIdentifier i) : id(i){}

TokenType::TokenType(){}

bool TokenType::operator==(TokenType type){
	return id == type.id && arrDims == type.arrDims;
}

bool TokenType::operator==(std::string str){
	return id == str;
}

bool TokenType::operator!=(const char* str){
	return id.str != std::string(str);
}

TokenArg::TokenArg(TokenIdentifier i, TokenType t) : id(i), type(t){}

bool TokenArg::operator==(TokenArg arg){
	return arg.type == type;
}

bool TokenArg::operator!=(TokenArg arg){
	return !(arg.type == type);
}

Args::Args(){}

bool Args::operator==(Args a){
	int i = 0;
	foreach(it, a.args) if(*it != args.at(i++)) return false;
	return true;
}

bool Args::isEmpty(){
	return args.size() == 0;
}

TokenDeclaration::TokenDeclaration(TokenIdentifier i, ModifiersInt m) : id(i), mods(m){
}

TokenDeclaration::TokenDeclaration(TokenIdentifier i) : id(i){
}

TokenDeclaration::TokenDeclaration() : id(TokenIdentifier()){}

TokenTypeDec::TokenTypeDec(Args a, TokenIdentifier i, ModifiersInt m) : TokenDeclaration(i, m), args(a){}

TokenTypeDec::TokenTypeDec(Args a, TokenIdentifier i) : TokenDeclaration(i), args(a){}

TokenClassDec::TokenClassDec(Args a, TokenIdentifier i, ModifiersInt m, Types s, ClassBlock b) : TokenTypeDec(a, i, m), block(b), supers(s){}

TokenProtocolDec::TokenProtocolDec(Args a, TokenIdentifier i, ModifiersInt m, Types  s, ClassBlock b) : TokenTypeDec(a, i, m), block(b), supers(s){}

TokenEnumDec::TokenEnumDec(Args a, TokenIdentifier i, std::vector<TokenIdentifier> v) : TokenTypeDec(a, i), instances(v){}

TokenFuncDec::TokenFuncDec(ModifiersInt m, TokenIdentifier i, Args a, TokenType t, TokenType t2) : TokenDeclaration(i, m), args(a), type(t), throws(t2){}

TokenFuncDec::TokenFuncDec() : TokenDeclaration(), type(TokenType()), throws(TokenType()){}

Types::Types(TokenType t){
	types.push_back(t);
}

Types::Types(){}

TokenBlock::TokenBlock() : TokenAnalysable(){}

TokenBlock::TokenBlock(TokenStatement* s) : TokenBlock(){
	stmts.push_back(s);
}

ClassBlock::ClassBlock(TokenFuncDec* funcDec){
	funcDecs.push_back(funcDec);
}

ClassBlock::ClassBlock(TokenVarDec* varDec){
	varDecs.push_back(varDec);
}

ClassBlock::ClassBlock(){}

TokenVarDec::TokenVarDec(ModifiersInt m, TokenIdentifier i, EnumVarDecKeyword::type k) : TokenDeclaration(i, m), decKeyword(k){}

TokenVarDecExplicit::TokenVarDecExplicit(TokenIdentifier i, EnumVarDecKeyword::type k, TokenType t) : TokenVarDec(mods, i, k), type(t){}

TokenVarDecExplicitAssign::TokenVarDecExplicitAssign(TokenIdentifier i, EnumVarDecKeyword::type k, TokenType t, TokenExpression* e) : TokenVarDecExplicit(i, k, t), expr(e){}

TokenVarDecImplicit::TokenVarDecImplicit(TokenIdentifier i, EnumVarDecKeyword::type k, TokenExpression* e, ModifiersInt m) : TokenVarDec(m, i, k), expr(e){}

TypeI TokenExpression::getExprType(){
	return TypeI("");
}

TokenExprInfix::TokenExprInfix(TokenExpression* e1, Operator o, TokenExpression* e2) : expr1(e1), op(o), expr2(e2){}

TypeI TokenExprInfix::getExprType(){
	TypeI expr1Type = expr1->getExprType(), expr2Type = expr2->getExprType();
	// Ensure that the types are either String or primitives
	if(StdTypes::isStandardType(expr1Type) && StdTypes::isStandardType(expr2Type)){
		// Get the most precedent type. Eg 1.2 + 4 gives a float64 and "hello" + 4 gives a String
		return Semantics::getPrecedentType(expr1Type, expr2Type);
	}else{
		Error::semanticError("Cannot apply operator to types other than primtitives and String objects (" + expr1Type.toString() + ", " + expr2Type.toString() + ")");
		errored = true;
		return TypeI("");
	}
}

TokenExprPrefix::TokenExprPrefix(Operator o, TokenExpression* e) : op(o), expr(e){}

TypeI TokenExprPrefix::getExprType(){
	return expr->getExprType();
}

TokenExprPostfix::TokenExprPostfix(TokenExpression* e, Operator o) : expr(e), op(o){}

TypeI TokenExprPostfix::getExprType(){
	return expr->getExprType();
}

TokenExprInt::TokenExprInt(int v) : val(v){}

TypeI TokenExprInt::getExprType(){
	return StdTypes::getAsTypeI(EnumPrimitiveType::INT);
}

TokenExprStr::TokenExprStr(std::string* s) : str(s){}

TypeI TokenExprStr::getExprType(){
	return TypeI(StdTypes::getStringShortName());
}

TokenExprChar::TokenExprChar(char c) : ch(c){}

TypeI TokenExprChar::getExprType(){
	return StdTypes::getAsTypeI(EnumPrimitiveType::CHAR);
}

TokenExprBool::TokenExprBool(bool v) : val(v){}

TypeI TokenExprBool::getExprType(){
	return StdTypes::getAsTypeI(EnumPrimitiveType::BOOL);
}

TokenExprFloat::TokenExprFloat(float v) : val(v){}

TypeI TokenExprFloat::getExprType(){
	return StdTypes::getAsTypeI(EnumPrimitiveType::FLOAT);
}

TokenExprFloat64::TokenExprFloat64(double v) : val(v){}

TypeI TokenExprFloat64::getExprType(){
	return StdTypes::getAsTypeI(EnumPrimitiveType::FLOAT64);
}

TokenExprLong::TokenExprLong(long v) : val(v){}

TypeI TokenExprLong::getExprType(){
	return StdTypes::getAsTypeI(EnumPrimitiveType::INT64);
}

TokenExprTernary::TokenExprTernary(TokenExpression* eB, TokenExpression* e1, TokenExpression* e2) : exprBool(eB), expr1(e1), expr2(e2){}

TypeI TokenExprTernary::getExprType(){
	return Semantics::getPrecedentTypeOrCommonSuper(expr1->getExprType(), expr2->getExprType());
}

TokenVariable::TokenVariable(TokenIdentifier i) : id(i){}

TypeI TokenVariable::getExprType(){
	//TODO: Get var type from symbol table
	return TypeI("");
}

TokenVarAssign::TokenVarAssign(TokenVariable v, Operator* o, TokenExpression* e) : var(v), op(o), expr(e){}

TokenFuncCall::TokenFuncCall(TokenIdentifier i, std::vector<TokenExpression*> e) : id(i), args(e){}
