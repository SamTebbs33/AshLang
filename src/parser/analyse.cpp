#include <parser/tokens.hpp>
#include <semantics/semantics.hpp>
#include <util/util.hpp>
#include <loader/context.hpp>
#include <loader/member.hpp>
#include <error/errors.hpp>

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
    Context::enterFuncContext(FuncContext(Context::getTypeContext().type->getFunc(id.str, &args)));
    int i = 0;
    foreach(it, args.args){
        (*it).analyse();
        if((*it).errored) errored = true;
        if(!Semantics::checkForNoDuplicates(&args, &(*it), i)) errored = true;
        i++;
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

void TokenTypeDec::analyse(){
    Context::enterTypeContext(TypeContext(Members::getType(id.str)));
}

void TokenClassDec::analyse(){
    TokenTypeDec::analyse();
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
    TokenTypeDec::analyse();
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
    expr->analyse();
}

void TokenVarDecImplicit::analyse(){
    TokenVarDec::analyse();
}

void TokenReturn::analyse(){
        if(Context::inFunc()){
            FuncSignature* func = Context::getFuncContext().sig;
            if(func){
                if(expr) expr->analyse();
                // If in a void function and the return expression is not null
                if(func->type.typeShortName == ""){
                    if(expr) Error::semanticError("Cannot return an expression in a void function");
                    errored = true;
                }else if(!expr){
                    Error::semanticError("Cannot return void in a non-void function");
                    errored = true;
                }
            }
        }
}

void TokenExprInfix::analyse(){
    expr1->analyse();
    expr2->analyse();
    if(expr2->errored || expr2->errored) errored = true;
}

void TokenExprPrefix::analyse(){
    expr->analyse();
    if(expr->errored) errored = true;
}

void TokenExprPostfix::analyse(){
    expr->analyse();
    if(expr->errored) errored = true;
}

void TokenExprTernary::analyse(){
    println("ternary");
    exprBool->analyse();
    expr1->analyse();
    expr2->analyse();
    TypeI t1 = expr1->getExprType(), t2 = expr2->getExprType();
    if(Semantics::getPrecedentTypeOrCommonSuper(t1, t2).typeShortName == ""){
        Error::semanticError("Ternary expressions are incompatible (" + t1.toString() + ", " + t2.toString() + ")");
        errored = true;
    }
}

void TokenVariable::analyse(){}

void TokenVarAssign::analyse(){}

void TokenFuncCall::analyse(){}
