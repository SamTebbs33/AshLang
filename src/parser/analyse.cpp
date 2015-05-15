#include <parser/tokens.hpp>
#include <semantics/semantics.hpp>
#include <util/util.hpp>

void TokenStatement::analyse(){}

void TokenType::analyse(){
    if(id.str != "") if(!Semantics::checkTypeExists(id.str)) errored = true;
}

void TokenArg::analyse(){
    type.analyse();
    // If the type errored or if the variable used for the argument already exists
    if(type.errored || Semantics::checkVarNotExistsInCurrentType(id.str)) errored = true;
}

void TokenBlock::analyse(){
    foreach(it, stmts){
        if(*it) (*it)->analyse();
    }
}

void TokenDeclaration::analyse(){}

void TokenFuncDec::analyse(){
    foreach(it, args.args){
        (*it).analyse();
        if((*it).errored) errored = true;
        if(!Semantics::checkForNoDuplicates(&args, &(*it))) errored = true;
    }
    type.analyse();
    if(type.errored) errored = true;
    // Ensure that the type used for the throws declaration is an instance of Throwable
    if(throws != "") Semantics::checkFuncThrowsExtendsThrowable(throws.id.str);
    block.analyse();
}

void ClassBlock::analyse(){
    foreach(it, varDecs) if(*it) (*it)->analyse();
    foreach(it, funcDecs) if(*it) (*it)->analyse();
}

void TokenTypeDec::analyse(){}

void TokenClassDec::analyse(){
    if(!TokenTypeDec::errored){
        foreach(it, supers.types){
            (*it).analyse();
            // Ensure the class is not attempting to extend itself
            if(!Semantics::checkSuperIsNotCurrentType((*it).id.str)) errored = true;
        }
    }
    block.analyse();
}

void TokenProtocolDec::analyse(){
    if(!TokenTypeDec::errored){
        foreach(it, supers.types){
            (*it).analyse();
            // Ensure the protocol is not attempting to implement itself
            if(!Semantics::checkSuperIsNotCurrentType((*it).id.str)) errored = true;
        }
    }
    block.analyse();
}

void TokenEnumDec::analyse(){}

void TokenFile::analyse(){
    foreach(it, typeDecs) if(*it) (*it)->analyse();
}

void TokenExpression::analyse(){}

void TokenVarDec::analyse(){}

void TokenVarDecExplicit::analyse(){
    type.analyse();
}

void TokenVarDecExplicitAssign::analyse(){
    TokenVarDecExplicit::analyse();
    expr.analyse();
}

void TokenVarDecImplicit::analyse(){}

void TokenReturn::analyse(){}

void TokenExprInfix::analyse(){}

void TokenExprPrefix::analyse(){}

void TokenExprPostfix::analyse(){}

void TokenExprTernary::analyse(){}

void TokenVariable::analyse(){}

void TokenVarAssign::analyse(){}

void TokenFuncCall::analyse(){}
