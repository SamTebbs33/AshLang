#include <parser/tokens.h>
#include <loader/context.h>
#include <loader/member.h>
#include <util/util.h>

TokenFile::TokenFile(TokenNamespace* n, Imports* i, std::vector<TokenTypeDec*>* v) : namespc(n), imports(i), typeDecs(v){
}

void TokenFile::preParse(){
	Context::push(new FileContext("", namespc != NULL ? Members::toQualifiedName(namespc->name) : NULL));
	if(namespc) namespc->preParse();
	if(imports) foreachp(it, imports->imports) (*it)->preParse();
	if(typeDecs) foreachp(it, typeDecs) (*it)->preParse();
}

TokenIdentifier::TokenIdentifier(std::string* str) : str(str){

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

TokenQualifiedName::TokenQualifiedName(TokenIdentifier* str){
	this->paths = new std::vector<std::string*>();
	this->paths->push_back(str->str);
}

TokenNamespace::TokenNamespace(){
}

TokenNamespace::TokenNamespace(TokenQualifiedName* name) : name(name){
}

void TokenNamespace::preParse(){

}

TokenImport::TokenImport(TokenQualifiedName* name) : name(name){

}

void TokenImport::preParse(){
	ClassLoader::importClass(*name->paths);
}

TokenReturn::TokenReturn(TokenExpression* e) : expr(e){

}

TokenReturn::TokenReturn() : expr(NULL){

}

Imports::Imports(){
	imports = new std::vector<TokenImport*>();
}

Imports::Imports(TokenImport* i){
	imports = new std::vector<TokenImport*>();
	imports->push_back(i);
}

Modifiers::Modifiers(){
	mods = new std::vector<TokenModifier*>();
}

Modifiers::Modifiers(TokenModifier* m){
	mods = new std::vector<TokenModifier*>();
	mods->push_back(m);
}

TokenType::TokenType(TokenIdentifier* i) : id(i){

}

TokenArg::TokenArg(TokenIdentifier* i, TokenType* t) : id(i), type(t){

}

Args::Args(){
	args = new std::vector<TokenArg*>();
}

TokenDeclaration::TokenDeclaration(TokenIdentifier* i, Modifiers* m) : id(i), mods(m){

}

TokenTypeDec::TokenTypeDec(Args* a, TokenIdentifier* i, Modifiers* m, TokenBlock* b) : TokenDeclaration(i, m), args(a), block(b){

}

void TokenTypeDec::preParse(){
	Members::addAndEnterType(new Type(Members::toModifiersInt(mods), Context::getNamespace(), id->str));
}

TokenClassDec::TokenClassDec(Args* a, TokenIdentifier* i, Modifiers* m, TokenBlock* b, Types* s) : TokenTypeDec(a, i, m, b), supers(s){

}

TokenProtocolDec::TokenProtocolDec(Args* a, TokenIdentifier* i, Modifiers* m, TokenBlock* b, Types* s) : TokenTypeDec(a, i, m, b), supers(s){

}

TokenEnumDec::TokenEnumDec(Args* a, TokenIdentifier* i, std::vector<TokenIdentifier*>* v, TokenBlock* b) : TokenTypeDec(a, i, new Modifiers(), b), instances(v){

}

TokenFuncDec::TokenFuncDec(TokenIdentifier* i, Args* a, TokenType* t, TokenType* t2) : TokenDeclaration(i, NULL), args(a), type(t), throws(t2){

}

void TokenFuncDec::preParse(){

}

Types::Types(TokenType* t){
	types = new std::vector<TokenType*>();
	types->push_back(t);
}

TokenBlock::TokenBlock(TokenStatement* s){
	stmts = new std::vector<TokenStatement*>();
	stmts->push_back(s);
}

TokenBlock::TokenBlock(){
	stmts = new std::vector<TokenStatement*>();
}

TokenVarDec::TokenVarDec(TokenIdentifier* i, EnumVarDecKeyword::type k) : TokenDeclaration(i, NULL), decKeyword(k){

}

TokenVarDecExplicit::TokenVarDecExplicit(TokenIdentifier* i, EnumVarDecKeyword::type k, TokenType* t) : TokenVarDec(i, k), type(t){

}

TokenVarDecExplicitAssign::TokenVarDecExplicitAssign(TokenIdentifier* i, EnumVarDecKeyword::type k, TokenType* t, TokenExpression* e) : TokenVarDecExplicit(i, k, t), expr(e){

}

TokenVarDecImplicit::TokenVarDecImplicit(TokenIdentifier* i, EnumVarDecKeyword::type k, TokenExpression* e) : TokenVarDec(i, k), expr(e){

}

TokenExprInfix::TokenExprInfix(TokenExpression* e1, Operator* o, TokenExpression* e2) : expr1(e1), op(o), expr2(e2){

}

TokenExprPrefix::TokenExprPrefix(Operator* o, TokenExpression* e) : op(o), expr(e){

}

TokenExprPostfix::TokenExprPostfix(TokenExpression* e, Operator* o) : expr(e), op(o){

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

TokenExprTernary::TokenExprTernary(TokenExpression* eB, TokenExpression* e1, TokenExpression* e2) : exprBool(eB), expr1(e1), expr2(e2){

}

TokenVariable::TokenVariable(TokenIdentifier* i) : id(i){
	arrExprs = new std::vector<TokenExpression*>();
}

TokenVarAssign::TokenVarAssign(TokenVariable* v, Operator* o, TokenExpression* e) : var(v), op(o), expr(e){

}

TokenFuncCall::TokenFuncCall(TokenIdentifier* i, std::vector<TokenExpression*>* e) : id(i), args(e){

}
