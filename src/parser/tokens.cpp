#include <parser/tokens.h>
#include <loader/context.h>
#include <loader/member.h>
#include <util/util.h>

Token::Token(){

}

void TokenPreParseable::preParse(){

}

TokenFile::TokenFile(TokenNamespace n, Imports i, std::vector<TokenTypeDec*> v) : namespc(n), imports(i), typeDecs(v){

}

TokenFile::TokenFile(){

}

TokenStatement::TokenStatement() : Token(){

}

void TokenFile::preParse(){
	Context::push(FileContext("", Members::toQualifiedName(&namespc.name, "")));
	namespc.preParse();
	foreach(it, imports.imports) (*it).preParse();
	foreach(it, typeDecs) if(*it) (*it)->preParse();
}

TokenIdentifier::TokenIdentifier(std::string* str) : str(str){

}

TokenIdentifier::TokenIdentifier(){

}

TokenModifier::TokenModifier(std::string s){
	if(s == "public") mod = EnumModifier::PUBLIC;
	else if(s == "private") mod = EnumModifier::PRIVATE;
	else if(s == "protected") mod = EnumModifier::PROTECTED;
	else if(s == "final") mod = EnumModifier::FINAL;
	else if(s == "required") mod = EnumModifier::REQUIRED;
	else if(s == "native") mod = EnumModifier::NATIVE;
	else if(s == "override") mod = EnumModifier::OVERRIDE;
	else if(s == "standard") mod = EnumModifier::STANDARD;
	else if(s == "static") mod = EnumModifier::STATIC;
}

TokenQualifiedName::TokenQualifiedName(TokenIdentifier id){
	paths.push_back(*id.str);
}

TokenQualifiedName::TokenQualifiedName(){

}

TokenNamespace::TokenNamespace(){

}

TokenNamespace::TokenNamespace(TokenQualifiedName name) : name(name){

}

void TokenNamespace::preParse(){

}

TokenImport::TokenImport(TokenQualifiedName name) : name(name){

}

void TokenImport::preParse(){
	ClassLoader::importClass(name.paths);
}

TokenReturn::TokenReturn(TokenExpression e) : expr(e){

}

TokenReturn::TokenReturn() {

}

Imports::Imports(){
}

Imports::Imports(TokenImport i){
	imports.push_back(i);
}

Modifiers::Modifiers(){
}

Modifiers::Modifiers(TokenModifier m){
	mods.push_back(m);
}

TokenType::TokenType(TokenIdentifier i) : id(i){

}

TokenType::TokenType(){

}

TokenArg::TokenArg(TokenIdentifier i, TokenType t) : id(i), type(t){

}

Args::Args(){
}

TokenDeclaration::TokenDeclaration(TokenIdentifier i, Modifiers m) : id(i), mods(m), TokenStatement(){

}

TokenDeclaration::TokenDeclaration() : id(TokenIdentifier()), mods(Modifiers()){

}

void TokenDeclaration::preParse(){
}

TokenTypeDec::TokenTypeDec(Args a, TokenIdentifier i, Modifiers m, TokenBlock b) : TokenDeclaration(i, m), args(a){

}

void TokenTypeDec::preParse(){
}

TokenClassDec::TokenClassDec(Args a, TokenIdentifier i, Modifiers m, TokenBlock b, Types s) : TokenTypeDec(a, i, m, b), supers(s){

}

void TokenClassDec::preParse(){
	
}

TokenProtocolDec::TokenProtocolDec(Args a, TokenIdentifier i, Modifiers m, TokenBlock b, Types  s) : TokenTypeDec(a, i, m, b), supers(s){

}

void TokenProtocolDec::preParse(){

}

TokenEnumDec::TokenEnumDec(Args a, TokenIdentifier i, std::vector<TokenIdentifier> v, TokenBlock b) : TokenTypeDec(a, i, Modifiers(), b), instances(v){

}

void TokenEnumDec::preParse(){

}

TokenFuncDec::TokenFuncDec(Modifiers m, TokenIdentifier i, Args a, TokenType t, TokenType t2) : TokenDeclaration(i, m), args(a), type(t), throws(t2){

}

TokenFuncDec::TokenFuncDec() : TokenDeclaration(), type(TokenType()), throws(TokenType()){

}

void TokenFuncDec::preParse(){
	Members::addFunction(new FuncSignature(id.str, &args, Members::toModifiersInt(mods)));
}

Types::Types(TokenType t){
	types.push_back(t);
}

TokenBlock::TokenBlock() : Token(){

}

TokenBlock::TokenBlock(TokenStatement* s) : Token(){
	stmts.push_back(s);
}

TokenVarDec::TokenVarDec(Modifiers m, TokenIdentifier i, EnumVarDecKeyword::type k) : TokenDeclaration(i, m), decKeyword(k){

}

void TokenVarDec::preParse(){

}

TokenVarDecExplicit::TokenVarDecExplicit(TokenIdentifier i, EnumVarDecKeyword::type k, TokenType t) : TokenVarDec(mods, i, k), type(t){

}

TokenVarDecExplicitAssign::TokenVarDecExplicitAssign(TokenIdentifier i, EnumVarDecKeyword::type k, TokenType t, TokenExpression e) : TokenVarDecExplicit(i, k, t), expr(e){

}

TokenVarDecImplicit::TokenVarDecImplicit(TokenIdentifier i, EnumVarDecKeyword::type k, TokenExpression e) : TokenVarDec(mods, i, k), expr(e){

}

TokenExprInfix::TokenExprInfix(TokenExpression e1, Operator o, TokenExpression e2) : expr1(e1), op(o), expr2(e2){

}

TokenExprPrefix::TokenExprPrefix(Operator o, TokenExpression e) : op(o), expr(e){

}

TokenExprPostfix::TokenExprPostfix(TokenExpression e, Operator o) : expr(e), op(o){

}

TokenExprInt::TokenExprInt(int v) : val(v){

}

TokenExprStr::TokenExprStr(std::string* s) : str(s){

}

TokenExprChar::TokenExprChar(char c) : ch(c){

}

TokenExprBool::TokenExprBool(bool v) : val(v){

}

TokenExprFloat::TokenExprFloat(float v) : val(v){

}

TokenExprFloat64::TokenExprFloat64(double v) : val(v){

}

TokenExprLong::TokenExprLong(long v) : val(v){

}

TokenExprTernary::TokenExprTernary(TokenExpression eB, TokenExpression e1, TokenExpression e2) : exprBool(eB), expr1(e1), expr2(e2){

}

TokenVariable::TokenVariable(TokenIdentifier i) : id(i){
}

TokenVarAssign::TokenVarAssign(TokenVariable v, Operator* o, TokenExpression e) : var(v), op(o), expr(e){

}

TokenFuncCall::TokenFuncCall(TokenIdentifier i, std::vector<TokenExpression> e) : id(i), args(e){

}
