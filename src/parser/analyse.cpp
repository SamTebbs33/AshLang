#include <parser/tokens.hpp>
#include <semantics/semantics.hpp>

void TokenStatement::analyse(){}

void TokenType::analyse(){
    if(!Semantics::checkTypeExists(*id.str)) errored = true;
}

void TokenArg::analyse(){}

void TokenBlock::analyse(){}

void TokenDeclaration::analyse(){}

void TokenFuncDec::analyse(){}

void TokenTypeDec::analyse(){}

void TokenClassDec::analyse(){}

void TokenProtocolDec::analyse(){}

void TokenEnumDec::analyse(){}

void TokenFile::analyse(){
    foreach(it, typeDecs) if(*it) (*it)->analyse();
}

void TokenExpression::analyse(){}

void TokenVarDec::analyse(){}

void TokenVarDecExplicit::analyse(){}

void TokenVarDecExplicitAssign::analyse(){}

void TokenVarDecImplicit::analyse(){}

void TokenReturn::analyse(){}

void TokenExprInfix::analyse(){}

void TokenExprPrefix::analyse(){}

void TokenExprPostfix::analyse(){}

void TokenExprTernary::analyse(){}

void TokenVariable::analyse(){}

void TokenVarAssign::analyse(){}

void TokenFuncCall::analyse(){}
